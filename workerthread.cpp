#include "workerthread.h"

WorkerThread::WorkerThread(const QString &m_strfile, QObject *parent)
    :QThread(parent)
    ,filename(m_strfile)
{

}


WorkerThread::~WorkerThread()
{

}

void WorkerThread::run()
{


  QFile file(filename);

  if (!file.open(QFile::ReadOnly | QFile::Text))
  {
    QMessageBox *msgBox = new QMessageBox(QMessageBox::Warning, "Warning",
                                           "Failed to parse the file into OSM Files.", QMessageBox::Ok);
     msgBox->show();
    return;

   }

  QString errorStr;
    int errorLine;
    int errorColumn;

    QDomDocument doc;

  // Parse File
  if(!doc.setContent(&file,false,&errorStr,&errorLine,&errorColumn))
  {
      QMessageBox *msgBox = new QMessageBox(QMessageBox::Warning, "Warning",
                                            "Failed to parse the file into a DOM tree.", QMessageBox::Ok);
      msgBox->show();
      return;
  }
  //Get the root element
   QDomNodeList nodeList = doc.elementsByTagName("osm");

   m_osm.clear();
   for(int i=0; i < nodeList.count(); i++)
   {
       QDomElement el = nodeList.at(i).toElement();
       m_osm.push_back(ParseOSMBlk(el));
   }


}


OSMBlk WorkerThread::ParseOSMBlk(QDomElement &elem)
{
    OSMBlk osm;

    QDomNodeList nodeListA = elem.elementsByTagName("node");

    for ( int i =0; i < nodeListA.count() ; i++)
    {
        QDomElement elNode = nodeListA.at(i).toElement();
        osm.NodeTag.push_back(ParseNodeBlk(elNode));

        emit sigAttrValue(osm.NodeTag.at(i).latitude,
                          osm.NodeTag.at(i).longitude);

    }

    QDomNodeList nodeList = elem.elementsByTagName("way");

    for (int i = 0; i < nodeList.count(); i++)
    {
        QDomElement el = nodeList.at(i).toElement();
        osm.wayTag.push_back(ParseWayBlk(el));   //way tag 넣기


    }


    QDomNodeList nodeRelation = elem.elementsByTagName("relation");

    for (int i =0; i < nodeRelation.count(); i++)
    {
        QDomElement el = nodeRelation.at(i).toElement();
        osm.relationTag.push_back(ParseRelationBlk(el));   //way tag 넣기

    }


    return osm;

}


NodeBlk WorkerThread::ParseNodeBlk(QDomElement &elem)
{
    NodeBlk nodeattr;

    nodeattr.id = elem.attribute("id");
    nodeattr.latitude = elem.attribute("lat");
    nodeattr.longitude = elem.attribute("lon");

    return nodeattr;
}

WayBlk WorkerThread::ParseWayBlk(QDomElement &elem)
{
    WayBlk way;

    way.id = elem.attribute("id");
    emit sigWayValue(way.id);

    // bring attribute <nd id= />
    QDomNodeList nodeList = elem.elementsByTagName("nd");

    for (int i = 0; i < nodeList.count(); i++)
    {
        QDomElement el = nodeList.at(i).toElement();
        way.attr.push_back(ParseAttrBlk(el));
        emit sigNodeValue(way.attr.at(i).ref);

    }

    // bring attribute  <tag k="man_made" v="gasometer"/>

    QDomNodeList nodeListB = elem.elementsByTagName("tag");

    for(int j = 0; j < nodeListB.count(); j++ )
    {
        QDomElement elB = nodeListB.at(j).toElement();
        way.attrB.push_back(ParseAttr2Blk(elB));
    }

    return way;

}

RelationBlk WorkerThread::ParseRelationBlk(QDomElement &elem)
{
    RelationBlk tagrelation;
    tagrelation.id = elem.attribute("id");

    QDomNodeList nodeListC = elem.elementsByTagName("member");

    for(int i = 0 ; i < nodeListC.count() ; i++ )
    {
        QDomElement el = nodeListC.at(i).toElement();
        tagrelation.attr3.push_back(ParseAttr3Blk(el));
    }

    QDomNodeList nodeListD = elem.elementsByTagName("tag");

    for(int j = 0; j < nodeListD.count(); j++)
    {
        QDomElement el = nodeListD.at(j).toElement();
        tagrelation.attr4.push_back(ParseAttr4Blk(el));
    }

    return tagrelation;

}


AttrBlk WorkerThread::ParseAttrBlk(QDomElement &elem)
{
   AttrBlk  attr;
   attr.ref = elem.attribute("ref");

   return attr;
 }

AttrBlk2 WorkerThread::ParseAttr2Blk(QDomElement &elem)
{
   AttrBlk2 attrB;
   attrB.k = elem.attribute("k");
   attrB.v = elem.attribute("v");

   return attrB;
}

AttrBlk3 WorkerThread::ParseAttr3Blk(QDomElement &elem)
{
    AttrBlk3 attrC;
    attrC.type = elem.attribute("type");
    attrC.ref = elem.attribute("ref");
    attrC.role = elem.attribute("role");

    return attrC;
}

AttrBlk4 WorkerThread::ParseAttr4Blk(QDomElement &elem)
{
    AttrBlk4 attrD;

    attrD.k = elem.attribute("k");
    attrD.v = elem.attribute("v");

    return attrD;
}



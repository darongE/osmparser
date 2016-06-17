#include "widget.h"
#include "ui_widget.h"
#include <QtWidgets>

// program name : OSM_Parse
// goal : osm 파일의 노드 값을 출력하는 기능


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);


    initialize();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initialize()
{

    QStringList labels;
    labels << tr("Title") << tr("Location");
    ui->treeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);
    ui->treeWidget->setHeaderLabels(labels);

//    folderIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirClosedIcon),
//                         QIcon::Normal, QIcon::Off);
//    folderIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon),
//                         QIcon::Normal, QIcon::On);

//    headIcon.addPixmap(style()->standardPixmap(QStyle::SP_FileIcon));
}

void Widget::on_pushBrowse_clicked()
{

   QString defaultpath = QDir::home().filePath("Documents");
   QString fileName =
           QFileDialog::getOpenFileName(this,tr("open osm file"),
                                        defaultpath,
                                         tr("osm files (*.osm)"));
   if(fileName.isEmpty())
      return;



   WorkerThread *pWorker = new WorkerThread(fileName,this);
   pWorker->start();


}


// parsing
//----------------------------------------------------------------------
// show on list
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





// print list
OSMBlk WorkerThread::ParseOSMBlk(QDomElement &elem)
{
    OSMBlk osm;

    QDomNodeList nodeListA = elem.elementsByTagName("node");

    for ( int i =0; i < nodeListA.count() ; i++)
    {
        QDomElement elNode = nodeListA.at(i).toElement();
        osm.NodeTag.push_back(ParseNodeBlk(elNode));

        qDebug() << "Node id "<< osm.NodeTag.at(i).id
                 << "Node lat "<< osm.NodeTag.at(i).latitude
                 << "Node long "<< osm.NodeTag.at(i).longitude;
    }


    QDomNodeList nodeList = elem.elementsByTagName("way");

    for (int i = 0; i < nodeList.count(); i++)
    {
        QDomElement el = nodeList.at(i).toElement();
        osm.wayTag.push_back(ParseWayBlk(el));   //way tag 넣기

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

    // bring attribute <nd id= />
    QDomNodeList nodeList = elem.elementsByTagName("nd");

    for (int i = 0; i < nodeList.count(); i++)
    {
        QDomElement el = nodeList.at(i).toElement();
        way.attr.push_back(ParseAttrBlk(el));

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













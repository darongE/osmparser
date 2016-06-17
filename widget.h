#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QDomDocument>
#include <QHash>
#include <QFile>
#include <QTreeWidget>

/*
 *  OSM File format
<osm version="0.6" generator="CGImap 0.4.0 (6509 thorn-04.openstreetmap.org)" copyright="OpenStreetMap and contributors">
 <bounds minlat="36.1862000" minlon="129.3654000" maxlat="36.2291000" maxlon="129.3896000"/>    // attr

 // attr
 <node id="241288245" visible="true" version="1" changeset="675468" timestamp="2008-01-21T06:39:31Z" user="dkt" uid="5553" lat="36.2393400" lon="129.3849300"/>
 <node id="241288215" visible="true" version="2" changeset="2345839" timestamp="2009-09-02T08:35:37Z" user="alimamo" uid="7213" lat="36.2331948" lon="129.3829771"/>
 <node id="241288217" visible="true" version="2" changeset="2345839" timestamp="2009-09-02T08:35:37Z" user="alimamo" uid="7213" lat="36.2316769" lon="129.3833089"/>
 <way id="363884083" visible="true" version="1" changeset="33090795" timestamp="2015-08-04T08:39:30Z" user="전홍익" uid="3065125">

// attribute nd, tag
  <nd ref="3680011507"/>
  <nd ref="3680011513"/>
  <nd ref="3680011516"/>
  <nd ref="3680011688"/>
  <tag k="highway" v="unclassified"/>
 </way>

 </osm>   --> tag
*/



namespace Ui {
class Widget;
}


typedef struct tag_AttrBlk
{
  QString ref;                //<nd ref="3680011507"/>

}AttrBlk, *pAttrBlk;

typedef struct tag_AttrBlk2
{
    QString k;
    QString v;

}AttrBlk2, *pAttrBlk2;


typedef struct tag_WayBlk
{
    QString id;
    QVector<AttrBlk> attr;
    QVector<AttrBlk2> attrB;

}WayBlk, *pWayBlk;


typedef struct tag_NodeBlk
{

  QString id;
  QString latitude;
  QString longitude;

}NodeBlk, *pNodeBlk;

typedef struct tag_OSMBlk
{
  QVector<NodeBlk> NodeTag;
  QVector<WayBlk> wayTag;

}OSMBlk, *pOSMBlk;




class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    bool Parse(QString filepath);


private slots:
    void on_pushBrowse_clicked();

private:
    Ui::Widget *ui;
    void initialize();

};

///-------------------------------------------------------------
class WorkerThread : public QThread
{
  Q_OBJECT

public:
  WorkerThread(const QString &m_strfile, QObject * parent);
  ~WorkerThread();

protected:
  void run();


private:

const QString filename;
  QVector <OSMBlk> M_Page();

  NodeBlk ParseNodeBlk(QDomElement &elem);
  WayBlk ParseWayBlk(QDomElement &elem);
  AttrBlk ParseAttrBlk(QDomElement &elem);
  AttrBlk2 ParseAttr2Blk(QDomElement &elem);
  OSMBlk   ParseOSMBlk(QDomElement &elem);

  QVector <OSMBlk> m_osm;
};



#endif // WIDGET_H

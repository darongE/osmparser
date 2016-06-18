#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

#include <QHash>
#include <QFile>
#include <QTreeWidget>
#include "workerthread.h"

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

typedef QVector<NodeBlk > vNodtag;
typedef QVector<AttrBlk > vAttr;
typedef QVector<AttrBlk2 > vAttrB;

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


public slots:


};



#endif // WIDGET_H

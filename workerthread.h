#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H
#include <QThread>
#include <QDomDocument>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include "typedef.h"


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
  QVector <OSMBlk> m_osm;


  OSMBlk  ParseOSMBlk(QDomElement &elem);
  NodeBlk ParseNodeBlk(QDomElement &elem);
  WayBlk ParseWayBlk(QDomElement &elem);
  RelationBlk ParseRelationBlk(QDomElement &elem);

  AttrBlk ParseAttrBlk(QDomElement &elem);
  AttrBlk2 ParseAttr2Blk(QDomElement &elem);
  AttrBlk3 ParseAttr3Blk(QDomElement &elem);
  AttrBlk4 ParseAttr4Blk(QDomElement &elem);

signals:
  void sigWayValue(QString id);
  void sigNodeValue(QString ref);
  void sigAttrValue(QString m_lat,QString m_long);

};


#endif // WORKERTHREAD_H

#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H
#include <QThread>
#include <QDomDocument>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include "typedef.h"

typedef QVector<NodeBlk > Nodetag;
typedef QVector<WayBlk > Waytag;


class WorkerThread : public QThread
{
  Q_OBJECT

public:
    WorkerThread(const QString &m_strfile, QObject * parent);
    ~WorkerThread();

protected:
    void run();

signals:
    void sigShowTree(const Nodetag &node,const Waytag &way);


private:

  const QString filename;
  QVector <OSMBlk> m_osm;

  OSMBlk  ParseOSMBlk(QDomElement &elem);
  NodeBlk ParseNodeBlk(QDomElement &elem);
  WayBlk ParseWayBlk(QDomElement &elem);

  AttrBlk ParseAttrBlk(QDomElement &elem);
  AttrBlk2 ParseAttr2Blk(QDomElement &elem);



};

#endif // WORKERTHREAD_H

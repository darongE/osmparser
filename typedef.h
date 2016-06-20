#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <QVector>



//<relation id="5374953" visible="true" version="3" changeset="37074883" timestamp="2016-02-08T08:47:20Z" user="topstone" uid="1696339">
// <member type="way" ref="361037877" role="outer"/>
// <member type="way" ref="361257770" role="outer"/>
// <member type="way" ref="361257764" role="outer"/>
// <member type="way" ref="180553645" role="outer"/>
// <member type="way" ref="186259909" role="outer"/>
//<tag k="admin_level" v="4"/>
//<tag k="alt_name:en" v="South Chungcheong Province"/>


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



typedef struct tag_AttrBlk3
{
  QString type;
  QString ref;
  QString role;

}AttrBlk3,*pAttrBlk3;

typedef struct tag_AttrBlk4
{
    QString k;
    QString v;

}AttrBlk4,*pAttrBlk4;




typedef struct tag_RelationBlk
{
    QString id;
    QVector<AttrBlk3> attr3;
    QVector<AttrBlk4> attr4;

}RelationBlk, *pRelationBlk;

typedef struct tag_OSMBlk
{
  QVector<NodeBlk> NodeTag;
  QVector<WayBlk> wayTag;
  QVector<RelationBlk> relationTag;
  //relation

}OSMBlk, *pOSMBlk;



#endif // TYPEDEF_H

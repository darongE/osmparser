## osmparser
Parse *.osm file(openstreetmap) and show on list

### 1. 목적
오픈스트리트맵 파일 (*.osm)의 테그의 데이터를 가져와서 보여주는 프로그램 입니다.

This program is for showing tag data on osm files.
It show on tree form.

### 2. TO DO List 
- [X] xml read 하는 API 구성
- [ ] tag 데이터 분류하기
- [ ] attribute 데이터 분류하기
- [ ] 데이터 출력 using TreeWidget

### 3. osm file tag 구성
```
 OSM File format
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
  <nd ref="3680011520"/>
  <nd ref="3680011688"/>
  <tag k="highway" v="unclassified"/>
 </way>

 <relation id="50470" visible="true" version="2" changeset="7309950" timestamp="2011-02-17T05:30:40Z" user="geri07" uid="220650">
  <member type="way" ref="22784210" role="outer"/>
  <tag k="type" v="multipolygon"/>
 </relation>

 </osm>   --> tag


```

### 4. 일정

![osmparser.png]https://raw.githubusercontent.com/darongE/osmparser/master/osmparser.png

 
 

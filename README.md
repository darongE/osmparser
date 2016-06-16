## osmparser
Parse *.osm file(openstreetmap) and show on list

### 1. 목적
오픈스트리트맵에 수많은 테그가 있습니다.
이 태그의 데이터를 분류하여 보기 쉽게 하고자 합니다.

### 2. 어떻게 만들 것인가?
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

 </osm>   --> tag

- first tag <way> </way> 개수 가져오기 
- attribute 데이터 가져오기 
- 데이터 출력 --> QTreeWidget
```
### 3. 제작할 기능 
- [X] xml read 하는 API 구성
- [ ] 노드 분석 기능 
- [ ] 데이터 출력 
 
 

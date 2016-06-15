## osmparser
Parse *.osm file(openstreetmap) and show on list

### 1. 목적
오픈스트리트맵에 수많은 테그가 있습니다.
이 태그의 데이터를 분류하여 보기 쉽게 하고자 합니다.

### 2. 어떻게 만들 것인가?
```
 <way id="100012511" visible="true" version="1" changeset="7304249" 
 timestamp="2011-02-16T14:15:57Z" user="geri07" uid="220650">
  <nd ref="436528798"/>
  <nd ref="1156321398"/>
  <nd ref="1156321409"/>
  <nd ref="1156321400"/>
  <nd ref="1156321410"/>
  <tag k="highway" v="residential"/>
  <tag k="review" v="no"/>
 </way>
```
- <way> </way> 태그 개수 가져오기 
- attribute 데이터 가져오기 
- 데이터 출력 --> QTreeWidget

### 3. 제작할 기능 
- [ ] xml read 하는 API 구성
- [ ] 노드 분석 기능 
- [ ] 데이터 출력 
 
 

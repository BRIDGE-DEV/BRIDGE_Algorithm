---
layout: single
title:  "Data Structure / Algorithm - Quadtree 공간 분할"
categories:
  - DataStructure_Algorithm
---

---

### 쿼드 트리 (Quadtree)
---

쿼드 트리는 트리 구조의 데이터로, **2차원 공간을 4개의 동일한 구역으로 재귀적으로 세분화하여 분할**한다.  
각 내부 노드에 4개의 자식이 있다.

![](/assets/images/algorithm_quadtree_2.png){: .align-center}{: width="70%" height="70%"}
*쿼드 트리의 모습*

참고
  * 이진 트리는 자식 노드가 2개
  * 쿼드 트리는 자식 노드가 4개
  * 옥트리는 자식 노드가 8개

쿼드 트리는 데이터베이스 검색에 사용되기도 하며,  
2차원 공간을 4분할하여 효율적인 데이터 탐색을 진행한다.  
(넓은 지역에 대한 데이터베이스 구축에 매우 용이하다)

![](/assets/images/algorithm_quadtree_1_1.png){: .align-center}{: width="70%" height="70%"}
*데이터 베이스에서의 쿼드 트리*

하지만 일반적으로는 쿼드 트리는 일반적으로 지형(Terrain)에 사용된다.

![](/assets/images/algorithm_quadtree_4.png){: .align-center}{: width="70%" height="70%"}
*지형(Terrain)에서의 쿼드 트리 컬링*

매우 거대한 지형을 빠르게 검색할 수 있고,  
큰 덩어리로 큼직하게 검색하고 찾아나가기 때문에 부하를 줄일 수 있다

---

### 쿼드트리 개요와 동작 원리

---

#### 개요

---

쿼드 트리 : 2차원 평면을 공간 분할하는 용도
   * 점(Point) 쿼드트리: 2차원 평면에서 가까운 위치를 효과적으로 찾는 데 사용 (지도, 도시)
   * **범위(Range) 쿼드트리**: 2차원 평면에서 영역을 가진 물체끼리 겹치는지 탐색하는 데 사용

게임에서는 주로 범위 쿼드트리를 사용한다.

플랫포머 게임에서의 충돌 처리, 탑다운 뷰에서의 충돌 처리 등 2D 평면 공간에서 객체의 충돌 처리를 감지한다.
(또는 위의 예시처럼 컬링에 사용되기도 한다)

충돌 처리는 주로 AABB 알고리즘을 이용하는데, 여기에 쿼드트리를 적용하면 효과적이다.  
한 물체에 대한 충돌 처리를 모든 객체와 일일이 비교해야 하는데 그러지 않아도 되고  
충돌 가능성이 있는 객체만 효과적으로 걸러낸다

#### 동작 원리

---

1. 쿼드 트리의 모든 노드는 고유한 사각형 AABB 영역과 객체 목록을 가진다
2. 전체 영역을 감싸는 사각형 AABB 영역을 생성하고 루트 노드로 지정
3. 자식으로 내려갈수록 4개의 자식을 가진 완전 트리 형태를 유지
4. **객체 삽입**: AABB 영역을 가진 객체를 노드의 객체 목록에 추가
   
  규칙 : 삽입할 물체를 살펴보고 필요하면 분할을 수행한다
  
  * 분할하는 경우는 삽입할 물체가 4분할 영역 중 하나에 <u>완전히 포함되어 있을 경우</u>  
  * <u>경계선에 걸쳐있다면</u>, 루트 목록에 추가하고 삽입 종료

  이렇게 트리 구조의 깊이를 늘려가면서 분할을 진행하는데 깊이를 너무 많이 설정하면 안 되기 때문에 **깊이 제한**을 걸어둔다

  ![](/assets/images/algorithm_quadtree_7.png){: .align-center}{: width="70%" height="70%"}
  *1. 게임 맵을 포함하는 거대 정사각형 영역에 물체를 배치하는 경우 루트 노드는 전체 정사각형 영역이 된다*

  ![](/assets/images/algorithm_quadtree_8.png){: .align-center}{: width="70%" height="70%"}
  *2. 첫 번째 물체의 배치. 루트 노드와 4분할된 자식 노드 영역 중 하나에 완전히 포함되는지 검사한다*

  ![](/assets/images/algorithm_quadtree_9.png){: .align-center}{: width="70%" height="70%"}
  *3. 분할된 노드 영역에 포함되면 재귀적으로 검사를 반복한다*

  ![](/assets/images/algorithm_quadtree_10.png){: .align-center}{: width="70%" height="70%"}
  *4. 분할된 영역에 완전히 포함되지 못하는 경우, 분할을 멈추고 포함하는 영역의 객체 목록에 추가 <br> 이러한 과정으로 객체 삽입이 종료된다.*
  
  <br>

  ![](/assets/images/algorithm_quadtree_11.png){: .align-center}{: width="70%" height="70%"}
  *참고 : 2번 객체를 배치한 예시 (루트 노드에서 바로 경계선에 걸리는 경우) - Root 노드에 객체를 추가한다*
  
  ![](/assets/images/algorithm_quadtree_12.png){: .align-center}{: width="70%" height="70%"}
  *참고 : 10개의 객체를 배치한 예시*
   
5. **충돌 질의**: 노드의 객체 목록에서 주어진 AABB 영역과 충돌하는 객체를 빠르게 파악
   
  주어진 AABB 영역이 쿼드트리 내 객체와 충돌하는지 파악하는 기능으로  
  <u>질의할 AABB 영역이 속한 사분면 노드를 모두 파악</u>한다  
  각 사분면 노드의 객체 목록에서 충돌을 가능 여부를 검색한다
   
  ![](/assets/images/algorithm_quadtree_13.png){: .align-center}{: width="70%" height="70%"}
  *붉은 영역의 AABB 영역과 충돌하는 객체를 탐색*

  붉은 영역이 3, 7, 8 객체와 충돌하고 있다  
  이 붉은 영역과 충돌하는 물체를 탐색하기 위해서는 10개의 객체를 모두 전수조사 해야 한다.  
  하지만 이 수가 많아지면 성능 저하가 발생하므로 트리구조를 활용해서 검색량을 줄인다.  
  (검색 가능성이 있는 노드만을 걸러내는 작업을 실행한다)
   
  ![](/assets/images/algorithm_quadtree_14.png){: .align-center}{: width="70%" height="70%"}
  *Root 영역*

  만약 다음과 같이 루트 노드의 객체 목록에 물체가 있다면 (가정)  
  루트노드의 객체 목록은 충돌 가능성이 있기 때문에 검사 목록에 추가한다

  ![](/assets/images/algorithm_quadtree_15.png){: .align-center}{: width="70%" height="70%"}
  *Upper Right 영역*

  깊이 1의 UpperRight 영역에 물체가 다음과 같이 있다면 (가정)  
  이또한 충돌 가능성이 있기 때문에 검사 목록에 추가한다

  ![](/assets/images/algorithm_quadtree_17.png){: .align-center}{: width="70%" height="70%"}
  *Upper Right 영역 내 LowerRight 영역*

  깊이 2의 Upper Right 영역 내 LowerRight 영역에 다음과 같이 물체가 있다면  
  ...
  
  ![](/assets/images/algorithm_quadtree_18.png){: .align-center}{: width="70%" height="70%"}
  *Upper Right 영역 내 LowerRight 영역 내 하위 4개의 사분면*

  깊이 3에서는 4개의 사분면 모두 충돌 가능성이 있으므로 모두 검사 목록에 추가한다  
  여기서 트리 구조의 깊이를 최대 3으로 제한해, 조사를 종료한다
  
  ![](/assets/images/algorithm_quadtree_19.png){: .align-center}{: width="70%" height="70%"}
  *붉은 영역에 대한 충돌을 감지하기 위해 조사해야 할 총 노드*

  깊이가 3이라면 85(1 + 4 + 16 + 64)개 노드가 생성되는데, 그 중 7개의 노드만을 감지하면 된다  
  충돌 검사의 효율성이 크게 증가한다

  객체의 삽입은 완전히 포함되는 경우에만 추가하면 됐다면,  
  충돌 질의를 수행하는 경우에는 삽입과 다르게 <u>겹치는 영역과 포함하는 영역의 노드를 모두 추가</u>해야 한다

### 쿼드 트리의 구현

---

...
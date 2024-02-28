---
layout: single
title:  "Data Structure / Algorithm - BFS와 최단 경로"
categories:
  - DataStructure_Algorithm
---

---

### BFS의 동작 원리

---

[이전 포스팅 내용 - BFS의 동작 순서](https://joonyle99.github.io/datastructure_algorithm/DataStructure_Algorithm-DFS-BFS/#bfs)

BFS는 그래프의 노드를 탐색하는 또 다른 방법으로, 시작 노드에 인접한 노드를 먼저 탐색하는 방식이다.  
이 알고리즘은 주로 <u>큐(Queue)</u>를 사용하여 구현되며, 다음과 같은 순서로 실행된다.

1. **시작 노드 선택 및 큐에 삽입** : 탐색을 시작할 노드를 선택하고, 이 노드를 큐에 삽입
2. **큐에서 노드 제거 및 방문** : 큐에서 노드를 하나 제거하고, 해당 노드를 방문 및 방문처리
3. **인접 노드 큐에 삽입** : 방문한 노드와 인접한 모든 노드를 큐에 삽입
4. **반복 실행** : 큐가 비어있을 때까지 2번과 3번의 과정을 반복

![](data:image/png;base64,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){: .align-center}
*BFS의 LEVEL*

### BFS의 장단점

---

BFS는 레벨(Level) 별로 탐색하므로, 최단 경로 문제에 자주 사용된다.  
또한, <u>DFS에 비해 구현이 조금 더 간단하며, 재귀 호출을 사용하지 않기 때문에 스택 오버플로의 위험이 적다.</u>

하지만 BFS는 탐색 과정에서 큐에 모든 인접 노드를 저장하기 때문에,  
특히 그래프가 밀집되어 있거나 노드 수가 많은 경우, <u>큐에 많은 노드가 저장되어 상당한 양의 메모리를 사용할 수 있다.</u>

### 백준 1697번 - 숨바꼭질

---

[문제 링크](https://www.acmicpc.net/problem/1697)

![](/assets/images/algorithm_shortestPath.png){: .align-center}
*문제 설명*

### 이 문제에서 BFS를 이용해야 하는 이유

---

수빈이의 위치가 주어졌을 때 동생에게 가기 위한 경로가 무수히 많다.  
그리고 한 위치에서 수빈이가 움직일 수 있는 경우는 다음과 같다.

![](/assets/images/algorithm_shortestPath2.png){: .align-center}
*수빈이의 이동 경우의 수. LEVEL은 시간을 의미한다*

1. 왼쪽으로 걷기
2. 오른쪽으로 걷기
3. 순간이동

하지만 '최단 시간'으로 가야 하므로 각 상황에서 선택할 수 있는 경로인 <u>'너비'를 우선으로 탐색</u>해야 한다.  
<u>수빈이가 동생을 찾았을 때의 LEVEL(경과 시간)이 최단 경로</u>인 것이므로 BFS로 풀어야 한다고 생각했다.

### 풀이 방법

---

```c++
	int N; cin >> N;	// 수빈이의 위치
	int K; cin >> K;	// 동생의 위치

	const int result = BFS(N, K);
	cout << result << '\n';
```

BFS의 매개변수로 수빈이의 시작 위치와 수빈이가 도착해야 하는 목적지인 동생의 위치를 넣어준다.  
BFS의 return이 정답(최단 시간)을 반환하도록 함수를 설계할 것이다.

```c++
// 걷기 기능
int Walk(int x, int dir)
{
	// X-1 또는 X+1로 이동하게 된다

	x += dir;
	return x;
}

// 순간이동 기능
int Teleport(int x)
{
	// 2*X의 위치로 이동하게 된다
	// *무조건 오른쪽으로만 이동*

	x *= 2;
	return x;
}
```

우선, 수빈이의 이동에 대한 기능을 구현한다.

```c++
int BFS(int subinPos, int sisterPos)
{
	// BFS를 위한 준비 단계
	std::queue<std::pair<int, int>> myQueue;	// 1. 큐 생성 <수빈의 위치, 이동 시간>
	bool visited[100001] = { false, };			// 2. 방문 여부를 저장할 배열 생성

	// 초기화
	myQueue.push(std::make_pair(subinPos, 0));
	visited[subinPos] = true;

	// 수빈이의 위치와 경과 시간에 대한 정보가 큐에 1개 들어가 있는 상태로 BFS 시작
	// 인접한 노드에 접근하며 방문 여부를 체크하고, 방문하지 않은 노드라면 큐에 넣는다.
	while (!myQueue.empty())
	{
		// 큐의 맨 앞에 있는 정보를 가져온 후 큐에서 제거
		auto prevInfo = myQueue.front();
		myQueue.pop();

		// 목표 지점에 도달했다면 걸린 시간을 리턴
		if (prevInfo.first == sisterPos)
			return prevInfo.second;

		// 3가지 이동 상황을 계산

		// 1. 오른쪽으로 걷기
		int rightResult = Walk(prevInfo.first, 1);
		// 길을 벗어났는지 체크
		if (rightResult <= 100000 && rightResult >= 0)
		{
			// 방문하지 않은 노드라면 큐에 넣는다.
			if (!visited[rightResult])
			{
				// 큐에 넣을 때, 수빈이의 위치를 업데이트 및 이동 시간을 1 증가시킨다.
				myQueue.push(std::make_pair(rightResult, prevInfo.second + 1));
				// 방문 처리
				visited[rightResult] = true;
			}
		}

		// 2. 왼쪽으로 걷기
		int leftResult = Walk(prevInfo.first, -1);
		if (leftResult <= 100000 && leftResult >= 0)
		{
			if (!visited[leftResult])
			{
				myQueue.push(std::make_pair(leftResult, prevInfo.second + 1));
				visited[leftResult] = true;
			}
		}

		// 3. 순간이동
		int teleportResult = Teleport(prevInfo.first);
		if (teleportResult <= 100000 && teleportResult >= 0)
		{
			if (!visited[teleportResult])
			{
				myQueue.push(std::make_pair(teleportResult, prevInfo.second + 1));
				visited[teleportResult] = true;
			}
		}
	}

	return 0;
}
```

수빈이가 최단 경로를 찾아가는 기능을, BFS를 이용해서 구현한다.
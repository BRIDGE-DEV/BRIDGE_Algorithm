---
layout: single
title:  "Data Structure / Algorithm - DFS와 백 트래킹"
categories:
  - DataStructure_Algorithm
---

---

### DFS의 동작 원리
---

[이전 포스팅 내용 - DFS의 동작 순서](https://joonyle99.github.io/datastructure_algorithm/DataStructure_Algorithm-DFS-BFS/#dfs)

DFS는 함수의 재귀적 특성(호출 스택)을 사용한다.  
이러한 재귀적 특성을 '백 트래킹'에 이용한다.

![](https://gptjs409.github.io/img/2019-09-04/jvm-002-flow1.png){: .align-center}
*함수의 호출 스택 처리 과정*

### 백준 15649번 - N과 M (1)
---

[문제 링크](https://www.acmicpc.net/problem/15649)

![](/assets/images/dataAlgorithm_backTracking.png){: .align-center}
*문제 설명*

N이 3, M이 3인 경우
1, 2, 3의 수가 있을 때, 길이가 3가 되는 수열을 출력한다.

![](/assets/images/dataAlgorithm_backTracking3.png){: .align-center}
*N이 3, M이 3인 경우 초반 노드 설정*
![](/assets/images/dataAlgorithm_backTracking4.png){: .align-center}
*예제에 대한 정답*

### DFS를 이용해야 하는 이유
---

이 문제의 경우 BFS가 아닌 DFS를 이용해야 한다.

이 문제는 우선 하나의 수열을 완성한 후, 그다음 수열의 탐색으로 넘어가는 경우가 구현하기 편한데,  
그 이유는 방문처리 때문이다.

위 예시에서 너비 우선 탐색(BFS)을 이용하게 된다면, 1로 시작하는 수열을 탐색할 때,
그의 자식인 1, 2, 3(LEVEL 2)을 먼저 탐색하게 되는데,

이 경우 하나의 수열이 아닌 3개의 수열을 동시에 탐색하려는 경우가 되면서 방문 처리를 하기 까다로워진다.

반면 DFS의 경우, 하나의 수열을 우선으로 완성시키기 때문에 visited 배열을 함수 인자로 전달하며 재귀적 특성을 이용해 방문 처리를 간단하게할 수 있다.

따라서 이렇게 한 루트를 우직하게 파고들며(Recursive) 해당 노드가 방문했는지 판단하고,
방문한 노드라면 처리하지 않고 가지치기(함수를 return)하는 방식을 사용한 DFS 백트래킹을 이용한다.

함수와 매개변수를 적극 사용하며 재귀함수의 특성을 이용하는 것이 포인트이다.

### 풀이 방법
---

```c++
// 전역 변수
int N, M;
std::vector<int> inputArray;
```

```c++
// N과 M을 입력
cin >> N >> M;

// 1 ~ N의 수를 담기 위한 inputArray
inputArray.resize(N + 1);
for (int i = 1; i <= N; ++i)
	inputArray[i] = i;

// 1 ~ N 까지 돌면서 수열의 시작값을 설정
for (int i = 1; i <= N; ++i)
{
	// 방문 처리를 위한 vector<>
	std::vector<bool> visited(N + 1);

	// 수열을 담기위한 vector<>
	std::vector<int> numVector;

	// DFS를 이용한 백 트래킹
	// visited와 numVector는 함수의 인자로 전달하며 계속해서 최신화된 정보를 가지고 있어야 한다.
	DFS(i, visited, numVector);
}
```

```c++
// DFS를 이용한 백 트래킹
void DFS(int number, std::vector<bool> visited, std::vector<int> numVector)
{
	// 들어온 수에 대한 '방문처리' 및 '수열에 등록'
	visited[number] = true;
	numVector.push_back(number);

	// 목표하는 수열의 길이
	const auto arrayCount = numVector.size();

	// 길이 M의 수열 생성 완료
	if (arrayCount == M)
	{
		// 수열 출력
		for (int i = 0; i < arrayCount; ++i)
		{
			if (i == arrayCount - 1)
				cout << numVector[i] << '\n';
			else
				cout << numVector[i] << " ";
		}

 		// 함수 종료
		return;
	}

	// 1 ~ N 까지 완전 탐색
	for (int i = 1; i <= N; ++i)
	{
		// 다음 수열 등록을 위한 Recursive
		// 방문 정보를 확인한다 (중복 방지)
		if (!visited[i])
			DFS(i, visited, numVector);
	}
}
```


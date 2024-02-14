#include <iostream>
#include <queue>
#include <list>

using std::cin;
using std::cout;

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

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 숨바꼭질

	// BFS로 풀어야겠다고 생각한 이유 :

	// 수빈이의 위치가 주어졌을 때 동생으로 가기 위한 경로가 무수히 많다.
	// 하지만 최단 시간으로 가야 하기 때문에 각 상황에서 선택 가능한 경로인 '너비'를 우선으로 탐색하며
	// 수빈이가 동생을 찾았을 때의 LEVEL(경과 시간)이 최소인 상황인 것이므로 BFS로 풀어야 한다고 생각했다.

	int N; cin >> N;	// 수빈이의 위치
	int K; cin >> K;	// 동생의 위치

	const int result = BFS(N, K);
	cout << result << '\n';

	return 0;
}

#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;

// 노드의 개수
int N;

// 인접 리스트 방식으로 트리의 관계를 정의
std::vector<std::vector<int>> tree(100001);

// 노드의 정점에 대한 방문처리
bool visited[100001] = {};

// 부모 노드를 저장 (index : 자식 번호, value : 부모 번호)
std::vector<int> parentArr(100001);

// DFS는 완전 탐색이므로 인접 리스트의 모든 노드 정보를 순회한다.
void DFS(int parentNode)
{
	// 노드는 "부모 노드"의 입장으로 진입한다.
	// 방문 처리
	visited[parentNode] = true;

	// 부모 노드의 모든 자식들을 순회하며, 자식들의 부모를 결정
	for (int i = 0; i < tree[parentNode].size(); ++i)
	{
		// 부모 노드에 연결된 "자식 노드"
		int childNode = tree[parentNode][i];

		// * 방문 정보를 검사하는 이유는 자식 노드만 가져오기 위함 *
		if (!visited[childNode])
		{
			// 깊이 우선 탐색을 위한 "재귀 함수"를 실행한다. (해당 노드를 부모 노드로 입력한)
			DFS(childNode);

			// 자식 노드에 부모 정보를 등록
			parentArr[childNode] = parentNode;
		}
	}
}

// BFS는 완전 탐색이므로 인접 리스트의 모든 노드 정보를 순회한다.
void BFS(int rootNode)
{
	// 너비 우선 탐색을 위해 "Queue 자료구조"를 사용한다
	std::queue<int> myQueue;
	// 처음 진입 노드인 루트 노드를 방문 처리
	visited[rootNode] = true;
	// 루트 노드를 처음에 Queue에 담고 시작
	myQueue.push(rootNode);

	// Queue에 노드가 있으면 계속해서 반복
	while (!myQueue.empty())
	{
		// Queue의 가장 앞에 있는 요소, 즉 가장 먼저 들어온 노드를 꺼낸다. (부모 노드)
		int parentNode = myQueue.front();
		// 꺼낸 노드를 parentNode에 저장했기 때문에 Pop()한다.
		myQueue.pop();

		// 부모 노드의 모든 자식들을 순회하며, 자식들의 부모를 결정
		for (int i = 0; i < tree[parentNode].size(); ++i)
		{
			// 부모 노드에 연결된 "자식 노드"
			int childNode = tree[parentNode][i];

			// * 방문 정보를 검사하는 이유는 자식 노드만 가져오기 위함 *
			if (!visited[childNode])
			{
				// Queue에 자식 노드를 Push()해준다.
				myQueue.push(childNode);

				visited[childNode] = true;

				// 자식 노드에 부모 정보를 등록
				parentArr[childNode] = parentNode;
			}
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 트리의 부모 찾기

	cin >> N;

	// 연결 정보가 주어진다.
	for (int i = 0; i < N - 1; ++i)
	{
		int from, to;
		cin >> from >> to;

		tree[from].push_back(to);
		tree[to].push_back(from);
	}

	/// 루트 노드에서부터 모든 노드를 탐색한다.

	// DFS(1);
	BFS(1);

	// 첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.
	for (int i = 2; i <= N; ++i)
		cout << parentArr[i] << '\n';

	return 0;
}

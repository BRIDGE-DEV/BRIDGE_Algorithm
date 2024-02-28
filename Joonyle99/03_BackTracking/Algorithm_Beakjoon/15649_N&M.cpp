#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int N, M;

std::vector<int> inputArray;

// numVector는 계속해서 최신화된 정보를 가지고 가야함
void DFS(int number, std::vector<bool> visited, std::vector<int> numVector)
{
	visited[number] = true;
	numVector.push_back(number);

	const auto arrayCount = numVector.size();

	// M개의 수열 생성 완료
	if (arrayCount == M)
	{
		// 수열 출력 후 종료
		for (int i = 0; i < arrayCount; ++i)
		{
			if (i == arrayCount - 1)
				cout << numVector[i] << '\n';
			else
				cout << numVector[i] << " ";
		}

		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!visited[i])
			DFS(i, visited, numVector);
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : N과 M (1)
	// Sorting : 백 트래킹
	// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

	cin >> N >> M;

	inputArray.resize(N + 1);

	for (int i = 1; i <= N; ++i)
		inputArray[i] = i;

	for (int i = 1; i <= N; ++i)
	{
		std::vector<bool> visited(N + 1);
		std::vector<int> numVector;
		DFS(i, visited, numVector);
	}

	return 0;
}
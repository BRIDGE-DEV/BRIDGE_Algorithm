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

// numVector�� ����ؼ� �ֽ�ȭ�� ������ ������ ������
void DFS(int number, std::vector<bool> visited, std::vector<int> numVector)
{
	visited[number] = true;
	numVector.push_back(number);

	const auto arrayCount = numVector.size();

	// M���� ���� ���� �Ϸ�
	if (arrayCount == M)
	{
		// ���� ��� �� ����
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

	// Title : N�� M (1)
	// Sorting : �� Ʈ��ŷ
	// 1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����

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
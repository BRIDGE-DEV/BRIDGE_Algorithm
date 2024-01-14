#include <iostream>
#include <queue>
#include <list>

using std::cin;
using std::cout;

// �ȱ� ���
int Walk(int x, int dir)
{
	// X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�

	x += dir;
	return x;
}

// �����̵� ���
int Teleport(int x)
{
	// 2*X�� ��ġ�� �̵��ϰ� �ȴ�
	// *������ ���������θ� �̵�*

	x *= 2;
	return x;
}

int BFS(int subinPos, int sisterPos)
{
	// BFS�� ���� �غ� �ܰ�
	std::queue<std::pair<int, int>> myQueue;	// 1. ť ���� <������ ��ġ, �̵� �ð�>
	bool visited[100001] = { false, };			// 2. �湮 ���θ� ������ �迭 ����

	// �ʱ�ȭ
	myQueue.push(std::make_pair(subinPos, 0));
	visited[subinPos] = true;

	// �������� ��ġ�� ��� �ð��� ���� ������ ť�� 1�� �� �ִ� ���·� BFS ����
	// ������ ��忡 �����ϸ� �湮 ���θ� üũ�ϰ�, �湮���� ���� ����� ť�� �ִ´�.
	while (!myQueue.empty())
	{
		// ť�� �� �տ� �ִ� ������ ������ �� ť���� ����
		auto prevInfo = myQueue.front();
		myQueue.pop();

		// ��ǥ ������ �����ߴٸ� �ɸ� �ð��� ����
		if (prevInfo.first == sisterPos)
			return prevInfo.second;

		// 3���� �̵� ��Ȳ�� ���

		// 1. ���������� �ȱ�
		int rightResult = Walk(prevInfo.first, 1);
		// ���� ������� üũ
		if (rightResult <= 100000 && rightResult >= 0)
		{
			// �湮���� ���� ����� ť�� �ִ´�.
			if (!visited[rightResult])
			{
				// ť�� ���� ��, �������� ��ġ�� ������Ʈ �� �̵� �ð��� 1 ������Ų��.
				myQueue.push(std::make_pair(rightResult, prevInfo.second + 1));
				// �湮 ó��
				visited[rightResult] = true;
			}
		}

		// 2. �������� �ȱ�
		int leftResult = Walk(prevInfo.first, -1);
		if (leftResult <= 100000 && leftResult >= 0)
		{
			if (!visited[leftResult])
			{
				myQueue.push(std::make_pair(leftResult, prevInfo.second + 1));
				visited[leftResult] = true;
			}
		}

		// 3. �����̵�
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

	// Title : ���ٲ���

	// BFS�� Ǯ��߰ڴٰ� ������ ���� :

	// �������� ��ġ�� �־����� �� �������� ���� ���� ��ΰ� ������ ����.
	// ������ �ִ� �ð����� ���� �ϱ� ������ �� ��Ȳ���� ���� ������ ����� '�ʺ�'�� �켱���� Ž���ϸ�
	// �����̰� ������ ã���� ���� LEVEL(��� �ð�)�� �ּ��� ��Ȳ�� ���̹Ƿ� BFS�� Ǯ��� �Ѵٰ� �����ߴ�.

	int N; cin >> N;	// �������� ��ġ
	int K; cin >> K;	// ������ ��ġ

	const int result = BFS(N, K);
	cout << result << '\n';

	return 0;
}

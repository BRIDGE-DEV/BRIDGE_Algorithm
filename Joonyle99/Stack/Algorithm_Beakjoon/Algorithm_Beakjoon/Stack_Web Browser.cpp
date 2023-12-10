#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;

std::stack<int> ReverseStack(std::stack<int> inputStack)
{
	std::stack<int> outputStack;
	while (!inputStack.empty())
	{
		outputStack.push(inputStack.top());
		inputStack.pop();
	}
	return outputStack;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �� ������ 2

	int N, Q;
	cin >> N >> Q;

	/*
	 * N : �� ������ ������ ��
	 * Q : ����ڰ� �����ϴ� �۾��� ����
	 */

	std::stack<int> backSpace;	// �ڷ� �̵��� �������� �׾Ƶδ� ��
	std::stack<int> frontSpace; // ������ �̵��� �������� �׾Ƶδ� ��

	int accessCount = 0;		// ������ �̵� Ƚ�� (�� / �� ������ �̵� ����)
	int curPageNumber = 0;		// ���� ������

	for (int i = 0; i < Q; ++i)
	{
		char task; cin >> task;
		if (task == 'A')
		{
			// �̵��� ������ �Է�
			int pageNumber;
			cin >> pageNumber;

			// ó�� �����ϴ� ��� �ڷ� ���� ������ �߰����� ����
			if (accessCount != 0)
				backSpace.push(curPageNumber);

			// ������ ���� ������ ����� �������� ��� �����ȴ�.
			while (!frontSpace.empty())
				frontSpace.pop();

			// �Էµ� �������� �̵��Ѵ�.
			curPageNumber = pageNumber;

			// ������ �̵� ī��Ʈ ����
			accessCount++;
		}
		else if (task == 'B')
		{
			if (!backSpace.empty())
			{
				// �ڷΰ��� ���� �������� �����ΰ��� ������ �߰��Ѵ�.
				frontSpace.push(curPageNumber);

				// �ڷΰ��� ������ ���� �ֱٿ� �湮�� �������� �̵�
				curPageNumber = backSpace.top();

				// �ڷΰ��� ������ pop
				backSpace.pop();
			}
		}
		else if (task == 'F')
		{
			if (!frontSpace.empty())
			{
				// ������ ���� ���� �������� �ڷΰ��� ������ �߰��Ѵ�.
				backSpace.push(curPageNumber);

				// �����ΰ��� ������ ���� �ֱٿ� �湮�� �������� �̵�
				curPageNumber = frontSpace.top();

				// �����ΰ��� ������ pop
				frontSpace.pop();
			}
		}
		else if (task == 'C')
		{
			std::stack<int> copyStack = backSpace;
			std::stack<int> myBackSpace;
			int targetTop = -1;
			while (!copyStack.empty())
			{
				if (targetTop != copyStack.top())
				{
					targetTop = copyStack.top();
					myBackSpace.push(copyStack.top());
				}

				copyStack.pop();
			}
			backSpace = ReverseStack(myBackSpace);
		}
	}

	// ù° �ٿ��� ���� ���� ���� �������� ��ȣ�� ����Ѵ�.
	cout << curPageNumber << '\n';

	// ��° �ٿ��� �ڷ� ���� �������� ���� �ֱٿ� �湮�� ������� �������� ��ȣ�� ����Ѵ�.
	// ����� �������� ���ٸ� -1 �� ����Ѵ�.
	if (backSpace.empty())
		cout << -1 << '\n';
	else
	{
		while (!backSpace.empty())
		{
			cout << backSpace.top() << " ";
			backSpace.pop();
		}
		cout << '\n';
	}

	// ��° �ٿ��� ������ ���� �������� ���� �ֱٿ� �湮�� ������� �������� ��ȣ�� ����Ѵ�.
	// ����� �������� ���ٸ� -1 �� ����Ѵ�.
	if (frontSpace.empty())
		cout << -1 << '\n';
	else
	{
		while (!frontSpace.empty())
		{
			cout << frontSpace.top() << " ";
			frontSpace.pop();
		}
		cout << '\n';
	}

	return 0;
}

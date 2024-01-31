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

	// Title : 웹 브라우저 2

	int N, Q;
	cin >> N >> Q;

	/*
	 * N : 웹 페이지 종류의 수
	 * Q : 사용자가 수행하는 작업의 개수
	 */

	std::stack<int> backSpace;	// 뒤로 이동할 페이지를 쌓아두는 곳
	std::stack<int> frontSpace; // 앞으로 이동할 페이지를 쌓아두는 곳

	int accessCount = 0;		// 페이지 이동 횟수 (뒤 / 앞 페이지 이동 제외)
	int curPageNumber = 0;		// 현재 페이지

	for (int i = 0; i < Q; ++i)
	{
		char task; cin >> task;
		if (task == 'A')
		{
			// 이동할 페이지 입력
			int pageNumber;
			cin >> pageNumber;

			// 처음 접속하는 경우 뒤로 가기 공간에 추가하지 않음
			if (accessCount != 0)
				backSpace.push(curPageNumber);

			// 앞으로 가기 공간에 저장된 페이지가 모두 삭제된다.
			while (!frontSpace.empty())
				frontSpace.pop();

			// 입력된 페이지로 이동한다.
			curPageNumber = pageNumber;

			// 페이지 이동 카운트 증가
			accessCount++;
		}
		else if (task == 'B')
		{
			if (!backSpace.empty())
			{
				// 뒤로가면 현재 페이지를 앞으로가기 공간에 추가한다.
				frontSpace.push(curPageNumber);

				// 뒤로가기 공간의 가장 최근에 방문한 페이지로 이동
				curPageNumber = backSpace.top();

				// 뒤로가기 공간을 pop
				backSpace.pop();
			}
		}
		else if (task == 'F')
		{
			if (!frontSpace.empty())
			{
				// 앞으로 가면 현재 페이지를 뒤로가기 공간에 추가한다.
				backSpace.push(curPageNumber);

				// 앞으로가기 공간의 가장 최근에 방문한 페이지로 이동
				curPageNumber = frontSpace.top();

				// 앞으로가기 공간을 pop
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

	// 첫째 줄에는 현재 접속 중인 페이지의 번호를 출력한다.
	cout << curPageNumber << '\n';

	// 둘째 줄에는 뒤로 가기 공간에서 가장 최근에 방문한 순서대로 페이지의 번호를 출력한다.
	// 저장된 페이지가 없다면 -1 을 출력한다.
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

	// 셋째 줄에는 앞으로 가기 공간에서 가장 최근에 방문한 순서대로 페이지의 번호를 출력한다.
	// 저장된 페이지가 없다면 -1 을 출력한다.
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

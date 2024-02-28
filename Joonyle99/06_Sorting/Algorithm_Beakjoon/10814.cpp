#include <bits/stdc++.h>
using namespace std;

pair<int, string> members[100005];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 나이순 정렬

	int N; cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> members[i].first;
		cin >> members[i].second;
	}

	// 우선 나이순으로 정렬한다
	// 그 이후에 가입한 순서는 자연적으로 처리가 된다 (stable sort를 사용한다)
	stable_sort(members, members + N, [&](pair<int, string> a, pair<int, string> b)
		{
			return a.first < b.first;
		});

	for (int i = 0; i < N; ++i)
	{
		cout << members[i].first << ' ' << members[i].second << '\n';
	}

	return 0;
}

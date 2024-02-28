// #include "Timer.h"
// #include "Random.h"

#include <bits/stdc++.h>

using namespace std;

vector<int> arr(1000005);
vector<int> tmp(1000005);

void BubbleSort(vector<int>& arr, int n)
{
	// 버블 정렬 O(N^2)
	// 거의 정렬된 상태라면 선택 정렬 보다 빠르다
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			// 정렬 상태에 따라 코드 실행이 스킵될 수 있다
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
}

void SelectSort(vector<int>& arr, int n)
{
	// 선택 정렬 O(N^2)
	// 버블 정렬에 비해 상대적으로 교환(swap) 횟수가 적다
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i; j < n; ++j) {
			// 이 작업은 정렬 상태와 상관없이 상수로 실행되는 코드이다
			if (arr[minIndex] > arr[j]) minIndex = j;
		}
		if (minIndex != i) swap(arr[minIndex], arr[i]);
	}
}

// mid = (st+en)/2라고 할 때 arr[st:mid], arr[mid:en]은 이미 정렬이 되어있는 상태일 때 arr[st:mid]와 arr[mid:en]을 합친다.
void merge(int st, int en) {
	int mid = (st + en) / 2;

	// arr[st:mid]를 정렬한다
	// arr[mid:en]를 정렬한다

	// O(N)의 시간복잡도로 두 리스트를 합칠 수 있다
	int aIndex = st;
	int bIndex = mid;
	vector<int> vec;
	for (int i = st; i < en; ++i) {
		if (aIndex >= mid) tmp[i] = arr[bIndex++];
		else if (bIndex >= en) tmp[i] = arr[aIndex++];
		else if (arr[aIndex] <= arr[bIndex]) tmp[i] = arr[aIndex++];
		else tmp[i] = arr[bIndex++];
		vec.push_back(i);
	}
	for (const auto i : vec)
	{
		arr[i] = tmp[i];
	}
}

// arr[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en) {
	if (en == st + 1) return; // 길이 1인 경우
	int mid = (st + en) / 2;
	merge_sort(st, mid); // arr[st:mid]을 정렬한다.
	merge_sort(mid, en); // arr[mid:en]을 정렬한다.
	merge(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 수 정렬하기 2

	// 수제로 만든 병합 정렬을 이용해 보자

	// Random rd = Random::GetInstance();

	int N; cin >> N;

	for(int i=0; i<N; ++i)
	{
		cin >> arr[i];
		// arr[i] = rd.GetRandomNumber();
	}

	/*
	Timer::GetInstance().Start_ChronoVersion();

	// 버블 정렬
	BubbleSort(arr, N);

	Timer::GetInstance().End_ChronoVersion("버블 정렬");

	for (int i = 0; i < N; ++i)
	{
		// cin >> arr[i];
		arr[i] = rd.GetRandomNumber();
	}

	Timer::GetInstance().Start_ChronoVersion();

	// 삽입 정렬
	SelectSort(arr, N);

	Timer::GetInstance().End_ChronoVersion("삽입 정렬");

	for (int i = 0; i < N; ++i)
	{
		// cin >> arr[i];
		arr[i] = rd.GetRandomNumber();
	}

	Timer::GetInstance().Start_ChronoVersion();

	// STL 정렬
	sort(arr.begin(), arr.end());

	Timer::GetInstance().End_ChronoVersion("STL 정렬");
	*/

	// 병합 정렬
	merge_sort(0, N);

	for(int i=0; i<N; ++i)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}

// #include "Timer.h"
// #include "Random.h"

#include <bits/stdc++.h>

using namespace std;

vector<int> arr(1000005);
vector<int> tmp(1000005);

void BubbleSort(vector<int>& arr, int n)
{
	// ���� ���� O(N^2)
	// ���� ���ĵ� ���¶�� ���� ���� ���� ������
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			// ���� ���¿� ���� �ڵ� ������ ��ŵ�� �� �ִ�
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
}

void SelectSort(vector<int>& arr, int n)
{
	// ���� ���� O(N^2)
	// ���� ���Ŀ� ���� ��������� ��ȯ(swap) Ƚ���� ����
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i; j < n; ++j) {
			// �� �۾��� ���� ���¿� ������� ����� ����Ǵ� �ڵ��̴�
			if (arr[minIndex] > arr[j]) minIndex = j;
		}
		if (minIndex != i) swap(arr[minIndex], arr[i]);
	}
}

// mid = (st+en)/2��� �� �� arr[st:mid], arr[mid:en]�� �̹� ������ �Ǿ��ִ� ������ �� arr[st:mid]�� arr[mid:en]�� ��ģ��.
void merge(int st, int en) {
	int mid = (st + en) / 2;

	// arr[st:mid]�� �����Ѵ�
	// arr[mid:en]�� �����Ѵ�

	// O(N)�� �ð����⵵�� �� ����Ʈ�� ��ĥ �� �ִ�
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

// arr[st:en]�� �����ϰ� �ʹ�.
void merge_sort(int st, int en) {
	if (en == st + 1) return; // ���� 1�� ���
	int mid = (st + en) / 2;
	merge_sort(st, mid); // arr[st:mid]�� �����Ѵ�.
	merge_sort(mid, en); // arr[mid:en]�� �����Ѵ�.
	merge(st, en); // arr[st:mid]�� arr[mid:en]�� ��ģ��.
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �� �����ϱ� 2

	// ������ ���� ���� ������ �̿��� ����

	// Random rd = Random::GetInstance();

	int N; cin >> N;

	for(int i=0; i<N; ++i)
	{
		cin >> arr[i];
		// arr[i] = rd.GetRandomNumber();
	}

	/*
	Timer::GetInstance().Start_ChronoVersion();

	// ���� ����
	BubbleSort(arr, N);

	Timer::GetInstance().End_ChronoVersion("���� ����");

	for (int i = 0; i < N; ++i)
	{
		// cin >> arr[i];
		arr[i] = rd.GetRandomNumber();
	}

	Timer::GetInstance().Start_ChronoVersion();

	// ���� ����
	SelectSort(arr, N);

	Timer::GetInstance().End_ChronoVersion("���� ����");

	for (int i = 0; i < N; ++i)
	{
		// cin >> arr[i];
		arr[i] = rd.GetRandomNumber();
	}

	Timer::GetInstance().Start_ChronoVersion();

	// STL ����
	sort(arr.begin(), arr.end());

	Timer::GetInstance().End_ChronoVersion("STL ����");
	*/

	// ���� ����
	merge_sort(0, N);

	for(int i=0; i<N; ++i)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>& arr1, vector<int>& arr2, int n)
{
	// 하나의 정렬된 리스트로 합치는 병합 정렬 알고리즘의 핵심 단계
	vector<int> arr12(n);
	int arr1Index = 0;
	int arr2Index = 0;
	int arr12Index = 0;
	while (arr12Index != n) {

		if (arr1Index >= arr1.size()) {
			arr12[arr12Index] = arr2[arr2Index++];
		}
		else if (arr2Index >= arr2.size()) {
			arr12[arr12Index] = arr1[arr1Index++];
		}
		else
		{
			if (arr1[arr1Index] >= arr2[arr2Index]) {		// >가 아닌 >=로 해준다. 정렬은 잘 실행되지만 Stable Sort 때문
				arr12[arr12Index] = arr2[arr2Index++];
			}
			else {
				arr12[arr12Index] = arr1[arr1Index++];
			}
		}

		arr12Index++;
	}

	for (const auto v : arr12) {
		cout << v << ' ';
	}
}

void Merge_BaaarkingDog(vector<int>& arr1, vector<int>& arr2, int n)
{
	vector<int> arr12(n);
	int aIndex = 0, bIndex = 0;
	for (int i = 0; i < n; ++i) {
		if (bIndex == arr2.size()) arr12[i] = arr1[aIndex++];
		else if (aIndex == arr1.size()) arr12[i] = arr2[bIndex++];
		else if (arr1[aIndex] <= arr2[bIndex]) arr12[i] = arr1[aIndex++];
		else arr12[i] = arr2[bIndex++];
	}
	for (const auto v : arr12) {
		cout << v << ' ';
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 배열 합치기

	int N, M;
	cin >> N >> M;

	vector<int> arr1(N);
	vector<int> arr2(M);

	for (int i = 0; i < N; ++i) {
		cin >> arr1[i];
	}

	for (int i = 0; i < M; ++i) {
		cin >> arr2[i];
	}

	Merge_BaaarkingDog(arr1, arr2, N + M);

	return 0;
}

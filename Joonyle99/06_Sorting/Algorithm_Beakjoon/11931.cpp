#include <bits/stdc++.h>
using namespace std;

int arr[1000005] = {};
int tmp[1000005] = {};

void merge(int st, int en)
{
	int mid = (st + en) / 2;

	// 두 리스트를 합칠 것이다
	// arr[st::mid]와 arr[mid::en]를 arr[st::en]으로 합칠 것이다

	// 각 리스트의 첫번째 요소를 시작점으로 한다
	// 왼쪽 리스트를 포인트하기 위한 변수
	int leftIndex = st;
	// 오른쪽 리스트를 포인트하기 위한 변수
	int rightIndex = mid;

	for (int i = st; i < en; ++i)
	{
		// 왼쪽 리스트가 이미 다 소진된 경우 (mid는 오른쪽 요소의 첫번째 요소 index임)
		if (leftIndex >= mid) tmp[i] = arr[rightIndex++];
		// 오른쪽 리스트가 이미 다 소진된 경우 (en는 오른쪽 요소의 끝에서 한 칸 더 간 index임)
		else if (rightIndex >= en)  tmp[i] = arr[leftIndex++];
		// 왼쪽 리스트의 값이 오른쪽 리스트의 값보다 작거나 같은 경우
		else if (arr[leftIndex] <= arr[rightIndex]) tmp[i] = arr[rightIndex++];
		// 오른쪽 리스트의 값이 왼쪽 리스트의 값보다 작은 경우
		else tmp[i] = arr[leftIndex++];
	}

	// tmp에 담아둔 값을 arr로 복사해준다
	// 이렇게 해야하는 이유는
	// arr 하나만 가지고는, 두 리스트를 하나의 리스트로 합치는 작업을 할 수 없기 때문이다.
	for (int i = st; i < en; ++i)
	{
		arr[i] = tmp[i];
	}
}

// * stable sort *
// 쪼개진 배열 조각 내에서 자리 바꿈만 하기 때문에
// 같은 값끼리 서로 자리가 바뀌는 상황은 생기지 않는다
void merge_sort(int st, int en)
{
	if (st + 1 >= en) return;

	int mid = (st + en) / 2;

	// 분할
	merge_sort(st, mid);
	merge_sort(mid, en);

	// 병합
	// 가장 안쪽까지 들어가면서
	// 배열의 크기가 1이 될 때까지 쪼갠다
	// 그 순간부터 다시 돌아오면서
	// 병합하는 과정을 거친다
	// 두 정렬된 리스트를 만들 것이고,
	// 그 두 리스트를 하나의 정렬된 리스트로 만들 것이다.
	// 이 과정은 선택 정렬 O(N^2) 이 아닌,
	// O(N)로 해결 가능하다
	merge(st, en);
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 수 정렬하기 4

	int N; cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	merge_sort(0, N);

	/*
	// 1. 오름 차순을 내림 차순으로 바꾸기
	// 이 방법도 정답이다
	for (int i = 0; i < N / 2; ++i)
	{
		swap(arr[i], arr[N - i - 1]);
	}
	*/

	for (int i = 0; i < N; ++i)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}

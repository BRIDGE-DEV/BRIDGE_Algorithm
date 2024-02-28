#include <bits/stdc++.h>
using namespace std;

/*
int arr[1000005] = {};

void quick_sort(int st, int en)
{
	// 추가적인 공간(Overhead)이 필요하지 않은 In-Place Sort이다
	// 하나의 배열 안에서의 자리 바꿈만으로 정렬이 가능하다

	// 만약 길이가 1이하인 배열이라면 return
	if (st + 1 >= en) return;

	int pivot = st;
	int lPointer = st + 1;
	int rPointer = en - 1;

	// 피봇의 올바른 위치를 찾을 것이다
	while (true)
	{
		// ** 핵심 로직 **
		// lPointer와 rPointer을 움직이면서
		// lPointer가 rPointer의 오른쪽에 있지 않도록 하기 위해서
		// lPointer <= rPointer 조건을 추가한다
		//
		// *** 여기서 핵심은 Pointer와 Pivot의 요소의 크기를 비교하는 과정에서 하나는 등호(=)를 붙여줘야 한다는 것이다 ***
		// 
		while (arr[lPointer] < arr[pivot] && lPointer <= rPointer) lPointer++;			// lPointer 요소보다 큰 수를 찾을 때까지 오른쪽으로 이동한
		while (arr[rPointer] >= arr[pivot] && lPointer <= rPointer) rPointer--;			// rPointer 요소보다 작거나 같은 수를 찾을 때까지 왼쪽으로 이동한다

		// 만약 rPointer가 lPointer를 지나쳐서 교차하는 경우 rPointer와 pivot의 위치를 변경한다
		if (rPointer < lPointer)
		{
			// 요소와 인덱스를 모두 바꾼다
			swap(arr[pivot], arr[rPointer]);
			break;
		}

		swap(arr[lPointer], arr[rPointer]);
	}

	// 피봇을 기준으로 왼쪽 리스트와 오른쪽 리스트를 쪼갠다
	// 주의 사항 -> pivot을 포함하면 안된다
	quick_sort(st, rPointer);
	quick_sort(rPointer + 1, en);
}
*/

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
		else if (arr[leftIndex] <= arr[rightIndex]) tmp[i] = arr[leftIndex++];
		// 오른쪽 리스트의 값이 왼쪽 리스트의 값보다 작은 경우
		else tmp[i] = arr[rightIndex++];
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

	// Title : 수 정렬하기 5

	// 피봇의 위치가 리스트의 맨 앞 요소로 고정이라서
	// 최악의 시간복잡도 0(N^2)가 나오는 것일 수도 있다
	//
	// 피봇의 위치를 바꿔보자

	int N; cin >> N;

	for (int i = 0; i < N; ++i) cin >> arr[i];

	// quick_sort(0, N);		// 시간 초과로 인해서 quick_sort를 사용할 수 없다. 최악의 시간 복잡도 O(N^2)이기 때문이다
	merge_sort(0, N);		// O(NlogN)의 시간복잡도가 보장되는 merge_sort를 사용한다

	for (int i = 0; i < N; ++i) cout << arr[i] << '\n';

	return 0;
}

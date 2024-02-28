#include <bits/stdc++.h>
using namespace std;

/*
int arr[10000001];
int tmp[10000001];

int myArr[10001] = {};

// 절반으로 나눠진 두 리스트를
// 하나의 리스트로 병합한다
void merge(int st, int en)
{
	// O(N)의 시간복잡도로 두 정렬된 리스트를 하나의 정렬된 리스트로 합친다 (최솟값을 구해서 하나하나 박는거는 O(N^2)이 걸린다)
	// merge sort가 stable sort이기 때문에 이렇게 해도 된다. (각각의 쪼개진 리스트에서 자리바꿈만 한다)

	int mid = (st + en) / 2;
	int leftListIndex = st;
	int rightListIndex = mid;
	for (int i = st; i < en; ++i)
	{
		if (leftListIndex >= mid) tmp[i] = arr[rightListIndex++];
		else if (rightListIndex >= en) tmp[i] = arr[leftListIndex++];
		else if (arr[leftListIndex] <= arr[rightListIndex]) tmp[i] = arr[leftListIndex++];
		else tmp[i] = arr[rightListIndex++];
	}

	// 이번 merge에서 바뀐 리스트(tmp)를 arr로 옮긴다
	for (int i = st; i < en; ++i)
	{
		arr[i] = tmp[i];
	}
}

// 어디부터 어디까지 정렬할건지?
// arr[st::en]
void merge_sort(int st, int en)
{
	if (st + 1 >= en) return;
	int mid = (st + en) / 2;

	// 이거는 배열을 실제로 건들지 않는다 merge() 함수로 가기 위한 구간 나누기 역할을 할 뿐이다.
	merge_sort(st, mid);
	merge_sort(mid, en);

	merge(st, en);
}

void quick_sort(int st, int en)
{
	// In-Place Sort
	// merge sort가 tmp[] 라는 추가적인 공간 (overhead)를 사용하는 반면,
	// quick sort는 추가적인 공간 없이 left, right, pivot의 자리만 O(N)의 시간복잡도로 바꿔주면 된다.

	if (st + 1 == en) return;
	int pivot = arr[st];	// 정렬할 리스트의 가장 왼쪽 원소를 피봇으로 둔다
	int left = st + 1;	// pivot 보다 큰 수를 찾아갈 포인터
	int right = en - 1;	// pivot 보다 작은 수를 찾아갈 포인터
	while (true)
	{
		while (pivot >= arr[left] && left <= right) left++;		// left 포인터가 pivot 보다 큰 수를 만날때까지 오른쪽으로 이동할 것이다.
		while (pivot < arr[right] && left <= right) right--;		// right 포인터가 pivot 보다 작거나 같은 수를 만날때까지 왼쪽으로 이동할 것이다
		if (left > right) break;
		swap(arr[left], arr[right]);
	}
	swap(arr[st], arr[right]);

	// right index 위치에 pivot이 들어와 있기 때문
	quick_sort(st, right);
	quick_sort(right + 1, en);
}
*/

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 수 정렬하기 3

	// Solve : 이 문제의 입력 횟수 N은 최대 10,000,000이다.
	// 시간 제한이 5초라고 하더라도 O(N^2)의 시간복잡도로는 턱도 없다
	// 왜냐하면 1000만의 제곱은 100,000,000,000,000이기 때문이다. (100조)
	// 컴퓨터는 100조번의 연산을 5초만에 할 수 없다 (1초에 약 1억)
	// 따라서 O(NlogN)의 시간복잡도인 정렬 알고리즘을 사용해야 1000만 x 46.5로 통과가 가능하다
	// 시간복잡도 O(NlogN)이 되기 위해서는 병합정렬 or 퀵정렬을 사용해야 한다.
	// 가보자

	int N; cin >> N;

	// 입력 받은 값을 index의 개수로 정리한다
	int myArr[10001] = {};
	for (int i = 0; i < N; ++i)
	{
		int v; cin >> v;
		myArr[v]++;
	}

	// 오름차순 정렬한 결과를 출력하자
	for (int i = 1; i < 10001; ++i)
	{
		while (myArr[i]--)
		{
			cout << i << '\n';
		}
	}

	return 0;
}

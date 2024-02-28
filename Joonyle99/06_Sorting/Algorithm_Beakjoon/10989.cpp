#include <bits/stdc++.h>
using namespace std;

/*
int arr[10000001];
int tmp[10000001];

int myArr[10001] = {};

// �������� ������ �� ����Ʈ��
// �ϳ��� ����Ʈ�� �����Ѵ�
void merge(int st, int en)
{
	// O(N)�� �ð����⵵�� �� ���ĵ� ����Ʈ�� �ϳ��� ���ĵ� ����Ʈ�� ��ģ�� (�ּڰ��� ���ؼ� �ϳ��ϳ� �ڴ°Ŵ� O(N^2)�� �ɸ���)
	// merge sort�� stable sort�̱� ������ �̷��� �ص� �ȴ�. (������ �ɰ��� ����Ʈ���� �ڸ��ٲ޸� �Ѵ�)

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

	// �̹� merge���� �ٲ� ����Ʈ(tmp)�� arr�� �ű��
	for (int i = st; i < en; ++i)
	{
		arr[i] = tmp[i];
	}
}

// ������ ������ �����Ұ���?
// arr[st::en]
void merge_sort(int st, int en)
{
	if (st + 1 >= en) return;
	int mid = (st + en) / 2;

	// �̰Ŵ� �迭�� ������ �ǵ��� �ʴ´� merge() �Լ��� ���� ���� ���� ������ ������ �� ���̴�.
	merge_sort(st, mid);
	merge_sort(mid, en);

	merge(st, en);
}

void quick_sort(int st, int en)
{
	// In-Place Sort
	// merge sort�� tmp[] ��� �߰����� ���� (overhead)�� ����ϴ� �ݸ�,
	// quick sort�� �߰����� ���� ���� left, right, pivot�� �ڸ��� O(N)�� �ð����⵵�� �ٲ��ָ� �ȴ�.

	if (st + 1 == en) return;
	int pivot = arr[st];	// ������ ����Ʈ�� ���� ���� ���Ҹ� �Ǻ����� �д�
	int left = st + 1;	// pivot ���� ū ���� ã�ư� ������
	int right = en - 1;	// pivot ���� ���� ���� ã�ư� ������
	while (true)
	{
		while (pivot >= arr[left] && left <= right) left++;		// left �����Ͱ� pivot ���� ū ���� ���������� ���������� �̵��� ���̴�.
		while (pivot < arr[right] && left <= right) right--;		// right �����Ͱ� pivot ���� �۰ų� ���� ���� ���������� �������� �̵��� ���̴�
		if (left > right) break;
		swap(arr[left], arr[right]);
	}
	swap(arr[st], arr[right]);

	// right index ��ġ�� pivot�� ���� �ֱ� ����
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

	// Title : �� �����ϱ� 3

	// Solve : �� ������ �Է� Ƚ�� N�� �ִ� 10,000,000�̴�.
	// �ð� ������ 5�ʶ�� �ϴ��� O(N^2)�� �ð����⵵�δ� �ε� ����
	// �ֳ��ϸ� 1000���� ������ 100,000,000,000,000�̱� �����̴�. (100��)
	// ��ǻ�ʹ� 100������ ������ 5�ʸ��� �� �� ���� (1�ʿ� �� 1��)
	// ���� O(NlogN)�� �ð����⵵�� ���� �˰����� ����ؾ� 1000�� x 46.5�� ����� �����ϴ�
	// �ð����⵵ O(NlogN)�� �Ǳ� ���ؼ��� �������� or �������� ����ؾ� �Ѵ�.
	// ������

	int N; cin >> N;

	// �Է� ���� ���� index�� ������ �����Ѵ�
	int myArr[10001] = {};
	for (int i = 0; i < N; ++i)
	{
		int v; cin >> v;
		myArr[v]++;
	}

	// �������� ������ ����� �������
	for (int i = 1; i < 10001; ++i)
	{
		while (myArr[i]--)
		{
			cout << i << '\n';
		}
	}

	return 0;
}

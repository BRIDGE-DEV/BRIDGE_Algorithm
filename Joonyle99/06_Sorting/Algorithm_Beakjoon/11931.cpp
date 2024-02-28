#include <bits/stdc++.h>
using namespace std;

int arr[1000005] = {};
int tmp[1000005] = {};

void merge(int st, int en)
{
	int mid = (st + en) / 2;

	// �� ����Ʈ�� ��ĥ ���̴�
	// arr[st::mid]�� arr[mid::en]�� arr[st::en]���� ��ĥ ���̴�

	// �� ����Ʈ�� ù��° ��Ҹ� ���������� �Ѵ�
	// ���� ����Ʈ�� ����Ʈ�ϱ� ���� ����
	int leftIndex = st;
	// ������ ����Ʈ�� ����Ʈ�ϱ� ���� ����
	int rightIndex = mid;

	for (int i = st; i < en; ++i)
	{
		// ���� ����Ʈ�� �̹� �� ������ ��� (mid�� ������ ����� ù��° ��� index��)
		if (leftIndex >= mid) tmp[i] = arr[rightIndex++];
		// ������ ����Ʈ�� �̹� �� ������ ��� (en�� ������ ����� ������ �� ĭ �� �� index��)
		else if (rightIndex >= en)  tmp[i] = arr[leftIndex++];
		// ���� ����Ʈ�� ���� ������ ����Ʈ�� ������ �۰ų� ���� ���
		else if (arr[leftIndex] <= arr[rightIndex]) tmp[i] = arr[rightIndex++];
		// ������ ����Ʈ�� ���� ���� ����Ʈ�� ������ ���� ���
		else tmp[i] = arr[leftIndex++];
	}

	// tmp�� ��Ƶ� ���� arr�� �������ش�
	// �̷��� �ؾ��ϴ� ������
	// arr �ϳ��� �������, �� ����Ʈ�� �ϳ��� ����Ʈ�� ��ġ�� �۾��� �� �� ���� �����̴�.
	for (int i = st; i < en; ++i)
	{
		arr[i] = tmp[i];
	}
}

// * stable sort *
// �ɰ��� �迭 ���� ������ �ڸ� �ٲ޸� �ϱ� ������
// ���� ������ ���� �ڸ��� �ٲ�� ��Ȳ�� ������ �ʴ´�
void merge_sort(int st, int en)
{
	if (st + 1 >= en) return;

	int mid = (st + en) / 2;

	// ����
	merge_sort(st, mid);
	merge_sort(mid, en);

	// ����
	// ���� ���ʱ��� ���鼭
	// �迭�� ũ�Ⱑ 1�� �� ������ �ɰ���
	// �� �������� �ٽ� ���ƿ��鼭
	// �����ϴ� ������ ��ģ��
	// �� ���ĵ� ����Ʈ�� ���� ���̰�,
	// �� �� ����Ʈ�� �ϳ��� ���ĵ� ����Ʈ�� ���� ���̴�.
	// �� ������ ���� ���� O(N^2) �� �ƴ�,
	// O(N)�� �ذ� �����ϴ�
	merge(st, en);
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : �� �����ϱ� 4

	int N; cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	merge_sort(0, N);

	/*
	// 1. ���� ������ ���� �������� �ٲٱ�
	// �� ����� �����̴�
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

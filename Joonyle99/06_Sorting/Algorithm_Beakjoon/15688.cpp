#include <bits/stdc++.h>
using namespace std;

/*
int arr[1000005] = {};

void quick_sort(int st, int en)
{
	// �߰����� ����(Overhead)�� �ʿ����� ���� In-Place Sort�̴�
	// �ϳ��� �迭 �ȿ����� �ڸ� �ٲ޸����� ������ �����ϴ�

	// ���� ���̰� 1������ �迭�̶�� return
	if (st + 1 >= en) return;

	int pivot = st;
	int lPointer = st + 1;
	int rPointer = en - 1;

	// �Ǻ��� �ùٸ� ��ġ�� ã�� ���̴�
	while (true)
	{
		// ** �ٽ� ���� **
		// lPointer�� rPointer�� �����̸鼭
		// lPointer�� rPointer�� �����ʿ� ���� �ʵ��� �ϱ� ���ؼ�
		// lPointer <= rPointer ������ �߰��Ѵ�
		//
		// *** ���⼭ �ٽ��� Pointer�� Pivot�� ����� ũ�⸦ ���ϴ� �������� �ϳ��� ��ȣ(=)�� �ٿ���� �Ѵٴ� ���̴� ***
		// 
		while (arr[lPointer] < arr[pivot] && lPointer <= rPointer) lPointer++;			// lPointer ��Һ��� ū ���� ã�� ������ ���������� �̵���
		while (arr[rPointer] >= arr[pivot] && lPointer <= rPointer) rPointer--;			// rPointer ��Һ��� �۰ų� ���� ���� ã�� ������ �������� �̵��Ѵ�

		// ���� rPointer�� lPointer�� �����ļ� �����ϴ� ��� rPointer�� pivot�� ��ġ�� �����Ѵ�
		if (rPointer < lPointer)
		{
			// ��ҿ� �ε����� ��� �ٲ۴�
			swap(arr[pivot], arr[rPointer]);
			break;
		}

		swap(arr[lPointer], arr[rPointer]);
	}

	// �Ǻ��� �������� ���� ����Ʈ�� ������ ����Ʈ�� �ɰ���
	// ���� ���� -> pivot�� �����ϸ� �ȵȴ�
	quick_sort(st, rPointer);
	quick_sort(rPointer + 1, en);
}
*/

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
		else if (arr[leftIndex] <= arr[rightIndex]) tmp[i] = arr[leftIndex++];
		// ������ ����Ʈ�� ���� ���� ����Ʈ�� ������ ���� ���
		else tmp[i] = arr[rightIndex++];
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

	// Title : �� �����ϱ� 5

	// �Ǻ��� ��ġ�� ����Ʈ�� �� �� ��ҷ� �����̶�
	// �־��� �ð����⵵ 0(N^2)�� ������ ���� ���� �ִ�
	//
	// �Ǻ��� ��ġ�� �ٲ㺸��

	int N; cin >> N;

	for (int i = 0; i < N; ++i) cin >> arr[i];

	// quick_sort(0, N);		// �ð� �ʰ��� ���ؼ� quick_sort�� ����� �� ����. �־��� �ð� ���⵵ O(N^2)�̱� �����̴�
	merge_sort(0, N);		// O(NlogN)�� �ð����⵵�� ����Ǵ� merge_sort�� ����Ѵ�

	for (int i = 0; i < N; ++i) cout << arr[i] << '\n';

	return 0;
}

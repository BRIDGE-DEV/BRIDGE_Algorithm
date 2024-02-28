#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ���� �ڸ���

	// 1 line
	long long treeCount, needLength;
	cin >> treeCount >> needLength;

	// 2 line
	std::vector<long long> treeHeights(treeCount);
	for (int i = 0; i < treeCount; ++i)
		cin >> treeHeights[i];

	long long result = 0;

	/*
	/// Brute Force

	int searchCount = 0;

	// ���ܱ��� ���̸� '���� ���� ������ ����'�� �ʱ� �����Ѵ�
	long long cuttingHeight = *std::max_element(treeHeights.begin(), treeHeights.end());
	while (true)
	{
	  // ���ܵ� ������ �� ���̸� ���Ѵ�
	  long long sumLength = 0;
	  for (const auto treeHeight : treeHeights)
	  {
		long long Length = treeHeight - cuttingHeight;
		if (Length > 0) sumLength += Length;
	  }

	  // ���ܵ� ������ �� ���̰� �����ȴٸ�
	  // �� ������ ���ܱ��� �ִ� ������ ���̹Ƿ� �����Ѵ�
	  if (sumLength >= needLength)
		break;

	  searchCount++;

	  cuttingHeight--;
	}
	// ������� ���ܱ��� ���̸� �����Ѵ�
	result = cuttingHeight;

	std::cout << "Answer : " << result << '\n';
	std::cout << "Brute Force Count : " << searchCount << '\n';
	*/

	/// Binary Search

	// ���� Ž���� ���� '���ĵ� ������ ����Ʈ'�� ������ ���Ѵ�
	std::sort(treeHeights.begin(), treeHeights.end());
	long long minHeight = 0;
	long long maxHeight = *(treeHeights.end() - 1);

	// �ִ� ���ܱ��� ���̸� ������ ����
	long long maxCuttingHeight = 0;

	// ���� Ž���� �󸶳� ȿ���������� ������ ����
	int searchDepth = 0;

	// ������ ��� ���� Ž���ϴ� ���� �ݺ��Ѵ�
	while (minHeight <= maxHeight)
	{
		// ���ܱ��� ���̸� min�� max�� �߰������� ����
		long long cuttingHeight = (minHeight + maxHeight) / 2;

		// ���ܵ� ������ �� ���̸� ���Ѵ�
		long long sumLength = 0;
		for (const auto treeHeight : treeHeights)
		{
			long long Length = (treeHeight - cuttingHeight);
			if (Length > 0) sumLength += Length;
		}

		// ���� Ž���� ��� ����Ǵ��� ����Ѵ�
		searchDepth++;

		// ���� �� �ʿ��� ��ŭ �߶��ٸ� �װ� �ִ��� ���ܱ� �����̹Ƿ� �����Ѵ�
		if (sumLength == needLength)
		{
			maxCuttingHeight = cuttingHeight;
			break;
		}

		// ���ܵ� ������ ���Ƽ� ���ܱ��� ���̸� �÷��� �Ǵ� ���
		if (sumLength > needLength)
		{
			maxCuttingHeight = cuttingHeight;
			minHeight = cuttingHeight + 1;	// ** + 1�� �߿��ϴ� **
		}
		// ���ܵ� ������ �����ؼ� ���ܱ��� ���̸� ������ �ϴ� ��� (�� ��� �ִ밪�� �������� �ʴ´�)
		else if (sumLength < needLength)
		{
			maxHeight = cuttingHeight - 1;	// ** -1�� �߿��ϴ� **
		}
	}

	result = maxCuttingHeight;
	std::cout << "Answer : " << result << '\n';
	std::cout << "Binary Search Count : " << searchDepth << '\n';

	/// �߿� ����Ʈ
	// min = current + 1;
	// max = current - 1;
	//
	// �̷������� +1�� -1�� �̿��ؼ� min�� max�� �������ִ� ������
	// ���ѷ����� ������ �ʵ��� �ϱ� ���ؼ��̴�
	//
	// �� �˰����� while() �ݺ��� Ż�� ������ minHeight <= maxHeight�ε�
	// +1�� -1�� ������ ������ ������ ���� ��Ȳ���� ���ѷ����� �����Եȴ�
	//
	// minHeight = 10, maxHeight = 11�� ���
	// cuttingHeight = (minHeight + maxHeight) / 2 = 10(10.5)�� �Ǳ� ������
	// ������ while()���� ���� �� ���� �ȴ�
	//
	// ���� Ž������ ������ Ž�� ������ ������ ���ؼ��� +1�� -1�� �ʼ��̴�

	return 0;
}

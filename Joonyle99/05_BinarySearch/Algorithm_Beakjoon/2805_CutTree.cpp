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

	// Title : 나무 자르기

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

	// 절단기의 높이를 '가장 높은 나무의 높이'로 초기 설정한다
	long long cuttingHeight = *std::max_element(treeHeights.begin(), treeHeights.end());
	while (true)
	{
	  // 절단된 나무의 총 길이를 구한다
	  long long sumLength = 0;
	  for (const auto treeHeight : treeHeights)
	  {
		long long Length = treeHeight - cuttingHeight;
		if (Length > 0) sumLength += Length;
	  }

	  // 절단된 나무의 총 길이가 충족된다면
	  // 그 순간이 절단기의 최대 높이일 것이므로 종료한다
	  if (sumLength >= needLength)
		break;

	  searchCount++;

	  cuttingHeight--;
	}
	// 결과값에 절단기의 높이를 저장한다
	result = cuttingHeight;

	std::cout << "Answer : " << result << '\n';
	std::cout << "Brute Force Count : " << searchCount << '\n';
	*/

	/// Binary Search

	// 이진 탐색을 위한 '정렬된 정수의 리스트'의 범위를 구한다
	std::sort(treeHeights.begin(), treeHeights.end());
	long long minHeight = 0;
	long long maxHeight = *(treeHeights.end() - 1);

	// 최대 절단기의 높이를 저장할 변수
	long long maxCuttingHeight = 0;

	// 이진 탐색이 얼마나 효율적인지를 보여줄 변수
	int searchDepth = 0;

	// 범위를 모두 이진 탐색하는 동안 반복한다
	while (minHeight <= maxHeight)
	{
		// 절단기의 높이를 min과 max의 중간값으로 설정
		long long cuttingHeight = (minHeight + maxHeight) / 2;

		// 절단된 나무의 총 길이를 구한다
		long long sumLength = 0;
		for (const auto treeHeight : treeHeights)
		{
			long long Length = (treeHeight - cuttingHeight);
			if (Length > 0) sumLength += Length;
		}

		// 이진 탐색이 몇번 실행되는지 계산한다
		searchDepth++;

		// 만약 딱 필요한 만큼 잘랐다면 그게 최대의 절단기 높이이므로 종료한다
		if (sumLength == needLength)
		{
			maxCuttingHeight = cuttingHeight;
			break;
		}

		// 절단된 나무가 많아서 절단기의 높이를 올려도 되는 경우
		if (sumLength > needLength)
		{
			maxCuttingHeight = cuttingHeight;
			minHeight = cuttingHeight + 1;	// ** + 1이 중요하다 **
		}
		// 절단된 나무가 부족해서 절단기의 높이를 내려야 하는 경우 (이 경우 최대값을 갱신하지 않는다)
		else if (sumLength < needLength)
		{
			maxHeight = cuttingHeight - 1;	// ** -1이 중요하다 **
		}
	}

	result = maxCuttingHeight;
	std::cout << "Answer : " << result << '\n';
	std::cout << "Binary Search Count : " << searchDepth << '\n';

	/// 중요 포인트
	// min = current + 1;
	// max = current - 1;
	//
	// 이런식으로 +1과 -1을 이용해서 min과 max를 조정해주는 이유는
	// 무한루프에 빠지지 않도록 하기 위해서이다
	//
	// 이 알고리즘은 while() 반복문 탈출 조건이 minHeight <= maxHeight인데
	// +1과 -1을 해주지 않으면 다음과 같은 상황에서 무한루프에 빠지게된다
	//
	// minHeight = 10, maxHeight = 11인 경우
	// cuttingHeight = (minHeight + maxHeight) / 2 = 10(10.5)가 되기 때문에
	// 영원히 while()문을 나올 수 없게 된다
	//
	// 이진 탐색에서 적절히 탐색 범위를 좁히기 위해서는 +1과 -1은 필수이다

	return 0;
}

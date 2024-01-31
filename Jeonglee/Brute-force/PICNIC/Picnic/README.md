# 소풍 문제 풀이

이 문제는 프로그래밍 대회에서 배우는 알고리즘 문제 해결 전략 책의 6장 무식하게 풀기에 있는 보글 문제이다.

[해당 책 정리 이슈](https://github.com/fkdl0048/BookReview/issues/188)

발표가 많이 밀리면서 이제야 정리하게 된다.

완전탐색문제의 재귀풀이는 동일하지만 이 문제가 전 문제와 다른 점은 중복을 세는 경우에 대하여 다룬다.

```c++
int n;
bool areFriends[10][10];
// taken[i] = i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int countPairings(bool taken[10]) {
   // 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
   bool finished = true;
    for (int i = 0; i < n; ++i)
         if (!taken[i])
              finished = false;
    if (finished) return 1;
    int ret = 0;
    // 서로 친구인 두 학생을 찾아 짝을 지어 준다.
    for (int i = 0; i < n; ++i)
         for (int j = 0; j < n; ++j)
              if (!taken[i] && !taken[j] && areFriends[i][j]) {
                   taken[i] = taken[j] = true;
                   ret += countPairings(taken);
                   taken[i] = taken[j] = false;
              }
    return ret;
}
```

책에서 주어지는 c++ 예제인데 이를 그대로 작성하게 되면 중복을 세는 경우가 발생한다.

- 같은 학생을 두 번 짝지어 준다. (0,1) 과 (1,0)은 같은 경우로 센다.
- 다른 순서로 학생들을 짝지어 주는 것과 (2,3) 후에 (0,1)을 짝지어주는 것은 완전히 같은 방법인데 다른 경우로 세고 있다.

이러한 문제는 생각보다 자주 마주하게 되며 실제로 다른 이슈에 기재된 실제 프로젝트 3Match 퍼즐에서도 경험했다.

해결하기 위한 가장 좋은 방법은 **항상 특정 형태를 갖는 답만을 세는 것이다.**

이 문제에선 가장 번호가 빠른 학생의 수로 기준을 잡았는데 뒤의 COVER문제도 중복을 세는 문제라 왼쪽 위를 기준으로 잡았다.

마찬가지로 중복을 세기 가장 좋은 방법은 특정 형태를 갖는 답을 찾는 것인데 이를 재귀나 반복으로 처리하기에 시작 지점, 가장 빠른 등으로 측정하는게 편해보인다.

`var result = CountPair(0, new bool[_studentNumber]);`

돌아가 완전 탐색도 완전 탐색이지만, 재귀적인 성격을 가장 많이 띄는 백 트래킹의 형태도 눈에 잘 익은 것 같다.

```cs
isPair[index] = isPair[i] = true;
result += CountPair(index + 1, isPair);
isPair[index] = isPair[i] = false;
```

이 문제의 기저사례는 다음과 같다.

```cs
if (index == _studentNumber)
{
    return 1;
}
```

불 필요한 반복을 줄이는 요소 (앞 문제 BOGGLE에서 설명)

```cs
if (isPair[index])
{
    return CountPair(index + 1, isPair);
}
```

문제 자체는 간단한데 `C#`으로 풀이하는게 맞는지에 대한 고민때문에 조금 돌아온 것 같다.

결론은 알고리즘도 알고리즘이지만 언어레벨의 공부를 좀 더 한다는 생각으로 진행하려고 한다.

# 3MatchPuzzle

실제로 프로젝트에 적용한 코드로 과거 뿌요뿌요, 캔디 사가? 와 같이 3MatchPuzzle을 구현한 코드입니다.

좀 다른 점이라고 한다면 Board가 따로 주어지지 않고 인 게임에 플레이어가 밀어서 움직여야 하는 오브젝트이기 때문에 Board대신 Pos으로 구현되어 있습니다.

다른 코드 대신 `ThreeMatchPuzzleLogic`만 봐도 무방합니다.

## 리뷰

간단하게 보석을 플레이어가 옮겼을 때 해당 보석 타입이 3줄로 일치한다면 보석을 파괴하는 코드라고 생각하면 됩니다.

상하, 좌우 길이 3으로 측정합니다.

```cs
public void CheckMatching()
{
    foreach (var jewelry in jewelries)
    {
        foreach (var direction in _directions)
        {
            CheckingBf(jewelry.transform.position, jewelry.JewelryType, direction,3);
        }
    }
}
```

완전 탐색으로 모든 보석에 대해서 4방향으로 각각 BF를 돌립니다.

경우의 수가 매우 많다고 생각할 수 있는데 마찬가지로 중복을 세지 않고 예외처리가 매우 많아서 생각외로 적은 경우의 수가 나옵니다.

```cs
private bool CheckingBf(Vector2 position, JewelryType type, Vector2 direction, int length)
{
    var jewelry = CheckAndReturnJewelry(position);
    
    if (jewelry == null)
    {
        return false;
    }
    if (jewelry.JewelryType != type)
    {
        return false;
    }
    if (length == 1)
    {
        return true;
    }
    
    if (CheckingBf(position + direction, type, direction,length - 1))
    {
        jewelry.DestroyJewelry();
        IsClear = true; // 1개라도 매칭되면 클리어
        return true;
    }
    
    return false;
}
```

해당 위치에 보석이 없거나, 타입이 일치하지 않거나, 구하려는 길이만큼 구했다면 종료합니다.

처음엔 움직였을 때 해당 보석의 상하좌우로 일치한다면 보석 파괴 후 종료로 간단하게 생각했는데, xxo의 경우와 같이 끝단에 위치한 경우엔 체크가 안되어 BF로 돌렸습니다.

여기서 닫힌 구간에 대한 문제가 발생했는데, 해당 보석으로 Direction만큼 이동 후 재귀를 했을 때 다시 전 보석으로 돌아가는 경우가 생겨서 Direction을 4방향으로 명시하고 해당 방향으로만 검사하도록 변경해서 해결했습니다..

좀 더 이해가 잘갈 수 있는 테스트 코드입니다.

```cs
using NUnit.Framework;
using Runtime.CH1.SubB;
using Runtime.ETC;
using System.Collections;
using UnityEngine;
using UnityEngine.TestTools;

namespace Tests.Runtime.CH1.Sub_B
{
    [TestFixture]
    public class ThreeMatchPuzzleTests
    {
        private GameObject _controllerObject;
        private ThreeMatchPuzzleController _controller;
        private Jewelry[] _jewelries;
        
        [UnitySetUp]
        public IEnumerator Setup()
        {
            _controllerObject = new GameObject("Controller");
            _controller = _controllerObject.AddComponent<ThreeMatchPuzzleController>();
            
            _jewelries = new Jewelry[3];
            
            for (int i = 0; i < _jewelries.Length; i++)
            {
                _jewelries[i] = new GameObject($"Jewelry{i}").AddComponent<Jewelry>();
                _jewelries[i].transform.parent = _controller.transform;
                _jewelries[i].transform.position = new Vector3(i, 0, 0f);
                _jewelries[i].JewelryType = JewelryType.None;
            }
            
            _controller.Jewelries = _jewelries;
            
            yield return new WaitForFixedUpdate();
        }
        
        [UnityTest]
        public IEnumerator TestCheckMatchingSuccess()
        {
            _jewelries[0].JewelryType = JewelryType.A;
            _jewelries[1].JewelryType = JewelryType.A;
            _jewelries[2].JewelryType = JewelryType.A;
            
            _controller.CheckMatching();
            
            yield return new WaitForFixedUpdate();
            
            Assert.IsTrue(_controller.IsClear);
        }
        
        [UnityTest]
        public IEnumerator TestCheckMatchingFail()
        {
            _jewelries[0].JewelryType = JewelryType.A;
            _jewelries[1].JewelryType = JewelryType.B;
            _jewelries[2].JewelryType = JewelryType.A;
            
            _controller.CheckMatching();
            
            yield return new WaitForFixedUpdate();
            
            Assert.IsFalse(_controller.IsClear);
        }
        
        [UnityTest]
        public IEnumerator TestValidateMovementSuccess()
        {
            _jewelries[0].JewelryType = JewelryType.A;
            _jewelries[1].JewelryType = JewelryType.B;
            _jewelries[2].JewelryType = JewelryType.A;
            
            Assert.IsTrue(_controller.ValidateMovement(_jewelries[0], Vector2.up));
            
            yield return new WaitForFixedUpdate();
        }
        
        [UnityTest]
        public IEnumerator TestValidateMovementFail()
        {
            _jewelries[0].JewelryType = JewelryType.A;
            _jewelries[1].JewelryType = JewelryType.B;
            _jewelries[2].JewelryType = JewelryType.A;
            
            Assert.IsFalse(_controller.ValidateMovement(_jewelries[0], Vector2.right));
            
            yield return new WaitForFixedUpdate();
        }

        [UnityTest]
        public IEnumerator TestPuzzleReset()
        {
            _jewelries[0].transform.position = new Vector3(1, 1, 0);
            
            _controller.PuzzleReset();
            
            yield return new WaitForFixedUpdate();
            
            Assert.AreEqual(new Vector3(0, 0, 0), _jewelries[0].transform.position);
        }

        [UnityTearDown]
        public IEnumerator Teardown()
        {
            Object.Destroy(_controllerObject);
            
            yield return new WaitForFixedUpdate();
        }
    }
}
```

지금은 이런 로직으로 만들어져 있는데 더 좋은 방법이 없는지 궁금합니다.
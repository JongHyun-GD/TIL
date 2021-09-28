## UniTask는멀티쓰레드일까?
- UniTask가 멀티쓰레드인지 확인하기 위해 간단한 코드를 써봤다.
```
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Cysharp.Threading.Tasks;
using System.Threading;

public class UniTaskTest : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log($"Main Thread: {Thread.CurrentThread.ManagedThreadId}");
        TestUniTask();
        TestUniTask();
        TestUniTask();
        TestUniTask();
    }

    private async UniTask TestUniTask()
    {
        await UniTask.Delay(1000);
        Debug.Log($"<color='lime'>UniTask Thread: {Thread.CurrentThread.ManagedThreadId}</color>");
    }
}
```

- 결과는 모두 같은 쓰레드에서 동작한다는 것이었다.
- 그렇다면 왜 Coroutine 대신에 UniTask를 써야할까?
	- 그 이유 중 하나는 UniTask가 Coroutine에 비해 성능이 좋기 때문이다.
	- 일단 GCAllocation Memory가 없다. 아예 하나도.
	- https://www.linkedin.com/pulse/unity-async-vs-coroutine-jo%C3%A3o-borks/

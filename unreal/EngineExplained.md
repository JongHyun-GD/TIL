# Introduction: The game loop

게임 프로그래밍에 있어서 가장 간단하고 중심이 되는 로직을 하나 꼽자면, **Game loop**일 것이다.

```
int main()
{
    init();
    while (!exit)
    {
        poll_event();
        update();
        render();
    }
    shutdown();
}
```

그런데 언리얼에서 코드를 쓰면 이러한 Game loop는 쓰지 않는다. 언리얼 엔진이 이런 복잡한 일들은 전부 해두었기 때문이다. 실제로 언리얼 엔진을 시작하는 코드를 찾아보려면 `Engine/Source/Runtime/Launch/Private`에 가면 된다. `LaunchWindows.cpp`를 보면 윈도우에서 어떻게 앱이 시작되는지 알 수 있다. 
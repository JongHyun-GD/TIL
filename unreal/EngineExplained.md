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

문제는 이걸 실제로 봐봤자 두려움만 생길 뿐이다. 다양한 방식의 컴파일을 지원하기 위해 많은 if문, global state를 설정하기 위한 자잘한 코드들을 볼 수 있다. 이런 것들을 하나하나 알 필요는 없을 수 있다. 중요한 건, 이 `LaunchWindows`가 결국 `Launch.cpp`의 `GuardedMain()`으로 이어진다는 것이다. 그렇다. 이 `GuardedMain()`이라는 게 우리가 찾던 그 게임 루프에 가장 가까운 것이다.

# GuardedMain, FEngineLoop

`GuardedMain()`도 만만찮게 생겼지만, 컴파일 플래그 등에 따른 여러 조건들을 대충 치우고 뼈대만 살펴보면 다음과 같다.

```  
#include "LaunchEngineLoop.h"  
bool GIsRequestingExit = False;

int32 GuardedMain(const TCHAR\* CmdLine)  
{  
	// Initialization을 준비하는 단계, 엔진 모듈을 로드한다.  
	int32 ErrorLevel = GEngineLoop.PreInit(CmdLine);  
	if (ErrorLevel != 0 || GIsRequestingExit)  
	{  
		return ErrorLevel;  
	}

	// UEngine을 만들고 initialization한다. 이 과정에서 late initialization이 실행되고 게임이 시작된다.
	ErrorLevel = GEngineLoop.Init();

	// 매 프레임마다 렌더링하고, 엔진에서 tick을 실행하고, RHI를 업데이트한다.
	while(!GIsRequestingExit)
	{
    	GEngineLoop.Tick();
	}

	// 안전하게 종료한다.
	GEngineLoop.Exit();
	return ErrorLevel;
}
```
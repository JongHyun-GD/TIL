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

## PreInit: loading engine, project, and plugin modules

엔진도 여러 모듈의 집합이다. 모듈 시스템은 방대한 모듈을 관리하고 그 중 필요한 것을 로딩할 수 있게 도와준다. Loading은 다음의 순서로 이뤄진다.

`LoadCoreModule(CoreUObject)` -> `LoadPreInitModule(Engine, Renderer, etc...)` -> `Project & Plugin` -> `LoadStartupCoreModules(Core, Networking, UMG, Slate, etc...)` -> `Project & Plugin`

모듈을 로드한다는 것은 실제로 어떻게 이뤄질까? 먼저 모듈에 있는 UObject 클래스를 전부 등록한다. 즉, Reflection System이 이 클래스를 알도록 하고, 또한 각 클래스마다 CDO를 만들어준다. CDO는 `Class Default Obeject`의 약자로 성능과 편의를 위해 만들어둔 기본 세팅의 인스턴스다. 객체를 만들거나 상속할 때, 바로 복제해서 쓸 수 있기 때문이다. 실제로 새로운 Actor 또는 GameMode 등을 만들면 UCLASS() 매크로를 붙이게 된다. 그래서 Constructor 코드가 발동될 때, 부모 클래스의 CDO에 Template의 형태로 Contruct를 실행하게 된다. 그때문에, **Constructor에서는 게임 플레이와 관련한 코드를 넣으면 안되는 것**이다. CDO가 만들어지는 시점이기 때문에 기본 세팅(Default Setting)만 해야 한다.  
이렇게 모든 클래스를 등록하고 나면 엔진은 모듈의 `StartupModule()`을 호출한다. 반대로 모듈이 언로드될 때는 `ShutdownModule()`이 발동한다.

## Init: Creating and starting the Engine (UEngine / UGameEngine)

`Init`은 비교적 직관적이다. 먼저 GameEngine Instance를 만든다. 이렇게 되면 이제까지 PreInit을 한건 Game Engine이 아니고 뭐냐고 생각할 수 있다. 그래서 조금 의미를 구분할 필요가 있다. 동영상에서는 `engine`과 `the Engine`으로 구분한다.

-   `engine`: 언리얼 엔진을 구성하는 모든 소스코드의 집합
-   `the Engine`: UEngine 클래스의 Instance

이렇게 표현하는 게 더 쉬워서 앞으로는 이 단어로 구분하겠다. 다시, `Init`은 `the Engine`을 만든다. 이 때, `the Engine`은 `UEditorEngine` 또는 `UGameEngine`으로 구분된다. 그래서 `Init` 시점에 `the Engine Congif File`을 확인해 어느 엔진 인스턴스가 필요한지 판단하고 그에 따라 `UEditorEngine` 혹은 `UGameEngine`을 만들어내는 것이다. 이렇게 만들어진 `the Engine`은 전역 변수로 등록되어 앞으로 계속 쓰이게 된다. 이는 `Engine/Engine.h`에서 정의되어 있다.  
그렇게 `the Engine`이 만들어지고 나면(the Engine의 Init()이 실행되는 시점), 이에 대한 브로드캐스트를 실행한다. 그 후, project나 plugin module을 로드한다. 이 과정을 전부 지나야 `the Engine`의 `Start()`가 실행된다. 이에 대한 브로드캐스트도 있다.  
그렇다면 `the Engine`은 대체 무슨 일을 하는 것일까? `the Engine`은 엄청난 양의 코드로 이뤄진 인스턴스인데, 그 중 우리가 지금 주시해야할 것은 **맵 로딩**이다. `the Engine`은 URL을 탐색할 수 있다. URL은 **client로서 참가할 서버의 주소**가 일 수도 있고, **로컬에서 로드할 맵 이름**일 수 있다. URL에 `?`를 달아서 argument를 줄 수도 있다. 예를 들자면, `127.0.0.1?Name=Jim`. 에디터 상에서 Project Settings의 Default Map을 수정하면 이 URL이 변경되는 것이다. Development Build에서는 이 URL을 다르게 줘서 런타임 중에 다른 맵을 로드할 수도 있다.

## Engine initialization (UGameInstance, UGameViewportClient, ULocalPlayer)

`UGameEngine::Init()`은 위에도 말했듯, 맵이 로딩되기 전에 실행된다. 이 Phase에서 중요한 오브젝트를 만들어낸다. 그것이 `a GameInstance`, `a GameViewportClient`, `a LocalPlayer`다. `a LocalPlayer`는 실제로 모니터 앞에 앉아 있는 사용자를, `a GameViewportClient`는 그 모니터를 의미한다. 이렇게 추상적인 이유는 이 오브젝트들이 rendering, audio, input system에 대한 high level interface를 제공하기 때문이다. 즉, **User와 the Engine 사이의 인터페이스**가 되는 것이다. `UGameInstance`는 4.4 버전부터 추가된 것으로, `the Engine`에서 일부 기능을 분리한 것이다.  
이렇게 `UGameEngine::Init()`이 끝나면 우리 손엔 **`UGameEngine`, `UGameInstance`, `ULocalPlayer`, `UGameViewportClient`** 이렇게 4개의 인스턴스가 있는 상태다. 이제 실제로 the Engine을 Start()할 차례다.

## Engine Start

이 시점이 처음으로 LoadMap이 일어나는 때다. LoadMap이 끝나면, `UWorld`, `ULevel`, `AActor`, `UActorComponent`은 물론, 엔진 사용을 용이하게 해주는 Actor들도 만들어진다. 그들이 `AGameModeBase`, `AGameSession`, `AGameStateBase`, `AGameNetworkManager`, `APlayerController`, `APlayerState`, `APawn`이다.  
갑자기 많은 인스턴스가 생겨서 혼란스러울 수 있는데, 이 인스턴스들의 라이프사이클을 생각해보면 구분하기 좋다. LoadMap이 되기 전에 있던 인스턴스들을 `Engine Object`라고 하고, 그 이후에 만들어진 인스턴스를 `Game Object`라고 해보자. **`Engine Object`와는 달리 `Game Object`들은 새로운 맵을 로드하거나 다른 서버에 접속하면 바로 파괴된다.**

## LoadMap: Reloading the world from disk (UWorld, ULevel)
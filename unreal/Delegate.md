## Delegate 정의

-   Delegate는 **대리인**이라는 의미다. 무엇을 **대리**한다는 걸까? Delegate가 대리하는 것은 함수다. 그러니까 특정 함수를 직접 부르는 대신, Delegate를 사용해서 **대리 실행**할 수 있다.

## Delegate의 소용 1: 클래스 간 결합도 낮추기

-   **대리 실행**이 왜 필요할까? 그 첫번째 이유는 클래스 사이 의존성을 약화시킬 수 있기 때문이다.
-   클래스 A가 대리인 MyDele\_A가 있다고 가정하자. MyDele\_A는 클래스 A의 멤버함수 PrintOne()의 대리자다. 그러니까 MyDele 보고 `너 실행해!`라고 말하면 실제로는 PrintOne()이 실행된다는 뜻이다.
-   `// 클래스 A를 나타낸 의사코드 class A { public: FDelegate MyDele_A; protected: void PrintOne(); public: A() { MyDele_A.Bind(PrintOne); // 이렇게 해서 PrintOne의 대리자로 MyDele_A를 선임했다고 치자. } }`
-   한 함수가 클래스 A에게 접근해 아무튼 Print 관련 함수를 써야한다고 생각해보자. 이 때, 대리자 MyDele\_A가 있기 때문에 따로 클래스 A의 멤버 함수를 부를 필요가 없고 대리자에게 실행하라고 하면 된다.
-   `void SomeFunc() { A MyA; A.MyDele_A.Execute(); // Delegate에게 실행하라고 한다. }`
-   여기까지는 아직 왜 Delegate가 필요한지 바로 느끼기 힘들다. 이 때, 클래스 A에 변화가 있다고 가정해보자. 이제 PrintOne이 아니라 PrintTwo()가 클래스 바깥에서 실행돼야 한다. 이 때, Delegate를 쓰고 있었다면 SomeFunc은 바꿀 필요가 없다. A 클래스만 바꾸면 된다.
-   `class A { public: FDelegate MyDele_A; protected: void PrintOne(); public: A() { MyDele_A.Bind(PrintTwo); // PrintOne에서 PrintTwo로 바뀌었다. } }`

## Delegate의 소용 2: 여러 함수를 한번에 호출 (이벤트)

-   Delegate가 **함수를 대리한다**고 설명했는데, 정확히 말하자면 **N개의 함수를 대리한다**고 할 수 있다. 일종의 체인 효과를 줄 수 있다고 이해하면 쉽다.
-   예를 들어, Warrior 클래스가 있다고 해보자. Warrior 클래스는 float 변수 hp를 가지고 있다.
-   `class Warrior { public: FMyDele TakeDamageEvent; // 데미지를 받아 hp의 값이 바뀌면 호출되는 Delegate다. private: float hp; public: float GetHp() { return hp; } void TakeDamage(float DamageAmount) { hp -= DamageAmount; TakeDamageEvent.Execute(); if (hp <= 0.f) Die(); } void Die() { std::cout << "Warrior is dead." << std::endl; } }`
-   Warrior는 몬스터나 장애물 등에 의해 공격을 받아 체력(hp)이 깎일 수 있다. 이 때, **Warrior의 체력바**와 **피가 튀는 이펙트**를 추가한다고 생각해보자. 체력바는 Warrior의 hp가 바뀔 때만 다시 그리면 되고, 피가 튀는 이펙트도 구현하기 나름이겠지만 hp가 깎일 때 만들어지면 된다. 이럴 때, 그 클래스들은 Warrior의 TakeDamageEvent에 해당 함수를 **바인드**하면 된다. 예시를 보자.
-   `class WarriorHealthBar { public: void RenderUI(); // HealthBar를 그리는 함수 WarriorHealthBar() { // 여기서 Warrior 인스턴스를 찾아서 이벤트에 RenderUI를 등록한다. GetWarrior()->TakeDamageEvent.Bind(&RenderUI); // GetWarrior()를 통해 Warrior 인스턴스에 접근할 수 있다고 가정했다. } }`

class EffectManager  
{  
public:  
PlayBloodEffect(); // 피가 튀기는 이펙트를 재생해주는 함수  
EffectManager() { // 여기서 Warrior 인스턴스를 찾아서 이벤트에 PlayBloodEffect를 등록한다.  
GetWarrior()->TakeDamageEvent.Bind(&PlayBloodEffect);  
}  
}

\`\`\`

-   이렇게 되면 Warrior는 WarrirorHealthBar, EffectManager가 존재하는지 아닌지도 알 필요 없이 관련 함수들을 실행시킬 수 있다. 더 많은 함수가 체인되더라도 Warrior의 의존성은 변함없다.

## Delegate in UE4

-   C++는 자체 Delegate가 없다. 대신 함수 포인터가 있어서 이를 이용해 Delegate를 만들어낼 수 있다. 언리얼 엔진은 자체 Delegate를 가지고 있다.
-   **Delegate의 선언**
    -   Delegate의 선언은 반환값(RetVal) + 인자(Payload)의 개수를 조합해 매크로로 선언하면 된다.
    -   예를 들어, Delegate에 바인딩하는 함수의 형태가 `int func(char, float)`라면 반환값의 Type은 int, 파라미터는 2개고 char, float형이다. 그러면 매크로는 이렇게 쓴다.
        -   `DECLARE_DELEGATE_RetVal_TwoParams( int, DelegateName, char, float )`
        -   조합이 매우 다양한데, 이는 [공식 API](https://docs.unrealengine.com/4.27/ko/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Delegates/)를 참고하는 것이 좋다.
-   UE4는 4가지의 Delegate를 제공한다. 이 때, singlecast-multicast / dynamic-event가 비슷한 범주다.
    -   singlecast
        -   함수 한개만 바인드할 수 있다.
        -   c++에서만 사용할 수 있다.
        -   `DECLARE_DELEGATE()`
            -   multicast
        -   함수 여러개를 바인드할 수 있다.
        -   c++에서만 사용할 수 있다.
        -   `DECLARE_MULTICAST_DELEGATE()`
    -   dynamic
        -   함수 한개 혹은 여러개를 바인드할 수 있다.
        -   직렬화를 하기 때문에 c++과 블루프린트 모두 사용할 수 있다.
        -   전역으로 설정할 수 있다.
        -   블루프린트에서 사용하기 위해 dynamic에 바인딩된 함수는 UFUNCTION() 매크로가 달려있어야 한다.
        -   `DECLARE_DYNAMIC_DELEGATE()`
    -   event
        -   함수 한개 혹은 여러개를 바인드할 수 있다.
        -   직렬화를 하기 때문에 c++과 블루프린트를 모두 사용할 수 있다.
        -   전역으로 설정할 수 없다. 무조건 클래스 내부에 있어야 한다.
        -   `DECLARE_EVENT()`

1.  타입 정의와 생성
    1.  Delegate 타입을 생성한다.
        1.  DECLARE\_DELEGATE(ReturnType, DelegateTypeName, ParamType…);
    2.  Delegate를 생성한다.
        1.  FMyDele MyDele;
2.  등록과 사용
    1.  MyDele.BindUFunction(this, “SubFunc1”);
    2.  if(MyDele.IsBound()) MyDele.Execute();  
        if(MyMulticast.IsBound()) Multi.Broacdcast();

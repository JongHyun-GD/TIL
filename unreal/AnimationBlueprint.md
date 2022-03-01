## Animation Blueprints

`Animation Blueprints`는 스켈레탈 메쉬의 애니메이션을 제어하기 위해 존재한다. `Animation Blueprints`는 크게 **두 개 그래프**, 즉 `EventGraph`와 `AnimGraph`로 구성된다.

## EventGraph와 AnimGraph의 관계

`Animation Blueprints`와 가장 직접적인 관련이 있다고 할 수 있는 건 `AnimGraph`라고 할 수 있다. `Animation Blueprint`라는 것의 제1 목표는 **이 프레임에 어떤 포즈를 취해야 하는지 계산하는 것**이기 때문이다. `AnimGraph`에서 이러한 역할을 여러 애니메이션 노드를 통해 수행한다.  
그렇다면 `EventGraph`는 왜 있는걸까? `EventGraph`는 AnimGraph의 계산과정에서 필요한 논리적인 연산을 수행해준다. 좀 더 과장해서 말하면, **애니메이션의 포즈를 구하는 작업 외의 일을 전부 도맡아한다.** 예를 들어, `Animation Blueprint`가 장착된 `Character`의 어떤 프로퍼티를 가져온다던가, `AnimGraph`가 어떤 단계의 포즈에 도달했을 때, 이벤트를 밖으로 뿌려준다던가 하는 일이 될 수 있다.

## AnimGraph

`AnimGraph`의 결과값은 `Animation Pose`다. 즉, 지금 이 순간에 `Animation Graph`가 장착된 스켈레탈 메쉬의 Bone들이 정확히 어디에 있어야 하는지 알아내야 한다. 이를 구하기 위해서 여러 가지 방법을 쓸 수 있다. 일단 맨처음에 `AnimGraph`와 관련한 튜토리얼 영상같은 걸 보고 따라해보면 굉장히 헷갈리는데, `AnimGraph`가 외부적으로는 `EventGraph`와 소통하고 내부적으로는 새로운 개념이라고 할 수 있는 `State Machine`과 `Blend Space`를 사용하기 때문이다. 특히 `State Machine` 노드를 만들어서, 그 노드에 들어가서 애니메이션 흐름을 만들고, 막 이러다보면 내가 정확히 어떤 작업을 하고 있는건지 파악하기 어렵다. (적어도 나는 그랬다.) 그래서 더욱 `State Machine`과 `Blend Space`를 간단히 이해해야 한다.

## State Machine

State Machine은 기본적으로 애니메이션의 상태(State)와 그 상태의 변경 조건을 시각화해주는 것에 불과하다. **애니메이션의 상태**라는 것이 뭘까? 게임에서 캐릭터의 애니메이션를 생각해보자. 이 애니메이션의 현재 상태라는 것이 분리가능한 것일 수 있다. 예를 들어, 가만히 있기 - 걷거나 달리기 - 점프 라는 방식이 있을 수 있다. State Machine은 이러한 **State**를 논리적인 관계로 묶은 것이다.

## Blend Space

`Blend Space`는 본질적으로 애니메이션을 부드럽게 이어주는 것이다. 이게 좀 애매한 설명인데, 걷기-달리기 / 걷기-공격하기 라는 두가지 애니메이션 간의 관계를 떠올려보자. 두 관계는 다른 점이 있다. 그건 걷기에서 달리기는 같은 그룹이지만, 걷기와 공격하기는 다른 그룹이라는 것이다. 그렇다면 `Blend Space`는 어디에 쓰는걸까? 걷기-달리기에 쓴다. 완전히 걸으면서 완전히 달릴 수는 없다. 반대로 완전히 걸으면서 완전히 공격할 수는 있다.

## EventGraph

`EventGraph`는 `AnimGraph`가 적절한 Pose를 구할 수 있도록 Pose와 관련한 일 외의 모든 일을 수행한다. 대충 여타 Blueprint와 비슷하게 쓸 수 있는데, 이벤트만 다르다. `EventGraph`의 이벤트는 `Blueprint Initialize Animation`과 `Blueprint Update Animation` 두개 뿐이다. 각기 `BeginPlay`, `Tick`에 대응한다.

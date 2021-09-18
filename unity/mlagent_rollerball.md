# RollerBall ML Project

## 목적

- Agent는 공을 굴려서 박스와 부딪혀야 한다.
- Agent는 Plane에서 떨어지면 안 된다.



## 환경 조성

### 1. 오브젝트 배치

- Plane(플랫폼) => Position(0,0,0)
- Cube(타겟) => Position(3, 0.5, 3)
- Sphere(에이전트) => Position(0, 0.5, 0)
- Academy => Position(0,0,0)

### 2. 에이전트 설정

- 에이전트의 역할

  - 주변 환경 관측 (Observation)
  - 정책에 따른 행동 (Actions)
  - 보상 (reward)

- 에이전트 클래스의 핵심 메소드

  - Initialize()

    - Play를 눌렀을 때, **한번** 호출되는 메소드

    - 주로 에피소드가 바뀌어도 변하지 않는 변수에 대한 초기화 작업이 이뤄진다.

    - ```c#
      public override void Initialize() {
        transform = GetComponent<Transform>();
      	rigidbody = GetComponent<Rigidbody>();
      }
      ```

  - OnEpisodeBegin()

    - 각 에피소드가 시작될 때마다 호출되는 메소드

    - 에피소드마다 해야하는 초기화 작업을 주로 수행한다.

    - 여기까지 구현하고 스크립트를 에이전트 오브젝트에 붙이면 제대로 배치하는지 살펴볼 수 있다.

    - ```c#
      public override void OnEpisodeBegin()
          {
              rigidbody.velocity = Vector3.zero;
              rigidbody.angularVelocity = Vector3.zero;
              transform.localPosition = new Vector3(
                  Random.Range(-randomPositionDeltaX, randomPositionDeltaX),
                  fixedPositionY,
                  Random.Range(-randomPositionDeltaZ, randomPositionDeltaZ));
      
              targetTransform.localPosition = new Vector3(
                  Random.Range(-randomPositionDeltaX, randomPositionDeltaX),
                  fixedPositionY,
                  Random.Range(-randomPositionDeltaZ, randomPositionDeltaZ));
          }
      ```

  - CollectObservations()

    - 관측정보의 수집 및 전달을 수행한다.

    - ```c#
      public override void CollectObservations(VectorSensor sensor)
          {
              sensor.AddObservation(targetTransform.localPosition); // 3 (x, y, z)
              sensor.AddObservation(transform.localPosition); // 3 (x, y, z)
              sensor.AddObservation(rigidbody.velocity.x); // 1 (x)
              sensor.AddObservation(rigidbody.velocity.z); // 1 (z)
          }
      ```

    - 각 벡터의 크기는 Behavior Parameter > VectorObservation > Space Size에도 적용해야 한다.

  - OnActionReceived()

    - 브레인(정책, Policy)로부터 전달받은 행동에 따라 에이전트가 수행할 동작을 정의한다.

    - 액션은 Continuous와 Discrete로 구분한다. 이 예제에서는 상/하,좌/우 화살표 키입력값에 따라 에이전트에 힘을 가한다.

    - ```c#
      		// v[0] : up, down
          // v[1] : left, right
          public override void OnActionReceived(float[] vectorAction)
          {
              float v = Mathf.Clamp(vectorAction[0], -1.0f, 1.0f);
              float h = Mathf.Clamp(vectorAction[1], -1.0f, 1.0f);
              Vector3 direction = (Vector3.forward * v) + (Vector3.right * h);
              rigidbody.AddForce(direction.normalized * forcePerAction);
      
              SetReward(noMovePanalty);
          }
      ```

  - Heuristic

    - 테스트를 위해 사용자로부터 키보드 입력값을 받는 부분

    - actionsOut에 입력값에 따른 액션값을 넣으면 된다. 이 예제에서는 상하 화살키를 v[0]에, 좌우 화살키를 v[1]에 담는다.

    - ```c#
          public override void Heuristic(float[] actionsOut)
          {
              actionsOut[0] = Input.GetAxis("Vertical");
              actionsOut[1] = Input.GetAxis("Horizontal");
              Debug.Log($"[0]={actionsOut[0]} [1]={actionsOut[1]}");
          }
      ```

### 3. Decision Requester 컴포넌트

- 브레인에게 Action을 요청하는 컴포넌트
- 주로 지속적으로 결정을 내려받아 행동해야 하는 학습 패턴에 사용한다.

### 4. Rewards 설정

- Reward와 관련한 함수는 두 개가 있다. SetReward(), AddReward()

- `SetReward()`  => 이전까지 모든 보상 내용을 지우고 현재의 보상값으로 대체한다.

- `AddReward()`  => 이제까지 보상에 보상값을 더한다.

- 현 예제에서는 플랫폼에서 떨어지면 바로 마이너스 보상을, 상자에 부딪히면 플러스 보상을 주고 에피소드를 끝낼 것이므로 `SetReward()` 를 사용할 것이다.

- ```c#
      public void OnCollisionEnter(Collision collision)
      {
          if (collision.collider.CompareTag("DeadZone"))
          {
              platformRenderer.material = badMaterial;
              SetReward(-1.0f);
              EndEpisode();
          }
  
          if (collision.collider.CompareTag("Target"))
          {
              platformRenderer.material = goodMaterial;
              SetReward(+1.0f);
              EndEpisode();
          }
      }
  ```





### 5. 학습 시키기

- Agent 스크립트의 MaxStep 설정
  - 한 에피소드에서 액션을 시도하는 횟수
  - 환경의 복잡도에 따라 가장 적절한 값을 찾아야 한다.
- Behaviour Name 설정
  - 환경설정 파일에서 자신의 학습환경을 찾기 위한 속성값
  - 훈련이 끝나면 해다 이름으로 모델 파일이 생성된다.
- Training Configuration File 작성
  - 자세한 내용은 [이 사이트](https://github.com/Unity-Technologies/ml-agents/blob/main/docs/Training-Configuration-File.md)를 참고하면 된다.
  - 이는 전체 훈련이 어떤 방식으로 이뤄질지 정의하는 파일이다.
  - ml-agents/config/ppo/[brainName].yaml에 저장한다.
  - 디폴트 내용은 각 버전마다 다르다. 예제 config 파일을 참고하자.
- `mlagents-learn {학습환경설정파일.yaml} --run-id={Behaviour 명}`
  - `mlagents-learn RollerBall.yaml --run-id=RollerBall`



## 참고

[MummyBasic for ML Agents](https://unity3dstudy.com/2020/08/22/MummyBasic-for-ML-Agents-02/)


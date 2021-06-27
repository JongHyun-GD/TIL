# Logistic Regression as a Neural Network

## Binary Classification

- 목표: 입력 벡터 x를 통해 결과값으로 0 또는 1을 얻는 것
  - 입력: 이미지의 r,g,b 벡터
  - 출력: 고양이 이다(1) 아니다(0)
- 실제로 입력값 X는 여러 입력의 묶어서 2차원 벡터로 나타낸다.
  - n_x = 한 입력의 길이
  - m = 입력 예시의 개수
  - 즉, **X = n_x * m** 크기를 가진 행렬이다.
- 그러니까 당연히 Y도 2차원 벡터로 묶인다.
  - **Y = [y^1, y^2, ..., y^m]**

## Logistic Regression

- Logistic Regression은 Binary Classification 문제를 푸는 알고리즘 중 하나이다.
- 고양이 판별기로 예를 들어보자.
  - 이 판별기에 입력값은 사진이다. 앞에서 말한 것처럼 이 사진은 n_x길이의 한 벡터로 변환된다.
  - 그렇다면 출력값은 이 사진이 고양이일 확률이 된다. 확률은 0과 1사이의 숫자다.
  - Logistic Regression에는 입력값에 영향을 미치는 **두 개의 파라미터(w, b)**가 존재한다. 이 파라미터는 다음과 같은 수식을 세운다.
    - ![img](https://latex.codecogs.com/gif.image?\dpi{200}w^Tx + b)
  - 이 값은 문제가 있는데, 이 값이 0과 1 사이의 수가 아닐 확률이 있기 때문이다. 이를 보완하기 위해 시그모이드 함수를 사용한다. 시그모이드 함수는 다음과 같다.
    - ![img](https://latex.codecogs.com/gif.image?\dpi{200}\sigma(z) = \frac{1}{1+e^{-z})
    - 들어오는 z값이 커질수록 e는 0에 수렴하고 z값이 작을 수록 e는 무한대에 가까워진다.
  - 이를 위의 수식에 적용하면 다음과 같은 식이 완성된다.
    - ![img](https://latex.codecogs.com/gif.image?\dpi{200}\hat{y} = \sigma(w^Tx+b))

## Logistic Regression cost function

- Logistic Regression을 여러 입력이 묶인 2차원 벡터로 일반화하면 다음과 같다.
  - ![img](https://latex.codecogs.com/gif.image?\dpi{200}\hat{y}^i = \sigma(w^Tx^i+b))

- 이렇게 얻은 값으로 Loss(Error) function을 만들 수 있다. Error function은 그 출력이 크면 클수록 답과는 멀다는 것을 의미한다.
  - 가장 간단한 방법으로 다음과 같은 식을 고안할 수 있다.
    - ![img](https://latex.codecogs.com/gif.image?L(\hat{y},y) = \frac{1}{2}(\hat{y}-y)^2)
    - 이 Loss function은 구불구불한 그래프를 만들어내고 이는 global optima가 아니라 local optima로 빨려들어갈 여지가 있다.
  - 실제로 사용하는 식은 다음과 같다.
    - ![img](https://latex.codecogs.com/gif.image?L(\hat{y},y)=-(y\log{\hat{y}}+(1-y)\log{(1-\hat{y})})
    - 이게 어떻게 Loss function의 역할을 할까? 두 가지 경우를 생각해보면 알 수 있다.
      - ![img](https://latex.codecogs.com/gif.image?y = 1:L(\hat{y},y)=-\log{\hat{y}})
        - 이 경우에 와이햇이 커질 수록, 즉 답에 근접할수록 Loss는 작아진다.
      - ![img](https://latex.codecogs.com/gif.image?y = 0:L(\hat{y},y)=-\log{(1-\hat{y})})
        - 화이햇이 작을 수록, 즉 답에 근접할수록 Loss는 작아진다.
- Loss function을 정의했으니 이를 통해 Cost function을 정의할 수 있다.
  - Cost function의 개념은 쉽다. 각 training example의 Loss의 평균이다. 식으로 나타내면 다음과 같다.
    - ![img](https://latex.codecogs.com/gif.image?J(w,b)=\frac{1}{m}\sum_{i=1}^{m}L(\hat{y}^i,y^i))

## Gradient Descent

- Gradient Descent 알고리즘은 Logistic Regression 의 파라미터 중 하나인 **w 벡터를 훈련**하는 역할을 한다.
- 우리는 J(w, b)가 가장 낮은, 그러니까 가장 오류가 적은 w, b 값을 알고자 한다.
- w,b와 J(w, b)의 관계를 그래프로 보면 다음과 같다.
  - ![Imgur](https://i.imgur.com/DOOkyHU.png)

- gradient descent를 평면으로 보기 위해서 일단 w만 보도록 하자.
  - ![Imgur](https://i.imgur.com/kMPtcnA.png)
  - J(w, b)를 미분한 값은 코드에서 단순화를 위해 주로 `dw`로 표현된다.
  - 결국 코드는 `w = w - alpha * dw` 가 될 것이다. 이 때, `alpha` 는 learning rate를 의미한다.

## Deivatives with a Computation Graph

- 신경망을 구성했다고 했을 때, 적절한 w값을 얻기 위해서 Backward Propagation을 한다. 이를 위해선 미분값이 필요한데, 그 이유는 무엇일까? 2차원 그래프에서가 아니라 신경망의 구조를 통해서 그 이유를 살펴보자.

  - 일단 미분은 무엇인가? 미분은 한 요소에 따른 어떤 값의 변화량을 산출한 것이다. 예를 들어 아래 식은 a값의 변화에 따른 J값의 변화량이며 또한 a에 대한 J의 미분값이다.

    ![img](https://latex.codecogs.com/gif.image?\frac{dJ}{da})

  - ![Imgur](https://i.imgur.com/AZpQBi0.png)

  - 실제로 신경망엔 위 그림과 같이 여러요소(X 벡터)가 들어가고 이는 어떤 프로세스(Hidden Layer)를 거쳐 결과값(J)으로 이어진다. 그렇다면 맨처음의 요소가 결과값에 대해서 어떤 영향을 미치는 지를 알아내는 건 조금 추상적으로 느껴질 수 있다. 그러니까 생각보다 dJ/da가 어려운 것이다.

  - 이 고민은 **Chain rule**을 통해 풀 수 있다. 체인 룰은 다음의 식과 같이 작동한다.

  - ![img](https://latex.codecogs.com/gif.image?\frac{dJ}{da} = \frac{dJ}{dv}*\frac{dv}{da})

  - 실제로 코딩할 때, 우리는 이러한 단계적인 미분값을 얻을 것이고 이를 곱해서 실질적인 변화값을 얻어낼 수 있다.

  - 참고로 이러한 결론적인 미분값은 코드에서 **dJ/dvar = dvar**와 같은 형식으로 치환된다.

## Logistic Regression Gradient Descent

- 그러면 실제로 이러한 미분값들을 어떻게 기울기 강하(Gradient Descent)에 사용할 수 있을지 알아보자.
- ![Imgur](https://i.imgur.com/lg2Ofcx.png)
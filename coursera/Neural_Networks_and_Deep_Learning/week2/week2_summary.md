# Week 2 Summary

## 의미

Coursera의 Neural Networks and Deep Learning Week2에서 **가장 간단한 형태**의 머신러닝을 구현했다. 보통 머신러닝의 신경망을 여러개의 뉴런으로 구성된 여러개의 뉴런층으로 보곤 한다. 그러니까 대충 N(뉴런의 개수) * M(뉴런 층의 개수)의 뉴런을 쓰는 것이다. 그렇다면 이러한 구성에서 가장 **간단한 형태**는 무엇일까? 당연히 N=1, M=1일 때일 것이다. 다시 말해, Week 2에서는 **뉴런 단 하나**를 코딩한다.

![Imgur](https://i.imgur.com/aR2cUWa.png)

## 1차 방정식의 성립

위의 그림에서 x는 입력값이다. 여러 입력값이 들어올 수 있고 이때 입력값은 각자마다 다른 중요도를 가질 것이다. 그렇다면 x1의 중요도를 w1이라고 정하자. 그러면 다음의 일차식을 만들 수 있다.

![img](https://latex.codecogs.com/gif.image?\dpi{200}w_1x_1+w_2x_2+...+w_nx_n+b=y)

이 때, b는 bias의 준말로, 기본적으로 더해줄 숫자라고 생각하면 편하다.

위 식을 보면 우리가 결국 알아내야 할 것은 명확하다. 어떤 x 벡터가 들어와도 적절하게 y값을 내보내줄 **w 벡터와 b**를 찾는 것이다.

##  Loss와 Cost

w 벡터와 b를 최적화하기 위해서 알아야할 가장 중요한 정보는 무엇일까? 그건 **지금 w 벡터와 b가 얼마나 틀렸는지**라는 수치 정보다. 이러한 오차를 머신러닝에서는 **Loss**라고 할 것이다. 자, 그럼 Loss의 수식을 생각해보자. 가장 먼저 머리에 떠오르는 건 **진짜 정답 - 내 정답**이다. 그런데 이 수식은 Loss가 마이너스 값이 될 여지가 있으므로 제곱하면 더 좋을 것 같다. 그럼 다음 수식이 나온다. (y = 진짜 정답, y_hat = 내 정답)

![img](https://latex.codecogs.com/gif.image?\dpi{200}L=(y-\hat{y})^2)

하지만 이 식은 큰 문제가 있다. 이를 그래프로 나타내면 **구불구불**하다는 것이다. 그러면 training할 때, local optima로 빨려들어갈 수 있으므로 지양해야 한다. 그래서 나오는 Loss function은 다음과 같다.

![img](https://latex.codecogs.com/gif.image?\dpi{200}L=-(y\log{\hat{y}}+(1-y)\log{(1-\hat{y})}))

Cost function은 그냥 Loss의 평균일 뿐이다.

![img](https://latex.codecogs.com/gif.image?\dpi{200}J(w,b)=\frac{1}{m}\sum_{i=1}^{m}{L_i})

## 정규화

위 Loss function는 한가지 전제가 있다. 바로 y와 y_hat이 0과 1사이라는 것이다. 이는 sigmoid function을 통해 구현한다. sigmoid는 다음과 같다.

![img](https://latex.codecogs.com/gif.image?\sigma(z)=\frac{1}{1+e^{-z}})

## 최적화

최적화의 목적은 간단하다. **Cost function의 값을 최소화하는 것**이다. 어떻게? 이를 위해 gradient descent를 사용한다. gradient descent의 방식은 간단하다. x1을 최적화하고 싶으면 Activation 함수를 x1에 대해 편미분하고 그 기울기만큼 x1값을 움직인다. 그렇다고 기울기만큼 움직이면 너무 많이 움직여서 최적화가 제대로 못 진행될 여지가 있기 때문에 이때, 기울기값에 Learning rate를 곱해준다.
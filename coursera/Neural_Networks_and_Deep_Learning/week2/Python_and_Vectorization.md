# Python and Vectorization

## Vectorization

- What is 'Vectorization'?

  - 코드 상에서 for loop를 벡터를 통해 제거하는 방법

  - 예를 들어 다음과 같은 방식의 코드가 있을 수 있다.

    - ```python
      z = 0
      for i in range(n - x):
      	z += w[i] * x[i]
      ```

  - 이 코드는 벡터화를 통해 다음과 같이 바꿀 수 있다.

    - ```python
      z = 0
      z += np.dot(w, x)
      ```

  - 벡터화된 버전이 for에 비해 월등히 빠른 속도를 가지고 있다.

- 
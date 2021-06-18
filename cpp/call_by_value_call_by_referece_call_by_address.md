## Call by value, Call by reference, Call by address(pointer)

### Motivation

C로 프로그래밍을 하면서 Call by reference와 Call by value에 대한 개념을 더욱 단단히 만들었다. 좀 잘못된 방향으로. 이제까지 함수에 인자를 넘겨주는 방식이 두 개, Call by value와 Call by reference 이렇게만 있다고 생각했다. Call by address를 어디서 보긴했는데, Call by reference의 다른 말인줄 알았다. 그러다가 C에는 [Call by reference가 없다](https://m.blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=han95173&logNo=220934411280) 라는 블로그 글을 읽게 되었는데, 내가 아주 잘못 이해하고 있었다는 걸 알 수 있었다. 

### Call by value

```c
# call by value => can not swap
void swap (int a, int b) {
	int t = a;
  a = b;
  b = t;
}
```

Call by value로 인자를 받아들이고 두 값을 바꾸려는 함수다. 당연히 실행이 안된다. 값을 복사해서 함수로 가져온 것이기 때문.

### Call by address

```c
# call by address => can swap but not 'call by reference'
void swap (int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
```

Call by address로 swap을 구현했다. swap 기능은 된다. 문제는 이게 **call by reference가 아니라는 점**이다. **C는 공식적으로 call by reference를 지원하지 않는다. 이 함수는 call by address를 통해 call by reference를 모방한 것일 뿐이다.** Call by reference였다면 실제로 인자로 받은 포인터 a, b 자체를 바꿀 수 있어야 하기 때문이다.

### Call by reference

```c
# call by reference
void swap (int &a, int &b)
{
  int t = a;
  a = b;
  b = t;
}
```

참조자를 통해서 call by reference를 구현할 수 있다. 참조자는 C++에서 추가된 개념이다.

## Summary

- C에는 Call by reference가 없다. Call by reference와 Call by address를 혼동하지 말자.
- Call by reference는 C++의 &을 통해 구현할 수 있다.
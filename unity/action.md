## Action
- 기본적으로 Action은 return값이 없는 함수의 대리자 역할을 한다.

### 1: 기존 메서드 지정
```
Action<string> _action1 = Print;
```

### 2: 무명 메서드 지정
```
Action<string, string> _action2 = delegate (string msg, string error)
{
	Console.WriteLine(msg, error);
};
_action2("msgmsg", "errerr");
```

### 3: 람다식 사용
```
Action<int, int> _action3 = (x, y) => Console.WriteLine(x+y);
```


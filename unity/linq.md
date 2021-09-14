# LINQ

## LINQ?
- 쿼리 = 데이터 소스에서 데이터를 검색하는 식


## LINQ 작업의 세 부분
- 데이터 소스 가져오기
- 쿼리 만들기
- 쿼리 실행
- **LINQ는 여기서 쿼리 만들기에 해당한다. 즉, 쿼리 자체에 해당할 뿐이지 쿼리가 실행된 것은 아니라는 뜻이다.**

## 예제
```c#
// https://docs.microsoft.com/ko-kr/dotnet/csharp/programming-guide/concepts/linq/introduction-to-linq-queries
class IntroToLINQ
{
    static void Main()
    {
        // The Three Parts of a LINQ Query:
        // 1. Data source.
        int[] numbers = new int[7] { 0, 1, 2, 3, 4, 5, 6 };

        // 2. Query creation.
        // numQuery is an IEnumerable<int>
        var numQuery =
            from num in numbers
            where (num % 2) == 0
            select num;

        // 3. Query execution.
        foreach (int num in numQuery)
        {
            Console.Write("{0,1} ", num);
        }
    }
}
```

## 성능
- LINQ는 성능을 확보하기 위해 만들어진 것이 아니다. 그보다는 유지보수나 가독성을 위해 존재한다. 그렇다고 해서 성능이 아주 느리다는 것은 아니기에 LINQ를 쓰기에 적합한 상황이라면 가독성을 위해 쓰는 것이 나을 수 있다. 
- [참고 사이트](https://medium.com/swlh/is-using-linq-in-c-bad-for-performance-318a1e71a732)

# DP 개념 및 특징
- 메모리를 사용해서 알고리즘 수행시간을 향상시키는 방법(메모이제이션)
- 이미 계산한 결과를 메모리에 저장한 뒤 같은 계산은 다시 계산하지 않음
- 일반적으로 탑다운(하향식), 바텀업(상향식) 방법 2가지 방식이 있음

## DP의 시간 복잡도
피보나치 수열의 시간 복잡도는 빅오 표기법으로 O(2^N)임 f(30)의 경우 10번의 연산이 필요

단순 재귀
```java
public class Fibo {
    public int fibonacci(int n) {
        if (n <= 1) {
            return n;
        }

        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
```

상향식 접근법(bottom-up)
```java
public class Fibo {
    static int[] dp = new int[100];

    public int fibonacci(int n) {
        dp[0] = 0;
        dp[1] = 1;

        int i;
        for (i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
```

하향식 접근법(top-down)
```java
public class Fibo {
    static int[] dp = new int[100];

    public static int fib(int n) {
        if (n <= 1) {
            return n;
        }
        if (dp[n] != 0) { // 메모이제이션
            return dp[n];
        }
        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
}
```

## 메모이제이션(Memoization)

Memorization과 혼동되기 쉽지만 구분되는 다른 단어. Memorization은 머리속에 무언가를 기억하는 암기의 뜻을 가지고 있으며 Memoization은 동적계획법에서 사용되는 알고리즘에서 사용되는 용어로 메모리에 결과를 저장해 두었다가 재사용 하는 방법을 뜻함

## Tabulation vs Memoization ?

동적계획법의 풀이법중 하향식이냐 상향식이냐에 따라서 불르는 명칭이 다르다고 함

Tabulation

- 상향식 접근 방법
- 하위 문제의 결과를 테이블에 저장합니다.
- 반복문으로 구현합니다.
- 입력이 많은 문제에 적합합니다.
- 하위 문제가 겹치지 않을 때 사용합니다.
- 큰 문제를 해결하기 위해 작은 문제를 호출

Memoization

- 하향식 접근 방법
- 함수 호출 결과를 캐시
- 재귀 구현
- 상대적으로 작은 입력 집합이 있는 문제에 적합
- 하위 문제에 하위 문제가 겹치는 경우 사용
- 작은 문제부터 순차적으로 풀어 나가며 큰 문제까지 해결

reference : https://www.geeksforgeeks.org/tabulation-vs-memoization/

# DP가 적용 가능한 문제

- 최적 부분 구조
    - 복잡한 문제를 여러 개의 작은 문제로 나누어 풀 수 있어야 함
- 중복되는 부분 문제
    - 동일한 작은 문제를 반복적으로 해결해야 함

# 그리디 알고리즘 vs DP

네비게이션을 예를 들면 목적지까지 갈 수 있는 경로를 찾을 때 DP 알고리즘은 모든 경우의 수를 고려하여 최적의 해를 찾아낸다. 반면 그리디 알고리즘은 순간 순간 교차로가 보일 때 마다 가장 효율적인 방법을 찾아서 목적지를 찾아간다.

DP 알고리즘을 사용하면 약간의 시간이 걸리는 단점이 있지만 반드시 최적의 결과를 보장한다는 장점이 있고 그리디 알고리즘은 항상 최적의 경로를 찾아주지는 않는다.
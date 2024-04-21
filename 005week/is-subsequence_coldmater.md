# 문제 정보

https://leetcode.com/problems/is-subsequence/

# 첫번째 시도

## 아이디어

투포인터. s 의 index 와 t 의 인덱스를 각각 조건에 따라 증가시켜간다. s 의 각 문자열과 t 의 각 문자열을 비교한다. 알고리즘은 다음과 같다.

- 일반 로직: 특정 인덱스의 문자가 일치하면 s 와 t 의 인덱스를 증가시키고, 일치하지 않으면, t 만의 인덱스를 증가시킨다.
- 종료조건
  - s 의 인덱스가 범위를 초과하면 true 판정 (subsequence 임)
  - t 의 인덱스가 범위를 초과하면 false 판정 (subsequence 가 아님)

## 소스코드

```cpp
class Solution {
public:
    bool go (int si, int ti, string s, string t) { // si: index of s, ti: index of t
        if (si >= s.size()) {
            return true;
        }

        if (ti >= t.size()) {
            return false;
        }

        if (s[si] == t[ti]) {
            return go(si + 1, ti + 1, s, t);
        }
        return go(si, ti + 1, s, t);
    }

    bool isSubsequence(string s, string t) {
        return go(0, 0, s, t);
    }
}
```

## 한계

DP 문제인데, DP 적인 요소가 쓰인 곳이 없다. 단순히 DP 적인 접근이 필요한 다음 단계의 문제를 풀 때 이 문제를 참고하는 걸까?

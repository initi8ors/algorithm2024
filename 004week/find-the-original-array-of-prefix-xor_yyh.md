# 문제
https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/
2433. Find The Original Array of Prefix Xor

# solution
```java
class Solution {
    public int[] findArray(int[] pref) {
        int[] result = new int[pref.length];

        result[0] = pref[0];
        for (int i = 1; i < pref.length; i++) {
            result[i] = pref[i - 1] ^ pref[i];
        }

        return result;
    }
}
```

# 풀이
XOR 는 서로 배타적일때 true 인 연산자로\
0 XOR 1 = 1\
1 XOR 1 = 0\
0 XOR 0 = 0\
의 값을 갖음

5 XOR ? = 2 일 때\
이진수로 다음과 같음\
5 = 101\
2 = 010

101 XOR 111 = 010 이 되므로\
7이 여야 함.

5에서 2를 XOR 하면 7이 나오고\
2에서 0을 XOR 하면 2가 나오는 규칙을 발견

순차적으로 XOR 하면 원본값을 알 수 있음
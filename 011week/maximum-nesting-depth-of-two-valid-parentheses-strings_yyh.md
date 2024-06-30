# 문제
https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
1111. Maximum Nesting Depth of Two Valid Parentheses Strings

# solution
```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] result = new int[seq.length()];
        Stack<Character> stack = new Stack<>();
        boolean curA = true;
        for (int i = 0; i < seq.length(); i++) {
            if (seq.charAt(i) == '(') {
                if (!stack.isEmpty()) {
                    if (seq.charAt(i - 1) == '(') {
                        curA = !curA;
                    }
                }
                stack.push(seq.charAt(i));
            } else {
                stack.pop();
                if (seq.charAt(i - 1) == ')') {
                    curA = !curA;
                }
            }
            if (curA) {
                result[i] = 0;
            } else {
                result[i] = 1;
            }
        }

        return result;
    }
}
```

# 풀이
Stack 자료구조와 그리디 알고리즘 사용

문제 정의\
seq와 같은 길이의 result를 반환\
result는 0과 1로 이루어져 있으며 A그룹과 B 그룹으로 나뉨\
A그룹이면 0, B 그룹이면 1

A그룹과 B 그룹의 정의는 Max(A.depth, B.depth)를 했을 때 가장 작게 나와야 된다고 함..\
정답은 복수 정답이며 조건에만 맞으면 됨

```
Example 2

Input: seq = "()(())()"
Output: [0,0,0,1,1,0,1,1]
```

예제를 분해해서 살펴보면 "()" "(())" "()" 세 부분으로 나눌 수 있음\
각 부분별 depth를 살펴보면 아래와 같음\
"()" : 1depth\
"(())" : 2depth\
"()" : 1depth


세 파트를 모두 A그룹으로 놓으면 max(A.depth, B.depth) = 2
A그룹과 B 그룹을 적절히 분배하면 A그룹 = "()()()", B 그룹 = "()"으로 만들어서 max(A.depth, B.depth) = 1이 가능함

"(())" 파트를 한번 더 세부파트로 나누어 보자면 "( ' ()'  )" 큰따옴표와 작은 따옴표로 나눌 수 있음\
즉 depth가 깊어질 때 마다 A그룹과 B 그룹으로 나누면 가장 작은 depth 그룹을 만들 수 있게 됨

depth가 변하는 경우는 두번 연속 같은 괄호가 나왔을 때 "(("나 "))" 의 케이스\
"()"의 케이스는 괄호가 열린 직후에 닫히므로 depth가 높아지거나 낮아지지 않음

시간복잡도는 O(N)

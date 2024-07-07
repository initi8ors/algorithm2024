# 문제
https://leetcode.com/problems/adding-spaces-to-a-string
2109. Adding Spaces to a String

# solution
```java
class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder sb = new StringBuilder();
        int beforeStartIndex = 0;
        for (int i = 0; i < spaces.length; i++) {
            sb.append(s.substring(beforeStartIndex, spaces[i]));
            sb.append(" ");
            beforeStartIndex = spaces[i];
        }
        sb.append(s.substring(beforeStartIndex));

        return sb.toString();
    }
}
```

# 풀이
StringBuilder와 substring method를 활용한 문자열 처리

### 알고리즘 설명
ex) EnjoyYourCoffee와 5, 9값이 주어졌을 경우
1. StringBuilder에 0~5의 값 Enjoy 추가
2. space 추가
3. 그 다음 index인 5 ~ 9까지의 String 값 Your을 StringBuilder에 추가
4. space 추가
5. index 9부터 마지막 String까지 StringBuilder에 추가
6. Enjoy Your Coffee 완성!

끝.


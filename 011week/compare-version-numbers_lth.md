# [Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/description/)

# 코드
```java
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1s = version1.split("\\.");
        String[] v2s = version2.split("\\.");

        int i = 0;
        while (i < v1s.length || i < v2s.length) {
            int num1 = i < v1s.length ? Integer.parseInt(v1s[i]) : 0;
            int num2 = i < v2s.length ? Integer.parseInt(v2s[i]) : 0;

            if (num1 < num2) {
                return -1;
            } else if (num1 > num2) {
                return 1;
            }
            i++;
        }

        return 0;
    }
}
```

# 접근 및 풀이방법
- 각 버전에서 `.` 기준으로 파트를 나누어 파트별 문자열을 정수로 치환
- 정수로 치환한 버전의 파트별로 대소를 구분
- 대소 구분이 되지 않는다면 같은 버전으로 취급

# 문제
https://leetcode.com/problems/compare-version-numbers/
165. Compare Version Numbers

# solution
```java
        String[] arr1 = version1.split("\\.");
        String[] arr2 = version2.split("\\.");

        for (int i = 0; i < Math.max(arr1.length, arr2.length); i++) {
        int num1 = i >= arr1.length ? 0 : Integer.parseInt(arr1[i]);
        int num2 = i >= arr2.length ? 0 : Integer.parseInt(arr2[i]);

        if (num1 < num2) return -1;
        else if (num1 > num2) return 1;
        }

        return 0;
```

# 풀이
그리디 알고리즘 ?

1. 각 서브 버전은 .으로 구분되기 때문에 .으로 split
2. 왼쪽에서 오른쪽으로 순차비교
3. 각 자리의 왼쪽의 0은 무시\
참고 version1과 version2의 서브버전이 다를 경우 서브버전이 없는 버전은 0으로 본다.

시간복잡도는 O(N)
# 문제
https://leetcode.com/problems/partition-array-for-maximum-sum/description/
1043. Partition Array for Maximum Sum

# solution
```java
class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int[] dp = new int[arr.length];
        dp[0] = arr[0];
        for (int i = 1; i < arr.length; i++) {
            int end = i - k + 1;
            if (end < 0) end = 0;
            for (int j = i; j >= end; j--) {
                int beforeDp = 0;
                if (j > 0) {
                    beforeDp = dp[j - 1];
                }
                dp[i] = Math.max(dp[i], beforeDp + getMax(arr, k, j, i));
            }
        }

        return dp[dp.length - 1];
    }

    public int getMax(int[] arr, int k, int start, int end) {
        int max = 0;
        for (int i = start; i <= end; i++) {
            if (i < 0) i = 0;
            max = Math.max(max, arr[i]);
        }

        return max * ((end - start) + 1);
    }
}
```

# 풀이
dp 풀이
1차 시도
처음 DP에 저장할 값은 index ~ (index - k)를 2차원 배열로 만들어서 계산
하지만 모든케이스를 고려하지 못하는 DP여서 오답

2차 시도
1. dp에는 index에 위치할때까지 가장 큰 partition array를 기억
2. 다음에 구할 dp는 dp[i-1] + dp[i] 부터 dp[i-k] + dp[i]중 max값을 계산

계산은 O(N^2) 예상
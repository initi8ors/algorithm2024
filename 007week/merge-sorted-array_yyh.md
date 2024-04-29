# 문제
https://leetcode.com/problems/merge-sorted-array/
88. Merge Sorted Array

# solution
```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if (n == 0) {
            return;
        }

        int[] nums3 = new int[m + n];
        int p1 = 0;
        int p2 = 0;


        for (int i = 0; i < m + n; i++) {
            if (p2 < n && (p1 == m || nums1[p1] > nums2[p2])) {
                nums3[i] = nums2[p2];
                p2++;
            } else {
                nums3[i] = nums1[p1];
                p1++;
            }
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = nums3[i];
        }
    }
}
```

# 풀이
투포인터 사용\
주어진 두개의 배열 nums1과 nums2가 이미 정렬되어 있기 때문에 투포인터를 사용하기에 적합

nums1의 길이를 m변수로 판단해야 하기 때문에 조건문이 복잡해짐
정렬을 할 때 다음에 올 숫자를 nums1에서 가져오는 경우
1. p2의 길이가 n에 도달 했을 때
2. p1이 아직 m에 도달하지 않아야 함
3. nums1[p1]의 값이 nums2[p2]보다 작을 때

다음에 올 숫자를 nums2에서 가져오는 경우
1. p1의 길이가 m에 도달 했을 때
2. p2가 아직 n에 도달하지 않아야 함
3. nums2[p2]의 값이 nums1[p1]보다 작을 때




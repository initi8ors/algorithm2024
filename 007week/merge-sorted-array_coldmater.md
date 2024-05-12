# 문제 정보

https://leetcode.com/problems/merge-sorted-array/

# 첫번째 풀이

## 아이디어

두 배열 요소는 이미 정렬되어 있는 상태이므로, 각각의 배열에 포인터를 두고 포인터의 값들을 비교하면서 반환될 배열에 값을 채워넣는다. nums1 배열의 크기가 합쳐진 배열의 크기와 동일하고, 오른쪽부터 채우기 위해 역방향으로 포인터를 진행한다.

## 소스코드

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int k = m + n - 1;

        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] < nums2[p2]) {
                nums1[k--] = nums2[p2--];
            } else {
                nums1[k--] = nums1[p1--];
            }
        }

        // cout << "p1: " << p1 << "\n";
        // cout << "p2: " << p2 << "\n";
        // cout << "k: " << k << "\n";
        while (p2 >= 0) {
            nums1[k--] = nums2[p2--];
        }
    }
};
```

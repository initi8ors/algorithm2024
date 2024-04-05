# 문제: 1. Two Sum

https://leetcode.com/problems/two-sum/

# 첫번째 시도

## 아이디어

O(n) 에 수행할 수 있도록, 주어진 배열을 순회하며 target 과의 차이를 key 로 index 를 hash table 에 저장한다. 만약 특정 원소의 값이 hash table 의 key 중 일치하는 key 값이 있다면 해당 key 의 index 와 특정 원소의 값은 합쳐서 target 이 된다는 의미가 된다. 이 순간에 현재 index 와 hash table 의 value 값을 쌍으로 반환한다.

## 소스코드

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.rbegin(), nums.rend()); // sorting reverse side
        vector<pair<int, int>> n;
        for (int i = 0; i < nums.size(); ++i) {
            n.push_back({ nums[i], i });
        }
        sort(n.begin(), n.end());

        int l = 0;
        int r = n.size() - 1;

        while (l < r) {
            int res = n[l].first + n[r].first;
            cout << res << "\n";
            if (res > target) {
                r--;
            } else if (res < target) {
                l++;
            } else {
                break;
            }
        }

        return {n[l].second, n[r].second};
    }
}
```

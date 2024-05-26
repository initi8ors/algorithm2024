# number-of-provinces

https://leetcode.com/problems/number-of-provinces/

# 첫 번째 시도

## 아이디어

일반적인 flood-fill 류의 문제인 것으로 판단했다. 모든 노드를 순회하면서 새로운 province 가 생겼다고 판단될 때마다 province number (소스코드에서는 regionNumber 라 칭함) 를 증가시키며 해당 노드와 연결된 노드들에는 모두 같은 number 를 할당해준다. 이 값은 visited matrix 에 할당되며, 0 초과한 숫자가 기록된 경우 방문한 것으로 보고, 앞서 설명한 것과 같이 여기에 채워져 있는 숫자는 province number 라고 생각해도 좋다.

## 소스코드

```cpp
class Solution {
public:
    int visited[200];
    void fill (int here, vector<vector<int>>& isConnected, int regionNumber) {
        // cout << "fill: " << here << "\n";
        visited[here] = regionNumber;

        for (int there = 0; there < isConnected[here].size(); ++there) {
            if (isConnected[here][there] == 0 || visited[there]) continue;
            fill(there, isConnected, regionNumber);
        }
    }
    int regionNumber = 0;
    int findCircleNum(vector<vector<int>>& isConnected) {
        for (int here = 0; here < isConnected.size(); ++here) {
            if (visited[here]) continue;
            fill(here, isConnected, ++regionNumber);
        }
        return regionNumber;
        return 0;
    }
}
```

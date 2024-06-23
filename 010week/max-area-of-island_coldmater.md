# balanced-binary-tree

https://leetcode.com/problems/max-area-of-island

# 첫 번째 시도

## 아이디어

## 소스코드

```cpp
class Solution {
public:
    int v[50][50];
    vector<vector<int>> g;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    int bfs (int y, int x) {
        v[y][x] = 1;

        int cnt = 1; // self
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= g.size() || nx >= g[0].size()) continue;
            if (g[ny][nx] == 0) continue;
            if (v[ny][nx] == 1) continue;

            cnt += bfs(ny,  nx);
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        g = grid;
        int m = 0; // max
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                if (v[i][j] == 1 || g[i][j] == 0) continue;
                int temp = bfs(i, j);
                // cout << "temp: " << temp << "\n";
                m = max(m, temp);
            }
        }
        return m;
    }
}
```

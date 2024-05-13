# nearest-exit-from-entrance-in-maze

https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

# 첫번째 시도

## 아이디어

전형적인 BFS 문제로 이해했다. queue 를 활용하여 그대로 구현한다.

1. 최초의 위치를 큐에 push 한다.
2. queue 사이즈가 있다면 반복하면 while 문을 순회한다.
3. queue 에서 pop 을 한 뒤, pop 한 위치로부터 상,하,좌,우 위치를 판단, 갈 수 있는 위치는 큐에 넣는다. (최대 4개의 위치가 큐에 넣어질 수 있음)
   - 이 때 큐에 넣지 못하는 조건은, 벽을 만나거나, 보드의 경계를 넘어섰거나, 이미 방문하였을 떄이다.
   - 큐에 넣을 때 방문을 기록하는 보드에 현재 위치에서의 값에 1을 더해 기록한다. (최단거리로 활용)
4. `2.` ~ `3.` 을 순회하면서 pop 한 이후에 Exit 에 조건을 만나면 해당 위치에서의 cnt 를 결과로 기록하고 while 문을 빠져나온다.
   - 단, Entrance 가 Exit 의 조건과 일치하는 경우는 제외해야 한다.

## 소스코드

```cpp
class Solution {
public:
    int v[100][100];
    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, 1, 0, -1 };

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int res = -1;
        int h = maze.size();
        int w = maze[0].size();
        int y = entrance[0];
        int x = entrance[1];

        queue<pair<int, int>> q;
        q.push({ y, x });

        while (q.size()) {
            y = q.front().first;
            x = q.front().second;
            // cout << "now: " << y << " " << x << "\n";
            q.pop();

            // check exit
            if (y == 0 || x == 0 || y == h - 1 || x == w - 1) {
                int cnt = v[y][x];
                if (cnt != 0) {
                    res = cnt;
                    break;
                }
            }

            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if (maze[ny][nx] == '+') continue;
                if (v[ny][nx] != 0) continue;

                v[ny][nx] = v[y][x] + 1;
                q.push({ny, nx});
            }
        }

        return res;
    }
};
```

## 한계

177/194 passed.
처음 위치를 방문으로 잡지 않았다.

# 두 번째 시도

## 아이디어

첫 번째 시도에 이어 Entrance 의 위치를 방문으로 잡아주어야 한다. 0 이 방문하지 않음을 의미하는 상태이므로, Entrance 에서의 위치에 1 을 할당해주고, cnt 를 더해간 뒤 마지막 결과를 리턴하기 전에 -1 을 해준다.

## 소스코드

```cpp
class Solution {
public:
    int v[100][100];
    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, 1, 0, -1 };

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int res = 0; // 🔄
        int h = maze.size();
        int w = maze[0].size();
        int y = entrance[0];
        int x = entrance[1];

        queue<pair<int, int>> q;
        q.push({ y, x });
        v[y][x] = 1; // 🔄

        while (q.size()) {
            y = q.front().first;
            x = q.front().second;
            // cout << "now: " << y << " " << x << "\n";
            q.pop();

            // check exit
            if (y == 0 || x == 0 || y == h - 1 || x == w - 1) {
                int cnt = v[y][x];
                if (cnt != 1) { // 🔄
                    res = cnt;
                    break;
                }
            }

            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if (maze[ny][nx] == '+') continue;
                if (v[ny][nx] != 0) continue;

                v[ny][nx] = v[y][x] + 1;
                q.push({ny, nx});
            }
        }

        return res - 1; // 🔄
    }
};
```

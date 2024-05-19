# 문제
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze
1926. Nearest Exit from Entrance in Maze

# solution
```java
class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        Integer[][] visit = new Integer[maze.length][maze[0].length];
        for (Integer[] v : visit) {
            Arrays.fill(v, -1);
        }
        visit[entrance[0]][entrance[1]] = 0;

        int x = maze.length;
        int y = maze[0].length;

        Queue<Integer[]> bfs = new LinkedList<>();
        bfs.add(new Integer[]{entrance[0], entrance[1]});

        while (!bfs.isEmpty()) {
            Integer[] position = bfs.poll();
            if (position[0] == 0 || position[1] == 0 || position[0] == x - 1 || position[1] == y - 1) {
                if (position[0] == entrance[0] && position[1] == entrance[1]) {

                } else {
                    return visit[position[0]][position[1]];
                }
            }
            // 위
            if (position[0] > 0 && maze[position[0] - 1][position[1]] == '.') {
                if (visit[position[0] - 1][position[1]] == -1) {
                    bfs.add(new Integer[]{position[0] - 1, position[1]});
                    visit[position[0] - 1][position[1]] = visit[position[0]][position[1]] + 1;
                }
            }
            // 왼
            if (position[1] > 0 && maze[position[0]][position[1] - 1] == '.') {
                if (visit[position[0]][position[1] - 1] == -1) {
                    bfs.add(new Integer[]{position[0], position[1] - 1});
                    visit[position[0]][position[1] - 1] = visit[position[0]][position[1]] + 1;
                }
            }
            // 오
            if (position[1] < y - 1 && maze[position[0]][position[1] + 1] == '.') {
                if (visit[position[0]][position[1] + 1] == -1) {
                    bfs.add(new Integer[]{position[0], position[1] + 1});
                    visit[position[0]][position[1] + 1] = visit[position[0]][position[1]] + 1;
                }
            }
            // 아
            if (position[0] < x - 1 && maze[position[0] + 1][position[1]] == '.') {
                if (visit[position[0] + 1][position[1]] == -1) {
                    bfs.add(new Integer[]{position[0] + 1, position[1]});
                    visit[position[0] + 1][position[1]] = visit[position[0]][position[1]] + 1;
                }
            }
        }

        return -1;
    }
}
```

# 풀이
BFS 알고리즘 사용
정석적인 최단거리 찾기 문제라고 생각

알고리즘
1. 다음에 탐색할 경로를 담을 queue를 만든다.
2. 시작 위치를 queue에 넣고 탐색을 시작한다.
3. queue에서 꺼낸 뒤 출구인지 확인한다.
4. 상,하,좌,우 한칸씩 탐색 한다. 이 때 visit 배열에 이동 거리를 저장한다.
5. 이동할 수 있을 경우 Queue에 넣는다.
6. 3 ~ 5를 반복한다.

이미 방문했는지 체크 및 이동거리를 확인하기 위해 visit 배열을 만들어 체크

시간복잡도는 O(N) 예상
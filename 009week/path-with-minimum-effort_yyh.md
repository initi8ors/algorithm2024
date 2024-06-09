# 문제
https://leetcode.com/problems/path-with-minimum-effort
1631. Path With Minimum Effort

# solution
```java
class Solution {
    public int minimumEffortPath(int[][] heights) {
        int yLength = heights.length - 1;
        int xLength = heights[0].length - 1;
        boolean[][] visit = new boolean[yLength + 1][xLength + 1];
        int[][] dp = new int[yLength + 1][xLength + 1];
        for (int[] arr : dp) {
            Arrays.fill(arr, Integer.MAX_VALUE);
        }

        PriorityQueue<Integer[]> queue = new PriorityQueue<>(Comparator.comparingInt(t -> t[2]));
        queue.add(new Integer[]{0, 0, 0});
        dp[0][0] = 0;

        int[] y = {-1, 0, 1, 0};
        int[] x = {0, 1, 0, -1};

        while(!queue.isEmpty()) {
            Integer[] pair = queue.poll();
            // 이미 방문 했으면 계산 X
            if (visit[pair[0]][pair[1]]) {
                continue;
            }
            // 방문했을때 값이 최소값이 아닐경우 계산 X
            if (dp[pair[0]][pair[1]] < pair[2]) {
                continue;
            }

            // 목적지가 가장 최소값이면 끝
            if (pair[0] == yLength && pair[1] == xLength) return pair[2];

            visit[pair[0]][pair[1]] = true;

            for (int i = 0; i < 4; i++) {
                int nextY = pair[0] + y[i];
                int nextX = pair[1] + x[i];
                if (nextY < 0 || nextY > yLength || nextX < 0 || nextX > xLength) {
                    continue;
                }

                // 다음 노드 거리와 현재 노드까지 거리 값중 큰값이 다음노드의 값보다 작으면 변경
                int value = Math.abs(heights[pair[0]][pair[1]] - heights[nextY][nextX]);
                value = Math.max(value, dp[pair[0]][pair[1]]);
                if (dp[nextY][nextX] > value) {
                    dp[nextY][nextX] = value;
                    queue.add(new Integer[]{nextY, nextX, dp[nextY][nextX]});
                }
            }
        }

        return 0;
    }
}
```

# 풀이
다익스트라 알고리즘 응용문제
다른점은 다익스트라 알고리즘은 지금까지 지나온 거리 + 다음 노드의 거리의 합산이 이미 계산한 다음노드의 거리보다 작으면 업데이트 하지만
이 문제는 지나온 거리중 두 셀의 거리가 가장 큰값을 기준으로 다음노드의 거리를 계산한다.

ex)
일반적인 다익스트라 알고리즘에서 거리값이 각각 1 -> 2 -> 5일 경우 1 + 3 = 4의 값을 가진다.
문제에서는 1 -> 2 -> 5일 경우 1에서 2를 이동할때 1의 값이 필요하고 2 -> 5를 이동할 때 3의 값이 필요한데 가장 큰값인 3이 정답이 된다.

알고리즘
1. 출발 노드와 다른 노드간 최단거리를 나타낼 표를 만든다.
2. 출발지에서 도달할 수 있는 노드간의 셀 거리를 계산한다.
    - 한번에 도달할 수 없는 노드는 빈칸으로 둔다.
3. 방문하지 않은 노드 중 가장 비용이 낮은 순부터 방문한다.
4. 방문한 노드에서 도달할 수 있는 노드 중 아직 방문하지 않은 노드의 비용을 계산한다.
    - 이전 노드에서 계산한 비용보다 낮을 경우 갱신한다.
    - 비용 공식 : max(현재 셀 도달 비용, abs(현재 셀 - 다음 셀))
5. 방문하지 않은 노드중 가장 비용이 낮은 노드가 목적지면 종료한다.
6. 3~5번을 반복한다.


시간복잡도는 O(N) 예상
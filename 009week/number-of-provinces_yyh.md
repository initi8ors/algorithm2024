# 문제
https://leetcode.com/problems/number-of-provinces/
547. Number of Provinces

# solution
```java
class Solution {
    private boolean visited[];
    private int result = 0;

    public int findCircleNum(int[][] isConnected) {
        visited = new boolean[isConnected.length];
        for (int i = 0; i < isConnected.length; i++) {
            dfs(isConnected, i, isConnected.length, true);
        }

        return result;
    }

    public void dfs(int[][] isConnected, int n, int length, boolean first) {
        // 이미 방문 했을 경우 return
        if (visited[n]) return;

        if (first) result++;
        visited[n] = true;

        for (int i = 0; i < length; i++) {
            if (isConnected[n][i] == 1) {
                dfs(isConnected, i, length, false);
            }
        }
    }
}
```

# 풀이
DFS 알고리즘 사용

정석적인 최단거리 찾기 문제라고 생각

알고리즘
1. 출발 지점마다 DFS알고리즘을 사용하여 탐색
2. 이미 방문한 지점일 경우 더이상 방문하지 않음
3. 처음 방문한 곳이면 새로운 connection을 발견 result값 + 1
4. 방문한 지점 방문여부 표시
5. 연결된 지점이 있을 경우 방문(연결된 지점 방문이기 때문에 첫방문 여부는 false로 변경하여 방문)
6. 2~5를 반복

시간복잡도는 O(N) 예상
# [Max Area Of Island](https://leetcode.com/problems/max-area-of-island/description/)

# 코드
```
class Solution {
    private int[] parent;
    private int[] size;
    private int ans;

    public int maxAreaOfIsland(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        parent = new int[rows * cols];
        size = new int[rows * cols];

        // 초기화
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    int index = r * cols + c;
                    parent[index] = index;
                    size[index] = 1; // 섬의 초기 크기 설정
                }
            }
        }

        // 그리드 순회
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    int index = r * cols + c;
                    
                    // 상하좌우로 연결된 섬 합치기
                    if (r > 0 && grid[r - 1][c] == 1) {
                        union(index, (r - 1) * cols + c);
                    }
                    if (r < rows - 1 && grid[r + 1][c] == 1) { 
                        union(index, (r + 1) * cols + c);
                    }
                    if (c > 0 && grid[r][c - 1] == 1) { 
                        union(index, r * cols + c - 1);
                    }
                    if (c < cols - 1 && grid[r][c + 1] == 1) { 
                        union(index, r * cols + c + 1); 
                    }

                }
            }
        }

        // 최대 섬 크기 계산
        for (int i = 0; i < rows * cols; i++) {
            if (parent[i] == i) { // 루트 노드인 경우
                ans = Math.max(ans, size[i]);
            }
        }

        return ans;
    }

    // Find 함수 (경로 압축 적용)
    private int find(int p) {
        if (p != parent[p]) {
            parent[p] = find(parent[p]);
        }
        return parent[p];
    }

    // Union 함수 (사이즈 기반 합 적용)
    private void union(int e1, int e2) {
        int root1 = find(e1);
        int root2 = find(e2);
        if(root1 != root2) {
            if(root1 >= root2) {
                unionApply(root1, root2);
            } else {
                unionApply(root2, root1);
            }
        }
    }

    // Union은 작은쪽을 더 큰쪽으로 편입
    private void unionApply(int g, int l) {
        parent[l] = g;
        size[g] += size[l];
    }
}
```

# 접근 및 풀이방법
- 섬면적을 Union Find 기법으로 합쳐주면서 섬의 크기를 카운팅

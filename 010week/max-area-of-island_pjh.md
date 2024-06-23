```kotlin
import kotlin.math.max

fun main() {
    println(
        maxAreaOfIsland(
            arrayOf(
                intArrayOf(0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0),
                intArrayOf(0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0),
                intArrayOf(0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0),
                intArrayOf(0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0),
                intArrayOf(0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0),
                intArrayOf(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),
                intArrayOf(0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0),
                intArrayOf(0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0),
            )
        )
    )

    println(
        maxAreaOfIsland(
            arrayOf(
                intArrayOf(0, 0, 0, 0, 0, 0, 0, 0)
            )
        )
    )
}

fun maxAreaOfIsland(grid: Array<IntArray>): Int {
    var result = 0
    val visited = Array(grid.size) {
        Array(grid[0].size) { false }
    }

    grid.forEachIndexed { i, map ->
        map.forEachIndexed { j, _ ->
            result = max(result, isIsland(grid, i, j, visited))
        }
    }

    return result
}

fun isIsland(grid: Array<IntArray>, i: Int, j: Int, visited: Array<Array<Boolean>>): Int {
    if (i !in grid.indices || j !in grid[0].indices) {
        return 0
    }
    if (visited[i][j]) return 0

    val directions = listOf(0 to 1, 1 to 0, 0 to -1, -1 to 0)
    var newArea = 0

    visited[i][j] = true

    if (grid[i][j] == 1) {
        newArea += 1

        directions.forEach {
            newArea += isIsland(grid, i + it.first, j + it.second, visited)
        }
    }

    return newArea
}
```

2차원 배열을 돌면서 dfs로 구함.  
각 원소를 돌면서 섬인 경우(1인 경우)에만 면적을 1더해주고 4방향을 돌면서 해당 방향에서 return되는 값을 면적(newArea)에 더해준다  
인덱스를 벗어나거나 방문된 곳의 경우 더해주지 않는다  
return되는 값을 max값과 계속 비교하면서 max값을 구해낸다

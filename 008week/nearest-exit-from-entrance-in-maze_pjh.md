```kotlin
import java.util.LinkedList
import kotlin.math.min

fun main() {
    println(nearestExit(arrayOf(
        charArrayOf('+', '+', '.', '+'),
        charArrayOf('.', '.', '.', '+'),
        charArrayOf('+', '+', '+', '.'),
    ), intArrayOf(1, 2))) // 1

    println(nearestExit(arrayOf(
        charArrayOf('+', '+', '+'),
        charArrayOf('.', '.', '.'),
        charArrayOf('+', '+', '+'),
    ), intArrayOf(1, 0))) // 2

    println(nearestExit(arrayOf(
        charArrayOf('.', '+'),
    ), intArrayOf(0, 0))) // -1
}

fun nearestExit(maze: Array<CharArray>, entrance: IntArray): Int {
    val directions = listOf(0 to 1, 1 to 0, 0 to -1, -1 to 0)
    var result = Int.MAX_VALUE
    val queue = LinkedList<Triple<Int, Int, Int>>()
    val visited = Array(maze.size) { Array(maze[0].size) { false } }

    queue.add(Triple(entrance[0], entrance[1], -1))

    while (queue.isNotEmpty()) {
        val cur = queue.poll()

        if (cur.first !in maze.indices || cur.second !in maze[0].indices) {
            result = min(result, cur.third)
            continue
        }

        if (maze[cur.first][cur.second] == '+') continue
        if (visited[cur.first][cur.second]) continue

        visited[cur.first][cur.second] = true

        directions.forEach {
            queue.add(Triple(cur.first + it.first, cur.second + it.second, cur.third + 1))
        }
    }

    return result
}
```

bfs로 구현하려고 했습니다.  
먼저 queue에 시작 위치를 넣고 -1로 시작 후 외곽(인덱스를 벗어 나는 경우)으로 가게 되는 경우 result를 우선 int의 max값으로 해둔 후 최소 값을 비교하고  
만약에 이미 방문한 경로이거나 벽(+)인 경우는 다시 반복하지 않도록(queue에 들어가지 않도록)해서 답을 구하려고 했는데 조건이 조금 부족한 부분이 있는지 실패했습니다

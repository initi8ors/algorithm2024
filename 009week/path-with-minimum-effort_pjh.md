```kotlin
fun main() {
    println(minimumEffortPath(arrayOf(
        intArrayOf(1, 2, 3),
        intArrayOf(3, 8, 2),
        intArrayOf(5, 3, 5),
    )))

    println(minimumEffortPath(arrayOf(
        intArrayOf(1, 2, 3),
        intArrayOf(3, 8, 4),
        intArrayOf(5, 3, 5),
    )))

    println(minimumEffortPath(arrayOf(
        intArrayOf(1, 2, 1, 1, 1),
        intArrayOf(1, 2, 1, 2, 1),
        intArrayOf(1, 2, 1, 2, 1),
        intArrayOf(1, 2, 1, 2, 1),
        intArrayOf(1, 1, 1, 2, 1),
    )))

   // 4
    println(minimumEffortPath(arrayOf(
        intArrayOf(1, 10, 6, 7, 9, 10, 4, 9),
    )))
}

fun minimumEffortPath(heights: Array<IntArray>): Int {
    val directions = listOf(0 to 1, 1 to 0, 0 to -1, -1 to 0)
    val y = heights.size
    val x = heights[0].size
    val values = Array(y) { IntArray(x) { Int.MAX_VALUE } }
    val queue = LinkedList<Pair<Int, Int>>()
    var cur = 0 to 0

    values[0][0] = 0

    queue.add(cur)

    while (!queue.isEmpty()) {
        cur = queue.poll()

        directions.forEach {
            val newY = cur.first + it.first
            val newX = cur.second + it.second

            if (newY in heights.indices && newX in heights[0].indices) {
                val diff = abs(heights[newY][newX] - heights[cur.first][cur.second])

                if (diff < values[newY][newX]) {
                    queue.add(newY to newX)
                    values[newY][newX] = diff
                }
            }
        }
    }

    return values[y - 1][x - 1]
}
```

1. 현재까지 진행된 거리 값을 저장할 array를 만든다
2. 시작(0, 0)부터 진행하고 queue에 좌표를 저장
3. queue를 돌면서 가능한 인덱스 값 내에서, 현재 값과 다음 값의 계산 결과와 다음 인덱스의 거리 값을 비교하여 작은 값을 저장한다
4. 위 과정을 반복 후 가장 끝(오른쪽 아래)인덱스에 저장된 값을 반환

위 과정대로 진행했는데 4번째 테스트 케이스에서 실패했고, 방법을 찾지 못했습니다

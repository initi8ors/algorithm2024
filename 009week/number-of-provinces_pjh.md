```kotlin
fun findCircleNum(isConnected: Array<IntArray>): Int {
    val graph = HashMap<Int, MutableSet<Int>>()
    val visited = HashSet<Int>()

    isConnected.forEachIndexed { idx1, list ->
        list.forEachIndexed { idx2, _ ->
            if (isConnected[idx1][idx2] == 1) {
                graph.putIfAbsent(idx1, mutableSetOf(idx2))
                graph[idx1]?.add(idx2)
            }
        }
    }

    return findProvince(graph, visited)
}

fun findProvince(graph: Map<Int, MutableSet<Int>>, visited: HashSet<Int>): Int {
    var province = 0

    for (value in graph.keys) {
        if (!visited.contains(value)) {
            dfs(value, graph, visited)
            province++
        }
    }

    return province
}

fun dfs(value: Int, graph: Map<Int, MutableSet<Int>>, visited: HashSet<Int>) {
    visited.add(value)
    for (connected in graph[value] ?: emptySet()) {
        if (!visited.contains(connected)) {
            dfs(connected, graph, visited)
        }
    }
}
```

주어진 array를 기준으로 값이 `1`인 경우에 index값을 HashMap에 바깥쪽 idx를 key값으로 안 쪽 idx를 value로 넣는다  
HashMap의 key를 기준으로 루프를 돌면서 방문되지 않은 경우에 dfs를 돌고 `visited`에 index값을 추가해주면서 바문 여부를 확인한다  
dfs를 돌면서 province의 수를 셉니다

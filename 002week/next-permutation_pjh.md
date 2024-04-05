```kotlin
fun main() {
    nextPermutation(intArrayOf(1, 2, 3))
    nextPermutation(intArrayOf(3, 2, 1))
    nextPermutation(intArrayOf(1, 1, 5))
    nextPermutation(intArrayOf(6, 7, 5, 3, 5, 6, 2, 9, 1, 2, 7, 0, 9))
}

fun nextPermutation(nums: IntArray): Unit {
    val numbers = intArrayOf(*nums).sortedArray()
    val visited = Array(nums.size) { false }
    val permutations = LinkedHashSet<String>()

    permutation(numbers, visited, Array(nums.size) { 0 }, nums.size, 0, permutations)

    val index = permutations.indexOf(nums.joinToString(","))
    val nexIndex = if (index == permutations.size - 1) {
        0
    } else {
        index + 1
    }

    val result = IntArray(nums.size)

    permutations.elementAt(nexIndex).split(",").forEachIndexed { i, s ->
        result[i] = s.toInt()
    }

    result.copyInto(nums)
}

fun permutation(numbers: IntArray, visited: Array<Boolean>, result: Array<Int>, size: Int, count: Int, permutations: LinkedHashSet<String>) {
    if (size == count) {
        permutations.add(result.joinToString(","))
        return
    }

    numbers.forEachIndexed { i, num ->
        if (!visited[i]) {
            visited[i] = true
            result[count] = num
            permutation(numbers, visited, result, size, count + 1, permutations)
            visited[i] = false
        }
    }
}
```

모든 순열을 구한 뒤 해당 순열을 정렬 후 index를 찾고 그 다음 index의 값을 원래 array에 복사를 하려고 했으나
최대 100개의 원소를 가질 수 있는데 13개의 원소만 가지더라도 실패하는 타임아웃이 나서 실패했습니다..
테케만 통과했습니다

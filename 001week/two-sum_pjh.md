```kotlin
fun main() {
    println(twoSum(intArrayOf(2, 7, 11, 15), 9))
    println(twoSum(intArrayOf(3, 2, 4), 6))
    println(twoSum(intArrayOf(3, 3), 6))
}

// n^2
//fun twoSum(nums: IntArray, target: Int): IntArray {
//    for (i in 0 until nums.size - 1) {
//        for (j in i + 1 until nums.size) {
//            if (nums[i] + nums[j] == target) {
//                return intArrayOf(i, j)
//            }
//        }
//    }
//
//    return intArrayOf()
//}

// n
fun twoSum(nums: IntArray, target: Int): IntArray {
    val numMap = hashMapOf<Int, Int>()

    nums.forEachIndexed { i, num ->
        numMap[num] = i
    }

    nums.forEachIndexed { i, num ->
        val s = target - num

        numMap[s]?.let {
            return intArrayOf(i, it)
        }
    }

    return intArrayOf()
}
```

O(n^2)으로의 구현은 바깥 for문은 첫번째 요소부터 마지막의 앞(n-1번째)요소 까지 돌고
안쪽 for문은 바깥 포문의 시작 인덱스보다 1크게 돌면서 모든 array의 값을 돌면서 `target`과 일치 하는 경우 리턴하게 했습니다.

O(n)으로 구현하려고 했던 방법은 우선 모든 요소의 값을 map(value: index)으로 만들어서 해당 값을 key로 만듭니다
그 다음은 다시 array를 돌면서 `target - nums[i]` 의 값이 map에 있는지 찾은후 해당 index들로 return하려고 했습니다.
같은 요소의 값을 어떻게 처리 해야할지 실제로 구현은 실패했으며 만약에 실제로 된다면 O(2n)이지만 이또한 O(n)이기 때문에 O(n)으로 구현이 됐을거라고 생각합니다. 

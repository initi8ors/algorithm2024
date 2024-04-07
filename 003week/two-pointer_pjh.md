# 투 포인터(Two pointers)

- 하나의 리스트, 1차원 배열 등에서 각각 다른 원소를 가리키고 있는 2개의 포인터를 조작하여 해를 찾는 알고리즘이다

## 문제 해결 방법
- 양끝을 시작(left or start)과 끝(right or end)의 인덱스로 각각의 포인터를 잡는다
- 찾아야 하는 값에 따라서 시작 값을 늘리거나 끝 값을 줄이는 과정을 반복하여 값을 찾는다
- 끝 인덱스 값이 시작 인덱스 값보다 크거나 같은(끝 인덱스 >= 시작 인덱스)동안만 반복하게 된다
- 시간 복잡도는 최악의 경우 *O(n)*

```kotlin
fun twoSum(nums: IntArray, target: Int): IntArray {
    val sorted = nums.sortedArray()
    var s = 0
    var e = nums.size - 1
    var sNumber = sorted[s]
    var eNumber = sorted[e]

    while (e >= s) {
        val sum = sorted[s] + sorted[e]
        sNumber = sorted[s]
        eNumber = sorted[e]

        if (sum > target) {
            e--
        } else if (sum < target) {
            s++
        } else {
            break
        }
    }

    val result = IntArray(2) { 0 }

    nums.forEachIndexed { i, value ->
        if (result[0] == 0 && sNumber == value) {
            result[0] = i
        }

        if (result[1] == 0 && eNumber == value && result[0] != i) {
            result[1] = i
        }
    }

    return result
}
```

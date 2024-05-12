```kotlin
fun main() {
    merge(intArrayOf(1, 2, 3, 0, 0, 0), 3, intArrayOf(2, 5, 6), 3)
    merge(intArrayOf(1), 1, intArrayOf(), 0)
    merge(intArrayOf(0), 0, intArrayOf(1), 1)
}

fun merge(nums1: IntArray, m: Int, nums2: IntArray, n: Int): Unit {
    var index1 = m - 1
    var index2 = n - 1
    var i = m + n - 1

    while (index1 > -1 && index2 > -1) {
        if (nums1[index1] < nums2[index2]) {
            nums1[i--] = nums2[index2--]
        } else {
            nums1[i--] = nums1[index1--]
        }
    }

    if (index1 > -1) {
        while(index1 > -1) {
            nums1[i--] = nums1[index1--]
        }
    }

    if (index2 > -1) {
        while(index2 > -1) {
            nums1[i--] = nums2[index2--]
        }
    }
}
```

nums1에 채워주기 위해서 인덱스를 앞이 아닌 맨 뒤부터 시작한다.
index를 앞에서부터 시작하게 되면 nums1의 값이 바뀌게 되면서 값이 이상하게 섞일 수 있다.
index1, index2 둘 중 하나가 안 끝났었을 수 있으므로 따로 while문을 다시 한 번 돌린다.

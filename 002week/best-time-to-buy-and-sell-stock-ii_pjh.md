```kotlin
fun maxProfit(prices: IntArray): Int {
    var max = 0

    prices.forEachIndexed { i, price ->
        val result = Array(prices.size) { 0 }

        search(prices, price, i, prices.size, 0, 0, result)

        if (result.last() > max) {
            max = result.last()
        }
    }

    return max
}

fun search(prices: IntArray, curValue: Int, cur: Int, size: Int, count: Int, profit: Int, result: Array<Int>) {
    if (size == cur) {
        if (profit > result[size - 1]) {
            result[size - 1] = profit
        }

        return
    }

    for (i in cur + 1 until size) {
        val nextValue = prices[i]

        if (nextValue > curValue) {
            if (i + 1 < size) {
                val newProfit = profit + (nextValue - curValue)

                if (newProfit > result[i]) {
                    result[i] = newProfit
                }

                search(prices, prices[i + 1], i + 1, size, count + 1, newProfit, result)
            }
        }

        search(prices, curValue, i + 1, size, count + 1, profit, result)
    }
}
```

접근 방법은 현재 주식 값에서 현재 보다 다음 원소가 가격이 높다면 판매, 맞거나 아니더라도 다음 주식 값으로 이동 하여
가장 이익이 많이 나오는 값을 다음 index에 저장 시키면서 가장 마지막 index값에 가장 이익이 많이 남는 값을 저장하려고 했습니다.
그러나.. 구현 실패입니다.

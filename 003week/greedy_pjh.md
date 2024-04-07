# 탐욕(Greedy) 알고리즘

- 현재 상황에서 고를 수 있는 최적의 이라고 생각 되는 것으로 선택하여 최적이 아닌 적합한 결과를 도출한다
- 모든 케이스를 고려 하는 것이 아니다 보니 상황 마다 선택되는 최적의 값이 최종적인 최적의 해가 될 수는 없다
- 보통 그리디 알고리즘을 적용하는 문제는 부분적으로 최적인 해를 구하는것이 최종적으로도 최적의 해가 나올 수 있는 문제이다

## 문제 해결 방법
- 선택 절차: 현재 상태에서 최적의 해답을 선택 
- 적절성 검사: 선택된 해가 문제의 조건을 만족하는지 검사 
- 해답 검사: 원래의 문제가 해결되었는지 검사 후 해결되지 않았다면 선택 절차로 돌아가 위의 과정을 반복

## Greedy 알고리즘을 적용하기 위한 2가지 조건
- Greedy 알고리즘을 적용할 수 있는 문제는 대부분의 탐욕스런 조건(greedy choice property)과 최적 부분 구조라는 두 조건이 만족해야 한다
- 탐욕스런 선택 조건은 앞의 선택이 이후의 선택에 영향을 주지 않고 최적 부분 구조 조건은 문제에 대한 최적해가 부분문제에 대해서도 역시 최적해라는 것이다

알고리즘 문제로서는 greedy 알고리즘이 결론적으로는 최적의 해를 구하게 되겠지만, 만약 실무에서 greedy 알고리즘을 사용해야 할 경우가 생긴다면 그게 최적의 해가 아니라는 것을 감안하고 써야 할 것 같다

```kotlin
fun main() {
    println(maxProfit(intArrayOf(7, 1, 5, 3, 6, 4)))
    println(maxProfit(intArrayOf(1, 2, 3, 4, 5)))
    println(maxProfit(intArrayOf(7, 6, 4, 3, 1)))
}

fun maxProfit(prices: IntArray): Int {
    var result = 0
    var owned = prices[0]
    var max = prices[0]

    for (i in 1 until prices.size) {
        val cur = prices[i]

        if (cur < max) {
            result += max - owned

            owned = cur
            max = cur
        } else {
            max = cur

            if (i == prices.size - 1) {
                result += max - owned
            }
        }
    }

    return result
}
```

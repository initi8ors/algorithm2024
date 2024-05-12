# 문제
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
123. Best Time to Buy and Sell Stock III

# solution
```java
class Solution {
    public int maxProfit(int[] prices) {
        int result = 0;

        int[] leftProfit = new int[prices.length];
        int[] rightProfit = new int[prices.length];
        int leftMin = prices[0];
        int rightMax = prices[prices.length - 1];

        leftProfit[0] = 0;
        for (int i = 1; i < leftProfit.length; i++) {
            leftProfit[i] = leftProfit[i - 1];
            if (prices[i] >= leftMin) {
                leftProfit[i] = Math.max(leftProfit[i - 1], prices[i] - leftMin);
            } else if (prices[i] <= leftMin) {
                leftMin = prices[i];
            }
        }

        int length = prices.length;
        rightProfit[0] = 0;
        for (int i = 1; i < rightProfit.length; i++) {
            rightProfit[i] = rightProfit[i - 1];
            if (prices[length - i - 1] <= rightMax) {
                rightProfit[i] = rightMax - prices[length - i - 1];
            } else if (prices[length - i - 1] >= rightMax) {
                rightMax = prices[length - i - 1];
            }
        }

        for (int i = 0; i < leftProfit.length; i++) {
            result = Math.max(result, leftProfit[i] + rightProfit[rightProfit.length - i - 1]);
        }

        return result;
    }
}
```

# 풀이
DP bottom up 방식으로 품

첫 아이디어 실패\
수익을 DP로 저장하는건 가능하다고 하더라도 그중 겹치지 않는 기간동안에 구매한 2번의 수익을 얻는 방법이 점화식으로 떠오르지 않음\
주식거래는 동시에 사고 파는건 안되고 2번에 나누어서 구매/판매를 해야 하기 때문\
이점을 이용 사고 판 구간을 나누어 계산하기로 함

총 2번의 거래가 있기 때문에 첫 거래 A구간과 두번째 거래 B구간으로 나눔

주식 가격\
1,2,3,4,5,6

알고리즘 순서\
A구간이 1 일 때는 B구간은 2,3,4,5,6 → 1번\
A구간이 1,2 일 때는 B구간은 3,4,5,6 → 2번\
A구간이 1,2,3 일 때는 B 구간은 4,5,6 - 3번\
…\
A구간이 1,2,3,4,5 일 때는 B 구간은 6 → N번\
A구간의 최대 값과 B 구간의 최대값을 구한 뒤 1~N번의 구간중 최대값을 구함\

각 구간의 최대값을 구하는 방법\
A구간이 1일때의 최대값 → 1\
A구간이 1,2일때의 최대값

1. 직전 값의 최소값, 최대값을 기억합니다.
2. 직전 값의 최소값보다 값이 더 낮아졌을 경우 최소값을 갱신합니다.
3. 직전 값의 최대값보다 값이 더 높아졌을 경우 최대값을 갱신합니다.
4. 수익을 계산해 구간의 DP값을 갱신합니다.

위 과정을 반복합니다.

예상되는 시간복잡도는 O(N)입니다.
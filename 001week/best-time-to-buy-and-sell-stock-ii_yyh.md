# 문제
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150
122. Best Time to Buy and Sell Stock II

# solution
```agsl
class Solution {
    public int maxProfit(int[] prices) {
        int buy = prices[0];
        int sell = prices[0];
        int result = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] < sell) {
                result += sell - buy;
                buy = prices[i];
                sell = prices[i];
            } else if (prices[i] > sell) {
                sell = prices[i];
            }
        }
        result += sell - buy;
        return result;
    }
}
```

# 풀이
가장 싸게 구매한 주식 p1(buy)\
가장 비싸게 판매할 주식 p2(sell)\
두개의 포인터를 만들어서 관리합니다

수익 실현을 하는 포인트가 두 곳 있습니다

1. 최고점을 만났을 때
2. 마지막 날

주식이 1에서 구매하고 이후 최고점이 5일 때 다음 주식 가격이 3으로 하락할 경우 5를 판매하고 3을 구매합니다\
이 때 구매한 주식 1을 5에 판매하므로 4의 수익이 생깁니다.


3으로 구매한 날이 마지막일 경우 3의 주식을 다시 판매합니다.\
3 - 3 = 0으로 수익은 0으로 끝납니다.

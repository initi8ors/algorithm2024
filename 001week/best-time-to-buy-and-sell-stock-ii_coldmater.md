# 문제 정보

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

# 첫번째 시도

## 아이디어

각 prices 의 요소마다 다음 price 로 진행하기 전에 3가지 분기를 수행한다. 사거나, 팔거나, 아무것도 하지 않거나.
그렇게 되면 문제의 조건에 따라 $3^{3*10^{4}}$개 만큼의 명령이 수행될 것이므로, DP 로 이미 수행된 연산은 다시 연산하지 않는 전략을 취한다.

## 소스코드

```cpp
short dp[30001][30001];
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // memset(dp, -1, sizeof(short) * 30001 * 30001);
        int res = go(0, -1, 0, prices);
        return res;
    }
private:
    int go(int i, int bi, int tp, vector<int>& prices) { // i: index, bi: buying index(-1: not holding), tp; total profit
        if (dp[i][bi + 1]) {
            cout << "i: " << i << ", bi: " << bi << ", dp[i][bi]: " << dp[i][bi + 1] << " Is in DP!\n";
            return dp[i][bi + 1];
        }
        if (i == prices.size() - 1) {
            // cout << "DONE -- " << "i: " << i << ", bi: " << bi << ", tp: " << tp << "\n";
            if (bi != -1) return tp + (prices[i] - prices[bi]);
            else return tp;
        }

        // buying
        int bp = 0;
        if (bi == -1) {
            bp = go(i + 1, i, tp, prices); // buying profit
        }

        // not trading
        int ntp = go(i + 1, bi, tp, prices); // ntp not trading profit

        // selling
        int sp = 0;
        if (bi != -1) {
            int profit = prices[i] - prices[bi];
            sp = go(i + 1, -1, tp + profit, prices); // selling profit
        }

        // if (i == 4) {
        //     cout << "i: " << i << ", bi: " << bi << ", tp: " << tp << " (" << bp << ", " << ntp << ", " << sp << ")\n";
        // }

        int p = max(max(bp, max(ntp, sp)), 0); // profit
        if (bi != -1) {
            cout << "i: " << i << ", bi: " << bi << ", profit: "<< p << " Saving on DP!\n";
            dp[i][bi + 1] = p;
        }
        return p;
    }
};
```

## 한계

dp 로 이미 수행된 연산을 수행하지 않는 아이디어는, 이 문제에는 적절하지 않다. 왜냐하면, 최댓값을 찾아야 하는데, 이미 수행된 연산을 대신 활용하면 최댓값이 아닐 수 있는 문제가 있다.

# 두번째 시도

## 아이디어

DP 와, 백트래킹 방법을 활용한다. 매 index 마다 선택지는 3가지이다. 사거나, 팔거나, 보류한다. 주식을 보유한 상태가 아니라면 사거나, 보류할 수 있고, 주식을 보유한 상태라면 팔거나, 보류할 수 있다. 이런 방식으로 매 순간 2가지의 선택지가 생길 것이므로, $2^{10^4}$ 만큼의 경우의 수가 생길 것이다. 특정 구간에 대한 연산은 다시 할 필요가 없을 것이므로 DP 를 활용하여, 특정 index 에서 동일한 상태라면 최댓값을 계산하지 않고, 저장된 값을 활용한다.

## 소스코드

```cpp
short dp[30001][30001];
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // memset(dp, -1, sizeof(short) * 30001 * 30001);
        int res = go(0, -1, 0, prices);
        return res;
    }
private:
    int go(int i, int bi, int tp, vector<int>& prices) { // i: index, bi: buying index(-1: not holding), tp; total profit
        if (dp[i][bi + 1]) {
            cout << "i: " << i << ", bi: " << bi << ", dp[i][bi]: " << dp[i][bi + 1] << " Is in DP!\n";
            return dp[i][bi + 1];
        }
        if (i == prices.size() - 1) {
            // cout << "DONE -- " << "i: " << i << ", bi: " << bi << ", tp: " << tp << "\n";
            if (bi != -1) return tp + (prices[i] - prices[bi]);
            else return tp;
        }

        // buying
        int bp = 0;
        if (bi == -1) {
            bp = go(i + 1, i, tp, prices); // buying profit
        }

        // not trading
        int ntp = go(i + 1, bi, tp, prices); // ntp not trading profit

        // selling
        int sp = 0;
        if (bi != -1) {
            int profit = prices[i] - prices[bi];
            sp = go(i + 1, -1, tp + profit, prices); // selling profit
        }

        // if (i == 4) {
        //     cout << "i: " << i << ", bi: " << bi << ", tp: " << tp << " (" << bp << ", " << ntp << ", " << sp << ")\n";
        // }

        int p = max(max(bp, max(ntp, sp)), 0); // profit
        if (bi != -1) {
            cout << "i: " << i << ", bi: " << bi << ", profit: "<< p << " Saving on DP!\n";
            dp[i][bi + 1] = p;
        }
        return p;
    }
};
```

## 한계

200 개의 테스트케이스 중 199 개를 통과할 수 있었지만, 나머지 1개 (실제 prices 가 $10^{4}$개인 경우) 는 시간초과로 통과하지 못했다.

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
주어진 인덱스 범위 안에서(함수 인자로 받음) 한 번씩만 사고 팔아 최대 수익을 얻는 함수를 만든다. 이는 O(n) 시간복잡도 내에 가능할 것으로 생각되는데, 한 번 순회할 때마다 최소값을 대체하고, 매 요소마다 해당 최소값과의 차이를 비교하면 최대 수익을 알아낼 수 있다.

이렇게 주어진 배열을 한 번 순회하여 최댓값을 찾아내면서, 산 곳의 index 와 판 곳의 index 를 기록한다. 그럼 이전에 사고 팔았던 영역을 제외하고 나머지 부분이 생겨나는데, 해당 부분에 대해서 다시 위에서 정의한 함수를 호출하게 한다. 

호출된 모든 함수의 합을 가지고 최대 수익을 계산해낼 수 있다.

## 소스코드
문제 풀이 전
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
# 문제 정보

# 첫번째 시도

## 아이디어

주어진 배열을 재귀적으로 진행하며, 문자로 디코딩할 수 있는지를 판단하고 가능한 조합만큼 분기 처리를 진행한다. 각 조합의 분기에서 반환된 조합의 개수를 더하여 반환한다.

종료조건은 인덱스의 범위가 초과되었을 때이거나, 디코딩 할 수 없는 상태(0으로 시작하는 코드)를 만났을 때이다.

각 인덱스에서의 연산을 DP 에 저장하고, 해당 인덱스의 연산은 그 인덱스에서의 카운트라고 볼 수 있으므로, 다시 계산할 필요가 없으므로 DP 에서 불러온다.

## 소스코드

```cpp
class Solution {
public:
    int dp[101];
    int go (int i, string s) {
        // DP 불러오는
        if (dp[i] != -1) return dp[i];
        if (i >= s.size()) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }

        int cnt = 0;
        // cout << s[i] << ":\n";
        if (i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            // cout << "jump jump " << s[i] << s[i+1] << "\n";
            // cout << s[i] << " " << s[i + 1] << "\n";
            int r = go(i + 2, s);
            // cout << "r: " << r << "\n";
            cnt += r;
        }
        // cout << "normal go " << s[i] << "\n";
        int res = go(i + 1, s);
        // cout << "s[i]: "<< s[i] << " res: " << res << "\n";
        cnt += res;
        // DP 에 저장하는
        dp[i] = cnt;
        return cnt;
    }

    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return go(0, s);
    }
}
```

# 문제 정보

https://leetcode.com/problems/partition-array-for-maximum-sum/

# 첫번째 시도

## 아이디어

주어진 배열에서 인덱스를 증가시켜가며 새로운 파티션을 시작할지, 이전 파티션에 포함시킬지를 결정한다.

새로운 파티션을 시작해야 하는 경우, 이전 파티션의 계산값(부분 배열의 가장 큰 원소로 모든 원소를 대체하여 합계 계산)을 계산한 뒤, 다음 index 를 호출한다.

종료조건은, 인덱스가 배열의 사이즈를 넘었을 때이고, 이 때에는 그 전 파티션에 대해서 계산값을 수행해준다.

단순하게는, 매 index 마다 새로운 파티션으로 할지, 이전 파티션에 포함할지와 같이 2가지 기준으로 분기되므로 $2^{500}$ 의 시간복잡도를 가지게 될 것이므로, DP 적인 접근이 필요하다. 매 index 에서의 go() 함수의 반환값은, 그 index 부터의 mamimum sum 은 최대가 되도록 계산하여, 동일하게 해당 인덱스에 접근시 다시 계산할 필요가 없도록 한다.

## 소스코드

```cpp
class Solution {
public:
    int dp[500][500];
    int go(vector<int>& arr, int k, int i, int pi) { // pi: right previous partition index
        // if (i > 499) cout << "i 499!!, i: " << i << "\n";
        if (dp[i][pi] != -1) return dp[i][pi]; // why this line shoudn't be at the first line of the block of go()? - overflow... 'i' can be 500 but, first dp was dp[500][500] -> memory reference fault

        if (i == arr.size()) {
            int submax = 0;
            for (int j = pi; j < i; ++j) {
                submax = max(submax, arr[j]);
            }
            // cout << "submax: " << submax << "\n";
            // dp[i][pi] = submax * (i - pi);
            return submax * (i-pi);
        }


        // include this element to previous partition
        int left = 0;
        int groupCount = i - pi;
        if (groupCount < k && i != 0) {
            left = go(arr, k, i + 1, pi); // maintain partition number to join this element to that group
        }

        // put new partition
        // 1. change subarray's values to maximum value of that subarray
        // 2. sum up them
        // 3. when return value come, then sum that return value and return.

        // TODO sum logic
        int right = 0;

        int submax = 0;
        for (int j = pi; j < i; ++j) {
            submax = max(submax, arr[j]);
        }
        int sum = submax * (i - pi);
        right = sum + go(arr, k, i + 1, i); // 'i' means put partition on left of this element.

        dp[i][pi] = max(left, right);
        // if (i >= 4 && i) {
        //     cout << "i: " << i << "\n";
        //     cout << "pi: " << pi << "\n";
        //     cout << "left: " << left << "\n";
        //     cout << "right: " << right << "\n\n";
        // }
        return dp[i][pi];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return go(arr, k, 0, 0);
    }
};
```

## 한계

제출 후 모든 테스트케이스에 대해서 통과하지는 못하였는데, 결과값과 기대값의 차이를 계산해보니 결과값에 마지막 원소의 값이 한 번 더 더해진 형태로 계산되었다. 종료조건에서 문제가 발생하였을 것이다.

# 두번째 시도

## 아이디어

종료조건쪽에서 문제의 원인을 찾아보도록 한다. 종료조건에서 인덱스의 콘솔을 찍어봤더니, index 가 500이 되는 순간이 있다. 그러나 이 값은 -1 이 아닐 확률이 크고(memset 의해 초기화되지 않은, dp 배열의 메모리 범위를 벗어나는) 이에 따라 의도치 않은 연산이 추가로 일어났따.

## 소스코드

### 교정1

dp 범위를 arr 의 크기보다 1 더 크게 잡아준다. (재귀함수에서는 index 가 arr 범위를 한 번 초과함)

```cpp
// 이외의 코드는 첫번째 아이디어의 소스코드와 동일
    int dp[501][501];
```

### 교정2

dp 판정 위치를 종료조건 밑에 위치 (index 가 배열 범위를 초과할 때에는 종료조건에 의해 먼저 반환되도록 함)

```cpp
// 이외의 코드는 첫번째 아이디어의 소스코드와 동일
        if (i == arr.size()) {
            int submax = 0;
            for (int j = pi; j < i; ++j) {
                submax = max(submax, arr[j]);
            }
            // cout << "submax: " << submax << "\n";
            // dp[i][pi] = submax * (i - pi);
            return submax * (i-pi);
        }

        if (dp[i][pi] != -1) return dp[i][pi]; // why this line shoudn't be at the first line of the block of go()? - overflow... 'i' can be 500 but, first dp was dp[500][500] -> memory reference fault
```

## 한계

제출 후 정답들의 분포를 보니 1~5ms 에도 풀리는 것으로 보인다. 하지만, 이 해법은 166ms 만큼의 시간이 걸린다.

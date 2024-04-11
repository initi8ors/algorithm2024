# 문제 정보

https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

# 첫 번째 시도

## 아이디어

xor 연산은 이항연산이며, 결합법칙 및 교환법칙이 성립한다.

1. $a \oplus b = c$
2. $a \oplus b \oplus b = c \oplus b$
3. $a \oplus (b \oplus b) = c \oplus b$
4. $a \oplus (0) = c \oplus b$
5. $a = c \oplus b$

따라서 문제에서 결과의 각 `result[i]` 는 `result[0]` 부터 `result[i-1]` 까지의 `xor` 로 알아낼 수 있다.

## 소스코드

```cpp
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> r;
        r.push_back(pref[0]);

    for (int i = 1; i < pref.size(); ++i) {
            cout << r[i - 1] << "\n";

            int j = r.size() - 1;
            int temp = pref[i];
            while(j >= 0) {
                temp ^= r[j--];
            }
            r.push_back(temp);
        }

        return r;
    }
};
```

## 한계

시간초과: $O(n^2)$ 보다 더 낮은 시간복잡도 안에서 해결되어야 한다.

# 두 번째 시도

## 아이디어

결정적 아이디어는 같은 숫자가 짝수번 xor 연산되었을 때 $0$ 이 된다는 사실이고, 이는 다른 수와 XOR 연산되었을 때 연산된 수가 그대로 나온다는 부분이다. -> 반복된 연산을 되풀이 할 필요가 없다. (e.g., `5 ^ 5 ^ 5 ^ 5 ^ 5 = 5`)

또한, 문제에 주어진 식을 정리하면 아래와 같다.

```text
a. pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]

b. pref[i] = pref[i - 1] ^ arr[i]

c. pref[i] ^ pref[i - 1] = arr[i]
```

## 소스코드

```cpp
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> r;
        r.push_back(pref[0]);

        for (int i = 1; i < pref.size(); ++i) {
            r.push_back(pref[i] ^ pref[i-1]);
        }

        return r;
    }
}
```

# 문제
https://leetcode.com/problems/circular-permutation-in-binary-representation/description/
1238. Circular Permutation in Binary Representation

# solution
```java
class Solution {
    public List<Integer> circularPermutation(int n, int start) {
        int[] nArr = new int[16];
        nArr[0] = 1;
        for (int i = 1; i < 16; i++) {
            nArr[i] = nArr[i - 1] * 2;
        }

        int num = 1;
        for (int i = 0; i < n; i++) {
            num += nArr[i];
        }

        Integer[] arr = new Integer[num];
        for (int i = 0; i < num; i++) {
            arr[i] = i;
        }

        permutation(arr, 0, num, start);

        return Arrays.asList(arr);
    }

    boolean permutation(Integer[] arr, int depth, int n, int start) {
        if (arr[0] == start && depth == n) {
            boolean result = true;
            for (int i = 1; i < n; i++) {
                if (Integer.bitCount(arr[i - 1] ^ arr[i]) != 1) {
                    result = false;
                }
            }
            if (result) {
                return true;
            }
        }


        for (int i=depth; i<n; i++) {
            swap(arr, depth, i);
            if (permutation(arr, depth + 1, n, start)) return true;
            swap(arr, depth, i);
        }

        return false;
    }

    void swap(Integer[] arr, int depth, int i) {
        int temp = arr[depth];
        arr[depth] = arr[i];
        arr[i] = temp;
    }
}
```

# 풀이
퍼뮤테이션에 조건을 추가하여 풀이

조건 1.\
start부터 시작해야 한다.

조건 2.\
다음 값은 1bit만 차이나야 한다.

### 알고리즘 설명

#### 전처리 작업(데이터 준비)
1. n >= 1 and n <= 16 조건에 맞춰 n이 주어졌을 때 구해야 하는 퍼뮤테이션 값을 쉽게 계산하기 위해 nArr을 준비
2. nArr을 이용해 num(퍼뮤테이션 길이)값을 구함 (ex: 3일 경우 3자리수이므로 4 + 2 + 1 = 7자리의 퍼뮤테이션 값이 된다.)

#### 1비트만 차이나는지 확인하기 위해 xor 연산자와 Integer.bitCount 메소드 활용\
ex)101, 111 두 값이 1bit만 차이나는지 확인하기
1. 먼저 xor 연산을 합니다. 서로 다른 값만 1이 남습니다. (010)
2. Integer.bitCount를 이용해 binary data에서 1의 개수를 셉니다.
3. 010은 1의 개수가 1이기 때문에 서로 틀린 부분은 1개입니다.

### 시간복잡도
일반적인 퍼뮤테이션의 시간복잡도 O(N^2)과 다를게 없음.
n = 16이므로 시간초과 시간단축을 위한 방법이 필요할 것 같음
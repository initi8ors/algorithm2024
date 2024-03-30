# 문제
https://leetcode.com/problems/next-permutation/
31. Next Permutation

# solution 
```agsl
class Solution {
    private int memory = 0;
    private int cnt = 0;
    private boolean stop = false;

    public void nextPermutation(int[] nums) {
        int n = nums.length;

        // 정순 array
        int[] sortArr = nums.clone();
        Arrays.sort(sortArr);

        // 역순 array
        int[] reverseArr = new int[n];
        for (int i = 0; i < n; i++) {
            reverseArr[i] = sortArr[n - i - 1];
        }

        boolean flag = Arrays.equals(nums, reverseArr);
        if (flag) {
            this.copyArr(nums, sortArr);
            return;
        }

        int[] arr = new int[nums.length];
        boolean[] visit = new boolean[nums.length];
        perm(sortArr, arr, nums, visit, 0, nums.length);
    }

    private void perm(int[] sortArr, int[] arr, int[] nums, boolean[] visit, int depth, int n) {
        if (stop) return;
        if (depth == n) {
            if (cnt++ == 1) {
                this.copyArr(nums, arr);
                stop = true;

            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (memory < n) {
                memory++;
                for (int j = n - 1; j >= 0; j--) {
                    if (!visit[j] && nums[depth] == sortArr[j]) {
                        i = j;
                        break;
                    }
                }
            }

            if (!visit[i]) {
                visit[i] = true;
                arr[depth] = sortArr[i];
                perm(sortArr, arr, nums, visit, depth + 1, n);
                visit[i] = false;
            }
        }
    }

    private void copyArr(int[] arr1, int[] arr2) {
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = arr2[i];
        }
    }
}
```

# 풀이
1차 시도 permutation을 구현하여 next permutation을 구하는 숫자를 찾을때까지 탐색\
다음 permutation을 구하려 했지만 timeout으로 실패

2차 시도 visit과 depth를 재현한 뒤 시작하도록 함\
ex) [3,1,2] 일 경우
depth 0은 index는 2 depth는 0임
depth 1은 index는 0 depth는 1임
depth 2는 index는 1 depth는 2임
index와 depth를 재현한 뒤 다음 permutation을 찾았지만 같은 숫자가 있는 경우 문제는 최대 permutation의 다음 값을 원하기 때문에 실패

3차 시도 permutation숫자를 오른쪽부터 재현\
index를 찾는 배열(sortArr)이 오름차순이기 때문에 가장 오른쪽부터 꺼내면 가장 큰 permutation을 구할 수 있음
한번 꺼낸 숫자는 visit을 이용해 패스하고 다음 숫자를 찾음
결과적으로 같은 숫자라고 하더라도 가장 큰 숫자의 permutation을 구할 수 있게 됨
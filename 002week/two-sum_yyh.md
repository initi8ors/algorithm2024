# 문제
https://leetcode.com/problems/two-sum
1. Two Sum

# solution 1
```agsl
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        boolean flag = true;
        for (int i = 0; i < nums.length; i++) {
            for (int j = nums.length - 1; j > 0; j--) {
                if (i != j && nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
        return null;
    }
}
```

# 풀이
브루트 포스로 풀이\
같은 숫자의 합이 target이 경우가 있어서 i와 j가 같을 때 패스하도록 해야합니다.

이중 for문으로 해결해서 시간복잡도는 O(n^2)이 되어서 효율은 좋지 않습니다.


# solution 2
```agsl
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] clone = nums.clone();
        Arrays.sort(nums);
        int lNumber = nums[0];
        int rNumber = nums[nums.length - 1];
        int lIndex = 0;
        int rIndex = nums.length - 1;

        int[] result = new int[2];
        while(lIndex != rIndex) {
            int sum = nums[lIndex] + nums[rIndex];
            if (sum == target) {
                lNumber = nums[lIndex];
                rNumber = nums[rIndex];
                break;
            } else if (sum < target) {
                lIndex++;
            } else {
                rIndex--;
            }
        }

        for (int i = 0; i < clone.length; i++) {
            if (clone[i] == lNumber) {
                result[0] = i;
            }
            if (clone[clone.length - i - 1] == rNumber) {
                result[1] = clone.length - i - 1;
            }
        }
        
        return result;
    }
}
```

# 풀이
투포인터 이용\
정답이 되는 index를 리턴해야 하기 때문에 array를 복사하여 정답용, index 찾기용으로 나눕니다.\
array 하나를 정렬해 포인터 2개를 만들어 왼쪽과 오른쪽끝에서 탐색을 시작합니다.\
두 포인터에 있는 값의 합이 target보다 작다면 왼쪽 포인터를 1 증가, target보다 크다면 오른쪽 포인터를 1 감소시킵니다.\
정답을 찾은 후 index용 array에서 값에 해당하는 index를 찾습니다.
시간복잡도는 정렬과 index를 찾는 반복문을 제외하면 O(n)을 예상합니다.

# solution 3
```agsl
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }

        for (int i = 0; i < nums.length; i++) {
            Integer idx = map.get(target - nums[i]);
            if (idx == null || idx == i) continue;
            result[0] = idx;
            result[1] = i;
        }

        return result;
    }
}
```

# 풀이
HashMap 이용\
array의 정답을 hashmap에 담은 뒤 target - array(index)를 map에서 찾습니다.\
찾은 값이 같은 숫자일 경우 index가 겹칠 수 있으니 이경우 패스합니다.
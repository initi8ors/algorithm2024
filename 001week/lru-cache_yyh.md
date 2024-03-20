# 문제
https://leetcode.com/problems/lru-cache/
146. LRU Cache

# solution
```agsl
class LRUCache {
    LinkedHashMap<Integer, Integer> linkedHashMap;
    int capacity;
    public LRUCache(int capacity) {
        this.capacity = capacity + 1;
        this.linkedHashMap = new LinkedHashMap<>(this.capacity);
    }

    public int get(int key) {
        Integer value = this.linkedHashMap.get(key);
        if (value == null) {
            return -1;
        }
        this.linkedHashMap.remove(key);
        this.linkedHashMap.put(key, value);
        return value;
    }

    public void put(int key, int value) {
        if (this.linkedHashMap.get(key) != null) {
            this.linkedHashMap.remove(key);
        }
        this.linkedHashMap.put(key, value);
        if (this.linkedHashMap.size() == capacity) {
            this.linkedHashMap.remove(this.linkedHashMap.keySet().iterator().next());
        }
    }
}
```

# 풀이
2가지 조건을 만족해야 합니다.
1. cache를 위해서 key, value 기반의 저장소가 필요
2. 만료를 위해서 먼저 저장된 순서 저장

키 저장소를 위해서 HashMap을 순서를 위해서 List를 활용할 수 있습니다.\
두가지 특성을 모두 가지고 있는 ListHashMap을 이용하여 구현해 풀어봤습니다.

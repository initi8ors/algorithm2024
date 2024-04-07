# 문제: LRU Cache

https://leetcode.com/problems/lru-cache/description/

# 첫번째 시도

## 아이디어

put() 과 get() 이 O(1) 에 수행되어야 한다는 문제의 조건으로부터, 캐시로부터 값을 가져오는 것은 hash table 을 활용해야겠다고 생각할 수 있었다. 하지만, 어떻게 least recently used 값을 저장할 수 있을지 적절한 자료구조를 떠올릴 수 없었다. (heap 자료구조를 구성하여 root node 에 방출될 값을 저장하는 방식을 생각하였지만, 이는 자료를 넣을 때 O(logN) 만큼의 시간복잡도를 가진다.)

## 소스코드

구현하지 않음

## 한계

**자료구조를 단 하나만 써야 한다는 강박**을 가질 필요는 없었다.

# 두번째 시도

## 아이디어

(1주차 스터디를 진행하여, 다른 스터디원들의 아이디어를 들은 뒤에) 첫번째 시도의 아이디어로부터 결국 두 가지 자료구조를 함께 활용하는 것으로 값을 가져올 때 O(1), 값을 저장할 때 O(1) 으로도 처리를 수행할 수 있음을 알 수 있었다.

LRU 는 일종의 방출(evict)되어야 하는 대상이 끝에 노출되어 있는 형태의 자료구조이어야 한다. 그런 의미에서 head, tail 포인터가 있으면 적절할 것이다. 구조의 업데이트가 일어날 때에도 시간복잡도는 여전히 O(1) 이어야 한다. -> Linked List 자료구조가 적절하다.

캐시에 값이 저장될 때마다 Linked List 에 값을 push_back(O(1)) 한다. 그리고 특정 값의 참조가 발생했을 때, 그 노드를 삭제하고(Linked List 의 노드 삭제 - O(1)) 다시 값을 push_back 한다.

Linked List 만으로는 값의 참조가 O(N) 이 소요될 것이므로, 값을 가져오는 자료구조는 hash table 로 하고, 값의 삽입이 발생했을 떄는 hash table 에도 같이 값을 저장해주고, 값을 get 하는 것은 hash table 을 활용한다.

## 소스코드

```cpp
class LRUCache {
public:
    int size;
    map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>>  l;
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        // Get value from the hash table.
        if (m.find(key) == m.end()) {
            return -1;
        }

        // Get node from the hash table.
        list<pair<int, int>>::iterator node = m.find(key)->second; // return type of find (of map) is `pair(key, value)`
        int v = node->second;

        // Update recently used list information.
        l.push_back({ key, v });
        list<pair<int,int>>::iterator i = l.end(); i--;
        l.erase(node);
        m[key] = i;

        return v;
    }

    void put(int key, int value) {
        // If the key exists, update the value (considered as used).
        if (m.find(key) != m.end()) {
            l.erase(m.find(key)->second);
            l.push_back({ key, value });
            list<pair<int,int>>::iterator i = l.end(); i--;
            m[key] = i;
            return; // ⚠
        }

        // If the size of the data structure is over the limit, evict the least recently used.
        if (m.size() >= size) {
            m.erase(l.front().first);
            l.pop_front();
        }

        // Put the key and value into the data structure.
        l.push_back({ key, value });
        list<pair<int,int>>::iterator i = l.end(); i--;
        m.insert({ key, i });
    }
}
```

## 노트

- list 의 iterator 는 list 에 저장된 각 요소로의 포인터이다.
- list 에 저장할 값은 `pair<int, int> // 각각 key, value` 이다.
- iter 가 list 의 iterator 라면 `*iter` 는 저장했던 `pair<int, int>` 자료를 의미한다.
- map 을 find 해서 가져온 결과는 `iterator<pair<?,?>>` 타입이다. (문제에서 저장에 활용한 pair 와는 무관)
  - `auto r = m.find(v);` 로 가져왔다면 key 는 r->start, value 는 r->second 로 접근할 수 있다.
- `list.first()`, `list.back()`는 요소 자체에 대한 접근이다.
  - ⚠️ 주의: iterator 반환되는 것이 아니다. 이 값을 map 의 값으로 저장했었는데, 이렇게 하면, 나중에 기존 값의 사용 상태를 업데이트(list 에서 삭제 후 list 에 push_back) 할 때, list 의 iterator 를 참조하지 못하게 된다.
  - 값에 대한 직접적인 접근이므로, 위의 제네릭 형태에서 list 의 값이 pair 이므로, `auto e = list.first()` 에서 `e.start` 와 같이 접근이 가능하다.
- `list.begin()`, `list.end()` 는 iterator 를 반환한다.
- `list.erase()` 는 `iterator` 를 인자로 전달받는다.
- list 의 마지막 요소부터 iterator 를 시작으로 삼고 싶다면, `list.rbegin()` 을 활용할 수 있다.

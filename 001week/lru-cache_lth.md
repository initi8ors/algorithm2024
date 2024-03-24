# LRU Cache
https://leetcode.com/problems/lru-cache/description/

약 3~4번 정도 수정에 수정을 거쳤으나 엣지케이스 통과하지 못함

[실패한 엣지케이스](https://leetcode.com/problems/lru-cache/submissions/1212452728)

# 코드
```java
class LRUCache {
    static class Node {
        public static final Node HEAD = new Node(-1, -1);
        public static final Node TAIL = new Node(-2, -2);
        int key;
        int value;
        Node prev;
        Node next;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    // key: cache key
    // value: Node
    Node[] cacheTable = new Node[10001];

    // Node, head(prev맨끝) 에 가까울수록 오래된 캐시
    Node cacheHead;
    // Node, tail(next맨끝) 에 가까울수록 최근 캐시
    Node cacheTail;
    int size;
    int capacity;

    public LRUCache(int capacity) {
        this.size = 0;
        this.capacity = capacity;
        cacheHead = Node.HEAD;
        cacheTail = Node.TAIL;
        cacheHead.next = cacheTail;
        cacheTail.prev = cacheHead;
    }

    public int get(int key) {
        Node cachedNode = cacheTable[key];
        if (cachedNode != null) {
            put(key, cachedNode.value);
            return cachedNode.value;
        }

        return -1;
    }

    public void put(int key, int value) {
        // 최신 캐시 업데이트
        if (cacheTable[key] != null) {
            Node node = cacheTable[key];
            if (node.value != value) {
                // 가장 안쓴 캐시 제거
                // head <-> node.prev <-> node <-> node.next <-> tail
                node.prev.next = node.next;
                node.next.prev = node.prev;
                cacheTable[key] = null;

                // head <-> node.prev <-> node <-> node.next <-> tail
                Node newNode = new Node(key, value);
                cacheTail.prev.next = newNode;
                newNode.prev = cacheTail.prev;
                newNode.next = cacheTail;
                cacheTable[key] = newNode;
                return;
            }

            node.prev.next = node.next;
            node.next.prev = node.prev;

            cacheTail.prev.next = node;
            node.prev = cacheTail.prev;
            node.next = cacheTail;
            cacheTail.prev = node;
            return;
        }

        // 최신 캐시 추가
        Node newNode = new Node(key, value);
        if (size < capacity) {
            // head <-> newNode <-> tail
            cacheTail.prev.next = newNode;
            newNode.prev = cacheTail.prev;
            newNode.next = cacheTail;
            cacheTail.prev = newNode;
            size++;
        }
        // 가장 안쓴 캐시 제거 & 최신 캐시로 갱신
        else {
            // 가장 안쓴 캐시 제거
            // head <-> oldCache <-> oldCache.next <-> tail
            Node oldCache = cacheHead.next;
            oldCache.next.prev = cacheHead;
            cacheHead.next = oldCache.next;
            cacheTable[oldCache.key] = null;

            // head <-> node.prev <-> node <-> node.next <-> tail
            cacheTail.prev.next = newNode;
            newNode.prev = cacheTail.prev;
            newNode.next = cacheTail;
        }
        cacheTable[key] = newNode;
    }

    private void printCache() {
        Node node = cacheHead;
        System.out.print("head -> ");
        while (node != null) {
            System.out.print(node.key + "-> ");
            node = node.next;
        }
        System.out.print("tail");
        System.out.println();
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```

# 풀이 방법
Doubly Linked List의 특성을 이용해서 가장 안쓴 캐시를 제거하고, 최신 캐신을 갱신한다.
`put`, `get`의 시간복잡도는 O(1)이어야 하기 때문에, 배열을 이용한 방법은 최소 O(N)이 걸리므로
참조형 선형 자료구조인 LinkedList를 사용해본다.

Singly가 아닌 Doubly를 선택한 이유는 최근 캐시로 갱신도 가능해야 하며, 가장 오래된 캐시를 제거할수도 있어야 하기 때문에
두개의 포인터를 가진 Doubly를 선택

또한, 캐시의 최대크기 제한이 있기 때문에, 갱신해야 할 캐시가 존재하는지 여부(`get`)도 O(1)만에 수행하기 위해
주소 직접접근이 가능한 주소를가진 배열(`cacheTable`)을 이용한다.






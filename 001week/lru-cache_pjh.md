```kotlin
fun main() {
    val cache = LRUCache(2)

    cache.put(1, 1)
    cache.put(2, 2)
//    cache.print()
    println(cache.get(1))
//    cache.print()
    cache.put(3, 3)
//    cache.print()
    println(cache.get(2))
    cache.put(4, 4)
    cache.print()
    println(cache.get(1))
    println(cache.get(3))
    println(cache.get(4))
}

class LRUCache(
    private val capacity: Int
) {
    private val map = HashMap<Int, Item>()
    private var first: Item? = null
    private var last: Item? = null

    fun get(key: Int): Int {
        val currentIem = map[key]

        return if (currentIem == null) {
            -1
        } else {
            if (currentIem.prev != null) {
                currentIem.prev!!.next = currentIem.next

                if (currentIem.next == null) {
                    last = currentIem.prev
                }
            }

            currentIem.next = first

            first = currentIem

            currentIem.value
        }
    }

    fun put(key: Int, value: Int) {
        val item = Item(key, value)

        if (first == null && map.isEmpty()) {
            last = item
        } else {
            item.next = first
            first?.prev = item

            if (first?.next == null) {
                last?.prev = item
            }

            if (map.keys.size >= capacity) {
                last?.let {
                    last = it.prev
                    last?.next = null
                    map.remove(it.key)
                }
            }
        }

        first = item
        this.map[key] = item
    }

    fun print() {
        println("---------------------------------------")
        println("first: ${first?.value}")
        println("last: ${last?.value}")

        println("--------------- map -------------------")
        map.forEach { (t, u) ->
            println("$t, ${u.value}")
        }

        println("--------------- linked list -------------------")
        var cur = first

        while (cur != null) {
            println("${cur.key} ${cur.value}")
            cur = cur.next
        }

        println("---------------------------------------")
    }

    inner class Item(
        val key: Int,
        val value: Int,
        var prev: Item? = null,
        var next: Item? = null,
    )
}
```

구현을 하려고 했던 방법은 map과 `DoubleLinkedList` 2개를 이용 하려고 했습니다.
맨 처음 문제를 보고 O(1)로 get이 되어야 하고 O(1)로 put이 되어야 하다보니 `LinkedHashMap`으로 구현하여 `Comparable`을 `lastUsed`라는 필드를 추가해서
정렬을 하고 각 값을 삭제하려 했으나 예상대로 되지 않았습니다.
다른 방법으로 `LinkedList`로 먼저 구현을 하려 했습니다. 그런데 get으로 조회도 O(1)로 되어야 하기 때문에 `LinkedList`로 만은 안 될 거 같아서 map도 추가 했습니다.
그리고 `LinkedList`도 최근에 사용한 값들을 순서대로 정렬 할 수도 있고 가장 마지막에 사용한 값을 삭제할 수 있으려면 각 item별로 prev, next로 관리하면 될 것이라고 생각해서 `DoubleLinkedList`로 구현하려고 했습니다

결론은 map삭제가 되지 않고 LinkedList 또한 모든 요소가 잘 관리가 되지 않아서 구현 실패했습니다.

```kotlin
fun main() {
    println(compareVersion("1.2", "1.10"))
    println(compareVersion("1.01", "1.001"))
    println(compareVersion("1.0", "1.0.0.0"))
    println(compareVersion("1", "1.1"))
    println(compareVersion("0.1", "0.0.1"))
}

fun compareVersion(version1: String, version2: String): Int {
    val splitVersion1 = version1.split(".").map { it.toInt() }
    val splitVersion2 = version2.split(".").map { it.toInt() }

    if (splitVersion1.size >= splitVersion2.size) {
        splitVersion2.forEachIndexed { i, n ->
            if (n > splitVersion1[i]) {
                return -1
            }

            if (n < splitVersion1[i]) {
                return 1
            }
        }

        return if (splitVersion1.slice(splitVersion2.size until splitVersion1.size).any { it != 0 }) {
            1
        } else {
            0
        }
    }

    splitVersion1.forEachIndexed { i, n ->
        if (n > splitVersion2[i]) {
            return 1
        }

        if (n < splitVersion2[i]) {
            return -1
        }
    }

    return if (splitVersion2.slice(splitVersion1.size until splitVersion2.size).any { it != 0 }) {
        -1
    } else {
        0
    }
}
```

숫자와 `.`으로만 구성된 문자열 2개가 주어져서, `.`으로 split후 각 자리를 integer화 시켰다.  
각 자리수를 돌면서 값을 비교하면 앞의 값이 크면 `1`, 뒤의 값이 크면 `-1`을 리턴하고 더 긴 버전을 가진게 있다면 나머지 루프를 더 돌면서 모두 `0`인지 확인한다.  
앞의 자리수에서 `0`이 아닌 값이 나온다면 `1`을 리턴하고 아니라면 `0`을 리턴한다.

```kotlin
fun main() {
    println(isSubsequence("abc", "ahbgdc"))
    println(isSubsequence("axc", "ahbgdc"))
    println(isSubsequence("", "ahbgdc"))
    println(isSubsequence("", ""))
    println(isSubsequence("b", "c"))
}

fun isSubsequence(s: String, t: String): Boolean {
    if (s.isEmpty()) {
        return true
    }

    return dp(s, t, 0, 0)
}

fun dp(s: String, t: String, sIdx: Int, tIdx: Int): Boolean {
    if (tIdx == t.length) {
        return false
    }

    return if (s.elementAt(sIdx) == t.elementAt(tIdx)) {
        if (sIdx + 1 == s.length) {
            return true
        }

        dp(s, t, sIdx + 1, tIdx + 1)
    } else {
        dp(s, t, sIdx, tIdx + 1)
    }
}
```

s의 인덱스와 t의 인덱스를 0부터 시작해서 해당 index의 값이 서로 같다면 양쪽 인덱스를 모두 증가 시켜주고 값이 다르다면 t의 인덱스 값만 늘려준다  
이후 값이 같을 때 s인덱스의 `+1`값이 s의 길이와 같다면 모두 찾았기 때문에 `true`를 리턴 시켜주고, 계속 증가 시켰는데 t의 index(`tIdx`)의 값이 t의 길이와 같아 진다면 모두 순회한거기 때문에 `false`를 return 시켜준다  
메모이제이션은 따로 필요하다고 생각이 들지 않아서 하지 않았습니다

```kotlin
fun numDecodings(s: String): Int {
    val result = mutableListOf<String>()

    decode(s, "${s.elementAt(0)}", 1, result)

    return result.size
}

fun decode(origin: String, str: String, idx: Int, result: MutableList<String>) {
    if (idx >= origin.length) {
        return
    }

    if (str.startsWith("0")) {
        return
    }

    val num = str.toInt()

    if (num >= 1 && num <= 26) {
        result.add(str)
    }

    if (str.length == 2) {
        decode(origin, "${origin.elementAt(idx)}", idx + 1, result)
    } else {
        decode(origin, "$str${origin.elementAt(idx)}", idx + 1, result)
        decode(origin, "${origin.elementAt(idx)}", idx + 1, result)
    }
}
```

구현은 아예 실패했습니다.
접근 방식은 시작 문자를 기준으로 index값을 하나씩 늘려 가면서 차례대로 문자를 이어 붙여가거나 다음 문자로 넘어가는 식으로 진행하면서
2글자가 된다면 다음 문자로 넘어가면서 계속 문자를 확인 하면서 해당 문자가 알파벳에 포함 되는지 확인 하고 결과 리스트에 더해서 개수를 구하려는 방식으로 하려고 했습니다

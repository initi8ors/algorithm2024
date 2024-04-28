## LCS(Longest Common Subsequence)
최장 공통 부분문자열.  
부분 문자열이란 연속되는 문자뿐 아니라 순서가 맞다면 연속 되지 않더라도 공통 부분인 문자열을 말한다.  

abcde와 bcd라고 하면 Longest Common Substring과 Longest Common Subsequence는 모두 `bcd`이다.  
abcde와 bce라고 하면 Longest Common Substring는 `bc`이고 Longest Common Subsequence는 `bce`이다.  

생명공학에서 염기서열 유사성 분석에 사용

```kotlin
fun main() {
    println(longestCommonSubsequence("abcde", "ace"))
    println(longestCommonSubsequence("abc", "abc"))
    println(longestCommonSubsequence("abc", "def"))
}

fun longestCommonSubsequence(text1: String, text2: String): Int {
    val result = Array(text2.length + 1) { Array(text1.length + 1) { 0 } }

    for (i in 1..text1.length) {
        val c1 = text1.elementAt(i - 1)

        for (j in 1..text2.length) {
            val c2 = text2.elementAt(j - 1)

            if (c1 == c2) {
                result[j][i] = result[j - 1][i - 1] + 1
            } else {
                result[j][i] = max(result[j][i - 1], result[j - 1][i])
            }
        }
    }

    return result[text2.length][text1.length]
}
```

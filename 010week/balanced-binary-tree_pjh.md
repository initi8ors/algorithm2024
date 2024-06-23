```kotlin
fun main() {
    // var ti = TreeNode(5)
    // var v = ti.`val`
    // root = [3,9,20,null,null,15,7]
    // root = [1,2,2,3,3,null,null,4,4]
    // root = []
}

fun isBalanced(root: TreeNode?): Boolean {
    if (root == null || root.left == null && root.right == null) {
        return true
    }

    return dfs(root) != -1
}

fun dfs(node: TreeNode?): Int {
    if (node == null) {
        return 0
    }

    val left = dfs(node.left)
    val right = dfs(node.right)

    if (left == -1 || right == -1 || abs(left - right) > 1) {
        return -1
    }

    return max(left, right) + 1
}

class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}
```

balanced tree는 서브 노드의 높이 차이가 2이상 나지 않아야 한다  
dfs로 각 node의 왼쪽과 오른쪽의 높이를 계산한다  
서브 노드의 높이를 계산 중 높이의 차이가 2이상 나게 되면 -1를 리턴하게 되고 재귀 호출을 하기 때문에 이전 서브노드가 이미 높이가 2이상(-1이 return)인 경우에 -1로 리턴 해준다  
결과는 -1이면 false 아니면 true를 return 한다

```kotlin
fun main() {
//    val obj = Twitter()
//
//    obj.postTweet(1, 5)
//
//    println(obj.getNewsFeed(1))
//
//    obj.follow(1, 2)
//    obj.postTweet(2, 6)
//
//    println(obj.getNewsFeed(1))
//
//    obj.unfollow(1, 2)
//    println(obj.getNewsFeed(1))
    val obj = Twitter()

    obj.postTweet(1, 5)
    obj.postTweet(1, 3)

    println(obj.getNewsFeed(1))
}

class Twitter() {
    private val followers = HashMap<Int, MutableList<Int>>()
    private val posts = HashMap<Int, MutableList<Post>>()

    fun postTweet(userId: Int, tweetId: Int) {
        if (posts.containsKey(userId)) {
            posts[userId]?.also {
                it.add(Post(tweetId))
                it.sortDescending()
            }
        } else {
            posts[userId] = mutableListOf(Post(tweetId))
        }
    }

    fun getNewsFeed(userId: Int): List<Int> {
        val myPost = posts[userId]?.toMutableList() ?: mutableListOf()

        followers[userId]?.forEach { followerId ->
            posts[followerId]?.let {
                myPost.addAll(it)
            }
        }

        return myPost.sortedDescending().map { it.postId }
    }

    fun follow(followerId: Int, followeeId: Int) {
        if (followers.containsKey(followerId)) {
            followers[followerId]!!.add(followeeId)
        } else {
            followers[followerId] = mutableListOf(followeeId)
        }
    }

    fun unfollow(followerId: Int, followeeId: Int) {
        followers[followerId]?.remove(followeeId)
    }

    inner class Post(val postId: Int): Comparable<Post> {
        private val createdAt = LocalDateTime.now()

        override fun compareTo(other: Post): Int {
            if (this.createdAt > other.createdAt) {
                return 1
            }

            if (this.createdAt < other.createdAt) {
                return -1
            }

            return 0
        }
    }
}
```

hash map에 user의 팔로워 id에 누가 팔로잉 하고 있는지를 저장하고, 각 user가 저장한 post들을 저장합니다  
feed를 가져올 때는 내 feed와 팔로워의 feed를 모두 가져와서 sorting을 하는데 post에 시간을 두어서 나중에 포스팅된 feed가 먼저 나올 수 있도록 합니다  
그런데 한 테스트 케이스에서 로컬에서 돌릴 때는 정상적으로 동작하는데 제출시 답이 다르게 나와서 실패했습니다

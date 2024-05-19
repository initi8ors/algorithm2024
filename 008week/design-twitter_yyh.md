# 문제
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze
1926. Nearest Exit from Entrance in Maze

# solution
```java
class Twitter {
    Map<Integer, LinkedList<Twit>> twit;
    Map<Integer, LinkedList<Integer>> follow;
    int t;
    public Twitter() {
        twit = new HashMap<>();
        follow = new HashMap<>();
        t = 1;
    }

    public void postTweet(int userId, int tweetId) {
        LinkedList<Twit> list = twit.getOrDefault(userId, new LinkedList<>());
        list.addFirst(new Twit(t++, tweetId));
        twit.put(userId, list);
        follow(userId, userId);
    }

    public List<Integer> getNewsFeed(int userId) {
        List<Integer> followList = follow.getOrDefault(userId, new LinkedList<>());
        PriorityQueue<Twit> queue = new PriorityQueue<>(new Comparator<Twit>() {
            @Override
            public int compare(Twit twit, Twit t1) {
                return t1.t - twit.t;
            }
        });
        for (Integer followId : followList) {
            LinkedList<Twit> twitList = twit.getOrDefault(followId, new LinkedList<>());
            int length = twitList.size();
            if (length > 10) length = 10;
            for (int i = 0; i < length; i++) {
                queue.add(twitList.get(i));
            }
        }
        List<Twit> result = new ArrayList<>();
        int queueLength = queue.size();
        if (queueLength > 10) queueLength = 10;
        for (int i = 0; i < queueLength; i++) {
            result.add(queue.poll());
        }

        return result.stream().map(x -> x.twitId).collect(Collectors.toList());
    }

    public void follow(int followerId, int followeeId) {
        LinkedList<Integer> list = follow.getOrDefault(followerId, new LinkedList<>());
        if (list.contains(followeeId)) return;
        list.add(followeeId);
        follow.put(followerId, list);
    }

    public void unfollow(int followerId, int followeeId) {
        LinkedList<Integer> followList = follow.get(followerId);
        followList.remove(Integer.valueOf(followeeId));
    }

    class Twit {
        int t;
        int twitId;
        public Twit(int t, int twitId) {
            this.t = t;
            this.twitId = twitId;
        }
    }
}
```

# 풀이
여러 자료구조를 복합적으로 사용한 구현문제라고 생각

사용한 자료구조
- HashMap
- LinkedList
- 우선순위 큐

Map과 List의 조합으로 트윗과 팔로우 저장소를 구현
user ID를 key로 하는 map에 트윗 글을 list로 저장
user ID를 key로 하는 map에 팔로우 한 user ID를 저장

LinkedList를 사용한 이유는 추가, 삭제가 자주 일어나는 구현이기 때문에 추가 삭제작업을 O(1) 처리하는게 유리하다고 판단

postTweet : 트윗 등록
Map에서 user ID로 트윗이 등록될 LinkedList를 꺼낸 뒤 첫번째 노드에 추가
시간복잡도 O(1)

getNewsFeed : 최신 트윗 조회
팔로우 한 유저 중 10개의 최신 트윗을 가져와야 함
구현 방법
1. 각 팔로우 마다 10개의 트윗을 조회
2. 우선순위 큐에 저장(최근에 저장된 트윗이 우선순위)
3. 우선순위 큐에서 10개의 트윗을 조회\
시간복잡도 O(1) ~ O(N) 어딘가.. 팔로우 유저 수를 생각하면 O(N) 트윗 수를 생각하면 O(1)

follow : 팔로우
Map에서 user ID로 조회해 이미 팔로우 되어있는지 확인
팔로우 되어있지 않다면 추가\
시간복잡도 O(N)

unfollow
map에서 user ID로 팔로우 리스트를 조회
팔로우 리스트에서 삭제\
시간복잡도 O(N)
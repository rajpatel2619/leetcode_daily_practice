class Twitter {
public:
    int timeStamp;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets; // user -> [(time, tweetId)]

    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // max-heap based on timestamp
        priority_queue<pair<int,int>> pq; // (time, tweetId)

        // include user's own tweets
        for (auto &tw : tweets[userId]) pq.push(tw);

        // include followees' tweets
        for (auto followee : following[userId]) {
            for (auto &tw : tweets[followee]) pq.push(tw);
        }

        vector<int> feed;
        int count = 0;
        while (!pq.empty() && count < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // can't follow self
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (following[followerId].count(followeeId))
            following[followerId].erase(followeeId);
    }
};

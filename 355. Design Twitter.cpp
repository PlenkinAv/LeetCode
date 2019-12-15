//https://leetcode.com/problems/design-twitter/

class Twitter {
private:
    struct tweet{
        int userId;
        int tweetId;
        int when_posted;
        tweet(int x, int y, int z):userId(x), tweetId(y), when_posted(z){};
    };
    struct mycompare{
        bool operator()(pair<list<tweet>::iterator, list<tweet>::iterator> p1, pair<list<tweet>::iterator, list<tweet>::iterator> p2){
            return p1.first->when_posted < p2.first->when_posted;
        }
    };
    int time = 0;
    unordered_map<int, unordered_set<int>> follower_dict;
    unordered_map<int, list<tweet>> twitter_dict;
public:
    /** Initialize your data structure here. */
    Twitter() {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follower_dict[userId].insert(userId);
        twitter_dict[userId].push_front(tweet(userId, tweetId, time));
        time++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if(follower_dict.find(userId) == follower_dict.end()) return res;
        priority_queue< pair<list<tweet>::iterator, list<tweet>::iterator>, vector<pair<list<tweet>::iterator, list<tweet>::iterator>>, mycompare> pq;
        for(auto it = follower_dict[userId].begin(); it != follower_dict[userId].end(); it++){
            if(twitter_dict[*it].begin() != twitter_dict[*it].end()){
                pq.push(make_pair(twitter_dict[*it].begin(), twitter_dict[*it].end()));
            }
        }
        int index = 0;
        while(!pq.empty() && index < 10){
            auto tmp = pq.top();
            pq.pop();
            res.push_back(tmp.first->tweetId);
            if(++tmp.first != tmp.second){
                pq.push(tmp);
            }
            index++;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follower_dict[followerId].insert(followerId);
        follower_dict[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(follower_dict.find(followerId) != follower_dict.end() && followerId != followeeId){
            follower_dict[followerId].erase(followeeId);
        }
    }
};
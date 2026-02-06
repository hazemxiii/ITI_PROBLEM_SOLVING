#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Tweet
{
public:
    int id;
    int time;
    Tweet(int id, int time)
    {
        this->id = id;
        this->time = time;
    }
};

struct Compare
{
    bool operator()(const Tweet *a, const Tweet *b)
    {
        return a->time < b->time;
    }
};

class User
{
public:
    unordered_set<int> following;
    unordered_set<Tweet *> tweets;
};
class Twitter
{
public:
    unordered_map<int, User *> users;
    unordered_map<int, Tweet *> tweets;
    int time;
    Twitter()
    {
        time = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        if (users.find(userId) == users.end())
        {
            users[userId] = new User();
        }
        users[userId]->tweets.insert(new Tweet(tweetId, time++));
    }

    vector<int> getNewsFeed(int userId)
    {
        if (users.find(userId) == users.end())
        {
            users[userId] = new User();
        }
        priority_queue<Tweet *, vector<Tweet *>, Compare> feed;
        // vector<int> feed;
        for (Tweet *t : users[userId]->tweets)
        {
            feed.push(t);
        }
        for (const int &u : users[userId]->following)
        {
            for (Tweet *t : users[u]->tweets)
            {
                feed.push(t);
            }
        }
        int count = 0;
        vector<int> out;
        while (!feed.empty() && count++ < 10)
        {
            out.push_back(feed.top()->id);
            feed.pop();
        }
        return out;
    }

    void follow(int followerId, int followeeId)
    {
        if (users.find(followerId) == users.end())
        {
            users[followerId] = new User();
        }
        if (users.find(followeeId) == users.end())
        {
            users[followeeId] = new User();
        }
        users[followerId]->following.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (users.find(followerId) == users.end())
        {
            users[followerId] = new User();
        }
        if (users.find(followeeId) == users.end())
        {
            users[followeeId] = new User();
        }
        users[followerId]->following.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main()
{
    return 0;
}

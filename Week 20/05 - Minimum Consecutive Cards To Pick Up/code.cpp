#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> last_seen;
        int ans = INT_MAX;

        for (int i = 0; i < cards.size(); i++) {
            if (last_seen.count(cards[i])) {
                int prev = last_seen[cards[i]];
                ans = min(ans, i - prev + 1);
            }
            last_seen[cards[i]] = i;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main()
{
return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26, 0);
        for (char task : tasks)
        {
            freq[task - 'A']++;
        }
        sort(freq.begin(), freq.end());
        int maxFreq = freq.back();
        int countMax = 0;
        for (int f : freq)
        {
            if (f == maxFreq)
                countMax++;
        }
        int partCount = maxFreq - 1;
        int partLength = n - (countMax - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - maxFreq * countMax;
        int idles = max(0, emptySlots - availableTasks);
        return tasks.size() + idles;
    }
};

int main()
{
    vector<char> v = {'A', 'C', 'A', 'B', 'D', 'B'};
    cout << Solution().leastInterval(v, 1);
    return 0;
}

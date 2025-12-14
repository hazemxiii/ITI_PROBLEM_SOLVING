#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        int s = intervals.size();
        if (s == 0)
        {
            return 1;
        }
        sort(intervals.begin(), intervals.end(), [](const Interval &x, const Interval &y)
             { return x.start < y.start; });
        Interval *last = &intervals[0];
        for (int i = 1; i < s; i++)
        {
            if (intervals[i].start < last->end)
            {
                return 0;
            }
            last = &intervals[i];
        }
        return 1;
    }

    bool canAttendMeetingsAnotherSolution(vector<Interval> &intervals)
    {
        int s = intervals.size();
        if (s == 0)
        {
            return 1;
        }
        for (int i = 0; i < s; i++)
        {
            for (int j = i + 1; j < s; j++)
            {
                if (intervals[i].start <= intervals[j].start && intervals[i].end > intervals[j].start)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};

int main()
{
    return 0;
}
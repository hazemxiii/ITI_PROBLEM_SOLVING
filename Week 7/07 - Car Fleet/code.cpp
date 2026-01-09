#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++)
        {
            double timeToTarget = double(target - position[i]) / speed[i];
            cars.push_back({position[i], timeToTarget});
        }

        sort(cars.begin(), cars.end(), greater<>());

        int fleets = 0;
        double slowest = 0.0;

        for (auto &car : cars)
        {
            double t = car.second;
            if (t > slowest)
            {
                fleets++;
                slowest = t;
            }
        }
        return fleets;
    }
};

int main()
{
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string organizingContainers(vector<vector<int>> container)
{
    int i;
    int j;
    int s = container.size();
    vector<int> arr(s, 0);
    vector<int> box(s, 0);
    for (i = 0; i < s; i++)
    {
        for (j = 0; j < s; j++)
        {
            arr[i] += container.at(i).at(j);
        }
    }
    for (i = 0; i < s; i++)
    {
        for (j = 0; j < s; j++)
        {
            box[i] += container.at(j).at(i);
        }
    }
    sort(arr.begin(), arr.end());
    sort(box.begin(), box.end());
    return arr == box ? "Possible" : "Impossible";
}

int main()
{
    return 0;
}
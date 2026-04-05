#include<iostream>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;
        for(char move : moves){
            switch (move) {
                case 'U':
                i--;
                break;
                case 'L':
                j--;
                break;
                case 'R':
                j++;
                break;
                case 'D':
                i++;
                break;
            }
        }
        return i==0&&j==0;
    }
};

int main()
{
return 0;
}

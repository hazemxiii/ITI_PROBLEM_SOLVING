#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int size = s.length();
        if(size!=t.length()) return 0;
        size_t temp[26] = {0};
        for(size_t i = 0 ; i < size ; i++){
                size_t c = s.at(i)-'a';
                temp[c] = temp[c]+1;
                c = t.at(i)-'a';
                temp[c] = temp[c]-1;
        }
        for(size_t c:temp){
            if(c!=0){
                return 0;
            }
        }
    return 1;
    }
};

int main(){
    return 0;
}

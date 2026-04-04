#include <cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int s = encodedText.length();
        int cols = ceil((1.0*s)/rows);
        string decoded;
        int i=0,j=0,startingCol=0;
        int indexOfLastSpace=-1;
        int decoded_len = 0;
        while(j<cols){
            int index = (i*cols) + j;
            decoded+=encodedText[index];
            decoded_len++;
            if(encodedText[index]==' '){
                if(indexOfLastSpace==-1){
                    indexOfLastSpace=decoded_len-1;
                }
            }else{
                indexOfLastSpace=-1;
            }
            i++;
            j++;
            if(i>=rows){
                i=0;
                j=++startingCol;
            }
        }
        return indexOfLastSpace==-1?decoded:decoded.substr(0,indexOfLastSpace);
    }
};
int main()
{
return 0;
}

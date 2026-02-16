#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        int *order_dict = new int[26];
        int shorter_word_length;
        int are_words_equal;
        for (int i = 0; i < 26; i++)
        {
            order_dict[order[i] - 'a'] = i;
        }
        int words_count = words.size();
        for (int i = 0; i < words_count - 1; i++)
        {
            shorter_word_length = min(words[i].size(), words[i + 1].size());
            are_words_equal = 0;
            for (int j = 0; j < shorter_word_length; j++)
            {
                if (order_dict[words[i][j] - 'a'] <
                    order_dict[words[i + 1][j] - 'a'])
                {
                    are_words_equal = 0;
                    break;
                }
                else if (order_dict[words[i][j] - 'a'] >
                         order_dict[words[i + 1][j] - 'a'])
                {
                    cout << "letter";
                    return 0;
                }
                are_words_equal = 1;
            }
            if (are_words_equal)
            {
                if (words[i].size() > words[i + 1].size())
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

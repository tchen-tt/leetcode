//
//  leetcode.hpp
//  leetcode
//
//  Created by chentao on 2020/10/5.
//

#ifndef leetcode_hpp
#define leetcode_hpp

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string s;
    int lengthOfLongSubstring();
    Solution(string s_): s(s_) {};
};


int Solution::lengthOfLongSubstring()
{
    unordered_set<char> maxstring;
    
    int stringLeng = (int) s.size();
    int length = 0;
    int j = -1;
    
    for (int i = 0; i < stringLeng; ++i)
    {
        if(i > 0) maxstring.erase(s[i-1]);
        while (j < stringLeng - 1 && !maxstring.count(s[j+1]))
        {
            maxstring.insert(s[j+1]);
            j++;
        }
        length = max(length, j - i + 1);
    }
    return length;
}

#endif /* leetcode_hpp */


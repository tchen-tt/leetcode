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
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string s;
    int lengthOfLongSubstring();
    int lengthOfLongSubstring1();
    int lengthOfLongSubstring2();
    Solution(string s_): s(s_) {};
};


// sliding window methods
// Time complexity o(N^2)
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


// hashmap methods
// Time complexity o(N)
int Solution::lengthOfLongSubstring1()
{
    int start = 0, end = 0, length = 0, result = 0;
    int sSize = (int) s.size();
    
    unordered_map<char, int> hash;
    while (end < sSize)
    {
        char tmpChar = s[end];
        
        if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
        {
            start = hash[tmpChar] + 1;
            length = end - start;
        }
        
        hash[tmpChar] = end;
        
        end++;
        length++;
        result = max(length, result);
    }
    return result;
}


// Array instead of hashmap methods
// Time complexity o(N)
int Solution::lengthOfLongSubstring2()
{
    int start = 0, end = 0, result = 0, length = 0;
    int sSize = (int) s.size();
    vector<int> vec(128, -1);
    
    while (end < sSize) {
        char tmpChar = s[end];
        
        if (vec[(int) tmpChar] >= start)
        {
            start = vec[(int) tmpChar] + 1;
            length = end - start;
        }
        vec[(int) tmpChar] = end;
        end++;
        length++;
        result = max(result, length);
    }
    
    return result;
}
#endif /* leetcode_hpp */

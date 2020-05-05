/*
    First Unique Character in a String

    Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

    Examples:
    s = "leetcode"
    return 0.

    s = "loveleetcode",
    return 2.

    Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    struct S
    {
        int freq=0;
        int index=-1;
    };
    int firstUniqChar(string s) {
        
        int n = 256;
        struct S char_arr[n];
        int ans = INT_MAX;
        for(int i=0; i<s.size(); i++)
        {
            (char_arr[s[i]].freq)++;
            char_arr[s[i]].index=i;
        }
        
        for(int i=0; i<n; i++)
            if(char_arr[i].freq == 1)
                ans = min(ans, char_arr[i].index);
        
        if(ans < s.size())
            return ans;
        
        return -1;
        
    }
};
/*
    Permutation in String
    Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
    In other words, one of the first string's permutations is the substring of the second string.

    Example 1:
    Input: s1 = "ab" s2 = "eidbaooo"
    Output: True
    Explanation: s2 contains one permutation of s1 ("ba").

    Example 2:
    Input:s1= "ab" s2 = "eidboaoo"
    Output: False
    
    Note:
        * The input strings only contain lower case letters.
        * The length of both given strings is in range [1, 10,000].
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {                
        int n = s2.size();
        int m = s1.size();
        

        if(s2.size()==0 || m > n)
            return false;

        
        vector<int> pFreq(26, 0);
        vector<int> currWinFreq(26, 0);
        
        for(int i=0; i<m; i++)
        {
            pFreq[s1[i]-'a']++;
            currWinFreq[s2[i]-'a']++;
        }
        for(int i=m; i<n; i++)
        {
            if(pFreq == currWinFreq)
                return true;
            currWinFreq[s2[i-m]-'a']--;
            currWinFreq[s2[i]-'a']++;
        }
        if(pFreq == currWinFreq)
            return true;
        
        return false;
    }
};
/*
    Find All Anagrams in a String

    Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

    Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

    The order of output does not matter.

    Example 1:
        Input:
        s: "cbaebabacd" p: "abc"
        Output:
        [0, 6]
        Explanation:
        The substring with start index = 0 is "cba", which is an anagram of "abc".
        The substring with start index = 6 is "bac", which is an anagram of "abc".

    Example 2:
        Input:
        s: "abab" p: "ab"
        Output:
        [0, 1, 2]
        Explanation:
        The substring with start index = 0 is "ab", which is an anagram of "ab".
        The substring with start index = 1 is "ba", which is an anagram of "ab".
        The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {  
        vector<int> res;
                
        int n = s.size();
        int m = p.size();

        if(s.size()==0 || m > n)
            return res;

        vector<int> pFreq(26, 0);
        vector<int> currWinFreq(26, 0);
        
        for(int i=0; i<m; i++)
        {
            pFreq[p[i]-'a']++;
            currWinFreq[s[i]-'a']++;
        }
        for(int i=m; i<n; i++)
        {
            if(pFreq == currWinFreq)
                res.push_back(i-m);
            currWinFreq[s[i-m]-'a']--;
            currWinFreq[s[i]-'a']++;
        }
        if(pFreq == currWinFreq)
            res.push_back(n-m);
        
        return res;
        
    }
};
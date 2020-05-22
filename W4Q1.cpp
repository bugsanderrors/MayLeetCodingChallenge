/*
    Sort Characters By Frequency

    Given a string, sort it in decreasing order based on the frequency of characters.

    Example 1:
        Input:
            "tree"
        Output:
            "eert"
        Explanation:
            'e' appears twice while 'r' and 't' both appear once.
            So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

    Example 2:
        Input:
            "cccaaa"
        Output:
            "cccaaa"
        Explanation:
            Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
            Note that "cacaca" is incorrect, as the same characters must be together.

    Example 3:
        Input:
            "Aabb"
        Output:
            "bbAa"
        Explanation:
            "bbaA" is also a valid answer, but "Aabb" is incorrect.
            Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
    multimap<int, char, greater<int>> invert(map<char, int>& M)
    {
        multimap<int, char, greater<int>> M2;
        
        for(auto it=M.begin(); it!= M.end(); ++it)
            M2.insert(make_pair(it->second, it->first));
        
        return M2;
    }
    string frequencySort(string s) {
        
        map<char, int> m;
        
        for(int i=0; i<s.size(); ++i)
            m[s[i]]++;
        
        multimap<int, char, greater<int>> sortedM = invert(m);
        
        string ans = "";
        
        for(auto it=sortedM.begin(); it!= sortedM.end(); ++it)
            ans.append(it->first, it->second);
        
        return ans;
        
    }
};
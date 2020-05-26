/*
    Contiguous Array

    Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

    Example 1:
    Input: [0,1]
    Output: 2
    Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

    Example 2:
    Input: [0,1,0]
    Output: 2
    Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

    Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        int k = 0,sum = 0, ans = 0;
        
        map<int, int> m;
        
        for(int i=0; i<n ; ++i)
        {
            if(nums[i] == 0)
                sum -= 1;
            if(nums[i] == 1)
                sum += 1;
            if(sum == k)
                ans = i+1;
            if(m.find(sum) == m.end())
                m[sum] = i;
            if(m.find(sum -k) != m.end())
            {
                int index = m[sum-k];
                ans = max(ans, i-index);
            }
        }
        return ans;
    }
};
/*
    First Bad Version

    You are a product manager and currently leading a team to develop a new product.
    Unfortunately, the latest version of your product fails the quality check.
    Since each version is developed based on the previous version, all the versions after a bad version are also bad.

    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

    You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version.
    You should minimize the number of calls to the API.

    Example:
    Given n = 5, and version = 4 is the first bad version.

    call isBadVersion(3) -> false
    call isBadVersion(5) -> true
    call isBadVersion(4) -> true

    Then 4 is the first bad version. 
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
typedef long long int ll;
class Solution {
public:
    int firstBadVersion(int n) {
        // we can do linear traversal but it will not minimize the API calls.
        // As the versions 1 - N are sorted, we can use binary search.
        
        ll low= 1;
        ll high= n;
        ll ans = 1;
        while(low<=high)
        {
            ll mid = (low+high)/2;
            
            if(isBadVersion(mid))
            {
                if(isBadVersion(mid-1) == false)
                {
                    ans = mid;
                    break;
                }
                high = mid;
            }
            else
            {
                if(isBadVersion(mid+1))
                {
                    ans = mid + 1;
                    break;
                }
                low = mid;
            }
        }
        return ans;
    }
};
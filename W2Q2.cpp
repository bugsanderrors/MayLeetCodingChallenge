/*
    Valid Perfect Square

    Given a positive integer num, write a function which returns True if num is a perfect square else False.

    Note: Do not use any built-in library function such as sqrt.

    Example 1:
    Input: 16
    Output: true

    Example 2:
    Input: 14
    Output: false
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num == 0)
            return false;
        long long int i = 1;
        while(i*i <= num)
        {
            if( num%i == 0 && num/i == i)
                return true;
            i++;
        }
        return false;        
    }
};
/*
    Check If It Is a Straight Line
    
    You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
    Check if these points make a straight line in the XY plane.

    Example 1:
    Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    Output: true

    Example 2:
    Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
    Output: false
    
    Constraints:
        * 2 <= coordinates.length <= 1000
        * coordinates[i].length == 2
        * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
        * coordinates contains no duplicate point.
*/

class Solution {
public:
    float slope(int x1, int y1, int x2, int y2)
    {
        return (float)(y2-y1)/(x2-x1);
    }        
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        if(n == 2)
            return true;
        
        int a = coordinates[0][0];
        int b = coordinates[0][1];
        
        int c = coordinates[1][0];
        int d = coordinates[1][1];
        
        float initial_slope = slope(a, b, c, d);
        
        for(int i=2; i<n; i++)
            if(slope(a, b, coordinates[i][0], coordinates[i][1]) != initial_slope)
                return false;
        
        return true;
    }
};
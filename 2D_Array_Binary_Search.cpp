QUESTION : Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.;


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true;

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false;
----------------------------------------------------------------------------
APPROACH  : If closely analyze the given matrix, we can notice one interesting property (╭ರ_•́): elements on the left are always smaller than the 
current element, and elements on the bottom are always greater. It reminds us of the Binary Search Tree, 
doesn''t it (๏็ટૄ◟๏็ )? Just look at this matrix from this angle and everything will become clear to you (our target, say, is 11):

LINK  :   https://leetcode.com/problems/search-a-2d-matrix/solutions/1895837/c-binary-search-tree-explained-with-img/

====================================================================================================================================================
  
CODE :::

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int r = 0, c = cols-1;
        while(r < rows and c > -1)
        {
            if(matrix[r][c] == target) return true;
            if(target > matrix[r][c]) r++;
            else c--;
        }
        return false;
    }
};

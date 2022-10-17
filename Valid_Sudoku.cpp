QUESTION  : Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.;

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true;


Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. 
  Since there are two 8's in the top left 3x3 sub-box, it is invalid.;

===============================================================================================

CODE 1 :: [ VECTOR APPROACH ] :::


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> row(9),col(9),sub(9);
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0', k = (i/3 * 3) + j/3;
                if(row[i].count(num) or col[j].count(num) or sub[k].count(num))
                    return false;
                row[i].insert(num);
                col[j].insert(num);
                sub[k].insert(num);
            }
        }
        return true;
    }
};

===============================================================================================
  
  
CODE 2 :: [ ARRAY APPROACH ] :::

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0}, cols[9][9] = {0}, subs[3][3][9] = {0};
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '0' - 1;
                if(rows[i][val] or cols[j][val] or subs[i/3][j/3][val]) return false;
                rows[i][val] = cols[j][val] = subs[i/3][j/3][val] = 1;
            }
        }
        return true;
    }
};

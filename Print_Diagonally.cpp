QUESTION : Give a N * N square matrix A, return all the elements of its anti-diagonals from top to bottom.;
==========================================================
Input: 
N = 2
A = [[1, 2],
     [3, 4]]
Output:
1 2 3 4;
-----------------------------------------
Input: 
N = 3 
A = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
Output: 
1 2 4 3 5 7 6 8 9;

==========================================
  
APPROACH : 
Step 1: Create an empty vector ans
Step 2: Run a loop from 0 to less than n
Step 3: set row = 0, col = k, k is loop variable.
Step 4: run a loop while col greater than 0, push a[row][col] into ans vector. Increase row by 1, decrease col by 1.

Step 5: Run a loop from 1 to less than n
Step 6: set row = j, col = n-1, j is loop variable.
Step 7: run a loop while row less than n, push a[row][col] into ans vector. Increase row by 1, decrease col by 1.

return ans vector.;

-----------------------------------------------------------------

Explanation of approach with help of an example:

Let the given matrix is
A = [[1, 2],
     [3, 4]]
So N=2.

Step 1: Create an empty vector ans={},
Step 2: Run a loop from 0 to less than 2.
Step 3: row=0, col=0,
Step 4: push A[0][0], ans={1}
Step 3: row=0, col=1,
Step 4: push A[0][1] and A[1][0], ans={1,2,3}

Step 5: Run a loop from 1 to less than 2
Step 6: set row = 1, col = 1.
bpush A[1][1], ans={1,2,3,4}

==========================================================================

CODE ::::


class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		vector<int> ans;

		// printing elements above and on 
	    // second diagonal
	    for (int k = 0; k < N; k++) {
	 
	        // traversing downwards starting
	        // from first row
	        int row = 0, col = k;
	        while (col >= 0) {
	            ans.push_back(A[row][col]);
	            row++, col--;
	        }
	    }
	 
	    // printing elements below second
	    // diagonal
	    for (int j = 1; j < N; j++) {
	 
	        // traversing downwards starting 
	        // from last column
	        int col = N - 1, row = j;
	        while (row < N) {
	            ans.push_back(A[row][col]);
	            row++, col--;
	        }
	    }

	    return ans;
	}

};

return ans.

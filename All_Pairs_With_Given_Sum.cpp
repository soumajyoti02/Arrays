QUESTION : Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

Note: All pairs should be printed in increasing order of u. For eg. for two pairs (u1,v1) and (u2,v2), if u12 then
(u1,v1) should be printed first else second;


Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the
pairs which sum to 9.;


Input:
A[] = {-1, -2, 4, -6, 5, 7}
B[] = {6, 3, 4, 0} 
X = 8 
Output:
4 4 
5 3;


CODE ::::


class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here   
        vector<pair<int,int>> ans;
        set<int> st;
        for(int i = 0; i < N; i++) st.insert(A[i]);
        
        for(int i = 0; i < M; i++)
        {
            int sol = X - B[i];
            if(st.find(sol) != st.end()) ans.push_back({sol,B[i]});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

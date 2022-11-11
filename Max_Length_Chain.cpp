Question : You are given N pairs of numbers. In every pair, the first number is always smaller than the second number;
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion;
You have to find the longest chain which can be formed from the given set of pairs;


Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
Output: 3
Explanation: The given pairs are { {5, 24}, {39, 60},
{15, 28}, {27, 40}, {50, 90} },the longest chain that
can be formed is of length 3, and the chain is
{{5, 24}, {27, 40}, {50, 90}};


Input:
N = 2
P[] = {5 10 , 1 11}
Output: 1
Explanation:The max length chain possible is only of
length one.;


Approach : Sort the structure by second;
Then  if(p[previous].second < p[current].first), Count it as a pair and move previous to current;


Code Below :


class Solution{
public:
    /*You are required to complete this method*/
    static bool compare(val v1, val v2)
    {
        return v1.second<v2.second;
    }
    int maxChainLen(struct val p[],int n){
        //Your code here
        sort(p,p+n,compare);
        int count = 1, j= 0;
        for(int i = 1; i < n; i++)
        {
            if(p[j].second < p[i].first) 
            {
                j = i;
                count++;
            }
        }
        return count;
    }
};

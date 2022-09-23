QUESTION : Given an array of n distinct elements, find the minimum number of swaps required to sort the array.
  
Input: {4, 3, 2, 1}
Output: 2
Explanation: Swap index 0 with 3 and 1 with 2 to form the sorted array {1, 2, 3, 4}.

Input: {1, 5, 4, 3, 2}
Output: 2;




class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>>v;
	    int n = nums.size();
	    for(int i = 0; i < n; i++)
	    {
	        v.push_back({nums[i],i});
	    }
	    
	    sort(v.begin(),v.end());
	    int count = 0;
	    for(int i = 0; i < n; i++)
	    {
	        if(v[i].second != i)
	        {
	            count++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return count;
	}
};

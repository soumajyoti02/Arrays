QUESTION : Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.
  
Input:
N = 5, K = 3
arr[] = {1,2,3,4,5}
Output: 3 2 1 5 4
Explanation: First group consists of elements
1, 2, 3. Second group consists of 4,5.
  
Input:
N = 4, K = 3
arr[] = {5,6,8,9}
Output: 8 6 5 9
  
  
  CODE BELOW --->>>



class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        for(long long i = 0;i<n;i+=k){ 
            
            /*If (ith index +k) is less than total number of elements it means
            k elements exist from current index so we reverse k elements 
            starting from current index.*/
            if(i+k < n){ 
                //reverse function used to reverse any part of the array.
                reverse(arr.begin()+i, arr.begin()+(i+k));
            }
            
            /*Else k elements from current index doesn't exist. 
            In that case we just reverse the remaining elements.*/
            else{
                //reverse function used to reverse any part of the array.
                reverse(arr.begin()+i, arr.end());
            }
        }
    }
};

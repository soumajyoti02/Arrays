QUESTION : Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader 
if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader;


Input:
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: The first leader is 17 
as it is greater than all the elements
to its right.  Similarly, the next 
leader is 5. The right most element 
is always a leader so it is also 
included.;


Input:
n = 5
A[] = {1,2,3,4,0}
Output: 4 0;


Approach : Its just like finding maximum element of an array from the end.

CODE BELOW ::::::::



class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> v;
        
        long long max = a[n-1];
        
        //We start traversing the array from last element.
        for(long long i =n-1; i >= 0; i--){
            //Comparing the current element with the maximum element stored. 
            //If current element is greater than max, we add the element.
            if(a[i] >= max){
                //Updating the maximum element.
                max = a[i];
                //Storing the current element in vector for leaders.
                v.push_back(max);
            }
        }
        //Finally reversing the vector in which leaders are stored.
        reverse(v.begin(), v.end());
        //returning the vector.
        return v;
        
    }
};
  
  

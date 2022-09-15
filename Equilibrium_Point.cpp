================================================================================================================================
QUESTION : Given an array A of n positive numbers.
The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
================================================================================================================================
Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 3 
Explanation: For second test case 
equilibrium point is at position 3 
as elements before it (1+3) = 
elements after it (2+2). 
--------------------------------------------------------------------
Input:
n = 1
A[] = {1}
Output: 1
Explanation:
Since its the only element hence
its the only equilibrium point.

----------------------------------------------------------------------

Here is my simple Approach for this problem :
<<<<<<<<<<<<------>>>>>>>>>>>>>
1) Find the SUM OF ALL ELEMENT of that given array.
2) We have to find such a point in that array for which, Sum of it's right part is equal to the Sum of it's left part. 
    --> At any point in the array while travarsing, We can find the SUM of right part's element by Just SUBSTRACT THAT ELEMENT WITH TOTAL SUM AND 
        store it in sum2;
        
        For example :
------------------------->>>>|~|<<<<------------------------- 
            If our Array is A[] = {1,3,5,2,2} then total SUM is : 13;
            
            --->>NOW Sum of right part is --> sum = sum - A[i];<<---
            
            Sum of right part of 1 is : 13 - 1 = 12;
            Sum of right part of 3 is : 12 - 3 = 9;
            Sum of right part of 5 is : 9 - 5 = 4;
            Sum of right part of 2 is : 4 - 2 = 2;
            Sum of right part of 2 is : 2 - 2 = 0; --> Last element, so No element is present on it's right side.
            
3) START A LOOP FOR i = 0 to n to travarse the array for checking that if any point, BOTH SIDE'S SUM is equal or not.

    3.1) int sum2 = 0; to Sum the elements of left side. It is using the same logic to SUM all elements of an Array.
    3.2) Make the sum of i's right side elements by : SUBSTRACTING THAT ELEMENT WITH SUM OF ALL ELEMENT (Explained above);
    3.3) If sum and sum2 are equal then that point is Our Desired point i.e. from that index, left and right part's sum are equal.
        So return i+1 because we have to return 1 based index.
        
4) Return -1 if no such point found and travarsal is completed.

  
  ######## CODE BELOW #########
  
  
class Solution{
    public:
    // Function to find equilibrium point in the array.
    int equilibriumPoint(long long a[], int n) {
    
        //We store the sum of all array elements.
        long long sum = 0;
        for (int i = 0; i < n; i++) 
           sum += a[i];
    
        //sum2 is used to store prefix sum.
        long long sum2 = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            
            //Leaving out the value of current element from suffix sum.
            sum = sum - a[i];
            
            //Checking if suffix and prefix sums are same.
            if (sum2 == sum) {
                //returning the index or equilibrium point.
                return (i + 1);
            }
            
            //Adding the value of current element to prefix sum.
            sum2 = sum2 + a[i];
        }
        return -1;
    }

};

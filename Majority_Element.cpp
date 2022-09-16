
============================================================================================================
QUESTION : Given an array A of N elements. Find the majority element in the array.
A majority element in an array A of size N is an element that appears more than N/2 times in the array.
============================================================================================================

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.
-------------------------------------------------
Input:
N = 5 
A[] = {3,1,3,3,2} 
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is 
the majority element.
-------------------------------------------------

<<<-----: Simple Approach to solve this Problem is :----->>>

1) Find the element which is repeating maximum times (byint findCandidate(int a[], int size) ) :
    i) Take a variable major and assign it with 0 [i.e. 1st index of given array]. It will store the index of most repetating element's index.
    ii) When a element is repeating, count will increase by 1 and when not repeating, count will decrease by 1.
        By this, After repeating some element, if other element starts then count will decrease. So if count becomes 0 then it proved that that element
        was not have greatest frequency. So we will reset count with 1 and will take that point as our major index.
        
                   INDEX -->   0 1 2 3 4 5 6 7 8 9 10 11 12
        Example: if array is : 3 3 4 4 4 4 5 5 5 5  5  5  5 ;
        
        Then major is a[0] = 3;
        For 3(a[1]) : count becomes 1 + 1 = 2;
        For 4(a[2]) : count becomes 2 - 1 = 1;
        For 4(a[3]) : count becomes 1 - 1 = 0; --> Then it's proved that 3 is not major, so now major = 4(array index 3) and count == 1;
        
        For 4(a[4]) : count becomes 1 + 1 = 2; --> MAJOR = index 3 i.e. 4
        For 4(a[5]) : count becomes 2 + 1 = 3; --> MAJOR = index 3 i.e. 4
        For 5(a[6]) : count becomes 3 - 1 = 2; --> MAJOR = index 3 i.e. 4
        For 5(a[7]) : count becomes 3 - 1 = 2; --> MAJOR = index 3 i.e. 4
        For 5(a[8]) : count becomes 2 - 1 = 1; --> MAJOR = index 3 i.e. 4
        For 5(a[9]) : count becomes 1 - 1 = 0; -->Then it's proved that 4 is not major, so now major = 5(array index 9) and count == 1;
        
       For 5(a[10]) : count becomes 1 + 1 = 2; --> MAJOR = index 9 i.e. 5
       For 5(a[11]) : count becomes 2 + 1 = 3; --> MAJOR = index 9 i.e. 5
       For 5(a[12]) : count becomes 3 + 1 = 4; --> MAJOR = index 9 i.e. 5

    
        
2) That function will return a value. Now check that value is present more than 50% times by FOR i = 0 to size and a counter.


          
          
          ## CODE BELOW ##
          
  */        

class Solution{
  public:
    int findCandidate(int a[], int size)
    {
        int major = 0, count = 1;
        for(int i = 1; i < size; i++)
        {
            if(a[major] == a[i])
                count++;
            else
                count--; // Decrease the counter because new values started. This will helps to keep track the greatest freq. 
            if(count == 0) // Means That previous value is not greatest. So move the major index into that new value. 
            {
                count = 1; // Reset the counter.
                major = i;
            }
        }
        return a[major];
    }
    bool ismajor(int a[],int n,int el)
    {
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == el)
                count++;
        }
        if(count > n/2)
            return true;
        else
            return false;
    }
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int major = findCandidate(a,size);
        if(ismajor(a,size,major))
            return major;
        return -1;
    }
};

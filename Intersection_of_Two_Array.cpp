QUESTION : Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.;

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2];

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.;


Approach 1 :

--> Create a map and enter all element of array 1 with their counts into it.
    Then run another loop for 2nd array and check if for any element, count in the map is > 0 ? If yes then put that element inside a answer vector.
      
      
Approach 2 :

--> Sort Both vector. Then run a loop for i and j < their size:
    i) if arr1[i] == arr2[j] then put that value inside answer vector and i++ & j++;
    ii) if arr[i] < arr2[j] then i+;
    iii) if arr1[i] > arr2[j] then j++;



CODE 1 :::: [ FOR MAP APPROACH ]

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums1.size(); i++)
        {
            mp[nums1[i]]++;
        }
        vector<int> ans;
        for(int i = 0; i < nums2.size(); i++)
        {
            if(mp[nums2[i]] > 0) 
            {
                mp[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};




CODE 2 :::: [FOR 2 POINTER APPROACH]


class Solution {// Two pointer ( i , j ) with sort
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> res;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++;
				j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
        }
        return res;
    }
};

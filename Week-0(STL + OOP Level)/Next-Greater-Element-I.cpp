/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.


Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.


# Approach
- Using a brute-force linear search
- For each element num in nums1, we first find its position in nums2.
- Once found, we continue traversing nums2 from that index to the right.
- We look for the first number greater than num. If found, store it; otherwise, store -1.
- Repeat this process for each element in nums1.

# Complexity
- Time complexity:*/

# Code
```cpp []
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans ;
        
        for(int i=0;i<nums1.size();i++){
            int num = nums1[i];
            int nextgreater = -1;
           bool found = false;
            for(int j=0;j<nums2.size();j++){
                if(num == nums2[j])
                found = true;
               else if(found && nums2[j] > num){
               nextgreater = nums2[j];
               break;
               }
                }
                ans.push_back(nextgreater);
            }
        return ans;
    }
};
```

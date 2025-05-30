// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).





//Below is a two pointer optimized approach: 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int k = 0;
     for(int i=0;i<nums.size();i++){
        if(nums[i]!=nums[k]){
            k++;
            nums[k]= nums[i];
        }
     }
     return k+1;
    }
};

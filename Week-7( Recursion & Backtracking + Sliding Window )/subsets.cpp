For example:
🌳 Full Recursion Tree for nums = [1, 2, 3]


//                                 []                          
//                           /      |      \
//                         1        2        3
//                       /   \     / \      / 
//                     2     3   3   -     -   
//                    /       -           
//                  3         -          
//                 /                    
//                -     

✅ Final Result Built in Order:
// [
//   [], 
//   [1],
//   [1, 2],
//   [1, 2, 3],
//   [1, 3],
//   [2],
//   [2, 3],
//   [3]
// ]
class Solution {
public:
void backtrack(vector<int>& nums, vector<int> current,int index, vector<vector<int>>& result ){
    result.push_back(current);
    for(int i = index; i<nums.size(); i++){
        current.push_back(nums[i]);
        backtrack(nums, current, i+1, result);
        current.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, current, 0, result);
        return result;
    }
};

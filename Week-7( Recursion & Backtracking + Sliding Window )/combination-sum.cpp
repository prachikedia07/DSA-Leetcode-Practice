// for example, [2,3,6,7]
//                             []
//                          / |  |  \
//                        2  3  6   7
//                      /          
//                   [2]         
//                  /             
//               [2,2]          
//              /                
//           [2,2,2]          
//          /                   
//       [2,2,2,2] ❌ → sum = 8 > 7 → backtrack  
//          \
//        [2,2,3] ✅ → sum = 7 → add to result
//          \
//        [2,3] ✅ → sum = 5 → keep going…
//          \
//          [3,3,1] ❌ (but 1 not in candidates) → ignore
//          ...

# Code
```cpp []
class Solution {
public:
void backtrack(int target, vector<int>& candidates, int index, vector<int>& curr, vector<vector<int>>& res ){
    if(target == 0){
    res.push_back(curr);
    return;
    }
    if(index >= candidates.size() || target<0) return;

    curr.push_back(candidates[index]);
    backtrack(target - candidates[index], candidates, index, curr, res);
    curr.pop_back();

    backtrack(target, candidates, index+1, curr, res);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(target, candidates, 0, curr, res);
        return res;
    }
};
```

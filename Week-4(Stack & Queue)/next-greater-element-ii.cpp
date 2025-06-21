/*# Approach
Use a monotonic stack to keep track of indices.
Traverse the array 2× to simulate circular behavior.
Use i % n to wrap around.

*/

  
  # Code
```cpp []
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res (n,-1);
        stack<int> st;
        for(int i = 2*n -1 ; i>=0 ; i--){
            while(!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }
            if(i < n){
                res[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return res;
    }
};
```

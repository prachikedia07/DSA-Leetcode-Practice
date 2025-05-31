/*# Approach
 - unordered_map to store the elements and their frequecies
 - Use hash maps to count frequencies
 - Check if the element exist in second array and if it's frequecy>0
 - Store the element in the resultant vector

 

# Complexity
- Time complexity:
Building map: O(n)
Checking elements in nums2: O(m)
→ Total: O(n + m)
  
- Space complexity:
Hash map stores up to n elements → O(n)*/

# Code
```cpp []
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums1.size();i++){
           mpp[nums1[i]]++;
        }
        for(int x : nums2){
            if(mpp[x]>0){
                result.push_back(x);
                mpp[x]--;
            }
        }
        return result;
    }
};
```

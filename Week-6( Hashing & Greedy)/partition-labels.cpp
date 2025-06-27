/*# Approach
-Build a map of the last index each character appears at in the string.
-Now we iterate through the string and expand the window (end) to the farthest last occurrence of any character we’ve seen so far.
- Keep track of:
- start: start of current part
- end: end boundary of the current part
-if i reaches end, we’ve found a complete partition: its length is end - start + 1
-Append that length to the result, and set start = i + 1 for the next partition.

# Complexity
- Time complexity:- 
O(n)

- Space complexity:- 
O(1)

*/
# Code
```cpp []
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        for(int i = 0 ; i<s.size();i++){
            last[s[i]] = i;
        }
        vector<int> res;
        int end =0, start =0;
        for(int i = 0; i<s.size() ;i++){
            end = max(end, last[s[i]]);
            if(end == i){
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
```

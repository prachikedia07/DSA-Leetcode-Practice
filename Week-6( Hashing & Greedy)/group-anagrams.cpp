/*### ✅ Approach

To group anagrams together, we use a **hash map** where the key is the **sorted version of each string**, and the value is a list of words that are anagrams of that key.

1. For each string in the input array, sort the string to get the key.
2. Insert the original string into the hash map under the sorted key.
3. After processing all strings, the hash map's values represent groups of anagrams.

---

### ⏱️ Complexity

- **Time Complexity:**  
  O(n⋅klogk) 
  where `n` is the number of strings and `k` is the maximum length of a string (due to sorting each string).

- **Space Complexity:**  
  O(n⋅k)  
  to store the strings in the hash map and the result.*/

---

### 💻 Code

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mpp[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& pair : mpp) {
            result.push_back(pair.second);
        }
        return result;
    }
};

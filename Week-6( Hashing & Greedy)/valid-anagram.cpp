/*# Approach
-We create an unordered map to store the frequencies of each character of both strings.
-We then use loop to increase frequency values for one string and decrease it for another.
-We then check if the map is empty or not

# Complexity
- Time complexity:
 O(n)

- Space complexity:
 O(1) */

# Code
```cpp []
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        for(char ch : t){
            freq[ch]--;
        }
        for(auto it : freq){
            if(it.second != 0)
            return false;
        }
        return true;
    }
};
```

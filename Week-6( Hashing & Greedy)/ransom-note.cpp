/*# Approach
-Using Hashmaps.
-Count frequency of each character in magazine.
-Decrease count while scanning ransomNote. 
-If any letter's count becomes negative, return false.

# Complexity
- Time complexity:
O(N + M)

- Space complexity:
O(1)

*/
# Code
```cpp []
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count;
        for(char ch : magazine){
            count[ch]++;
        }
        for(char ch : ransomNote){
            count[ch]--;
            if(count[ch] < 0)
            return false;
        }
        return true;
    }
};
```

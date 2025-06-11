/* NEW TITLE OF THE QUESTION IS: "FIND THE INDEX OF THE FIRST OCCURENCE IN A STRING"

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.


A



   TIME COMPLEXITY-
   O(n * m)   
   SPACE COMPLEXITY-
   O(m)     
                                                                                                */

//One line approach using STL properties of C++:
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
```

//Better approach for better working in every platform alogn with handling edge cases:
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
      
        if(m==0){
            return 0;        //edge case
        }
      
        for(int i=0;i<=n-m;i++){
            if(haystack.substr(i,m)==needle){
                return i;
            }
        }
        return -1;
    }
};

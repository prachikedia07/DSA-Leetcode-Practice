# Code
```cpp []
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<32 ;i++){
            int bitSum = 0;
            for(int num : nums){
                if((num >> i) & 1)
                    bitSum++;
            }
                if(bitSum % 3 != 0)
                result |= (1 << i);
        }
        return result;
    }
};
```

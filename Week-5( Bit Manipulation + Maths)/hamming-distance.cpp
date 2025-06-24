# Code
```cpp []
class Solution {
public:
    int hammingDistance(int x, int y) {
        int Xor = x^y;
        int count = 0;
        while(Xor){
            count += ( Xor & 1);
            Xor = Xor>>1;
        }
        return count;
    }
};
```

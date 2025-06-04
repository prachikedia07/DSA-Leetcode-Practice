/*## 🧠 Approach

### 🔹 Brute Force
- Check all possible pairs of lines `(i, j)` such that `i < j`.
- For each pair, calculate the container area.
- Track the maximum area encountered.
- **Drawback:** Inefficient for large inputs.

### 🔹 Optimal (Two Pointers)
- Use two pointers: `left` at `0`, and `right` at `n - 1`.
- While `left < right`:
- Calculate area using the shorter of the two heights and the width
- Move the pointer pointing to the **shorter height**, since moving the taller one can't help increase area.
- Keep updating the `maxArea`.

---

## ⏱️ Complexity

| Approach        | Time Complexity | Space Complexity |
|----------------|------------------|------------------|
| Brute Force     | O(n²)            | O(1)             |
| Two Pointers    | O(n)             | O(1)             |
  */

---

## ✅ Code
```cpp
//Brute Force Approach
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        for(int i = 0; i < height.size(); i++) {
            for(int j = i + 1; j < height.size(); j++) {
                int width = j - i;
                int h = min(height[i], height[j]);
                int area = width * h;
                maxWater = max(area, maxWater);
            }
        }
        return maxWater;
    }
};

// Optimal Two Pointer Approach
class Solution {
public:
  int maxArea(vector<int>& height) {
      int left = 0;
      int right = height.size() - 1;
      int maxArea = 0;

      while (left < right) {
          int currArea = min(height[left], height[right]) * (right - left);
          maxArea = max(maxArea, currArea);

          if (height[left] < height[right])
              left++;
          else
              right--;
      }

      return maxArea;
  }
};


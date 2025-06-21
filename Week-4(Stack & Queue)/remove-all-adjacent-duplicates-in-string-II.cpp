/*

## 🧠 Approach

We use a **stack** to keep track of each character along with its **current consecutive frequency**.

- Traverse the string character by character.
- If the top of the stack has the same character, increment the count.
- If the count reaches `k`, remove that group from the stack (pop).
- Otherwise, push a new pair `{character, 1}`.
- After processing, rebuild the result string by multiplying each character by its stored count (from the stack).

We finally **reverse** the result since the stack gives us characters in reverse order.

---

## ⏱️ Complexity

- **Time complexity:** $$O(n)$$  
  Each character is processed at most twice — once when pushed, once when popped.

- **Space complexity:** $$O(n)$$  
  In the worst case, all characters are distinct and remain in the stack.

---*/

## 💻 Code

```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        
        for (char ch : s) {
            if (!st.empty() && st.top().first == ch) {
                st.top().second++;
                if (st.top().second == k) {
                    st.pop();
                }
            } else {
                st.push({ch, 1});
            }
        }

        string result;
        while (!st.empty()) {
            auto [ch, count] = st.top();
            st.pop();
            result.append(count, ch);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

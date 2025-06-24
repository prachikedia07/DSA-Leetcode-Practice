# 📚 Week 5: Bit Manipulation + Maths

## 🧠 Topics to Study

- **Bitwise Operators**
- **XOR Properties** (especially for problems involving "single number")
- **Binary Representation and Manipulation**
- **Math Techniques**:
  - Excel-style column conversions
  - Hamming distance
  - Overflow-safe addition/subtraction

Take time to understand:
- How each bitwise operation affects binary numbers.
- How bit tricks help reduce space/time complexity.
- Patterns like:
  - XOR for finding unique numbers
  - Rightmost set bit usage
  - Bit count problems

---

## 🧩 LeetCode Questions

| #  | Problem | Difficulty | Tags |
|----|---------|------------|------|
| 1  | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | Easy | Bit Manipulation |
| 2  | [Counting Bits](https://leetcode.com/problems/counting-bits/) | Easy | Bit Manipulation, DP |
| 3  | [Single Number](https://leetcode.com/problems/single-number/) | Easy | Bit Manipulation |
| 4  | [Single Number II](https://leetcode.com/problems/single-number-ii/) | Medium | Bit Manipulation |
| 5  | [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) | Medium | Bit Manipulation |
| 6  | [Reverse Bits](https://leetcode.com/problems/reverse-bits/) | Easy | Bit Manipulation |
| 7  | [Power of Two](https://leetcode.com/problems/power-of-two/) | Easy | Math, Bit Manipulation |
| 8  | [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/) | Easy | Math |
| 9  | [Hamming Distance](https://leetcode.com/problems/hamming-distance/) | Easy | Bit Manipulation |
| 10 | [Missing Number](https://leetcode.com/problems/missing-number/) | Easy | Math, XOR, Bit Manipulation |

---

## 🎯 Goals

- Master key **bit manipulation tricks** and understand when to apply them.
- Build strong intuition on how binary operations work under the hood.
- Recognize patterns involving:
  - XOR for unique elements
  - Bitwise counting
  - Binary digit manipulations
- Practice translating **math problems into bit operations** when appropriate.

---

## 🛠 Tips

- Use pen and paper to manually simulate bitwise operations.
- Memorize basic formulas like: `n & (n-1)` → removes the rightmost set bit.
- Know `n & 1` checks odd/even, `n ^ n = 0`, `n ^ 0 = n`.
- Use unsigned types carefully in languages like C++ or Java.
- Understand why XOR works to find the unique number when all others are in pairs.


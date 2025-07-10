# 📚 Week 9: Graphs & Heaps

## 📅 Topics to Cover

- **Graphs**
  - BFS (Breadth-First Search)
  - DFS (Depth-First Search)
  - Topological Sort
- **Heaps**
  - Min Heaps & Max Heaps
  - `priority_queue` in C++

---

## 🧠 Concepts to Revise

### Graphs
- Adjacency List / Matrix
- BFS & DFS templates
- Detecting cycles in directed/undirected graphs
- Topological sorting
- Connected components

### Heaps
- Min Heap / Max Heap basics
- STL `priority_queue`
- Custom comparators
- Using heap for streaming data

---

## ✅ Problems to Practice

| # | Problem | Level | Topic |
|---|---------|--------|-------|
| 1 | [Number of Islands](https://leetcode.com/problems/number-of-islands/) | 🟡 Medium | BFS / DFS |
| 2 | [Flood Fill](https://leetcode.com/problems/flood-fill/) | 🟢 Easy | DFS |
| 3 | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/) | 🟢 Easy | Min Heap |
| 4 | [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/) | 🟢 Easy | Max Heap |
| 5 | [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/ ) | 🟡 Medium |  Max Heap |
| 6 | [Course Schedule](https://leetcode.com/problems/course-schedule/) | 🟡 Medium | Graphs, Topo Sort |
| 7 | [Course Schedule-II](https://leetcode.com/problems/course-schedule-ii/) | 🟡 Medium | Graphs, Topo Sort |
| 8 | [Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/) | 🟡 Medium | Graphs, Topo Sort |
| 9 | [Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/) | 🟡 Medium | Graph, DFS |
| 10 | [Dijkstra's Algorithm](https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1) | 🟡 Medium | Graph, Heaps |
| 11 | [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/) | 🔴 Hard | Graph, Backtracking |
| 12 | [Alien Dictionary](https://practice.geeksforgeeks.org/problems/alien-dictionary/1) | 🔴 Hard | Graph, Topo Sort |

---

## 🛠️ C++ STL to Master

- `queue` and `stack`
- `priority_queue`
- `unordered_map` / `set`
- `pair` and `tuple`

---

## ✍️ Tips

- Practice both **DFS** and **BFS** approaches for graph traversal problems.
- For heap problems, be familiar with:
  - Default max-heap: `priority_queue<int>`
  - Min-heap: `priority_queue<int, vector<int>, greater<int>>`
- For topological sorting (like Course Schedule), try both **Kahn’s Algorithm (BFS)** and **DFS with cycle detection**.
- Visualize graphs to debug easier.

---

## 📌 Goal

Solve all 10 problems by the end of the week to strengthen my foundation in graph algorithms and heap-based problems.

💪

---

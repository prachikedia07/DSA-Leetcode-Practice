# Code
```cpp []
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revgraph(n);
        vector<int> outdegree(n,0);
        for(int u = 0; u < n; u++){
            for(auto v : graph[u]){
                revgraph[v].push_back(u);
                outdegree[u]++;
            }
        }
        queue<int> q;
        vector<int> safeNodes;

        for(int i = 0; i< n; i++){
            if(outdegree[i] == 0)
            q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it : revgraph[node]){
                outdegree[it]--;
                if(outdegree[it] == 0) q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
```

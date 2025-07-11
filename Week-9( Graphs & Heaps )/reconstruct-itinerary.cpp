# Code
```cpp []
class Solution {
public:
void dfs(string airport, vector<string>& itinerary,  unordered_map<string,
                      priority_queue<string, vector<string>, greater<string>>>&
            graph){
    auto& dests = graph[airport]; // reference to the min-heap
    while (!dests.empty()) {
        string next = dests.top(); dests.pop();
        dfs(next, itinerary, graph);
    }
    itinerary.push_back(airport); // post-order
}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,
                      priority_queue<string, vector<string>, greater<string>>>
            graph;
        for (auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }
        vector<string> itinerary;
        dfs("JFK", itinerary, graph);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
```

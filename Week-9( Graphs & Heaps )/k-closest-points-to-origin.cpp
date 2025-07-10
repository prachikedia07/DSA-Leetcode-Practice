# Code
```cpp []
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;
        vector<vector<int>> ans;
        for(auto point : points ){
            int x = point[0] , y = point[1];
            int dist = x*x + y*y;
            pq.push({dist, {x,y}});
            if(pq.size() > k)
            pq.pop();
        }
        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            int x = p.second.first;
            int y = p.second.second;
            ans.push_back({x,y});
        }
       return ans; 
    }
};
```


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> answer(temperatures.size(), 0);
        for(int i = 0; i< temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int prevIndex = st.top();
                st.pop();
                answer[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }
        return answer;
    }
};

/*# Appraoch
-While iterating over asteroids:
  If current asteroid is positive, push it onto the stack.
  If current asteroid is negative, handle possible collisions with stack top (which might be positive and moving toward it).


 */
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int ast : asteroids){
            bool destroyed = false;
            while(!st.empty() && ast < 0 && st.top() > 0){
                if(abs(ast) > st.top()){
                    st.pop();
                    continue;
                } else if(abs(ast) == st.top()){
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; 
                    break;
                }
            }
            if(!destroyed)
            st.push(ast);
        }
        vector<int> answer(st.size());
        for(int i = st.size() - 1 ; i>=0  ;i--){
            answer[i] = st.top();
            st.pop();
        }
        return answer;
    }
};

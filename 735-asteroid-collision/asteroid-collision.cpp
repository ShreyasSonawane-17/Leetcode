class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        if (n == 0)
            return {};

        st.push(asteroids[0]);
        int i = 1;

        while (i < n) {
            if (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                if (st.top() > abs(asteroids[i])) {
                    i++;
                } else if (st.top() < abs(asteroids[i])) {
                    st.pop();

                    if (st.empty() || st.top() < 0) {
                        st.push(asteroids[i]);
                        i++;
                    }
                } else {
                    st.pop();
                    i++;
                }
            } else {
                st.push(asteroids[i]);
                i++;
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
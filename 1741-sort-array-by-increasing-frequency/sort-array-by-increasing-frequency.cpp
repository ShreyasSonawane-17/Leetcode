class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto x : nums) {
            mp[x]++;
        }

        vector<pair<int, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            if (a.second == b.second)
                return a.first > b.first;

            return a.second < b.second;
        });

        vector<int> ans;
        for (auto it : v) {
            int a = it.second;
            while (a > 0) {
                ans.push_back(it.first);
                a--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (auto x : nums) {
            mp[x]++;
        }

        vector<int> ans;
        int cnt = 0;
        int cnt2 = 0;
        for (auto it : mp) {
            if (it.second % 2 == 0) {
                cnt += it.second / 2;
            } else {
                cnt += it.second / 2;
                cnt2 += it.second % 2;
            }
        }
        ans.push_back(cnt);
        ans.push_back(cnt2);

        return ans;
    }
};
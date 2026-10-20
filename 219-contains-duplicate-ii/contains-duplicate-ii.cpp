class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto it : mp) {
            vector<int> v = it.second;

            for (int i = 0; i < v.size(); i++) {
                for (int j = i + 1; j < v.size(); j++) {
                    if (abs(v[i] - v[j]) <= k) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
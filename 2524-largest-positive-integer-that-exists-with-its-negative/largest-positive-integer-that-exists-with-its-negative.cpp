
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        int maxi = -1;

        for (auto it : mp) {
            if (it.first > 0 && mp.count(-it.first)) {
                maxi = max(maxi, it.first);
            }
        }

        return maxi;
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;

        int n = nums.size();
        for (auto x : nums) {
            mp[x]++;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        int total = n * (n + 1) / 2;

        for (auto it : mp) {
            if (it.second > 1) {
                ans.push_back(it.first);
                sum = sum - it.first;
                int a = total - sum;
                ans.push_back(a);
            }
        }

        return ans;
    }
};
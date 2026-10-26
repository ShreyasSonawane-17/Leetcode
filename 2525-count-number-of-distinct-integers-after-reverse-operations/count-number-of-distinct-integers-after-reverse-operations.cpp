class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int rev = 0;
            while (a > 0) {
                int digit = a % 10;
                a = a / 10;
                rev = rev * 10 + digit;
            }
            v.push_back(rev);
        }

        for (int i = 0; i < v.size(); i++) {
            nums.push_back(v[i]);
        }

        unordered_map<int, int> mp;

        for (auto x : nums) {
            mp[x]++;
        }

        int cnt = 0;
        for (auto it : mp) {
            if (it.second >= 1)
                cnt++;
        }

        return cnt;
    }
};
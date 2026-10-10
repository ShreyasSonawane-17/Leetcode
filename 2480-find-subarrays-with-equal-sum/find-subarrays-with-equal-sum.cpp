class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        int i = 0;
        int j = 1;
        int n = nums.size();

        int sum = 0;
        while (i < n - 1) {
            sum = nums[i] + nums[i+1];
            mp[sum]++;
            i++;
        }

        for(auto it : mp){
            if(it.second > 1) return true;
        }

        return false;
    }
};
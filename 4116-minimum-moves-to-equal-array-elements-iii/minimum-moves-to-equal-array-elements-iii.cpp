class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int diff = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            diff += nums[n-1] - nums[i];
        }

        return diff;
    }
};
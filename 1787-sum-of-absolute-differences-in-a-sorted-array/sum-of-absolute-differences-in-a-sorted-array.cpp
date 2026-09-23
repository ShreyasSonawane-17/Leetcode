class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        // Calculate answer for index 0
        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += nums[i] - nums[0];
        }

        ans[0] = sum;

        // Calculate remaining answers
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + (2 * i - n) * (nums[i] - nums[i - 1]);
        }

        return ans;
    }
};
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0) {
                int a = nums[i] % 10;
                if (a == digit)
                    cnt++;
                nums[i] = nums[i] / 10;
            }
        }

        return cnt;
    }
};
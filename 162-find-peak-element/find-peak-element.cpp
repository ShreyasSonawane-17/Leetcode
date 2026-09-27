class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 0;
        while(i < nums.size() - 1 && nums[i] < nums[i+1]){
            i++;
        }

        return i;
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid = 0;

        while(e >= mid){
            if(nums[mid] == 2){
                swap(nums[mid],nums[e]);
                e--;
                
            }
            else if(nums[mid] == 0){
                swap(nums[mid], nums[s]);
                s++;
                mid++;
            }
            else{
                mid++;
            }
        }
    }
};
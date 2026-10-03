class Solution {
public:
    int arraySign(vector<int>& nums) {
       int zerocnt = 0;
       int negcnt = 0;

       for(int i = 0; i< nums.size(); i++){
            if(nums[i] == 0) zerocnt++;
            if(nums[i] < 0) negcnt++;
       }

       if(zerocnt > 0) return 0;
       if(negcnt % 2 != 0) return -1;

       return 1;
    }
};
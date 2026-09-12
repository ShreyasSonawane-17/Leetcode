class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        queue<int> q1;
        queue<int> q2;

        for(int i = 0 ; i< nums.size(); i++){
            if(nums[i] >= 0) q1.push(nums[i]);
            if(nums[i] < 0) q2.push(nums[i]);
        }

        while(!q1.empty() || !q2.empty()){
            if(!q1.empty()){
                ans.push_back(q1.front());
                q1.pop();
            }
            if(!q2.empty()){
                ans.push_back(q2.front());
                q2.pop();
            }
        }
        return ans;
    }
};
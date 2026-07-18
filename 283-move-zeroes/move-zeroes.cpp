class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> q1;
        queue<int> q2;
        for(auto x : nums){
            if(x != 0) q1.push(x);

            else 
            if(x == 0) q2.push(x);

        }
        nums.clear();
        while(!q1.empty()){
            nums.push_back(q1.front());
            q1.pop();
        }

        while(!q2.empty()){
            nums.push_back(q2.front());
            q2.pop();
        }
        
    }
};
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> mp;

        for(auto x : nums){
            mp[x]++;
        }

        vector<int> ans;
        for(auto it : mp){
            int a = it.first;
            if(it.second == 1 && mp.find(a-1) == mp.end() && mp.find(a+1) == mp.end()){
                ans.push_back(a);
            }
        }

        return ans;
    }
};
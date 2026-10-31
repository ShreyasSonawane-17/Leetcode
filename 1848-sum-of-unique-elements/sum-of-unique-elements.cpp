class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto x : nums){
            mp[x]++;
        }

        vector<int> v;
        for(auto it : mp){
            if(it.second == 1) v.push_back(it.first);
        }

        int sum = 0;
        for(int i = 0; i<v.size(); i++){
            sum += v[i];
        }

        return sum;
    }
};
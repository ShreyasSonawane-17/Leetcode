class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int a = *min_element(nums.begin(),nums.end());
        int b = *max_element(nums.begin(),nums.end());

        vector<int> ans;
        
        sort(nums.begin(),nums.end());

        for(int i = a; i<b ; i++){
            if(!binary_search(nums.begin(), nums.end(), i+1)){
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};
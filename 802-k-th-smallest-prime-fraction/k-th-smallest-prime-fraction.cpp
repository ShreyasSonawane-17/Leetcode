class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int,int>> nums;
        

        for(int i = 0; i<arr.size(); i++){
            for(int j = i + 1; j<arr.size(); j++){
                nums.push_back({arr[i],arr[j]});
            }
        }
        sort(nums.begin(),nums.end(), [](auto a, auto b){
            return a.first * b.second < b.first * a.second;
        });

        return {nums[k-1].first,nums[k-1].second};
    }
};
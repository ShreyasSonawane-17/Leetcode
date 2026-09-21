class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> arr;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] >= 0){
                arr.push_back(nums[i]);
            }
        }
        if(arr.size() == 0) return nums;
        k = k % arr.size();
        
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
        reverse(arr.begin(), arr.end());

        int i = 0;
        int j = 0;
        while(i < nums.size() && j < nums.size()){
            if(nums[i] >= 0){
                nums[i] = arr[j];
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return nums;
    }
};

class Solution {
public:
    int ds(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = -1;

        for (int x : nums) {
            int s = ds(x);

            if (mp.count(s)) {
                maxi = max(maxi, x + mp[s]);
            }

            mp[s] = max(mp[s], x);
        }

        return maxi;
    }
};

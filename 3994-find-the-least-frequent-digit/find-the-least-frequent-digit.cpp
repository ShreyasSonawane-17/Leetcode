class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int, int> mp;

        while (n > 0) {
            int digit = n % 10;
            mp[digit]++;
            n /= 10;
        }

        int mn = INT_MAX;
        int ans = -1;

        for (auto it : mp) {
            if (it.second < mn) {
                mn = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};
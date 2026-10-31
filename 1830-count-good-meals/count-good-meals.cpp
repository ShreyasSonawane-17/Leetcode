
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        long long cnt = 0;
        long long mod = 1e9 + 7;

        unordered_map<int, int> mp;

        for (int x : deliciousness) {

            for (int p = 1; p <= (1 << 21); p *= 2) {
                int y = p - x;

                if (mp.count(y)) {
                    cnt = (cnt + mp[y]) % mod;
                }
            }

            mp[x]++;
        }

        return cnt;
    }
};


class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> freq(121, 0);

        for (int age : ages) {
            freq[age]++;
        }

        int cnt = 0;

        for (int x = 1; x <= 120; x++) {
            for (int y = 1; y <= 120; y++) {
                if (y > 0.5 * x + 7 && y <= x) {
                    cnt += freq[x] * freq[y];

                    if (x == y) {
                        cnt -= freq[x];
                    }
                }
            }
        }

        return cnt;
    }
};

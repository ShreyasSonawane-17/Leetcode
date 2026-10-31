
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();

        // Even at infinite speed, minimum time is n - 1 hours.
        if (hour <= n - 1) return -1;

        int left = 1, right = 10000000;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            double time = 0;

            for (int i = 0; i < n; i++) {
                double t = (double)dist[i] / mid;

                if (i != n - 1) {
                    time += ceil(t);
                } else {
                    time += t;
                }
            }

            if (time <= hour) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};

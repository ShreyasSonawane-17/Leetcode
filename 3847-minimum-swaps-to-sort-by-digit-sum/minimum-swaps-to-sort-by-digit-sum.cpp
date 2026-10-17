class Solution {
public:
    int sum(int x) {
        int a = 0;

        while (x > 0) {
            a += x % 10;
            x /= 10;
        }

        return a;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({sum(nums[i]), nums[i]});
        }

        vector<pair<int, int>> sorted = v;
        sort(sorted.begin(), sorted.end());

        // Map each original number to its sorted position.
        // If duplicate values are possible, track original indices instead.
        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[i] = i;
        }

        // Minimum swaps are found by counting permutation cycles.
        // Store original indices alongside values to handle duplicates correctly.
        vector<tuple<int, int, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({sum(nums[i]), nums[i], i});
        }

        sort(a.begin(), a.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || get<2>(a[i]) == i) {
                visited[i] = true;
                continue;
            }

            int cycle = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = get<2>(a[j]);
                cycle++;
            }

            if (cycle > 1) {
                swaps += cycle - 1;
            }
        }

        return swaps;
    }
};
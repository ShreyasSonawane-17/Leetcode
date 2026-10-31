class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long time = 0;
        long long total = 0;

        for(int i = 0; i<customers.size(); i++){
            time = max(time, (long long)customers[i][0]);

            time += customers[i][1];

            total += time - customers[i][0];
        }

        return (double) total/customers.size();
    }
};
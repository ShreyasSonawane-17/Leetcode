class Solution {
public:
    int total(string s) {

        int hrs = stoi(s.substr(0, 2));
        int mins = stoi(s.substr(3, 2));

        int time = hrs * 60 + mins;
        return time;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;

        for (int i = 0; i < timePoints.size(); i++) {
            v.push_back(total(timePoints[i]));
        }
        sort(v.begin(), v.end());

        int diff = 0;
        int mini = INT_MAX;
        for (int i = 0; i < v.size() - 1; i++) {
            diff = v[i + 1] - v[i];
            mini = min(mini, diff);
        }
        mini = min(mini, 1440 - v.back() + v[0]);

        return mini;
    }
};
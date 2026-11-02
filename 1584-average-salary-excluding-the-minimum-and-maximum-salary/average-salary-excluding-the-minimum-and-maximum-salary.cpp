class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        double ans = 0;
        int n = salary.size();
        int sum = 0;
        for(int i = 1; i<n-1; i++){
            sum += salary[i];
        }
        return (double)sum/(n-2);
    }
};
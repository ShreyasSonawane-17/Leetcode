class Solution {
public:
    int reverseDegree(string s) {
        int pro = 1;
        int sum = 0;
        for(int i = 0 ; i<s.length(); i++){
            char ch = s[i];
            pro =  ((i + 1) * ('z' - ch + 1));
            sum += pro;
        }

        return sum;
    }
};
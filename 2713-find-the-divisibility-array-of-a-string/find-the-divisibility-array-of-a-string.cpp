class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long prevrem = 0;
        for (int i = 0; i < word.length(); i++) {
            int currDigit = word[i] - '0';
            long long dividend = (prevrem * 10) + currDigit;

            int rem = (dividend % m);
            if (rem == 0)
                ans.push_back(1);
            else
                ans.push_back(0);

            prevrem = rem;
        }
        return ans;
    }
};
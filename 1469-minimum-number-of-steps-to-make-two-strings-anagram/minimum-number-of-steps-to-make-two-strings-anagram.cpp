
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        int cnt = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                cnt += freq[i];
        }

        return cnt;
    }
};

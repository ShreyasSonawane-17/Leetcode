class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp;

        for (auto x : words1) {
            mp[x]++;
        }

        unordered_map<string, int> mp2;

        for (auto x : words2) {
            mp2[x]++;
        }
        int cnt = 0;
        for (auto it : mp) {
            if (it.second == 1 && mp2.find(it.first) != mp2.end() &&
                mp2[it.first] == 1)
                cnt++;
        }

        return cnt;
    }
};
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        stringstream ss(s1);
        string word;
        while (ss >> word) {
            mp[word]++;
        }

        unordered_map<string, int> mp2;
        stringstream ss2(s2);
        string word2;
        while (ss2 >> word2) {
            mp2[word2]++;
        }

        vector<string> ans;

        for (auto it : mp) {
            if (mp2.find(it.first) == mp2.end() && it.second == 1)
                ans.push_back(it.first);
        }

        for (auto it : mp2) {
            if (mp.find(it.first) == mp.end() && it.second == 1)
                ans.push_back(it.first);
        }

        return ans;
    }
};
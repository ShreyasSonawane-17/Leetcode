class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                bool common = false;
                vector<int> freq(26, 0);
                for (char c : words[i]) {
                    freq[c - 'a'] = 1;
                }
                for (char c : words[j]) {
                    if (freq[c - 'a'] == 1) {
                        common = true;
                        break;
                    }
                    
                }

                if (!common) {
                    int pro = words[i].length() * words[j].length();
                    ans = max(ans, pro);
                }
            }
        }
        return ans;
    }
};
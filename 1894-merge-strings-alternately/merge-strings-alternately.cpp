class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        if(word1.length() == 0) return word2;
        if(word2.length() == 0) return word1;

        int i = 0;
        int j = 0;

        while(i < word1.length() || j < word2.length()){
            if(i<word1.length()){
                ans.push_back(word1[i]);
                i++;
            } 
            if(j<word2.length()){
                ans.push_back(word2[j]);
                j++;
            }
        }
        return ans;
    }
};
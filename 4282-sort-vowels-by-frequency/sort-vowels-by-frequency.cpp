class Solution {
public:
    string sortVowels(string s) {
        vector<int> freq(5, 0);
        string vowels = "aeiou";

        // Count frequencies
        for (char c : s) {
            int idx = vowels.find(c);
            if (idx != string::npos) {
                freq[idx]++;
            }
        }

        // Store vowels in order of first occurrence
        vector<char> order;
        vector<bool> seen(5, false);

        for (char c : s) {
            int idx = vowels.find(c);

            if (idx != string::npos && !seen[idx]) {
                order.push_back(c);
                seen[idx] = true;
            }
        }

        // Sort by frequency, keeping first occurrence order for ties
        sort(order.begin(), order.end(), [&](char a, char b) {
            int x = vowels.find(a);
            int y = vowels.find(b);

            return freq[x] > freq[y];
        });

        // Replace vowels
        int j = 0;

        for (char &c : s) {
            int idx = vowels.find(c);

            if (idx != string::npos) {
                int current = vowels.find(order[j]);
                c = order[j];

                freq[current]--;

                if (freq[current] == 0)
                    j++;
            }
        }

        return s;
    }
};
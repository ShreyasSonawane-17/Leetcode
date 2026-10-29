
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback,
                            vector<string>& negative_feedback,
                            vector<string>& report,
                            vector<int>& student_id, int k) {

        unordered_set<string> pos(positive_feedback.begin(),
                                  positive_feedback.end());
        unordered_set<string> neg(negative_feedback.begin(),
                                  negative_feedback.end());

        vector<pair<int, int>> v;

        for (int i = 0; i < report.size(); i++) {
            stringstream ss(report[i]);
            string word;
            int score = 0;

            while (ss >> word) {
                if (pos.count(word))
                    score += 3;
                else if (neg.count(word))
                    score -= 1;
            }

            v.push_back({score, student_id[i]});
        }

        sort(v.begin(), v.end(), [](auto a, auto b) {
            if (a.first != b.first)
                return a.first > b.first;

            return a.second < b.second;
        });

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};

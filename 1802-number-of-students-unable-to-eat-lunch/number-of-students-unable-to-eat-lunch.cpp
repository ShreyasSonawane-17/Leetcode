class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s = students.size();
        int m = sandwiches.size();
        int cnt = 0;

        int i = 0, j = 0;
        while(i < s && j<m){
            if(students[i] == sandwiches[j]){
                students.erase(students.begin() + i);
                j++;
                s--;
                cnt = 0;
                i = 0;
            }
            else{
                rotate(students.begin(),students.begin() + 1, students.end());
                cnt++;

                if(cnt == s) break;

            }
        }

        return s;
    }
};
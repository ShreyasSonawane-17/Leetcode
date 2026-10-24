class Solution {
public:
    bool isprime(int x){
        int fact = 0;
        for(int i = 1 ;i<=x; i++){
            if(x % i == 0) fact++;
        }
        if(fact == 2) return true;
        return false;
    }
    vector<int> dtb(int x){
        vector<int> s;
        while( x > 0){
            s.push_back(x%2);
            x = x / 2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        

        for(int i = left; i<= right; i++){
            int onecnt = 0;
            vector<int> v = dtb(i);
            for(int j = 0; j<v.size(); j++){
                if(v[j] == 1) onecnt++;
            }

            if(isprime(onecnt)) cnt++;
        }

        return cnt;
    }
};
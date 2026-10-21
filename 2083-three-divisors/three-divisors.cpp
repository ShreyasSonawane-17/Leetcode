class Solution {
public:
    int factors(int x){
        int cnt = 0;
        for(int i = 1; i<=x ;i++){
            if(x % i == 0) cnt++;
        }
        return cnt;
    }
    bool isThree(int n) {
        int a = factors(n);
        if( a == 3) return true;

        return false;
        
    }
};
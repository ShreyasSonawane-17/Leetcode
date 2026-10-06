class Solution {
public:
    bool isPrime(long long n) {
        if (n < 2)
            return false;

        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    long long sumOfLargestPrimes(string s) {
        set<long long> primes;

        for (int i = 0; i < s.length(); i++) {
            long long num = 0;

            for (int j = i; j < s.length(); j++) {
                num = num * 10 + (s[j] - '0');

                if (isPrime(num)) {
                    primes.insert(num);
                }
            }
        }

        vector<long long> ans(primes.begin(), primes.end());

        sort(ans.rbegin(), ans.rend());

        long long sum = 0;

        for (int i = 0; i < min(3, (int)ans.size()); i++) {
            sum += ans[i];
        }

        return sum;
    }
};
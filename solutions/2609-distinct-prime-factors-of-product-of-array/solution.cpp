class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> primes;

        for (int num : nums) {
            int x = num;
                for (int p = 2; p * p <= x; p++) {
                  while (x % p == 0) {
                     primes.insert(p);   
                     x /= p;
                    }
                }
            if (x > 1) primes.insert(x); 
        }
        return primes.size();
    }
};

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
   
        constexpr int primeMask = 665772; 
        int ans = 0;
        
        for (int num = left; num <= right; ++num) {
            int setBits = __builtin_popcount(num); 
            if ((primeMask >> setBits) & 1) {
                ++ans;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) {
            sum += x;
        }
        // remainder when sum is divided by k
        int remainder = sum % k;
        return remainder;  // if remainder == 0, answer is 0
    
        
    }
};

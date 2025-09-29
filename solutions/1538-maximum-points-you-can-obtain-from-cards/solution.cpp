class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int lsum = 0, rsum = 0, maxsum = 0;

        for (int i = 0; i < k; i++) {
            lsum += nums[i];
        }
        maxsum = lsum;

        int rindex = n - 1;

       
        for (int i = k - 1; i >= 0; i--) {
            lsum -= nums[i];          
            rsum += nums[rindex--];  
            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};



class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        
        // First subarray always starts at nums[0]
        int cost = nums[0];
        
        // Find two smallest elements in nums[1..n-1]
        int firstMin = INT_MAX, secondMin = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (nums[i] < firstMin) {
                secondMin = firstMin;
                firstMin = nums[i];
            } else if (nums[i] < secondMin) {
                secondMin = nums[i];
            }
        }
        
        return cost + firstMin + secondMin;

    }
};

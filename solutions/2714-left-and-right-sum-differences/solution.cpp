class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0), ans(n, 0);

        // Compute prefix sums (left side)
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] + nums[i - 1];
        }

        // Compute suffix sums (right side)
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] + nums[i + 1];
        }

        // Compute absolute difference
        for (int i = 0; i < n; i++) {
            ans[i] = abs(left[i] - right[i]);
        }

        return ans;
    }
};


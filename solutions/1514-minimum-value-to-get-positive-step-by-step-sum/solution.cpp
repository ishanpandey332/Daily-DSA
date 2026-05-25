class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, minSum = INT_MAX;
        for (int x : nums) {
            sum += x;
            minSum = min(minSum, sum);
        }
        return minSum >= 1 ? 1 : 1 - minSum;
    }
};

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
         if (n < 3) return false;

    int i = 0;

    // Step 1: strictly increasing prefix
    while (i + 1 < n && nums[i] < nums[i + 1]) i++;
    int p = i;

    // Step 2: strictly decreasing segment
    while (i + 1 < n && nums[i] > nums[i + 1]) i++;
    int q = i;

    // Step 3: strictly increasing suffix
    while (i + 1 < n && nums[i] < nums[i + 1]) i++;

    // Validity check
    return (p > 0 && q > p && q < n - 1 && i == n - 1);
}
};

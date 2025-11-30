class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int total = 0;
        for (int num : nums) total = (total + num) % p;
        if (total == 0) return 0;

        unordered_map<int, int> prefixMod;
        prefixMod[0] = -1;
        int prefix = 0, minLen = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            prefix = (prefix + nums[i]) % p;
            int target = (prefix - total + p) % p;
            if (prefixMod.count(target)) {
                minLen = min(minLen, i - prefixMod[target]);
            }
            prefixMod[prefix] = i;
        }

        return minLen == nums.size() ? -1 : minLen;

        
    }
};

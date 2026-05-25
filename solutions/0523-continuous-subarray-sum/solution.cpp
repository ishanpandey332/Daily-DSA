class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> seen; 
        seen[0] = -1; 
        int prefix = 0;
        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int rem = prefix % k;
            if(seen.count(rem)) {
                if(i - seen[rem] >= 2) return true;
            } else {
                seen[rem] = i;
            }
        }
        return false;
    }
};


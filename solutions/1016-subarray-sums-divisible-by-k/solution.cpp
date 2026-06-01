class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        long long prefixsum=0;
        int ans=0;
        for(int num : nums){
            prefixsum+=num;
            int rem=((prefixsum%k)+k)%k;
            ans+=mp[rem];
          mp[rem]++;

        }
        return ans;
        
    }
};

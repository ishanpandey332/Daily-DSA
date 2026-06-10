class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int ones=0;
        for(int i =0; i<n; i++){
            if(nums[i]==1){
                ones++;
            }
        }

        if(ones<1){
            return 0;
        }


        int zc=0;
        for(int i=0;i<ones;i++){
            if(nums[i]==0) zc++;

        }

        int ans=zc;
        for(int i=ones; i<n+ones; i++){
            if (nums[i % n] == 0) zc++;
            if (nums[(i - ones) % n] == 0) zc--;

            ans = min(ans, zc);

        }

        return ans;

        
    }
};

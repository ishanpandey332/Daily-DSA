class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int maxlen =0;\
        int countzeroes = 0;
        for(int right = 0;right<nums.size();right++){
            // nums[right]++;

            if(nums[right]==0){
                countzeroes++;
            }

            while(countzeroes>k){
                // nums[left]--;
                if(nums[left]==0){
                    countzeroes--;
                } 
                left++;    
            }
             maxlen = max(maxlen,right-left+1);
           
        }
        return maxlen;
    }
};

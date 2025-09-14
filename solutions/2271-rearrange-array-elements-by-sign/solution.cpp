class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n);
        int even_idx=0;
        int odd_idx=1;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                temp[even_idx]=nums[i];
                even_idx+=2;
            }
            else{
                temp[odd_idx]=nums[i];
                odd_idx+=2;

            }
        }
        nums = temp;

        return nums;
    }
};

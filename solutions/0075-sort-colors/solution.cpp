class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(),nums.end());

        // for(int i=0;i<nums.size();i++){
        //     cout<< nums[i];
        // }

        int n=nums.size();

        int l=0;
        int m=0;
        int h=n-1;

        while(m<=h){
            if(nums[m]==0){
                swap(nums[l++],nums[m++]);
            }

            else if(nums[m]==1){ m++;
            }

            else{
                swap(nums[m],nums[h--]);
            }

        }
        
    }
};

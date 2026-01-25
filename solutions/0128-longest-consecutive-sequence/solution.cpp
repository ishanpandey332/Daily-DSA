class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
         if (n == 0) return 0; 
        sort(nums.begin(),nums.end());
        int last=INT_MIN;
        int count=0;
        int longest=1;
        for(int i=0;i<n;i++){
            if(nums[i]-1==last){
                count++;
                last=nums[i];
            }
            else if(nums[i] != last){
                count=1;
                last=nums[i];
            }
            longest= max(longest,count);
        }
        return  longest;
    }
};

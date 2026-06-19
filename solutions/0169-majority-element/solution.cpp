// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         return nums[n/2];
        
//     }
// };


class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int> freq;
       int n=nums.size();
       for(int nm:nums){
        freq[nm]++;
        if(freq[nm]>n/2)  return nm;
       }

       return -1;
        
    }
};

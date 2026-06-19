class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum = sum + gain[i];
            ans = max(sum, ans);
        }
        return ans;
        
    }
};

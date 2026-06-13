class Solution {
public:

    // int count(int i, int n, vector<int> &dp){
    //     if(i==n) return 1;

    //     if(i>n) return 0;

    //     if(dp[i]!= -1) return dp[i];
    //     return dp[i]=count(i+1,n,dp) + count(i+2,n,dp);
    // }
    

    
    // int climbStairs(int n) {
        
    //     vector<int> dp(n+2,-1);
    //     return count(0,n,dp);
    // }

        // bottom up

    // int climbStairs(int n) {
        
    //     vector<int> dp(n+2,-1);
    //     dp[n]=1;
    //     dp[n+1]=0;
    //     for(int i=n-1;i>=0;i--)
    //     dp[i]=dp[i+1]+dp[i+2];
    //     return dp[0];
    // }


    // space opt
     int climbStairs(int n) {
        
        int curr, next=1, next2=0;
        
        
        for(int i=n-1;i>=0;i--){
        curr=next+next2;
        next2=next;
        next=curr;
        }
           
           
        return curr;
    }
};

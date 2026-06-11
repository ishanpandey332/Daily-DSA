class Solution {
public:
    // int fibon(int n, vector<int> &dp) {
    //     if(n<=1){
    //         return n;
    //     }
    //     if(dp[n]!= -1) return dp[n];

    //     return dp[n] = fibon(n-1,dp)+fibon(n-2,dp);
        
    // }

    int fib(int n){

        if (n<=1) return n;
        // vector<int> dp(n+1,-1);
        //  dp[0]=0;
        //  dp[1]=1;

        //  for(int i=2;i<=n;i++){
        //      dp[i]= dp[i-1]+dp[i-2];
        //  }

        //  return dp[n];

        int curr, prev =1, prev2=0;
        for(int i=2;i<=n;i++){
            curr = prev + prev2;

            prev2= prev;
            prev = curr;
        }
    return curr;
    }
};

class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int num = n; num < n +10;num++){
            if(dpp(num)%t==0)
            return num;
        }
        throw;
        
    }


    private:
    int dpp(int num){
        int dp = 1;
        while(num>0){
            dp *= num%10;
            num = num/10;
        }
        return dp;
    }

};

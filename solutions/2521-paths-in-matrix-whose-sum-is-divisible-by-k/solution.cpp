class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int MOD = 1e9 + 7;
        
        // 3D DP: dp[i][j][mod] = number of paths to (i,j) with sum % k == mod
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        
        dp[0][0][grid[0][0] % k] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int mod = 0; mod < k; ++mod) {
                    int newMod = (mod + grid[i][j]) % k;
                    if (i > 0)
                        dp[i][j][newMod] = (dp[i][j][newMod] + dp[i-1][j][mod]) % MOD;
                    if (j > 0)
                        dp[i][j][newMod] = (dp[i][j][newMod] + dp[i][j-1][mod]) % MOD;
                }
            }
        }
        
        return dp[m-1][n-1][0];

        
    }
};

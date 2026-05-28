class Solution {
public:
    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];
        int n = arr.size();
        int best = 1; // count current index

        // jump right
        for (int x = 1; x <= d && i + x < n; x++) {
            if (arr[i + x] >= arr[i]) break;
            best = max(best, 1 + dfs(i + x, arr, d, dp));
        }

        // jump left
        for (int x = 1; x <= d && i - x >= 0; x++) {
            if (arr[i - x] >= arr[i]) break;
            best = max(best, 1 + dfs(i - x, arr, d, dp));
        }

        return dp[i] = best;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, arr, d, dp));
        }
        return ans;
    }
};


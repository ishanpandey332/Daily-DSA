class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
                int m = mat.size(), n = mat[0].size();
        
        // Step 1: Build prefix sum matrix
        vector<vector<int>> prefix(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i+1][j+1] = mat[i][j] 
                                 + prefix[i][j+1] 
                                 + prefix[i+1][j] 
                                 - prefix[i][j];
            }
        }
        
        // Helper function: check if square of size L exists
        auto exists = [&](int L) {
            for (int i = L; i <= m; i++) {
                for (int j = L; j <= n; j++) {
                    int total = prefix[i][j] 
                              - prefix[i-L][j] 
                              - prefix[i][j-L] 
                              + prefix[i-L][j-L];
                    if (total <= threshold) return true;
                }
            }
            return false;
        };
        
        // Step 2: Binary search on side length
        int left = 0, right = min(m, n), ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (exists(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }


        
    
};

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> sortedNums;
        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            sortedNums.push_back(arr[i].first);
            pos[arr[i].second] = i;
        }

        int LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        LOG++;

        vector<vector<int>> jump(n, vector<int>(LOG));

        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n && sortedNums[r + 1] - sortedNums[i] <= maxDiff)
                r++;
            jump[i][0] = r;
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                jump[i][k] = jump[jump[i][k - 1]][k - 1];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int a = pos[q[0]];
            int b = pos[q[1]];

            if (a > b) swap(a, b);

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            if (jump[a][LOG - 1] < b) {
                ans.push_back(-1);
                continue;
            }

            int cur = a;
            int res = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (jump[cur][k] < b) {
                    cur = jump[cur][k];
                    res += (1 << k);
                }
            }

            ans.push_back(res + 1);
        }

        return ans;
    }
};

class Solution {
public:
    using ll = long long;

    struct Node {
        ll cnt;
        ll wav;
    };

    string s;
    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    Node dfs(int pos, int last1, int last2,
             bool started, bool tight) {

        if (pos == (int)s.size())
            return {1, 0};

        if (!tight && vis[pos][last1][last2][started][0])
            return dp[pos][last1][last2][started][0];

        int lim = tight ? s[pos] - '0' : 9;

        Node res = {0, 0};

        for (int d = 0; d <= lim; d++) {
            bool ntight = tight && (d == lim);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 10, 10, false, ntight);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
                continue;
            }

            if (!started) {
                Node nxt = dfs(pos + 1, d, 10, true, ntight);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
                continue;
            }

            int add = 0;

            if (last2 != 10) {
                if ((last1 > last2 && last1 > d) ||
                    (last1 < last2 && last1 < d))
                    add = 1;
            }

            Node nxt = dfs(pos + 1, d, last1, true, ntight);

            res.cnt += nxt.cnt;
            res.wav += nxt.wav + nxt.cnt * add;
        }

        if (!tight) {
            vis[pos][last1][last2][started][0] = true;
            dp[pos][last1][last2][started][0] = res;
        }

        return res;
    }

    long long solve(long long n) {
        if (n <= 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, false, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        auto melidroni = make_pair(num1, num2); // required by problem
        return solve(num2) - solve(num1 - 1);
    }
};

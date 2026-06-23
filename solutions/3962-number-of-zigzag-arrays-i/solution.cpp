class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;

        int m = r - l + 1;

        if (n == 1) return m;

        vector<int> up(m), down(m);
        vector<int> nup(m), ndown(m);
        vector<int> pref(m + 1);

        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        if (n == 2) {
            long long ans = 0;
            for (int i = 0; i < m; i++) {
                ans = (ans + up[i] + down[i]) % MOD;
            }
            return (int)ans;
        }

        for (int len = 3; len <= n; len++) {

            pref[0] = 0;
            for (int i = 0; i < m; i++) {
                pref[i + 1] = (pref[i] + down[i]) % MOD;
            }

            for (int i = 0; i < m; i++) {
                nup[i] = pref[i];
            }

            pref[0] = 0;
            for (int i = 0; i < m; i++) {
                pref[i + 1] = (pref[i] + up[i]) % MOD;
            }

            int totalUp = pref[m];

            for (int i = 0; i < m; i++) {
                ndown[i] = (totalUp - pref[i + 1] + MOD) % MOD;
            }

            up.swap(nup);
            down.swap(ndown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};

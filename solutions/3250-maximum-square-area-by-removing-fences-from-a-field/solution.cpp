class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hDiffs, vDiffs;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i+1; j < hFences.size(); j++) {
                hDiffs.insert(hFences[j] - hFences[i]);
            }
        }

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i+1; j < vFences.size(); j++) {
                vDiffs.insert(vFences[j] - vFences[i]);
            }
        }

        long long maxSide = -1;
        for (int d : hDiffs) {
            if (vDiffs.count(d)) {
                maxSide = max(maxSide, (long long)d);
            }
        }

        if (maxSide == -1) return -1;
        return (maxSide * maxSide) % MOD;
    }
};

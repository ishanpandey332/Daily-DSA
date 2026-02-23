class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = 1 << k;  
        if (s.size() < n) return false;

        vector<bool> seen(n, false);
        int window = 0;

        if (k > 1) {
            window = stoi(s.substr(0, k - 1), nullptr, 2);
        }

        for (int i = k - 1; i < s.size(); i++) {
            window = ((window << 1) & (n - 1)) + (s[i] - '0');
            seen[window] = true;
        }

        return all_of(seen.begin(), seen.end(), [](bool v) { return v; });
    }
};



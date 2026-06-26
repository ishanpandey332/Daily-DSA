class Fenwick {
public:
    vector<int> bit;
    int n;

    Fenwick(int sz) {
        n = sz;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        bool found = false;
        for (int x : nums)
            if (x == target) {
                found = true;
                break;
            }

        if (!found) return 0;

        Fenwick ft(2 * n + 5);

        int offset = n + 2;
        int pref = offset;

        ft.update(pref, 1);

        long long ans = 0;

        for (int x : nums) {
            if (x == target)
                pref++;
            else
                pref--;

            ans += ft.query(pref - 1);
            ft.update(pref, 1);
        }

        return ans;
    }
};

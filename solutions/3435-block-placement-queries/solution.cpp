class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAXX = 50000;

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(MAXX);

        vector<int> seg(4 * (MAXX + 1), 0);

        auto update = [&](auto&& self, int node, int l, int r,
                          int idx, int val) -> void {
            if (l == r) {
                seg[node] = val;
                return;
            }

            int mid = (l + r) >> 1;

            if (idx <= mid)
                self(self, node * 2, l, mid, idx, val);
            else
                self(self, node * 2 + 1, mid + 1, r, idx, val);

            seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
        };

        auto query = [&](auto&& self, int node, int l, int r,
                         int ql, int qr) -> int {
            if (qr < l || r < ql)
                return 0;

            if (ql <= l && r <= qr)
                return seg[node];

            int mid = (l + r) >> 1;

            return max(
                self(self, node * 2, l, mid, ql, qr),
                self(self, node * 2 + 1, mid + 1, r, ql, qr)
            );
        };

        update(update, 1, 0, MAXX, MAXX, MAXX);

        vector<bool> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                auto itR = obstacles.lower_bound(x);

                int right = *itR;
                int left = *prev(itR);

                update(update, 1, 0, MAXX, right, right - x);
                update(update, 1, 0, MAXX, x, x - left);

                obstacles.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];

                auto it = obstacles.lower_bound(x);

                int prevObs;

                if (it != obstacles.end() && *it == x)
                    prevObs = *prev(it);
                else
                    prevObs = *prev(it);

                int best = query(query, 1, 0, MAXX, 0, x);

                best = max(best, x - prevObs);

                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};

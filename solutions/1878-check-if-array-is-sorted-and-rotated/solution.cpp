#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int countBreaks = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i+1) % n]) {
                countBreaks++;
            }
        }

        return countBreaks <= 1;
    }
};


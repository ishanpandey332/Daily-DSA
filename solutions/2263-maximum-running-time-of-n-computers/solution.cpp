class Solution {
public:
bool canRun(long long time, int n, vector<int>& batteries) {
        long long total = 0;
        for (int b : batteries) {
            total += min((long long)b, time);
        }
        return total >= time * n;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
         long long left = 1, right = accumulate(batteries.begin(), batteries.end(), 0LL);
        long long ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRun(mid, n, batteries)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;

        
    }
};

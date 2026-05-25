class Solution {
public:
    int maxScore(string s) {
        int totalOnes = count(s.begin(), s.end(), '1');
        int zeros = 0, onesRight = totalOnes, maxScore = INT_MIN;
        
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') zeros++;
            else onesRight--;
            
            maxScore = max(maxScore, zeros + onesRight);
        }
        return maxScore;
    }
};

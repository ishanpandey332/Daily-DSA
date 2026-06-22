class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int letterCount[26] = {0};
      
        for (char c : text) {
            letterCount[c - 'a']++;
        }
      
        letterCount['o' - 'a'] /= 2;
        letterCount['l' - 'a'] /= 2;
      
        int maxBalloons = INT_MAX;
      
        string balloonLetters = "balon";
        for (char c : balloonLetters) {
            maxBalloons = min(maxBalloons, letterCount[c - 'a']);
        }
      
        return maxBalloons;
    }
};
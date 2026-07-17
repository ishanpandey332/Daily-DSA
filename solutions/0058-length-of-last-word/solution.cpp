
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == ' ') i--;

        int start = i;
        while (i >= 0 && s[i] != ' ') i--;

        return start - i;
    }
};


class Solution {
public:
    string processStr(string s) {
        string result;
      
        for (char c : s) {
            //  alphabetic, append it to result
            if (isalpha(c)) {
                result += c;
            } 
            // If  '*', remove the last character from result
            else if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } 
            // If '#', duplicate the current result string
            else if (c == '#') {
                result += result;
            } 
            // If '%', reverse the entire result string
            else if (c == '%') {
                std::reverse(result.begin(), result.end());
            }
        }
      
        return result;
    }
};


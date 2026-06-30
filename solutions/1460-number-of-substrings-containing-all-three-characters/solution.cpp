class Solution {
public:
    int numberOfSubstrings(string s) {
       
        int lastPosition[3] = {-1, -1, -1};
        int result = 0;
      
        for (int i = 0; i < s.size(); ++i) {
           
            lastPosition[s[i] - 'a'] = i;
          
           
            int minPosition = min(lastPosition[0], min(lastPosition[1], lastPosition[2]));
          
           
            result += minPosition + 1;
        }
      
        return result;
    }
};


class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
        int fv = 0;  
        int tn = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 5) {
                fv++;
            } else if(arr[i] == 10) {
                if(fv) {
                    fv--;
                    tn++;
                } else {
                    return false;
                }
            } else {  
                if(tn && fv) {
                    tn--;
                    fv--;
                } else if(fv >= 3) {
                    fv -= 3;
                } else {
                    return false;
                }
            }
        }

        return true; 
    }
};

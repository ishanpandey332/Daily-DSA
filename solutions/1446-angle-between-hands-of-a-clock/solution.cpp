class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = (hour % 12) * 30 + minutes * 0.5;
        double mins = minutes * 6;

        double diff = abs(hr - mins);

        return min(diff, 360.0 - diff);
        
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int mw= 0, lp =0, rp= height.size()-1;
         while (lp<rp){
            int w =rp - lp,ht= min(height[lp],height[rp]),cw= ht*w;
            mw= max(mw,cw);
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return mw;
        
    }
};

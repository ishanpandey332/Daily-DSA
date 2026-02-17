class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size());
        
        for (int i = 2 * nums.size() - 1; i >= 0; i--) {
            int idx = i % nums.size();
            
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }
            
            ans[idx] = st.empty() ? -1 : st.top();
            st.push(nums[idx]);
        }
        
        return ans;
    }
};

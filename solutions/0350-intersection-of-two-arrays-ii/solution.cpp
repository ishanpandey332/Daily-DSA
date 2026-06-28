class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> frequencyMap;

        for (int element : nums1) {
            ++frequencyMap[element];
        }

        vector<int> result;

        for (int element : nums2) {
           
            if (frequencyMap[element]-- > 0) {
                result.push_back(element);
            }
        }

        return result;
    }
};


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                first = num; // Update smallest element found so far
            } else if (num <= second) {
                second = num; // Update second smallest element
            } else {
                // If num is greater than both first and second, we found a triplet!
                return true;
            }
        }
        return false;
    }
};
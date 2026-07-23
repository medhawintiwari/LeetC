class Solution {
public:
    int finddays(int cap, vector<int>& wt) {
        int day = 1, load = 0;
        for (int i = 0; i < wt.size(); i++) {
            if (load + wt[i] > cap) {
                day += 1;
                load = wt[i];
            } else {
                load += wt[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // range of capacity will be from the max value of weights till the
        // total sum of weights reason: the ship will only be able to carry
        // everything if its capacity is atleast equal or more than equal to the
        // largest weight the sum of weights will get the work done in 1 day
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (high >= low) {
            int mid = (low + high) / 2;
            int numberofdays = finddays(mid, weights);
            if (numberofdays <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
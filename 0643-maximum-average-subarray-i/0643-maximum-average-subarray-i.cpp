class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int current_sum=0;
        //sum of first k elements
        for (int i=0; i<k; i++) {
            current_sum+=nums[i];
        }
        int max_sum = current_sum;

        //slide window
        for (int i=k; i<nums.size(); i++) {
            current_sum+=nums[i]-nums[i-k];
            max_sum=max(max_sum, current_sum);
        }

        return (double)max_sum/k;
    }
};
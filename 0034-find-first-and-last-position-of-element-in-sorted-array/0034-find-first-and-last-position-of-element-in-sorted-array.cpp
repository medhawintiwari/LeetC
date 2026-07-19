class Solution {
public:

    int firstocc(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] > target) {
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                st = mid + 1;
            }
            else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }

    int lastocc(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] > target) {
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                st = mid + 1;
            }
            else {
                ans = mid;
                st = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstocc(nums, target);
        int last = lastocc(nums, target);
        return {first, last};
    }
};
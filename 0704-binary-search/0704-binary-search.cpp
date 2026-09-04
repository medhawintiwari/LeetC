class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, st, end;
        st=0;
        end=nums.size()-1;
        mid=st+(end-st)/2;
        while(st<=end) {
            mid=st+(end-st)/2;
            if (nums[mid]>target) {
                end=mid-1;
            } 
            else if (nums[mid]<target) {
                st=mid+1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
    
};

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n= arr.size();
        int low=0;
        int high=n-1;
        while (low<=high) {
            int mid=(high+low)/2;
            if (arr[mid]==target) {
                return mid;
            }
            else if ( arr[low]<=arr[mid]) //left sorted
            {
                if (arr[low]<=target && arr[mid]>=target) {
                    high=mid-1;
                }
                else {
                    low=mid+1;
                }
            }
            else {
                if (arr[mid]<=target && target<=arr[high]) {
                    low=mid+1;
                }
                else {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
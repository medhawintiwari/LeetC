class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n= arr.size();
        
        if (n==1) return arr[0];  //just one element in the array
       
        if (arr[0]!=arr[1]) return arr[0];  //first element single
       
        if (arr[n-2]!=arr[n-1]) return arr[n-1];  //last element single
        
        int low=1;   //shorter search space
        int high=n-2;
        while (low<=high) {
            int mid=(low+high)/2;
            
            if (arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) {  //if mid is the single element
                return arr[mid];
            }
            
            if (((mid%2==1)&&(arr[mid-1]==arr[mid])) || ((mid%2==0) && (arr[mid+1]==arr[mid]))) {  //if we at left half
                low=mid+1;
            }
            
            else {  //if we at right half
                high=mid-1;
            }

        }
        return -1;
    }
};
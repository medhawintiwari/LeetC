class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (k < nums[i]) {
                k = nums[i];
            }
        }
        int c[201];
        vector<int> b(n);
        for (int i = 0; i <= 200 ; i++) {
            c[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            c[nums[i] + 100] = c[nums[i] + 100] + 1;
        }
        
        int max_f = 0;
        for (int i = 0; i <= 200; i++) {
            if (c[i] > max_f) {
                max_f = c[i];
            }
        }
        int ind = 0;
        for (int f = 1; f <= max_f; f++) {
            // FIX: Run this loop backwards (from 200 down to 0)
            // This ensures larger numbers come first when frequencies are equal
            for (int i = 200; i >= 0; i--) {
                if (c[i] == f) {
                    for (int j = 0; j < f; j++) {
                        b[ind] = i - 100; 
                        ind++;
                    }
                }
            }
        }
        return b;
    }
};
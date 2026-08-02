class Solution {
public:

bool canweplace(vector<int> &pos, int dist, int m) {
    int countm = 1, last = pos[0];
    for (int i=1 ; i<pos.size(); i++) {
        if (pos[i] - last >= dist) {
            countm++;
            last = pos[i];
        }
        if(countm>= m) return true;
    }
    return false;
}
    int maxDistance(vector<int>& position, int m) {
        sort (position.begin(), position.end());
        int n = position.size();
        int low = 1, high = position[n-1] - position[0];
        while (low <= high) {
            int mid = (low +high) /2;
            if (canweplace(position, mid, m)== true) {
                low = mid+1;
            }
            else {
                high = mid -1;
            }
        }
        return high;

    }
};
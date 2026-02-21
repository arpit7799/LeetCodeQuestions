class Solution {
public:
    
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;
        
        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;   // reset after making bouquet
                }
            } else {
                flowers = 0;      // break adjacency
            }
        }
        
        return bouquets >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        long long required = 1LL * m * k;
        if (required > bloomDay.size()) 
            return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;   // try smaller day
            } else {
                low = mid + 1;    // need more days
            }
        }
        
        return ans;
    }
};
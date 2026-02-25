class Solution {
public:

    int computeSum(vector<int>& nums, int div) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + div - 1) / div;  // ceiling division
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (computeSum(nums, mid) <= threshold) {
                ans = mid;
                high = mid - 1;   // try smaller divisor
            } else {
                low = mid + 1;    // need bigger divisor
            }
        }

        return ans;
    }
};
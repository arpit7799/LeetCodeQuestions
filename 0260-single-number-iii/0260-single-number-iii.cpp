class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int xr = 0;

        for (int num : nums)
            xr ^= num;

        long long diff = (long long)xr & (-(long long)xr);

        int a = 0, b = 0;

        for (int num : nums) {
            if (num & diff)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};
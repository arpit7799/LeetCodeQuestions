class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int ans = 0;
        int r = 0;
        int s = 0;
        for(r;r<k;r++)
        {
            s+=arr[r];
        }
        if(s/k >= threshold) ans++;
        int l = 0;
        while(r<arr.size())
        {
            s+=arr[r];
            s-=arr[l];
            if(s/k >= threshold) ans++;
            l++;
            r++;
        }
        return ans;
    }
};
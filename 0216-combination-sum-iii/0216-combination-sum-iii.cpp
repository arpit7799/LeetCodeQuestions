class Solution {
public:

    void solve(int num,
               int k,
               int target,
               vector<int>& curr,
               vector<vector<int>>& ans){
        
        if(target == 0 && curr.size() == k){
            ans.push_back(curr);
            return;
        }
        
        if(num > 9 || target < 0 || curr.size() > k)
            return;
        
        // Take
        curr.push_back(num);
        
        solve(num + 1,
              k,
              target - num,
              curr,
              ans);
        
        curr.pop_back();
        
        // Not Take
        solve(num + 1,
              k,
              target,
              curr,
              ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        vector<int> curr;
        
        solve(1, k, n, curr, ans);
        
        return ans;
    }
};
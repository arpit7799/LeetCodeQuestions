class Solution {
public:

    void solve(int idx,
               string& digits,
               string& curr,
               vector<string>& ans,
               vector<string>& mp){
        
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }
        
        string letters = mp[digits[idx] - '0'];
        
        for(char ch : letters){
            
            curr.push_back(ch);
            
            solve(idx + 1,
                  digits,
                  curr,
                  ans,
                  mp);
            
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        if(digits.empty())
            return {};
        
        vector<string> mp = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
        
        vector<string> ans;
        string curr;
        
        solve(0, digits, curr, ans, mp);
        
        return ans;
    }
};
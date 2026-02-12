class Solution {
public:
    void backtrack(int o,int c,int n,string& ans,vector<string>& res){
        if (ans.size()==2*n){
            res.push_back(ans);
            return;
        }
        if (o<n){
            ans.push_back('(');
            backtrack(o+1,c,n,ans,res);
            ans.pop_back();
        }
        if (o>c){
            ans.push_back(')');
            backtrack(o,c+1,n,ans,res);
            ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string ans;
        vector<string> res;
        backtrack(0,0,n,ans,res);
        return res;
    }
};
class Solution {
public:
    void solve(string op, int open, int close, vector<string> &ans){
        // Base case: both open and close are used up
        if (open == 0 && close == 0) {
            ans.push_back(op);
            cout << "Adding to result: " << op << endl;
            return;
        }
        // When open and close are the same, we can only add '('
        if (open == close) {
            solve(op + '(', open - 1, close, ans);
        }
        // When no open parentheses are left, we can only add ')'
        else if (open == 0) {
            solve(op + ')', open, close - 1, ans);
        }
        // When no close parentheses are left, we can only add '('
        else if (close == 0) {
            solve(op + '(', open - 1, close, ans);
        }
        // Otherwise, we have a choice to add '(' or ')'
        else {
            solve(op + '(', open - 1, close, ans);
            solve(op + ')', open, close - 1, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> ans;
        string op = "";
        solve(op, open, close, ans);
        return ans;
    }
};
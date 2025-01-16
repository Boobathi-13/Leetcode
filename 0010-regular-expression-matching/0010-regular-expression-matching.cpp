class Solution {
public:
    string s1, s2;
    int m, n;
    int dp[21][21]; // Constraints ensure lengths ≤ 20

    int fn(int i, int j) {
        if (j >= n) return i >= m; // If pattern is finished, check if string is also finished

        if (dp[i][j] != -1) return dp[i][j];

        // Check if current characters match or if pattern has '.'
        bool match = (i < m) && (s1[i] == s2[j] || s2[j] == '.');

        if (j + 1 < n && s2[j + 1] == '*') { // Handle '*'
            return dp[i][j] = (fn(i, j + 2) || // Skip the '*' and preceding character
                               (match && fn(i + 1, j))); // Use '*' to match current character
        } else {
            return dp[i][j] = match && fn(i + 1, j + 1); // Regular character match
        }
    }

    bool isMatch(string s, string p) {
        s1 = s, s2 = p;
        m = s1.size(), n = s2.size();
        memset(dp, -1, sizeof(dp)); // Initialize dp array
        return fn(0, 0); // Start matching from the beginning
    }
};

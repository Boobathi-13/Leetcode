/*
f(i): total appeal of all substrings ending at index i
f(i) = f(i-1)+(i)-(lastIndex[s[i]])
base case:
f(0) = 1
ans = sum(f(i)) where i = 0 to s.length
*/
class Solution {
    public long appealSum(String s) {
        int n = s.length();
        // keeps track of the last index of cur character in for loop
        int[] lInd = new int[26];
        Arrays.fill(lInd, -1);
        // dp[i]: total appeal of all substrings ending at index i-1
        // here dp is running one step ahead of f defined above
        // i.e. dp[i+1] = f(i), dp[0] = 0
        long[] dp = new long[n+1];
        long res = 0l;
        for(int i = 0; i < n; i ++) {
            int c = s.charAt(i)-'a';
            dp[i+1] = dp[i]+i-lInd[c];
            res += dp[i+1];
            // set last index so that it can be used if character 'c' occurs again after ith index 
            lInd[c] = i;
        }
        return res;
    }
}
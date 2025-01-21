int climbStairs(int n) {

    // As same a fibonacci problem
    int dp[n+1];

    dp[0] = 1; // This alone changes
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}
int fib1(int n, int dp[]) {
    if (n <= 1) return n; // Base cases: fib(0) = 0, fib(1) = 1
    if (dp[n] != -1) return dp[n]; // Use precomputed result if available
    dp[n] = fib1(n-1,dp) + fib1(n-2,dp); // Recursively compute and store result
    return dp[n];
}

int fib(int n) {
    int dp[31];
    memset(dp, -1, sizeof(dp)); // Initialize all values to -1
    return fib1(n,dp);
}
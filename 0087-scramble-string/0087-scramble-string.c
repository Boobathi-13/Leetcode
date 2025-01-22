#define MAX_LEN 30

bool isScramble(char *s1, char *s2) {
    int n = strlen(s1);
    if (n != strlen(s2)) return false;

    // DP table initialization
    bool dp[MAX_LEN + 1][MAX_LEN][MAX_LEN] = {{{false}}};

    // Base case: k = 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[1][i][j] = (s1[i] == s2[j]);
        }
    }

    // Fill DP table for lengths k = 2 to n
    for (int k = 2; k <= n; k++) { // Length of the substring
        for (int i = 0; i <= n - k; i++) { // Start index in s1
            for (int j = 0; j <= n - k; j++) { // Start index in s2
                for (int p = 1; p < k; p++) { // Split point
                    // No swap case
                    if (dp[p][i][j] && dp[k - p][i + p][j + p]) {
                        dp[k][i][j] = true;
                        break;
                    }
                    // Swap case
                    if (dp[p][i][j + k - p] && dp[k - p][i + p][j]) {
                        dp[k][i][j] = true;
                        break;
                    }
                }
            }
        }
    }

    return dp[n][0][0];
}
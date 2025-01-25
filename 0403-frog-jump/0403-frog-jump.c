
// Define the maximum number of stones
#define MAX_STONES 2000

// A helper function to find if a given value exists in an array
bool find(int* stones, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (stones[i] == value) return true;
    }
    return false;
}

// Main function to check if the frog can cross
bool canCross(int* stones, int stonesSize) {
    // Base case: If the second stone is not at 1, return false
    if (stones[1] != 1) return false;

    // Create a 2D dynamic array to store possible jump sizes
    bool dp[MAX_STONES][MAX_STONES];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;  // Starting position, no jump required

    for (int i = 0; i < stonesSize; i++) {
        for (int k = 0; k < stonesSize; k++) {
            if (dp[i][k]) {
                // Calculate next positions based on jump sizes k-1, k, k+1
                for (int step = k - 1; step <= k + 1; step++) {
                    if (step > 0 && find(stones, stonesSize, stones[i] + step)) {
                        int index = 0;
                        while (stones[index] != stones[i] + step) index++;
                        dp[index][step] = true;
                    }
                }
            }
        }
    }

    // Check if any jump size reaches the last stone
    for (int k = 0; k < stonesSize; k++) {
        if (dp[stonesSize - 1][k]) return true;
    }
    return false;
}

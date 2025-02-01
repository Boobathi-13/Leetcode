#define MAX_LEN 300

// Function to check if a word exists in the dictionary
bool isInDict(char *word, char **wordDict, int wordDictSize) {
    for (int i = 0; i < wordDictSize; i++) {
        if (strcmp(wordDict[i], word) == 0) {
            return true;
        }
    }
    return false;
}

bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    int len = strlen(s);
    bool dp[MAX_LEN + 1] = {false};  // dp[i] means s[0:i] can be segmented
    dp[0] = true; // Base case: empty string

    // Iterate over the string
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            char subStr[MAX_LEN + 1];
            strncpy(subStr, s + j, i - j);
            subStr[i - j] = '\0';

            if (dp[j] && isInDict(subStr, wordDict, wordDictSize)) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[len];
}

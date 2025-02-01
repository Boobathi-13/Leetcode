char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0) return s;
    
    int start = 0, maxLength = 1;
    
    // Helper function to expand around center
    int expandAroundCenter(char* s, int left, int right) {
        while (left >= 0 && right < len && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    for (int i = 0; i < len; i++) {
        // Check for odd-length palindromes
        int len1 = expandAroundCenter(s, i, i);
        // Check for even-length palindromes
        int len2 = expandAroundCenter(s, i, i + 1);
        
        // Get the maximum length from the two cases
        int maxLen = (len1 > len2) ? len1 : len2;
        
        if (maxLen > maxLength) {
            maxLength = maxLen;
            start = i - (maxLen - 1) / 2;
        }
    }

    // Allocate memory for the result and return it
    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';
    return result;
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

bool isAnagram(char* s, char* t) {
    // If lengths are different, they can't be anagrams
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // Create arrays to count the frequency of each character
    int count[ALPHABET_SIZE] = {0};

    // Traverse through both strings and update the character count
    for (int i = 0; i < strlen(s); i++) {
        count[s[i] - 'a']++; // Increment count for s[i]
        count[t[i] - 'a']--; // Decrement count for t[i]
    }

    // If the strings are anagrams, all counts should be 0
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int repeatedStringMatch(char* a, char* b) {
    int n = strlen(a);
    int m = strlen(b);

    // Calculate the maximum size needed for the repeated string
    int max_repeats = m / n + 3; // At most `m/n + 2` repetitions are sufficient
    char *temp = (char *)malloc((max_repeats * n + 1) * sizeof(char));

    // Initialize `temp` with an empty string
    temp[0] = '\0';

    int count = 0;
    // Repeatedly concatenate `a` until `temp` length >= `m`
    while (strlen(temp) < m) {
        strcat(temp, a);
        count++;
    }

    printf("%d\n",count);

    // Check if `b` is a substring of `temp`
    if (strstr(temp, b)) {
        free(temp);
        return count;
    }

    // Concatenate one more time and check again
    strcat(temp, a);
    count++;

    if (strstr(temp, b)) {
        free(temp);
        return count;
    }

    // If no match is found, return -1
    free(temp);
    return -1;
}
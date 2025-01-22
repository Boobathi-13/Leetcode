bool areOccurrencesEqual(char* s) {
    int hash[26];
    int n = strlen(s), k = 0;

    for(int i=0; i<n; i++) hash[s[i]-'a']++;
    for(int i=0; i<26; i++) if(hash[i]!=0 && (hash[s[0]-'a'] != hash[i])) return false;
    return true;
}
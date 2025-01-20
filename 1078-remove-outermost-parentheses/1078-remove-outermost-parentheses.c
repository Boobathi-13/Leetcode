char* removeOuterParentheses(char* s) {
    int j = 0;
    int count = 0;
    int n = strlen(s);
    char* res = (char*)malloc(sizeof(char)*n);
    for(int i=0; i<n; i++){
        if((s[i]=='(' && ++count!=1) || (s[i]==')' && --count!=0)) res[j++]=s[i];
    }
    res[j]='\0';
    return res;
}
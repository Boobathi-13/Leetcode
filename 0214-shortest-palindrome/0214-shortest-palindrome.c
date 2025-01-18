char* shortestPalindrome(char* s) {
    int n = strlen(s);
    char* a=(char*)malloc((sizeof(char))*2*n+1);
    int i=0,j;
    for(j=n-1; j>=0; j--) {
        a[j]=s[i];
        i++;
    }
    int k=0,m=0;
    while(s[k]!='\0') {
        int t=k;
        m=0;
        while(t<n) {
            if(s[m]!=a[t]) break;
            t++;
            m++;
        }
        if(t==n) break;
        k++;
    }
    while(s[m]!='\0') {
        a[i]=s[m];
        m++;
        i++;
    }
    a[i] = '\0';
    return a;
}
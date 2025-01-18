char* shortestPalindrome(char* s) {
    if(strlen(s)<2)
        return s;
    char *a = (char*)malloc(sizeof(char) * strlen(s) * 2 + 1);
    int i;
    for(i=0;i<strlen(s);i++){
        a[i] = s[strlen(s)-1-i];
    }

    int j=0,k=0,t=0;
    while(s[j] != '\0'){
        int c = k;
         t = 0;
        while(c<i){
            if(s[t] != a[c])
                break;
            t++;
            c++;
        } 
        if(c == i)
            break;
        k++;       

    }
    while(s[t] != '\0'){
        a[i] = s[t];
        i++;
        t++;
    }
    a[i] = '\0';
    return a;
}
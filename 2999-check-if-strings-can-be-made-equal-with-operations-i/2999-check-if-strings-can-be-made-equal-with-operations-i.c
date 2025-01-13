bool canBeEqual(char* s1, char* s2) {
    if(strcmp(s1,s2)==0) return true;
    void swap(char* s1, int i, int j) {
        char temp = s1[i];
        s1[i] = s1[j];
        s1[j] = temp;
    }

    char s1c1[5], s1c2[5];

    strcpy(s1c1,s1);
    strcpy(s1c2,s1);

    swap(s1c1,0,2);
    swap(s1c2,1,3);

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(j-i == 2) swap(s1,i,j);
        }
    }
    
    if(strcmp(s1c1,s2)==0 || strcmp(s1c2,s2)==0 || strcmp(s1,s2)==0) return true;
    return false;
}
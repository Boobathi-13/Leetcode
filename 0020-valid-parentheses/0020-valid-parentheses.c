bool isValid(char* s) {
    char stack[10000];
    int top = -1;
    for(int i=0; i<strlen(s); i++) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') s[++top]=s[i];
        else if(top!= -1 && s[i]==')' && s[top]=='(') top--;
        else if(top!= -1 && s[i]=='}' && s[top]=='{') top--;
        else if(top!= -1 && s[i]==']' && s[top]=='[') top--;
        else return false;
    }
    if(top==-1) return true;
    else return false;
}
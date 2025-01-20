bool isValid(char* s) {
    int n = strlen(s);
    char stack[10000];
    int top = -1;
    for(int i=0; i<n; i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='[') stack[++top]=s[i];
        else{
            if(top>=0 && (stack[top]=='('&&s[i]==')' || stack[top]=='{'&&s[i]=='}' || stack[top]=='['&&s[i]==']')) top--;
            else return false;
        }
    }
    if(top == -1) return true;
    else return false;
}
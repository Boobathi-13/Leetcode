int scoreOfParentheses(char * s){
    int res=0, balance=0;
    for(int index=0; s[index]; ++index){
        if(s[index]=='('){
            balance++;
        }
        else{ // When s[index] == ')'
            balance--;
            if(s[index-1]=='('){
                res = res + pow(2,balance);
            }
        }
    }
    return res;
}
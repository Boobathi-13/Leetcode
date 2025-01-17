int scoreOfParentheses(char * S){
    int res = 0, balance = 0;
    for ( int index = 0; S[index]; ++index )
    {
        balance += S[index] == '(' ? 1 : -1;
        if ( index && S[index - 1] == '(' && S[index] == ')' )
            res += pow( 2, balance );
    }
    return res;
}
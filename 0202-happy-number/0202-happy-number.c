bool isHappy(int n) {
    int compute(int n){
        int output = 0;
        while(n>0){
            int digit = n%10;
            output = output + digit*digit;
            n /= 10;
        }
        return output;
    }
    do{
        n = compute(n);
    }
    while(n!=1 && n!=4);
    if(n==1)
        return true;
    return false;
}
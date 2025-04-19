class Solution {
    public String convertToBase7(int num) {
        int flag = 0;
        int m = 1;
        if(num<0) {
            num = -num;
            flag = 1;
        }

        if(num == 0) return "0";

        int ans = 0;
        int n = 0;
        while(num>0) {
            n = num % 7;
            n = n * m;
            m *= 10;
            ans = ans + n;
            num /= 7;
        }
        if(flag == 1){
            ans = -ans;
        }
        String res = String.valueOf(ans);
        return res;
    }
}
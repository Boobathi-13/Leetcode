import java.util.*;

class Solution {
    public String solve(String s) {
        StringBuilder ans = new StringBuilder();
        int tmp = 0;

        for (char ch : s.toCharArray()) {
            tmp = tmp * 10 + (ch - '0');
        }

        while (tmp > 0) {
            ans.insert(0, (tmp % 2 == 0) ? "0" : "1");
            tmp /= 2;
        }

        return ans.toString();
    }

    public String convertDateToBinary(String s) {
        return solve(s.substring(0, 4)) + "-" + solve(s.substring(5, 7)) + "-" + solve(s.substring(8, 10));
    }
}
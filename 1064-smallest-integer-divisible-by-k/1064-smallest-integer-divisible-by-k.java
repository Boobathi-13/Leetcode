class Solution {
    public int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        
        int phi = get_euler(k * 9);
        int res = phi;
        for (int i = 1; i <= phi / i; i++) {
            if (phi % i == 0) {
                if (qmi(10, i, 9 * k) == 1) return i;
                if (qmi(10, phi / i, 9 * k) == 1) res = Math.min(res, phi / i);
            }
        }
        return res;
    }
    private int get_euler(int x) {
        int res = x;
        for (int i = 2; i <= x / i; i++) {
            if (x % i == 0) {
                res = res / i * (i - 1);
                while (x % i == 0) x /= i;
            }
        }
        if (x > 1) res = res / x * (x - 1);
        return res;
    }
    private long qmi(long a, long k, long p) {
        long res = 1;
        while (k > 0) {
            if ((k & 1) == 1) res = res * a % p;
            a = a * a % p;
            k >>= 1;
        }
        return res;
    }
}
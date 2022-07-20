int gcd(int m, int n) {
    int rem, gcd;
    while (n != 0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    gcd = m;
}
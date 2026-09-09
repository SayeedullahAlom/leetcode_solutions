class Solution {
public:
    long long countCommas(long long n) {
        long long k = 0;

        if (n <= 999)
            return 0;

        // 1 comma
        if (n <= 999999)
            return n - 1000 + 1;

        k += 999999 - 1000 + 1;

        // 2 commas
        if (n <= 999999999)
            return k + (n - 1000000 + 1) * 2;

        k += (999999999 - 1000000 + 1) * 2;

        // 3 commas
        if (n <= 999999999999LL)
            return k + (n - 1000000000LL + 1) * 3;

        k += (999999999999LL - 1000000000LL + 1) * 3;

        // 4 commas
        if (n <= 999999999999999LL)
            return k + (n - 1000000000000LL + 1) * 4;

        k += (999999999999999LL - 1000000000000LL + 1) * 4;

        // 5 commas
        return k + (n - 1000000000000000LL + 1) * 5;
    }
};
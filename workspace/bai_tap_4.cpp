fraction addFrac(fraction otherFraction) {
    fraction tong;
    tong.numerator = numerator*otherFraction.denominator + otherFraction.numerator*denominator;
    tong.denominator = denominator*otherFraction.denominator;
    int max;
        if (tong.numerator >= tong.denominator) max = tong.numerator;
        else max = tong.denominator;
        for (int i = max; i >= 2; i--) {
            if (tong.denominator % i == 0 && tong.numerator % i == 0) {
                tong.denominator/=i;
                tong.numerator/=i;
            }
        }
    return tong;
}
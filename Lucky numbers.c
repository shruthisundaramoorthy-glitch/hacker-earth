#include <stdio.h>
#include <stdbool.h>

bool isLucky(long long n) {

    if(n == 0)
        return false;

    while(n > 0) {

        int digit = n % 10;

        if(digit % 2 == 0) {
            return false;
        }

        n /= 10;
    }

    return true;
}

int main() {

    long long N;
    scanf("%lld", &N);

    long long d = 0;

    while(1) {

        
        if(N - d >= 0 && isLucky(N - d)) {
            printf("%lld\n", N - d);
            break;
        }

        if(isLucky(N + d)) {
            printf("%lld\n", N + d);
            break;
        }

        d++;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {

    int T;
    scanf("%d", &T);

    while(T--) {

        int N, K;
        scanf("%d %d", &N, &K);

        int A[N];

        long long sum = 0;

        for(int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            sum += A[i];
        }

     
        qsort(A, N, sizeof(int), compare);

        
        for(int i = N - K; i < N; i++) {
            sum += A[i];
        }

        printf("%lld\n", sum);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {

    int T;
    scanf("%d", &T);

    while(T--) {

        int N, K;
        scanf("%d %d", &N, &K);

        int A[N], B[N];

        long long sum = 0;

        for(int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            sum += A[i];
        }

        for(int i = 0; i < N; i++) {
            scanf("%d", &B[i]);
        }

        int diff[N];
        int cnt = 0;

      
        for(int i = 0; i < N; i++) {

            if(B[i] > A[i]) {
                diff[cnt++] = B[i] - A[i];
            }
        }

  
        qsort(diff, cnt, sizeof(int), compare);

       
        for(int i = 0; i < cnt && i < K; i++) {
            sum += diff[i];
        }

        printf("%lld\n", sum);
    }

    return 0;
}
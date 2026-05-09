#include <stdio.h>

int main() {

    int T;
    scanf("%d", &T);

    while(T--) {

        int N, M;
        scanf("%d %d", &N, &M);

        int A[N], B[M];

        long long sumA = 0, sumB = 0;

        for(int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            sumA += A[i];
        }

        for(int i = 0; i < M; i++) {
            scanf("%d", &B[i]);
            sumB += B[i];
        }

       
        if(sumA != sumB) {
            printf("-1\n");
            continue;
        }

        int i = 0, j = 0;
        long long currA = 0, currB = 0;
        int count = 0;

        while(i < N || j < M) {

            if(currA == currB) {

                if(currA != 0) {
                    count++;
                }

                if(i < N) currA = A[i++];
                else currA = 0;

                if(j < M) currB = B[j++];
                else currB = 0;
            }
            else if(currA < currB) {
                currA += A[i++];
            }
            else {
                currB += B[j++];
            }
        }

     
        if(currA == currB) {
            count++;
        }

        printf("%d\n", count);
    }

    return 0;
}
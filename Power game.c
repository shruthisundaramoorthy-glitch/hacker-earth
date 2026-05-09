#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    int A[M];

    for(int i = 0; i < M; i++) {
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
    }

    qsort(A, M, sizeof(int), compare);

    long long maxScore = 0;
    long long minScore = 0;

  
    for(int i = 0; i < M; i += 2) {
        maxScore += A[i];
    }

    
    for(int i = 1; i < M; i += 2) {
        minScore += A[i];
    }

    printf("%lld %lld\n", maxScore, minScore);

    return 0;
}
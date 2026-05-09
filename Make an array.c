#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int solve (int N, int* A) {

    long long sum = 0;

    for(int i = 0; i < N; i++) {
        sum += A[i];
    }

    
    if(sum % (N - 1) != 0) {
        return -1;
    }

    long long x = sum / (N - 1);


    for(int i = 0; i < N; i++) {
        if(A[i] > x) {
            return -1;
        }
    }

    return (int)x;
}

int main() {

    int T;
    scanf("%d", &T);

    for(int t_i = 0; t_i < T; t_i++) {

        int N;
        scanf("%d", &N);

        int *A = (int *)malloc(sizeof(int) * N);

        for(int i_A = 0; i_A < N; i_A++) {
            scanf("%d", &A[i_A]);
        }

        int out_ = solve(N, A);

        printf("%d\n", out_);

        free(A);
    }
}
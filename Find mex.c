#include <stdio.h>
#include <stdbool.h>

int main() {

    int N;
    scanf("%d", &N);

    int A[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    bool present[1000005] = {false};

    int mex = 0;

    for(int i = 0; i < N; i++) {

        present[A[i]] = true;

        
        while(present[mex]) {
            mex++;
        }

        printf("%d ", mex);
    }

    return 0;
}
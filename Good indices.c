#include <stdio.h>

int main() {

    int T;
    scanf("%d", &T);

    while(T--) {

        int N;
        scanf("%d", &N);

        int A[N];

        for(int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        for(int i = 0; i < N; i++) {

            if(i == 0 || i == N - 1) {
                printf("-1 ");
                continue;
            }

            int left = i - 1;
            int right = i + 1;

            int l = -1, r = -1;

       
            for(int j = i - 1; j >= 0; j--) {
                if(A[j] < A[i]) {
                    l = j;
                    break;
                }
            }

          
            for(int j = i + 1; j < N; j++) {
                if(A[j] < A[i]) {
                    r = j;
                    break;
                }
            }

            if(l == -1 || r == -1) {
                printf("-1 ");
            }
            else {
               
                int left_del = (i - l - 1);
                int right_del = (r - i - 1);

                printf("%d ", left_del + right_del);
            }
        }

        printf("\n");
    }

    return 0;
}
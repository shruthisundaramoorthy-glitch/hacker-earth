#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int value;
    int dist;
} Node;


int countBits(int x) {
    int count = 0;

    while(x) {
        count += x & 1;
        x >>= 1;
    }

    return count;
}


int compare(const void *a, const void *b) {

    Node *x = (Node *)a;
    Node *y = (Node *)b;

    if(x->dist != y->dist) {
        return x->dist - y->dist;
    }

    
    return x->value - y->value;
}

int main() {

    int T;
    scanf("%d", &T);

    while(T--) {

        int N, K;
        scanf("%d %d", &N, &K);

        Node arr[N];

        for(int i = 0; i < N; i++) {

            int x;
            scanf("%d", &x);

            arr[i].value = x;
            arr[i].dist = countBits(x ^ K);
        }

        qsort(arr, N, sizeof(Node), compare);

        for(int i = 0; i < N; i++) {
            printf("%d ", arr[i].value);
        }

        printf("\n");
    }

    return 0;
}
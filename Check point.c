#include <stdio.h>
#include <string.h>

#define MAX 505

int graph[MAX][MAX];
int matchR[MAX];
int visited[MAX];

int L, R, M;

int bpm(int u) {

    for(int v = 1; v <= R; v++) {

        if(graph[u][v] && !visited[v]) {

            visited[v] = 1;

            if(matchR[v] == -1 || bpm(matchR[v])) {

                matchR[v] = u;
                return 1;
            }
        }
    }

    return 0;
}

int main() {

    scanf("%d %d %d", &L, &R, &M);

    memset(graph, 0, sizeof(graph));

    for(int i = 0; i < M; i++) {

        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
    }

    memset(matchR, -1, sizeof(matchR));

    int result = 0;

    for(int u = 1; u <= L; u++) {

        memset(visited, 0, sizeof(visited));

        if(bpm(u)) {
            result++;
        }
    }

    printf("%d\n", result);

    return 0;
}
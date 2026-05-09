#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2005

int adj[MAX][MAX];
int deg[MAX];

int parent[MAX];
int depth[MAX];
int visited[MAX];

void dfs(int u, int p, int d) {

    parent[u] = p;
    depth[u] = d;
    visited[u] = 1;

    for(int i = 0; i < deg[u]; i++) {

        int v = adj[u][i];

        if(v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int lca(int u, int v) {

    while(depth[u] > depth[v])
        u = parent[u];

    while(depth[v] > depth[u])
        v = parent[v];

    while(u != v) {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int dist(int u, int v) {

    int L = lca(u, v);

    return depth[u] + depth[v] - 2 * depth[L];
}

int getPath(int u, int v, int path[]) {

    int L = lca(u, v);

    int temp1[MAX], temp2[MAX];
    int c1 = 0, c2 = 0;

    while(u != L) {
        temp1[c1++] = u;
        u = parent[u];
    }

    temp1[c1++] = L;

    while(v != L) {
        temp2[c2++] = v;
        v = parent[v];
    }

    int idx = 0;

    for(int i = 0; i < c1; i++)
        path[idx++] = temp1[i];

    for(int i = c2 - 1; i >= 0; i--)
        path[idx++] = temp2[i];

    return idx;
}

int main() {

    int T;
    scanf("%d", &T);

    while(T--) {

        int N;
        scanf("%d", &N);

        for(int i = 1; i <= N; i++) {
            deg[i] = 0;
            visited[i] = 0;
        }

        for(int i = 0; i < N - 1; i++) {

            int u, v;
            scanf("%d %d", &u, &v);

            adj[u][deg[u]++] = v;
            adj[v][deg[v]++] = u;
        }

        dfs(1, 0, 0);

        int Q;
        scanf("%d", &Q);

        while(Q--) {

            int A, B, C, D;
            scanf("%d %d %d %d", &A, &B, &C, &D);

            int path1[MAX], path2[MAX];

            int n1 = getPath(A, B, path1);
            int n2 = getPath(C, D, path2);

            int ans = 1000000000;

            for(int i = 0; i < n1; i++) {

                for(int j = 0; j < n2; j++) {

                    int d = dist(path1[i], path2[j]);

                    if(d < ans)
                        ans = d;
                }
            }

            printf("%d\n", ans);
        }
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {

    char num[100005];
    int k;

    scanf("%s %d", num, &k);

    int n = strlen(num);
    char stack[100005];
    int top = -1;

    for(int i = 0; i < n; i++) {

        while(top >= 0 && k > 0 && stack[top] < num[i]) {
            top--;
            k--;
        }

        stack[++top] = num[i];
    }

   
    top -= k;

    for(int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }

    return 0;
}
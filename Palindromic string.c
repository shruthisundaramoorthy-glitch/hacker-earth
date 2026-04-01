

    #include <stdio.h>
    #include <string.h>
     
    int main() {
        char str[1001]; 
        int i, len, flag = 0;
     
        
        if (scanf("%s", str) != 1) return 0;
     
        len = strlen(str);
     
        
        for (i = 0; i < len / 2; i++) {
            
            if (str[i] != str[len - i - 1]) {
                flag = 1; 
                break;
            }
        }
     
        
        if (flag == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
     
        return 0;
    }

Language: C

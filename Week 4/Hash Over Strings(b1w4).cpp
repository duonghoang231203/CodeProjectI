#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    for (int i = 0; i < n; i++) {
        char s[201];
        fgets(s, sizeof(s), stdin);

        int len = strlen(s) - 1; 
        unsigned long long hash = 0;
        for (int j = 0; j < len; j++) {
            hash = (hash * 256 + s[j]) % m;
        }

        printf("%llu\n", hash);
    }

    return 0;
}


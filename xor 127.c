#include <stdio.h>

int main() {
    char *str = "Hello World";
    int i;

    printf("AND with 127:\n");
    for (i = 0; str[i] != '\0'; i++)
        printf("%c", str[i] & 127);

    printf("\n\nOR with 127:\n");
    for (i = 0; str[i] != '\0'; i++)
        printf("%c", str[i] | 127);

    printf("\n\nXOR with 127:\n");
    for (i = 0; str[i] != '\0'; i++)
        printf("%c", str[i] ^ 127);

    return 0;
}

out put:-
AND with 127:
Hello World

OR with 127:


XOR with 127:
7?_(


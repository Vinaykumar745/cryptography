#include <stdio.h>
int main() {
    char *str = "Hello World";
    int i;
    printf("Result after XOR with 0:\n");
    for (i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i] ^ 0);
    }
    return 0;
}

out put:-
Result after XOR with 0:
Hello World

#include <stdio.h>
#include <ctype.h>

int main() {
    char text[50] = "HELLO";
    int key = 3, i;

    printf("Encrypted Text: ");
    for (i = 0; text[i] != '\0'; i++) {
        printf("%c", (text[i] - 'A' + key) % 26 + 'A');
    }

    printf("\nDecrypted Text: ");
    for (i = 0; text[i] != '\0'; i++) {
        printf("%c", (text[i] - 'A' - key + 26) % 26 + 'A');
    }

    return 0;
}


output:-
Encrypted Text: KHOOR
Decrypted Text: EBIIL


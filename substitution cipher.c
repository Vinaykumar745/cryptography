#include <stdio.h>

int main() {
    char text[] = "HELLO";
    char key[]  = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;

    printf("Encrypted Text: ");
    for (i = 0; text[i] != '\0'; i++)
        printf("%c", key[text[i] - 'A']);

    printf("\nDecrypted Text: ");
    for (i = 0; text[i] != '\0'; i++) {
        for (int j = 0; j < 26; j++) {
            if (key[j] == key[text[i] - 'A'])
                printf("%c", j + 'A');
        }
    }

    return 0;
}

output:-
plain text: HELLO
cipher: ITSSG
Decrypted: HELLO


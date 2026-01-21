#include <stdio.h>
#include <string.h>

int main() {
    char plaintext[] = "HELLODES";
    char key = 5;
    char encrypted[20], decrypted[20];
    int i;

    // Encryption
    for (i = 0; plaintext[i] != '\0'; i++) {
        encrypted[i] = plaintext[i] ^ key;
    }
    encrypted[i] = '\0';

    // Decryption
    for (i = 0; encrypted[i] != '\0'; i++) {
        decrypted[i] = encrypted[i] ^ key;
    }
    decrypted[i] = '\0';

    printf("Plain Text    : %s\n", plaintext);
    printf("Encrypted Text: ");
    for (i = 0; encrypted[i] != '\0'; i++)
        printf("%c", encrypted[i] + 32);   // make printable

    printf("\nDecrypted Text: %s\n", decrypted);

    return 0;
}


output:-
Plain Text    : HELLODES
Encrypted Text: m`iija`v
Decrypted Text: HELLODES



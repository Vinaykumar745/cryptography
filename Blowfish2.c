#include <stdio.h>
#include <string.h>

int main() {
    char plaintext[] = "HELLO";
    char key[] = "KEY";
    char encrypted[20], decrypted[20];
    int i, keyLen;

    keyLen = strlen(key);

    // Encryption
    for (i = 0; plaintext[i] != '\0'; i++) {
        encrypted[i] = plaintext[i] ^ key[i % keyLen];
    }
    encrypted[i] = '\0';

    // Decryption
    for (i = 0; encrypted[i] != '\0'; i++) {
        decrypted[i] = encrypted[i] ^ key[i % keyLen];
    }
    decrypted[i] = '\0';

    printf("Plain Text    : %s\n", plaintext);

    printf("Encrypted Text: ");
    for (i = 0; encrypted[i] != '\0'; i++)
        printf("%d ", encrypted[i]);   // print ASCII values

    printf("\nDecrypted Text: %s\n", decrypted);

    return 0;
}


output:-
Plain Text    : HELLO
Encrypted Text: 3
Decrypted Text: H

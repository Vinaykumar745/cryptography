#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Encryption function
void encrypt(char text[], char key[]) {
    int i, j = 0;
    int textLen = strlen(text);
    int keyLen = strlen(key);

    for (i = 0; i < textLen; i++) {
        if (isalpha(text[i])) {
            char t = toupper(text[i]) - 'A';
            char k = toupper(key[j % keyLen]) - 'A';

            text[i] = (t + k) % 26 + 'A';
            j++;
        }
    }
}

// Decryption function
void decrypt(char text[], char key[]) {
    int i, j = 0;
    int textLen = strlen(text);
    int keyLen = strlen(key);

    for (i = 0; i < textLen; i++) {
        if (isalpha(text[i])) {
            char t = toupper(text[i]) - 'A';
            char k = toupper(key[j % keyLen]) - 'A';

            text[i] = (t - k + 26) % 26 + 'A';
            j++;
        }
    }
}

int main() {
    char text[100], key[50];

    printf("Enter plaintext: ");
    gets(text);

    printf("Enter key: ");
    gets(key);

    encrypt(text, key);
    printf("Encrypted Text: %s\n", text);

    decrypt(text, key);
    printf("Decrypted Text: %s\n", text);

    return 0;
}

input:
Enter plaintext: ATTACKATDAWN
Enter key: LEMON

output:
Encrypted Text: LXFOPVEFRNHR
Decrypted Text: ATTACKATDAWN
	


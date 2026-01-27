#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Plain and cipher alphabets
char plain[]  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char cipher[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

// Encryption function
void encrypt(char text[]) {
    int i, j;

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            for (j = 0; j < 26; j++) {
                if (toupper(text[i]) == plain[j]) {
                    text[i] = cipher[j];
                    break;
                }
            }
        }
    }
}

// Decryption function
void decrypt(char text[]) {
    int i, j;

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            for (j = 0; j < 26; j++) {
                if (toupper(text[i]) == cipher[j]) {
                    text[i] = plain[j];
                    break;
                }
            }
        }
    }
}

int main() {
    char text[100];

    printf("Enter text: ");
    gets(text);

    encrypt(text);
    printf("Encrypted Text: %s\n", text);

    decrypt(text);
    printf("Decrypted Text: %s\n", text);

    return 0;
}


input:
	HELLO

output:
	Encrypted Text: ITSSG
Decrypted Text: HELLO


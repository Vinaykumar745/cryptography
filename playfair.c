#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

// Generate key matrix
void generateMatrix(char key[]) {
    int used[26] = {0};
    int i, j, k = 0;

    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            used[ch - 'A'] = 1;
            matrix[k / 5][k % 5] = ch;
            k++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (i + 'A' == 'J') continue;
        if (!used[i]) {
            matrix[k / 5][k % 5] = i + 'A';
            k++;
        }
    }
}

// Find position of character in matrix
void findPosition(char ch, int *row, int *col) {
    int i, j;
    if (ch == 'J') ch = 'I';

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
}

// Encryption
void encrypt(char text[]) {
    int i, r1, c1, r2, c2;
    char a, b;

    for (i = 0; text[i] != '\0'; i += 2) {
        a = text[i];
        b = text[i + 1];

        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);

        if (r1 == r2) {
            text[i]     = matrix[r1][(c1 + 1) % 5];
            text[i + 1] = matrix[r2][(c2 + 1) % 5];
        } 
        else if (c1 == c2) {
            text[i]     = matrix[(r1 + 1) % 5][c1];
            text[i + 1] = matrix[(r2 + 1) % 5][c2];
        } 
        else {
            text[i]     = matrix[r1][c2];
            text[i + 1] = matrix[r2][c1];
        }
    }
}

// Decryption
void decrypt(char text[]) {
    int i, r1, c1, r2, c2;
    char a, b;

    for (i = 0; text[i] != '\0'; i += 2) {
        a = text[i];
        b = text[i + 1];

        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);

        if (r1 == r2) {
            text[i]     = matrix[r1][(c1 + 4) % 5];
            text[i + 1] = matrix[r2][(c2 + 4) % 5];
        } 
        else if (c1 == c2) {
            text[i]     = matrix[(r1 + 4) % 5][c1];
            text[i + 1] = matrix[(r2 + 4) % 5][c2];
        } 
        else {
            text[i]     = matrix[r1][c2];
            text[i + 1] = matrix[r2][c1];
        }
    }
}

int main() {
    char text[100], key[50];

    printf("Enter key: ");
    gets(key);

    printf("Enter text (even length, uppercase): ");
    gets(text);

    generateMatrix(key);

    encrypt(text);
    printf("Encrypted Text: %s\n", text);

    decrypt(text);
    printf("Decrypted Text: %s\n", text);

    return 0;
}

input:
Key: MONARCHY
Text: INSTRUMENTS

output:
Encrypted Text: GATLMZCLRQXA
Decrypted Text: INSTRUMENTS
	

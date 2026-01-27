#include <stdio.h>
#include <string.h>

// Encryption function
void encryptRailFence(char text[], int key) {
    int len = strlen(text);
    char rail[key][len];
    
    // Fill rail matrix with '\n'
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    int dir_down = 0;
    int row = 0, col = 0;

    for (int i = 0; i < len; i++) {
        if (row == 0 || row == key - 1)
            dir_down = !dir_down;

        rail[row][col++] = text[i];

        dir_down ? row++ : row--;
    }

    printf("Encrypted Text: ");
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                printf("%c", rail[i][j]);
    printf("\n");
}

// Decryption function
void decryptRailFence(char cipher[], int key) {
    int len = strlen(cipher);
    char rail[key][len];

    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    int dir_down;
    int row = 0, col = 0;

    // Mark zigzag positions
    for (int i = 0; i < len; i++) {
        if (row == 0)
            dir_down = 1;
        if (row == key - 1)
            dir_down = 0;

        rail[row][col++] = '*';

        dir_down ? row++ : row--;
    }

    // Fill cipher text
    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*' && index < len)
                rail[i][j] = cipher[index++];

    // Read decrypted text
    row = 0; col = 0;
    printf("Decrypted Text: ");
    for (int i = 0; i < len; i++) {
        if (row == 0)
            dir_down = 1;
        if (row == key - 1)
            dir_down = 0;

        if (rail[row][col] != '\n')
            printf("%c", rail[row][col++]);

        dir_down ? row++ : row--;
    }
    printf("\n");
}

int main() {
    char text[100];
    int key;

    printf("Enter text: ");
    gets(text);

    printf("Enter number of rails: ");
    scanf("%d", &key);

    encryptRailFence(text, key);
    decryptRailFence(text, key);

    return 0;
}
input:
Enter text: HELLOWORLD
Enter number of rails: 3

output:
Encrypted Text: HOLELWRDLO
Decrypted Text: HELLOWORLD
	



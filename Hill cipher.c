#include <stdio.h>

int main() {
    int key[2][2] = {{3,3},{2,5}};
    int text[2] = {0,2};   // A=0, C=2
    int cipher[2];

    cipher[0] = (key[0][0]*text[0] + key[0][1]*text[1]) % 26;
    cipher[1] = (key[1][0]*text[0] + key[1][1]*text[1]) % 26;

    printf("Encrypted Text: %c%c\n", cipher[0]+'A', cipher[1]+'A');

    return 0;
}

output:
	Encrypted Text: GK

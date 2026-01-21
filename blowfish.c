#include <stdio.h>

// P-array (sub keys)
unsigned int P[18] = {
    0x243F6A88, 0x85A308D3, 0x13198A2E, 0x03707344,
    0xA4093822, 0x299F31D0, 0x082EFA98, 0xEC4E6C89,
    0x452821E6, 0x38D01377, 0xBE5466CF, 0x34E90C6C,
    0xC0AC29B7, 0xC97C50DD, 0x3F84D5B5, 0xB5470917,
    0x9216D5D9, 0x8979FB1B
};

// Simple F function (Beginner version)
unsigned int F(unsigned int x) {
    return x << 1;   // left shift
}

// Blowfish Encryption
void encrypt(unsigned int *L, unsigned int *R) {
    int i;
    unsigned int temp;

    for (i = 0; i < 16; i++) {
        *L = *L ^ P[i];
        *R = *R ^ F(*L);

        // swap L and R
        temp = *L;
        *L = *R;
        *R = temp;
    }

    // undo last swap
    temp = *L;
    *L = *R;
    *R = temp;

    *R = *R ^ P[16];
    *L = *L ^ P[17];
}

int main() {
    unsigned int L = 1234;
    unsigned int R = 5678;

    printf("Plain Text:\n");
    printf("L = %u\nR = %u\n", L, R);

    encrypt(&L, &R);

    printf("\nCipher Text:\n");
    printf("L = %u\nR = %u\n", L, R);

    return 0;
}


output:-
Plain Text:
L = 1234
R = 5678

Cipher Text:
L = 4198006990
R = 2674989272


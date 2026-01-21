#include <stdio.h>

// AES S-Box (partial for demo)
unsigned char sbox[16] = {
    0x63, 0x7c, 0x77, 0x7b,
    0xf2, 0x6b, 0x6f, 0xc5,
    0x30, 0x01, 0x67, 0x2b,
    0xfe, 0xd7, 0xab, 0x76
};

// SubBytes step
void subBytes(unsigned char state[4]) {
    for (int i = 0; i < 4; i++)
        state[i] = sbox[state[i] % 16];
}

// ShiftRows step
void shiftRows(unsigned char state[4]) {
    unsigned char temp = state[1];
    state[1] = state[2];
    state[2] = state[3];
    state[3] = temp;
}

// AddRoundKey step
void addRoundKey(unsigned char state[4], unsigned char key[4]) {
    for (int i = 0; i < 4; i++)
        state[i] ^= key[i];
}

int main() {
    unsigned char state[4] = {'A', 'B', 'C', 'D'};
    unsigned char key[4]   = {'K', 'E', 'Y', '1'};

    printf("Plain Text: ");
    for (int i = 0; i < 4; i++)
        printf("%c ", state[i]);

    addRoundKey(state, key);
    subBytes(state);
    shiftRows(state);

    printf("\nEncrypted Text: ");
    for (int i = 0; i < 4; i++)
        printf("%02X ", state[i]);

    return 0;
}

output:
	Plain Text: A B C D
Encrypted Text: 7C 77 7B 63


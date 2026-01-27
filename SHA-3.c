#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ROUNDS 24
#define SHA3_256_RATE 136   // 1088 bits = 136 bytes

uint64_t RC[24] = {
    0x0000000000000001ULL, 0x0000000000008082ULL,
    0x800000000000808AULL, 0x8000000080008000ULL,
    0x000000000000808BULL, 0x0000000080000001ULL,
    0x8000000080008081ULL, 0x8000000000008009ULL,
    0x000000000000008AULL, 0x0000000000000088ULL,
    0x0000000080008009ULL, 0x000000008000000AULL,
    0x000000008000808BULL, 0x800000000000008BULL,
    0x8000000000008089ULL, 0x8000000000008003ULL,
    0x8000000000008002ULL, 0x8000000000000080ULL,
    0x000000000000800AULL, 0x800000008000000AULL,
    0x8000000080008081ULL, 0x8000000000008080ULL,
    0x0000000080000001ULL, 0x8000000080008008ULL
};

int r[5][5] = {
    {0,  36, 3,  41, 18},
    {1,  44, 10, 45, 2},
    {62, 6,  43, 15, 61},
    {28, 55, 25, 21, 56},
    {27, 20, 39, 8,  14}
};

uint64_t rotl(uint64_t x, int n) {
    return (x << n) | (x >> (64 - n));
}

void keccak_f(uint64_t state[5][5]) {
    uint64_t C[5], D[5], B[5][5];

    for (int round = 0; round < ROUNDS; round++) {

        // ? step
        for (int x = 0; x < 5; x++)
            C[x] = state[x][0] ^ state[x][1] ^ state[x][2] ^ state[x][3] ^ state[x][4];

        for (int x = 0; x < 5; x++) {
            D[x] = C[(x + 4) % 5] ^ rotl(C[(x + 1) % 5], 1);
            for (int y = 0; y < 5; y++)
                state[x][y] ^= D[x];
        }

        // ? and p steps
        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 5; y++)
                B[y][(2 * x + 3 * y) % 5] = rotl(state[x][y], r[x][y]);

        // ? step
        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 5; y++)
                state[x][y] = B[x][y] ^ ((~B[(x + 1) % 5][y]) & B[(x + 2) % 5][y]);

        // ? step
        state[0][0] ^= RC[round];
    }
}

void sha3_256(const unsigned char *input, int len, unsigned char *output) {
    uint64_t state[5][5] = {0};
    int i;

    // Absorb phase
    for (i = 0; i < len; i++) {
        ((unsigned char*)state)[i] ^= input[i];
    }

    // Padding
    ((unsigned char*)state)[len] ^= 0x06;
    ((unsigned char*)state)[SHA3_256_RATE - 1] ^= 0x80;

    keccak_f(state);

    // Squeeze output
    memcpy(output, state, 32);
}

int main() {
    unsigned char message[] = "HELLO";
    unsigned char hash[32];

    sha3_256(message, strlen((char*)message), hash);

    printf("SHA3-256 Hash:\n");
    for (int i = 0; i < 32; i++)
        printf("%02x", hash[i]);

    printf("\n");
    return 0;
}


output:
	SHA3-256 Hash:
3338be694f50c5f338814986cdf0686453a888b84f424d792af4b9202398f392


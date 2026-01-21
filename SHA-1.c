#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))

void sha1(const char *msg) {
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xEFCDAB89;
    uint32_t h2 = 0x98BADCFE;
    uint32_t h3 = 0x10325476;
    uint32_t h4 = 0xC3D2E1F0;

    uint64_t ml = strlen(msg) * 8;
    uint8_t data[64] = {0};

    strcpy((char*)data, msg);
    data[strlen(msg)] = 0x80;

    for (int i = 0; i < 8; i++)
        data[63 - i] = ml >> (8 * i);

    uint32_t w[80];
    for (int i = 0; i < 16; i++)
        w[i] = (data[i*4] << 24) | (data[i*4+1] << 16) |
               (data[i*4+2] << 8) | (data[i*4+3]);

    for (int i = 16; i < 80; i++)
        w[i] = ROTLEFT(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1);

    uint32_t a = h0, b = h1, c = h2, d = h3, e = h4, f, k, temp;

    for (int i = 0; i < 80; i++) {
        if (i < 20) {
            f = (b & c) | ((~b) & d);
            k = 0x5A827999;
        } else if (i < 40) {
            f = b ^ c ^ d;
            k = 0x6ED9EBA1;
        } else if (i < 60) {
            f = (b & c) | (b & d) | (c & d);
            k = 0x8F1BBCDC;
        } else {
            f = b ^ c ^ d;
            k = 0xCA62C1D6;
        }

        temp = ROTLEFT(a,5) + f + e + k + w[i];
        e = d;
        d = c;
        c = ROTLEFT(b,30);
        b = a;
        a = temp;
    }

    h0 += a;
    h1 += b;
    h2 += c;
    h3 += d;
    h4 += e;

    printf("SHA-1 Hash: ");
    printf("%08x%08x%08x%08x%08x\n", h0, h1, h2, h3, h4);
}

int main() {
    char message[100];

    printf("Enter message: ");
    gets(message);

    sha1(message);
    return 0;
}

output:-
Enter message: hello
SHA-1 Hash: aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d


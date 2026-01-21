#include <stdio.h>
#include <math.h>

// Function to calculate gcd
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Power modulo function
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        result = (result * base) % mod;
        exp--;
    }
    return result;
}

int main() {
    int p = 3, q = 11;
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 0;
    for (int i = 2; i < phi; i++) {
        if (gcd(i, phi) == 1) {
            e = i;
            break;
        }
    }

    int d = 0;
    for (int i = 1; i < phi; i++) {
        if ((e * i) % phi == 1) {
            d = i;
            break;
        }
    }

    int msg = 7;  // Plain text
    long long cipher = power(msg, e, n);
    long long decrypted = power(cipher, d, n);

    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("n = %d\n", n);
    printf("phi = %d\n", phi);
    printf("Public Key (e,n) = (%d,%d)\n", e, n);
    printf("Private Key (d,n) = (%d,%d)\n", d, n);

    printf("\nPlain Text = %d", msg);
    printf("\nEncrypted Text = %lld", cipher);
    printf("\nDecrypted Text = %lld", decrypted);

    return 0;
}


output:
	p = 3
q = 11
n = 33
phi = 20
Public Key (e,n) = (3,33)
Private Key (d,n) = (7,33)

Plain Text = 7
Encrypted Text = 13
Decrypted Text = 7


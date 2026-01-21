#include <stdio.h>

// Function to calculate (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        result = (result * base) % mod;
        exp--;
    }
    return result;
}

int main() {
    long long p = 23;   // Prime number
    long long g = 5;    // Primitive root

    long long a = 6;    // Alice's private key
    long long b = 15;   // Bob's private key

    long long A = power(g, a, p); // Alice's public key
    long long B = power(g, b, p); // Bob's public key

    long long keyA = power(B, a, p); // Alice computes secret key
    long long keyB = power(A, b, p); // Bob computes secret key

    printf("Public values:\n");
    printf("p = %lld, g = %lld\n\n", p, g);

    printf("Alice private key = %lld\n", a);
    printf("Bob private key   = %lld\n\n", b);

    printf("Alice public key = %lld\n", A);
    printf("Bob public key   = %lld\n\n", B);

    printf("Secret key computed by Alice = %lld\n", keyA);
    printf("Secret key computed by Bob   = %lld\n", keyB);

    return 0;
}

output:
	Public values:
p = 23, g = 5

Alice private key = 6
Bob private key   = 15

Alice public key = 8
Bob public key   = 19

Secret key computed by Alice = 2
Secret key computed by Bob   = 2


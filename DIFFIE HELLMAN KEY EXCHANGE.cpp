#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int power(int a, int b, int p) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}
int main() {
    int p, g, a, b, A, B, K1, K2;
    printf("Enter a prime number (p): ");
    scanf("%d", &p);
    printf("Enter a generator (g) for Zp*: ");
    scanf("%d", &g);
    printf("Enter the private key of Alice (a): ");
    scanf("%d", &a);
    printf("Enter the private key of Bob (b): ");
    scanf("%d", &b);
    A = power(g, a, p);
    B = power(g, b, p);
    K1 = power(B, a, p);
    K2 = power(A, b, p);
    printf("Public parameters: (p = %d, g = %d)\n", p, g);
    printf("Private keys: (a = %d, b = %d)\n", a, b);
    printf("Alice's public key: A = %d\n", A);
    printf("Bob's public key: B = %d\n", B);
    printf("Shared secret keys: (K1 = %d, K2 = %d)\n", K1, K2);
    return 0;
}

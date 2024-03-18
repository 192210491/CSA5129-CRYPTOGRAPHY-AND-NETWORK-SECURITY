#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MOD 26 // Modulus for the alphabet (26 for English alphabet)

// Function to calculate the determinant of a 2x2 matrix
int calculateDeterminant(int key[2][2]) {
    return key[0][0] * key[1][1] - key[0][1] * key[1][0];
}

// Function to calculate the modular inverse of a number
int modInverse(int a, int m) {
    a = (a % m + m) % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Modular inverse doesn't exist
}

// Function to encrypt the plaintext using Hill Cipher
void hillCipherEncrypt(char *plaintext, int key[2][2]) {
    int len = strlen(plaintext);

    // Padding the plaintext if its length is odd
    if (len % 2 != 0) {
        plaintext[len] = 'X';
        plaintext[len + 1] = '\0';
        len++;
    }

    // Performing encryption
    for (int i = 0; i < len; i += 2) {
        int char1 = plaintext[i] - 'A';
        int char2 = plaintext[i + 1] - 'A';

        int encrypted_char1 = (key[0][0] * char1 + key[0][1] * char2) % MOD;
        int encrypted_char2 = (key[1][0] * char1 + key[1][1] * char2) % MOD;

        plaintext[i] = encrypted_char1 + 'A';
        plaintext[i + 1] = encrypted_char2 + 'A';
    }
}

int main() {
    char plaintext[100];
    int key[2][2];

    // Get plaintext input
    printf("Enter the plaintext (uppercase letters only): ");
    scanf("%s", plaintext);

    // Get the key matrix input
    printf("Enter the key matrix (2x2 matrix elements separated by space):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    // Check if the key matrix is invertible
    int determinant = calculateDeterminant(key);
    if (determinant == 0 || modInverse(determinant, MOD) == -1) {
        printf("Invalid key matrix. The matrix is not invertible.\n");
        return 1;
    }

    // Encrypt the plaintext
    hillCipherEncrypt(plaintext, key);

    // Display the encrypted text
    printf("Encrypted Text: %s\n", plaintext);

    return 0;
}


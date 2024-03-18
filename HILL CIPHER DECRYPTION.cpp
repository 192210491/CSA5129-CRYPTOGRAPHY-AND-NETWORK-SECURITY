#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

// Function to calculate the modular inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Modular inverse doesn't exist
}

// Function to decrypt using Hill Cipher
void hillDecrypt(int keyMatrix[][MAX_SIZE], int dimension, char cipherText[], int length) {
    int i, j, k, cipherMatrix[MAX_SIZE], plainMatrix[MAX_SIZE];

    // Convert the cipher text to numbers
    for (i = 0; i < length; ++i) {
        cipherMatrix[i] = cipherText[i] - 'A'; // Assuming uppercase alphabets
    }

    // Calculate the determinant of the key matrix
    int det = keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0];
    det = (det % 26 + 26) % 26; // Ensure positive value

    // Find the modular inverse of the determinant
    int detInverse = modInverse(det, 26);
    if (detInverse == -1) {
        printf("Determinant inverse does not exist.\n");
        return;
    }

    // Calculate the adjoint matrix
    int adj[MAX_SIZE][MAX_SIZE];
    adj[0][0] = keyMatrix[1][1];
    adj[0][1] = -keyMatrix[0][1];
    adj[1][0] = -keyMatrix[1][0];
    adj[1][1] = keyMatrix[0][0];

    for (i = 0; i < dimension; ++i) {
        for (j = 0; j < dimension; ++j) {
            adj[i][j] = (adj[i][j] % 26 + 26) % 26; // Ensure positive value
        }
    }

    // Multiply adjoint matrix with determinant inverse
    for (i = 0; i < dimension; ++i) {
        for (j = 0; j < dimension; ++j) {
            keyMatrix[i][j] = (adj[i][j] * detInverse) % 26;
        }
    }

    // Calculate the plain text matrix
    for (i = 0; i < length; i += dimension) {
        for (j = 0; j < dimension; ++j) {
            plainMatrix[i + j] = 0;
            for (k = 0; k < dimension; ++k) {
                plainMatrix[i + j] += keyMatrix[j][k] * cipherMatrix[i + k];
            }
            plainMatrix[i + j] %= 26;
        }
    }

    // Convert numbers back to characters and print the plain text
    printf("Decrypted Text: ");
    for (i = 0; i < length; ++i) {
        printf("%c", (char)(plainMatrix[i] + 'A')); // Assuming uppercase alphabets
    }
    printf("\n");
}

int main() {
    int keyMatrix[MAX_SIZE][MAX_SIZE], dimension, i, j;
    char cipherText[MAX_SIZE];

    printf("Enter the dimension of the key matrix: ");
    scanf("%d", &dimension);

    printf("Enter the key matrix elements (in uppercase): \n");
    for (i = 0; i < dimension; ++i) {
        for (j = 0; j < dimension; ++j) {
            scanf("%d", &keyMatrix[i][j]);
        }
    }

    printf("Enter the cipher text (in uppercase): ");
    scanf("%s", cipherText);

    int length = strlen(cipherText);

    if (length % dimension != 0) {
        printf("Invalid input length. Length should be a multiple of the key matrix dimension.\n");
        return 1;
    }

    hillDecrypt(keyMatrix, dimension, cipherText, length);

    return 0;
}


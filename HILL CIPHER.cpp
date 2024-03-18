#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 10

int key[MAX_SIZE][MAX_SIZE];

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

void getKeyMatrix(char keyMatrix[MAX_SIZE][MAX_SIZE], int keySize) {
    int i, j;
    for (i = 0; i < keySize; i++) {
        for (j = 0; j < keySize; j++) {
            key[i][j] = keyMatrix[i][j] - 'a';
        }
    }
}

void encrypt(int cipherMatrix[MAX_SIZE][1], int keySize) {
    int i, j, k;
    for (i = 0; i < keySize; i++) {
        cipherMatrix[i][0] = 0;

        for (j = 0; j < keySize; j++) {
            cipherMatrix[i][0] += key[i][j] * cipherMatrix[j][0];
        }

        cipherMatrix[i][0] = cipherMatrix[i][0] % 26;
    }
}

void hillCipherEncrypt(char plaintext[], char keyMatrix[MAX_SIZE][MAX_SIZE], int keySize) {
    int i, j;

    int cipherMatrix[MAX_SIZE][1];

    for (i = 0; i < keySize; i++) {
        cipherMatrix[i][0] = plaintext[i] - 'a';
    }

    getKeyMatrix(keyMatrix, keySize);

    encrypt(cipherMatrix, keySize);

    printf("The encrypted message is: ");
    for (i = 0; i < keySize; i++) {
        printf("%c", (cipherMatrix[i][0] + 'a'));
    }
    printf("\n");
}

int main() {
    char plaintext[MAX_SIZE * MAX_SIZE];
    char keyMatrix[MAX_SIZE][MAX_SIZE];
    int keySize;

    printf("Enter the size of key matrix (max 3x3): ");
    scanf("%d", &keySize);

    if (keySize > MAX_SIZE || keySize <= 0) {
        printf("Invalid key size. Please enter a valid size.\n");
        return 1;
    }

    printf("Enter the key matrix elements: \n");
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) {
            scanf(" %c", &keyMatrix[i][j]);
            keyMatrix[i][j] = tolower(keyMatrix[i][j]);
        }
    }

    printf("Enter the plaintext to encrypt (max %d characters): ", keySize * keySize);
    scanf("%s", plaintext);

    if (strlen(plaintext) != keySize * keySize) {
        printf("Invalid plaintext length. Please enter a valid plaintext.\n");
        return 1;
    }

    hillCipherEncrypt(plaintext, keyMatrix, keySize);

    return 0;
}


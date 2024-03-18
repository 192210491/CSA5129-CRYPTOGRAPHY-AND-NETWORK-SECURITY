#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ROWS 10
#define MAX_COLS 10
void encrypt(char *plaintext, char *key) {
    int keyLen = strlen(key);
    int textLen = strlen(plaintext);
    int rows = (textLen + keyLen - 1) / keyLen;
    int cols = keyLen;
    char matrix[MAX_ROWS][MAX_COLS];
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (k < textLen)
                matrix[i][j] = plaintext[k++];
            else
                matrix[i][j] = 'X'; 
        }
    }
    printf("Matrix before transposition:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < keyLen; i++) {
        int idx = key[i] - '0';
        for (int j = 0; j < rows; j++) {
            printf("%c", matrix[j][idx - 1]);
        }
    }
    printf("\n");
}

int main() {
    char plaintext[100];
    char key[20];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    printf("Enter the key (sequence of numbers without spaces): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    encrypt(plaintext, key);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the given string using Caesar cipher
void encrypt(char *message, int shift) {
    int i;
    for (i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + shift) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + shift) % 26 + 'A';
        }
    }
}

// Function to decrypt the given string using Caesar cipher
void decrypt(char *message, int shift) {
    encrypt(message, 26 - shift); // Decrypting is the same as encrypting with the complement shift
}

int main() {
    char message[100];
    int shift;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the shift value (0-25): ");
    scanf("%d", &shift);

    // Remove the newline character from fgets
    message[strcspn(message, "\n")] = '\0';

    // Encrypting the message
    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    // Decrypting the message
    decrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}


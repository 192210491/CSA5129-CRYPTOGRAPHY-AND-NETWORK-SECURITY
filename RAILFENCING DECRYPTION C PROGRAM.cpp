#include <stdio.h>
#include <string.h>

void decryptRailFence(char *cipherText, int rails, char *decryptedText) {
    int len = strlen(cipherText);
    int rail = 0, i, j;
    int down = 1;
    
    for (i = 0; i < len; i++) {
        if (rail == 0)
            down = 1;
        else if (rail == rails - 1)
            down = 0;
        
        decryptedText[rail * len / rails + i / rails] = cipherText[i];
        
        if (down)
            rail++;
        else
            rail--;
    }
    
    decryptedText[len] = '\0';
}

int main() {
    char cipherText[] = "ENTER_YOUR_CIPHERTEXT_HERE"; // Replace with your ciphertext
    int rails = 3; // Replace with the number of rails used in encryption
    char decryptedText[100]; // Adjust the size according to your ciphertext
    
    decryptRailFence(cipherText, rails, decryptedText);
    
    printf("Decrypted Text: %s\n", decryptedText);
    
    return 0;
}


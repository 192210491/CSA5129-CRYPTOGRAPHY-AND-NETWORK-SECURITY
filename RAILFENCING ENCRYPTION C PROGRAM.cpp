#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt using the Rail Fence Cipher
void encryptRailFence(char *text, int rails) {
    int len = strlen(text);
    char railMatrix[rails][len];

    // Initialize rail matrix to '.'
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            railMatrix[i][j] = '.';

    int row = 0;
    int dir_down = 0;

    for (int i = 0; i < len; i++) {
        // place the character
        railMatrix[row][i] = text[i];

        // change direction if we've reached the top or bottom rail
        if (row == 0 || row == rails - 1)
            dir_down = !dir_down;

        // move to the next row
        row += dir_down ? 1 : -1;
    }

    // Construct the encrypted string
    int index = 0;
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (railMatrix[i][j] != '.')
                text[index++] = railMatrix[i][j];
}

int main() {
    char text[1000];
    int rails;

    printf("Enter the text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    // Check if the number of rails is valid
    if (rails < 2) {
        printf("Number of rails should be 2 or more.\n");
        return 1;
    }

    // Remove spaces and non-alphabetic characters from the input string
    int len = strlen(text);
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            text[index] = toupper(text[i]);
            index++;
        }
    }
    text[index] = '\0'; // Null-terminate the modified string

    encryptRailFence(text, rails);

    printf("Encrypted text: %s\n", text);

    return 0;
}


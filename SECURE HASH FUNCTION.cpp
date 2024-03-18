#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/sha.h>

void sha256_hash(const unsigned char *input, size_t len, unsigned char hash[SHA256_DIGEST_LENGTH]) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, len);
    SHA256_Final(hash, &sha256);
}

int main() {
    char input_string[] = "Hello, world!"; // Replace this string with the input you want to hash
    unsigned char hash[SHA256_DIGEST_LENGTH];
    
    sha256_hash((unsigned char *)input_string, strlen(input_string), hash);
    
    printf("SHA-256 hash of '%s' is: ", input_string);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}


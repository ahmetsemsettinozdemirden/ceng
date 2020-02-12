#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cipher.h"

char* encrypt(const char* str, const int shift) {
    char* encrypted_str;
    strcpy(encrypted_str, str);
    for(int i=0; i < strlen(str); i++) {
        encrypted_str[i] = str[i] + shift;
    }
    return encrypted_str;
}

char* decrypt(const char* str, const int shift) {
    char* decrypted_str;
    strcpy(decrypted_str, str);
    for(int i=0; i < strlen(str); i++) {
        decrypted_str[i] = str[i] - shift;
    }
    return decrypted_str;
}

int printFailure() {
    printf("please use as shown below.\nusage: cipher <encrypt/decrypt> <shift(int)> <str>\n");
    return EXIT_FAILURE;
}
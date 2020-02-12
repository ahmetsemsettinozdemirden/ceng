#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cipher.h"

/**
 * usage, $ cipher <encrypt/decrypt> <shift(int)> <str>
 * */
int main(int argc, char const *argv[]) {
    
    if(argc != 4) {
        return printFailure();
    }
        
    int shift = atoi(argv[2]);
    if (shift == 0 && strcmp(argv[2], "0")) {
        return printFailure();
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        printf("%s", encrypt(argv[3], shift));
        return EXIT_SUCCESS;
    } else if (strcmp(argv[1], "decrypt") == 0) {
        printf("%s", decrypt(argv[3], shift));
        return EXIT_SUCCESS;
    } else {
        return printFailure();
    }
    
    return 0;
}
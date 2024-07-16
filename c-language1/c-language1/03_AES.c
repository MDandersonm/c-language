#define _CRT_SECURE_NO_WARNINGS
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include <stdio.h>

void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

int encrypt(unsigned char* plaintext, int plaintext_len, unsigned char* key,
    unsigned char* iv, unsigned char* ciphertext)
{
    EVP_CIPHER_CTX* ctx;
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

int decrypt(unsigned char* ciphertext, int ciphertext_len, unsigned char* key,
    unsigned char* iv, unsigned char* plaintext)
{
    EVP_CIPHER_CTX* ctx;
    int len;
    int plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        handleErrors();
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return plaintext_len;
}

int main(void)
{
    unsigned char key[16] = "0123456789012345"; // 16 byte key
    unsigned char iv[16] = "1234567890123456"; // 16 byte IV
    unsigned char plaintext[1024];
    unsigned char ciphertext[1048];
    unsigned char decryptedtext[1024];
    FILE* file;
    int decryptedtext_len, ciphertext_len, choice;

    do {
        printf("1. 암호화하기\n");
        printf("2. 복호화하기\n");
        printf("0. 종료\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear the newline character

        if (choice == 1) {
            printf("Enter password to encrypt: ");
            fgets((char*)plaintext, sizeof(plaintext), stdin);
            plaintext[strlen((char*)plaintext) - 1] = '\0'; // Remove newline

            ciphertext_len = encrypt(plaintext, strlen((char*)plaintext), key, iv, ciphertext);

            file = fopen("encrypted.txt", "wb");
            if (file == NULL) {
                perror("Failed to open file");
                return 1;
            }
            fwrite(ciphertext, 1, ciphertext_len, file);
            fclose(file);
            printf("Password encrypted and saved to 'encrypted.txt'\n");
        }
        else if (choice == 2) {
            file = fopen("encrypted.txt", "rb");
            if (file == NULL) {
                perror("Failed to open file");
                return 1;
            }
            ciphertext_len = fread(ciphertext, 1, sizeof(ciphertext), file);
            fclose(file);

            decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
            decryptedtext[decryptedtext_len] = '\0';

            printf("Decrypted password: %s\n", decryptedtext);
        }
    } while (choice != 0);

    return 0;
}

#include <openssl/aes.h>
#include <openssl/rand.h>
#include <stdio.h>
#include <string.h>

// 256 ��Ʈ AES Ű�� ���
#define KEY_SIZE 32
#define IV_SIZE 16
#define BUFFER_SIZE 1024

void encrypt(FILE* in, FILE* out, unsigned char* key, unsigned char* iv) {
    unsigned char inbuf[BUFFER_SIZE], outbuf[BUFFER_SIZE + AES_BLOCK_SIZE];
    int bytes_read, bytes_written;
    AES_KEY enc_key;

    AES_set_encrypt_key(key, 256, &enc_key);

    while (1) {
        bytes_read = fread(inbuf, 1, BUFFER_SIZE, in);
        if (bytes_read == 0) break;
        AES_cbc_encrypt(inbuf, outbuf, bytes_read, &enc_key, iv, AES_ENCRYPT);
        fwrite(outbuf, 1, bytes_read, out);
    }
}

void decrypt(FILE* in, FILE* out, unsigned char* key, unsigned char* iv) {
    unsigned char inbuf[BUFFER_SIZE], outbuf[BUFFER_SIZE + AES_BLOCK_SIZE];
    int bytes_read;
    AES_KEY dec_key;

    AES_set_decrypt_key(key, 256, &dec_key);

    while (1) {
        bytes_read = fread(inbuf, 1, BUFFER_SIZE, in);
        if (bytes_read == 0) break;
        AES_cbc_encrypt(inbuf, outbuf, bytes_read, &dec_key, iv, AES_DECRYPT);
        fwrite(outbuf, 1, bytes_read, out);
    }
}

int main() {
    FILE* f_in, * f_out;
    unsigned char key[KEY_SIZE], iv[IV_SIZE];

    // Ű�� IV�� �����ϰ� �����ϰų� �����ؾ� �մϴ�. ���⼭�� ������ ���� ���Ƿ� ����
    memset(key, 0x00, KEY_SIZE);
    memset(iv, 0x00, IV_SIZE);
    strcpy((char*)key, "exampleverysecurekey1234567890"); // Ű�� 32 ����Ʈ
    RAND_bytes(iv, IV_SIZE);

    // ����� �Է� �ޱ�
    char password[128];
    printf("Enter password to encrypt: ");
    fgets(password, sizeof(password), stdin);

    // ���� ����
    f_in = fmemopen(password, strlen(password), "rb");
    f_out = fopen("encrypted.txt", "wb");

    if (f_in == NULL || f_out == NULL) {
        perror("File error");
        return 1;
    }

    encrypt(f_in, f_out, key, iv);
    fclose(f_in);
    fclose(f_out);

    // ���Ϸκ��� �а� ��ȣȭ�ϱ�
    f_in = fopen("encrypted.txt", "rb");
    f_out = fopen("decrypted.txt", "wb");

    if (f_in == NULL || f_out == NULL) {
        perror("File error");
        return 1;
    }

    decrypt(f_in, f_out, key, iv);
    fclose(f_in);
    fclose(f_out);

    printf("Encryption and decryption done.\n");
    return 0;
}

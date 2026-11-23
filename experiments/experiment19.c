
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main()
{
    unsigned char key[32] = "12345678901234567890123456789012";
    unsigned char iv[16] = "1234567890123456";
    unsigned char text[] = "Cryptography CBC mode encryption";
    unsigned char cipher[100];
    int len, total = 0;

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    EVP_EncryptUpdate(ctx, cipher, &len, text, strlen((char *)text));
    total = len;

    EVP_EncryptFinal_ex(ctx, cipher + total, &len);
    total += len;

    printf("Encrypted ciphertext:\n");

    for(int i = 0; i < total; i++)
        printf("%02X ", cipher[i]);

    printf("\n");

    EVP_CIPHER_CTX_free(ctx);

    return 0;
}

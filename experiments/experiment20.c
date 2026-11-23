
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

void encrypt(int mode, unsigned char *input,
             unsigned char *output,
             unsigned char *key, unsigned char *iv)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int len, total;

    if(mode == 1)
        EVP_EncryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL);
    else
        EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);

    EVP_CIPHER_CTX_set_padding(ctx, 0);

    EVP_EncryptUpdate(ctx, output, &len, input, 48);
    total = len;

    EVP_EncryptFinal_ex(ctx, output + total, &len);

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(int mode, unsigned char *input,
             unsigned char *output,
             unsigned char *key, unsigned char *iv)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int len;

    if(mode == 1)
        EVP_DecryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL);
    else
        EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);

    EVP_CIPHER_CTX_set_padding(ctx, 0);

    EVP_DecryptUpdate(ctx, output, &len, input, 48);
    EVP_DecryptFinal_ex(ctx, output + len, &len);

    EVP_CIPHER_CTX_free(ctx);
}

int main()
{
    unsigned char key[16] = "1234567890123456";
    unsigned char iv[16] = "abcdefghijklmnop";

    unsigned char text[48] =
        "ABCDEFGHIJKLMNOPQRSTUVWX1234567890ABCDEF";

    unsigned char cipher[64], plain[64];

    encrypt(1, text, cipher, key, iv);

    cipher[0] ^= 1;

    decrypt(1, cipher, plain, key, iv);

    printf("ECB mode after error:\n");
    printf("%s\n", plain);

    encrypt(2, text, cipher, key, iv);

    cipher[0] ^= 1;

    decrypt(2, cipher, plain, key, iv);

    printf("\nCBC mode after error:\n");
    printf("%s\n", plain);

    return 0;
}

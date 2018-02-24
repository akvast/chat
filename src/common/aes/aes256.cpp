/*
 *   Byte-oriented AES-256 implementation.
 *   All lookup tables replaced with 'on the fly' calculations.
 *
 *   Copyright (c) 2007-2009 Ilya O. Levin, http://www.literatecode.com
 *   Other contributors: Hal Finney
 *
 *   Permission to use, copy, modify, and distribute this software for any
 *   purpose with or without fee is hereby granted, provided that the above
 *   copyright notice and this permission notice appear in all copies.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include "aes256.h"

#include <openssl/evp.h>
#include <openssl/rand.h>

// AES256 ECB: For first version

pair<void *, size_t> aes_ecb_encrypt(void *data, size_t size, const uint8_t *key) {
    int outlen;
    uint8_t *result = (uint8_t *) malloc(16 * (size / 16 + 1));

    EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_EncryptInit_ex(&ctx, EVP_aes_256_ecb(), NULL, key, NULL);
    EVP_EncryptUpdate(&ctx, result, &outlen, (uint8_t *) data, size);
    EVP_EncryptFinal_ex(&ctx, result + outlen, &outlen);
    EVP_CIPHER_CTX_cleanup(&ctx);

    return pair<void*, size_t>((void *) result, 16 * (size / 16 + 1));
}

pair<void *, size_t> aes_ecb_decrypt(void *data, size_t size, const uint8_t *key) {
    int outlen, finallen;
    uint8_t *result = (uint8_t *) malloc(size);

    EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_DecryptInit_ex(&ctx, EVP_aes_256_ecb(), NULL, key, NULL);
    EVP_DecryptUpdate(&ctx, result, &outlen, (uint8_t *) data, size);
    EVP_DecryptFinal_ex(&ctx, result + outlen, &finallen);
    EVP_CIPHER_CTX_cleanup(&ctx);

    result = (uint8_t *) realloc(result, outlen + finallen);
    return pair<void*, size_t>(result, outlen + finallen);
}

// AES256 CBC:

pair<void *, size_t> aes_cbc_encrypt(const void *data, size_t size, const uint8_t *key) {
    int outlen;
    uint8_t *result = (uint8_t *) malloc(17 + 16 * (size / 16 + 1));

    result[0] = 1; // Encrypt version
    RAND_bytes(result + 1, 16); // IV

    EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_EncryptInit_ex(&ctx, EVP_aes_256_cbc(), NULL, key, result + 1);
    EVP_EncryptUpdate(&ctx, result + 17, &outlen, (uint8_t *) data, size);
    EVP_EncryptFinal_ex(&ctx, result + 17 + outlen, &outlen);
    EVP_CIPHER_CTX_cleanup(&ctx);

    return pair<void*, size_t>((void *) result, 17 + 16 * (size / 16 + 1));
}

pair<void *, size_t> aes_cbc_decrypt(const void *data, size_t size, const uint8_t *key) {
    if (size < 33)
        return pair<void *, size_t>(nullptr, 0);

    int outlen, finallen;
    uint8_t *result = (uint8_t *) malloc(size - 17);

    EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_DecryptInit_ex(&ctx, EVP_aes_256_cbc(), NULL, key, ((uint8_t *) data) + 1);
    EVP_DecryptUpdate(&ctx, result, &outlen, ((uint8_t *) data) + 17, (int) (size - 17));
    EVP_DecryptFinal_ex(&ctx, result + outlen, &finallen);
    EVP_CIPHER_CTX_cleanup(&ctx);

    result = (uint8_t *) realloc(result, outlen + finallen);
    return pair<void*, size_t>(result, outlen + finallen);
}

// Auto:

pair<void *, size_t> aes_decrypt(void *data, size_t size, const uint8_t *key) {
    if (size % 16 == 0)
        return aes_ecb_decrypt(data, size, key);
    return aes_cbc_decrypt(data, size, key);
}
#pragma once

#include <functional>
#include <string>

using namespace std;

// ECB:

pair<void *, size_t> aes_ecb_encrypt(void *data, size_t size, const uint8_t *key);

pair<void *, size_t> aes_ecb_decrypt(void *data, size_t size, const uint8_t *key);

// CBC:

pair<void *, size_t> aes_cbc_encrypt(const void *data, size_t size, const uint8_t *key);

pair<void *, size_t> aes_cbc_decrypt(const void *data, size_t size, const uint8_t *key);

// Auto:

pair<void *, size_t> aes_decrypt(void *data, size_t size, const uint8_t *key);
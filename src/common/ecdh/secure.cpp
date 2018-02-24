#include "ecies.h"

namespace ecdh {

    uint16_t secure_key_length(secure_t *cryptex) {
        secure_head_t *head = (secure_head_t *) cryptex;
        return head->key;
    }

    uint16_t secure_mac_length(secure_t *cryptex) {
        secure_head_t *head = (secure_head_t *) cryptex;
        return head->mac;
    }

    uint16_t secure_body_length(secure_t *cryptex) {
        secure_head_t *head = (secure_head_t *) cryptex;
        return head->body;
    }

    uint16_t secure_orig_length(secure_t *cryptex) {
        secure_head_t *head = (secure_head_t *) cryptex;
        return head->orig;
    }

    uint16_t secure_total_length(secure_t *cryptex) {
        secure_head_t *head = (secure_head_t *) cryptex;
        return (uint16_t) (sizeof(secure_head_t) + (head->key + head->mac + head->body));
    }

    void *secure_key_data(secure_t *cryptex) {
        return cryptex + sizeof(secure_head_t);
    }

    void *secure_mac_data(secure_t *cryptex) {
        secure_head_t *head = (secure_head_t *) cryptex;
        return cryptex + (sizeof(secure_head_t) + head->key);
    }

    void *secure_body_data(secure_t *cryptex) {
        secure_head_t *head = (secure_head_t *) cryptex;
        return cryptex + (sizeof(secure_head_t) + head->key + head->mac);
    }

    void *secure_alloc(uint16_t key, uint16_t mac, uint16_t orig, uint16_t body) {
        secure_t *cryptex = (secure_t *) malloc(sizeof(secure_head_t) + key + mac + body);
        secure_head_t *head = (secure_head_t *) cryptex;
        head->key = key;
        head->mac = mac;
        head->orig = orig;
        head->body = body;
        return cryptex;
    }

    void secure_free(secure_t *cryptex) {
        free(cryptex);
        return;
    }

}
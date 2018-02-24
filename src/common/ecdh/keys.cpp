#include "ecies.h"

#define LOGD {};

namespace ecdh {

    EC_GROUP *eliptic = NULL;

    void ecies_group_init(void) {

        EC_GROUP *group;

        if (!(group = EC_GROUP_new_by_curve_name(ECIES_CURVE))) {
            LOGD("EC_GROUP_new_by_curve_name failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
        }

        else if (EC_GROUP_precompute_mult(group, NULL) != 1) {
            LOGD("EC_GROUP_precompute_mult failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            EC_GROUP_free(group);
        }

        EC_GROUP_set_point_conversion_form(group, POINT_CONVERSION_COMPRESSED);
        eliptic = group;

        return;
    }

    void ecies_group_free(void) {

        EC_GROUP *group = eliptic;
        eliptic = NULL;
        if (group) {
            EC_GROUP_free(group);
        }
        return;
    }

// This is not thread-safe! You'll need to use a mutex if you want this to work in a multi-threaded world.
// But its worth noting that duplicating the group instead of allocating it on each pass reduced the execution time by 50%!
    EC_GROUP *ecies_group(void) {

        EC_GROUP *group;

        if (eliptic) {
            return EC_GROUP_dup(eliptic);
        }

        if (!(group = EC_GROUP_new_by_curve_name(ECIES_CURVE))) {
            LOGD("EC_GROUP_new_by_curve_name failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            return NULL;
        }

        else if (EC_GROUP_precompute_mult(group, NULL) != 1) {
            LOGD("EC_GROUP_precompute_mult failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            EC_GROUP_free(group);
            return NULL;
        }

        EC_GROUP_set_point_conversion_form(group, POINT_CONVERSION_COMPRESSED);

        return EC_GROUP_dup(group);
    }

    void ecies_key_free(EC_KEY *key) {
        EC_KEY_free(key);
        return;
    }

    EC_KEY *ecies_key_create(void) {

        EC_GROUP *group;
        EC_KEY *key = NULL;

        if (!(key = EC_KEY_new())) {
            LOGD("EC_KEY_new failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            return NULL;
        }

        if (!(group = ecies_group())) {
            EC_KEY_free(key);
            return NULL;
        }

        if (EC_KEY_set_group(key, group) != 1) {
            LOGD("EC_KEY_set_group failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            EC_GROUP_free(group);
            EC_KEY_free(key);
            return NULL;
        }

        EC_GROUP_free(group);

        if (EC_KEY_generate_key(key) != 1) {
            LOGD("EC_KEY_generate_key failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            EC_KEY_free(key);
            return NULL;
        }

        return key;
    }

    EC_KEY *ecies_key_create_public_octets(unsigned char *octets, size_t length) {

        EC_GROUP *group;
        EC_KEY *key = NULL;
        EC_POINT *point = NULL;

        if (!(key = EC_KEY_new())) {
            LOGD("EC_KEY_new failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            return NULL;
        }

        if (!(group = ecies_group())) {
            EC_KEY_free(key);
            return NULL;
        }

        if (EC_KEY_set_group(key, group) != 1) {
            LOGD("EC_KEY_set_group failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            EC_GROUP_free(group);
            EC_KEY_free(key);
            return NULL;
        }

        if (!(point = EC_POINT_new(group))) {
            LOGD("EC_POINT_new failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            EC_GROUP_free(group);
            EC_KEY_free(key);
            return NULL;
        }

        if (EC_POINT_oct2point(group, point, octets, length, NULL) != 1) {
            LOGD("EC_POINT_oct2point failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            EC_GROUP_free(group);
            EC_KEY_free(key);
            return NULL;
        }

        if (EC_KEY_set_public_key(key, point) != 1) {
            LOGD("EC_KEY_set_public_key failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            EC_GROUP_free(group);
            EC_POINT_free(point);
            EC_KEY_free(key);
            return NULL;
        }

        EC_GROUP_free(group);
        EC_POINT_free(point);

        if (EC_KEY_check_key(key) != 1) {
            LOGD("EC_KEY_check_key failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            EC_KEY_free(key);
            return NULL;
        }

        return key;
    }

    EC_KEY *ecies_key_create_public_hex(char *hex) {

        EC_GROUP *group;
        EC_KEY *key = NULL;
        EC_POINT *point = NULL;

        if (!(key = EC_KEY_new())) {
            LOGD("EC_KEY_new");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            return NULL;
        }

        if (!(group = EC_GROUP_new_by_curve_name(ECIES_CURVE))) {
            LOGD("EC_GROUP_new_by_curve_name failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            EC_KEY_free(key);
            return NULL;
        }

        EC_GROUP_set_point_conversion_form(group, POINT_CONVERSION_COMPRESSED);

        if (EC_KEY_set_group(key, group) != 1) {
            LOGD("EC_KEY_set_group");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            EC_GROUP_free(group);
            EC_KEY_free(key);
            return NULL;
        }

        if (!(point = EC_POINT_hex2point(group, hex, NULL, NULL))) {
            LOGD("EC_POINT_hex2point");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            EC_KEY_free(key);
            return NULL;
        }

        if (EC_KEY_set_public_key(key, point) != 1) {
            LOGD("EC_KEY_set_public_key");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            EC_GROUP_free(group);
            EC_POINT_free(point);
            EC_KEY_free(key);
            return NULL;
        }

        EC_GROUP_free(group);
        EC_POINT_free(point);

        if (EC_KEY_check_key(key) != 1) {
            LOGD("EC_KEY_check_key");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            EC_KEY_free(key);
            return NULL;
        }

        return key;
    }

    std::pair<uint8_t *, size_t> ecies_key_public_get_binary(EC_KEY *key) {

        const EC_POINT *point;
        const EC_GROUP *group;

        if (!(point = EC_KEY_get0_public_key(key))) {
            LOGD("EC_KEY_get0_public_key");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            return std::pair<uint8_t *, size_t>(nullptr, 0);
        }

        if (!(group = EC_KEY_get0_group(key))) {
            LOGD("EC_KEY_get0_group");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            return std::pair<uint8_t *, size_t>(nullptr, 0);
        }

        BIGNUM *bn = BN_new();

        if (!(bn = EC_POINT_point2bn(group, point, POINT_CONVERSION_COMPRESSED, bn, NULL))) {
            LOGD("EC_POINT_point2bn");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            BN_free(bn);
            return std::pair<uint8_t *, size_t>(nullptr, 0);
        }

        int size;
        unsigned char *data = (unsigned char *) malloc((size_t) BN_num_bytes(bn));

        if ((size = BN_bn2bin(bn, data)) == 0) {
            LOGD("BN_bn2bin");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            BN_free(bn);
            return std::pair<uint8_t *, size_t>(nullptr, 0);
        }

        BN_free(bn);
        return std::pair<uint8_t *, size_t>(data, size);
    }

    char *ecies_key_public_get_hex(EC_KEY *key) {

        char *hex;
        const EC_POINT *point;
        const EC_GROUP *group;

        if (!(point = EC_KEY_get0_public_key(key))) {
            LOGD("EC_KEY_get0_public_key");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            return NULL;
        }

        if (!(group = EC_KEY_get0_group(key))) {
            LOGD("EC_KEY_get0_group");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            return NULL;
        }

        if (!(hex = EC_POINT_point2hex(group, point,
                                       POINT_CONVERSION_COMPRESSED, NULL))) {
            LOGD("EC_POINT_point2hex");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            return NULL;
        }

        //LOGD("PUB: %s", hex);
        return hex;
    }

    EC_KEY *ecies_key_create_private_binary(uint8_t *data, size_t size) {

        EC_GROUP *group;
        BIGNUM *bn = NULL;
        EC_KEY *key = NULL;

        if (!(key = EC_KEY_new())) {
            LOGD("EC_KEY_new");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            return NULL;
        }

        if (!(group = EC_GROUP_new_by_curve_name(ECIES_CURVE))) {
            LOGD("EC_GROUP_new_by_curve_name failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            EC_KEY_free(key);
            return NULL;
        }

        EC_GROUP_set_point_conversion_form(group, POINT_CONVERSION_COMPRESSED);

        if (EC_KEY_set_group(key, group) != 1) {
            LOGD("EC_KEY_set_group");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            EC_GROUP_free(group);
            EC_KEY_free(key);
            return NULL;
        }

        EC_GROUP_free(group);

        if (!(bn = BN_bin2bn(data, (int) size, NULL))) {
            LOGD("BN_bin2bn");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            EC_KEY_free(key);
            return NULL;
        }

        if (EC_KEY_set_private_key(key, bn) != 1) {
            LOGD("EC_KEY_set_public_key");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            EC_KEY_free(key);
            return NULL;
        }

        return key;
    }

    EC_KEY *ecies_key_create_private_hex(char *hex) {

        EC_GROUP *group;
        BIGNUM *bn = NULL;
        EC_KEY *key = NULL;

        if (!(key = EC_KEY_new())) {
            LOGD("EC_KEY_new");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            return NULL;
        }

        if (!(group = EC_GROUP_new_by_curve_name(ECIES_CURVE))) {
            LOGD("EC_GROUP_new_by_curve_name failed. {error = %s}",
                 ERR_error_string(ERR_get_error(), NULL));
            EC_KEY_free(key);
            return NULL;
        }

        EC_GROUP_set_point_conversion_form(group, POINT_CONVERSION_COMPRESSED);

        if (EC_KEY_set_group(key, group) != 1) {
            LOGD("EC_KEY_set_group");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            EC_GROUP_free(group);
            EC_KEY_free(key);
            return NULL;
        }

        EC_GROUP_free(group);

        if (!(BN_hex2bn(&bn, hex))) {
            LOGD("BN_hex2bn");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            EC_KEY_free(key);
            return NULL;
        }

        if (EC_KEY_set_private_key(key, bn) != 1) {
            LOGD("EC_KEY_set_private_key");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            EC_KEY_free(key);
            BN_free(bn);
            return NULL;
        }

        BN_free(bn);

        return key;
    }

    std::pair<uint8_t *, size_t> ecies_key_private_get_binary(EC_KEY *key) {

        const BIGNUM *bn;

        if (!(bn = EC_KEY_get0_private_key(key))) {
            LOGD("EC_KEY_get0_private_key");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            return std::pair<uint8_t *, size_t>(nullptr, 0);
        }

        int size;
        unsigned char *data = (unsigned char *) malloc((size_t) BN_num_bytes(bn));

        if ((size = BN_bn2bin(bn, data)) == 0) {
            LOGD("BN_bn2bin");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            return std::pair<uint8_t *, size_t>(nullptr, 0);
        }

        return std::pair<uint8_t *, size_t>(data, size);
    }

    char *ecies_key_private_get_hex(EC_KEY *key) {

        char *hex;
        const BIGNUM *bn;

        if (!(bn = EC_KEY_get0_private_key(key))) {
            LOGD("EC_KEY_get0_private_key");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            return NULL;
        }

        if (!(hex = BN_bn2hex(bn))) {
            LOGD("BN_bn2hex");
            LOGD("%s", ERR_error_string(ERR_get_error(), NULL));
            return NULL;
        }

        //LOGD("PRIV: %s", hex);
        return hex;
    }

}
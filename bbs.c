#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "bbs.h"

int bbs_init(bbs_t* ptr, char* bbsN_str, char* seed_str) {
    int err = 0;
    err = mpz_init_set_str(ptr->N, bbsN_str, 16);
    err = mpz_init_set_str(ptr->x, seed_str, 16);
    return err;
}

void bbs_free(bbs_t* ptr) {
    mpz_clear(ptr->N);
    mpz_clear(ptr->x);
    ptr = NULL;
}

uint64_t bbs_rand(bbs_t* ptr) {
    static uint64_t cache[3];
    static int count = 2;

    if (count == 2) {
        for (int i = 0; i < 8 * sizeof(uint64_t); i++) {
            mpz_mul(ptr->x, ptr->x, ptr->x);      // x = x * x
            mpz_mod(ptr->x, ptr->x, ptr->N);      // x = x % N
            uint64_t b = mpz_get_ui(ptr->x) & 7;  // b = x & 7
            cache[0] = (cache[0] << 1) | ((b & 1) != 0);
            cache[1] = (cache[1] << 1) | ((b & 2) != 0);
            cache[2] = (cache[2] << 1) | ((b & 4) != 0);
        }
    }

    count = (count + 1) % 3;
    return cache[count];
}

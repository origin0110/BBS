#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef GMP_MINI
#include <gmp.h>  // gmp or gmp-mini is necessary: https://gmplib.org/
#else
#include "gmp-mini.h"
#endif

#define BBS_N \
    "27a7c524954ec6fde2012b0886038279dffecf9e3dc110fc23eb51d34a115dc4\
8d2c86cb9c57cc8ad5dbb9fe8304329d54a3dd243d097869c82c992eb17899b4\
09416f53dd290ff48820a23a01858bdab5f72f61a748adf46bd703e548489afb\
5dcde42b8337abfef76801bb16106c670ee4b2b0874c15431598b57e200c9ec0\
7d7ca03c65345f713f542351e7cd2a146169b018c03cc4854624a9f737b58c6b\
34c53c91ae6a2a0224b09643bcfccafbac6c4c27fbc288e30bb9ebb7b9a0ea3d\
57fd561d074a559dac0ab22841d8abe157e367ebc2559b744bb0060b372e6339\
14062b46616dfe3d4d738e9a3e3ed96adfc74abf2d326096cd5af51712087103\
543f8ac60a2808bac1c3ee979e4acbecbac9cedac5a07aaa997f64cc895bb0d5\
006f136d8f9022aca504d52611c9f1431a84560811ba6df7c7c5df94b5ee4259\
19eb0ec1c51d48825f1fde43e626ae514551aaef67c5130bb2de785771692ec7\
720e46f14a87f2ccce7ea4725c2ba905492c9045017135cf4882c91e03f35254\
b1766322df5c4ebcb662485ade68c12ae70255f641a6f36d20385e226b8053ac\
3289f41cc91730fc701255bc7a5d7ceab580ac79631f202a1541185d2f2229fc\
2366e5dd8586a56e597274347e6233abd26c5ff3660af9dd0c9a885ac383cf7e\
90cb86306df8c8d39a1ccfae169d4ef7f77f1fcda9540b2a270e80df3fe67e85"

typedef struct {
    mpz_t N;
    mpz_t x;
} bbs_t;

// initialization a bbs prng
int bbs_init(bbs_t* ptr, char* bbsN_str, char* seed_str);

// free a bbs prng
void bbs_free(bbs_t* ptr);

// generate a random number
uint64_t bbs_rand(bbs_t* ptr);

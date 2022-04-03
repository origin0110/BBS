#include <stdio.h>
#include "bbs.h"

int main(void) {
    char* bbsN_str = BBS_N;
    char* key_str = "abcdef1145141919810abcdef";

    // declare a bbs prng, then initialization it with HEX string
    bbs_t bbs;
    bbs_t* bbs_ptr = &bbs;
    bbs_init(bbs_ptr, bbsN_str, key_str);

    // 105,000 byte/s on Zen3@4.4gHz with 4096bit bbsN
    for (int i = 0; i < 10000; i++)
        printf("%llu,\n", bbs_rand(bbs_ptr));

    // recover a bbs prng after use, or there may be a memory leak
    bbs_free(bbs_ptr);

    return 0;
}
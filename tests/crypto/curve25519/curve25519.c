#include "Curve25519-donna.h"
/* #include "Hacl_Curve25519_51.h" */

#include <stdio.h>
#include <stdint.h>

__attribute__((section(".secret"))) uint8_t out[32] = {
    0xa5, 0x46, 0xe3, 0x6b, 0xf0, 0x52, 0x7c, 0x9d, 0x3b, 0x16, 0x15, 0x4b, 0x82, 0x46, 0x5e, 0xdd,
    0x62, 0x14, 0x4c, 0x0a, 0xc1, 0xfc, 0x5a, 0x18, 0x50, 0x6a, 0x22, 0x44, 0xba, 0x44, 0x9a, 0xc4
};
__attribute__((section(".secret"))) uint8_t public[32] = {
    0xe6, 0xdb, 0x68, 0x67, 0x58, 0x30, 0x30, 0xdb, 0x35, 0x94, 0xc1, 0xa4, 0x24, 0xb1, 0x5f, 0x7c,
    0x72, 0x66, 0x24, 0xec, 0x26, 0xb3, 0x35, 0x3b, 0x10, 0xa9, 0x03, 0xa6, 0xd0, 0xab, 0x1c, 0x4c
};
__attribute__((section(".secret"))) uint8_t private[32] = {
    0xc3, 0xda, 0x55, 0x37, 0x9d, 0xe9, 0xc6, 0x90, 0x8e, 0x94, 0xea, 0x4d, 0xf2, 0x8d, 0x08, 0x4f,
    0x32, 0xec, 0xcf, 0x03, 0x49, 0x1c, 0x71, 0xf7, 0x54, 0xb4, 0x07, 0x55, 0x77, 0xa2, 0x85, 0x52
};

__attribute__((section(".declassified"))) volatile uint8_t declassified[32];

int main() {

    /* curve25519_donna(private, public, out); */
    curve25519_donna(private, public, out);
    /* Hacl_Curve25519_51_ecdh(out, private, public); */

    for (size_t i = 0; i < sizeof(out); ++i) {
        declassified[i] = out[i];
    }

    for (size_t i = 0; i < sizeof(declassified); ++i) {
        printf("%02x", declassified[i]);
    }

    printf("\n");
}

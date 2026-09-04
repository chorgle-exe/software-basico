#include <stdio.h>
 
unsigned char switch_byte(unsigned char x) {
    return ((x << 4) | (x >> 4)) & 0xFF;
}
 
unsigned char rotate_left(unsigned char x, int n) {
    return ((x << n) | (x >> (8 - n))) & 0xFF;
}
 
int main(void) {
    /* testes de switch_byte */
    printf("switch_byte(0xAB) = 0x%02x (esperado 0xba)\n", switch_byte(0xAB));
    printf("switch_byte(0x12) = 0x%02x (esperado 0x21)\n", switch_byte(0x12));
    printf("switch_byte(0x00) = 0x%02x (esperado 0x00)\n", switch_byte(0x00));
    printf("switch_byte(0xFF) = 0x%02x (esperado 0xff)\n", switch_byte(0xFF));
    printf("switch_byte(0xF0) = 0x%02x (esperado 0x0f)\n", switch_byte(0xF0));
 
    /* testes de rotate_left */
    printf("rotate_left(0x61, 1) = 0x%02x (esperado 0xc2)\n", rotate_left(0x61, 1));
    printf("rotate_left(0x61, 2) = 0x%02x (esperado 0x85)\n", rotate_left(0x61, 2));
    printf("rotate_left(0x61, 7) = 0x%02x (esperado 0xb0)\n", rotate_left(0x61, 7));
    printf("rotate_left(0x80, 1) = 0x%02x (esperado 0x01)\n", rotate_left(0x80, 1));
    printf("rotate_left(0x01, 3) = 0x%02x (esperado 0x08)\n", rotate_left(0x01, 3));
    printf("rotate_left(0xAA, 4) = 0x%02x (esperado 0xaa)\n", rotate_left(0xAA, 4));
 
    return 0;
}
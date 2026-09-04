#include <stdio.h>

int odd_ones(unsigned int x) {
    x ^= x >> 16;  /* combina bit a bit as duas metades de 16 bits */
    x ^= x >> 8;   /* combina as duas metades de 8 bits */
    x ^= x >> 4;   /* combina as duas metades de 4 bits */
    x ^= x >> 2;   /* combina as duas metades de 2 bits */
    x ^= x >> 1;   /* combina os dois últimos bits */
    return x & 1;  /* isola o resultado final */
}

int main(void) {
  printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
  printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
  return 0;
}
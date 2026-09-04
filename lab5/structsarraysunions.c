#include <stdio.h>


/* funcao dump: imprime, byte a byte, o conteudo de um bloco de memoria */

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}


/* parte 2: struct X, com "buraco" entre os campos b e c              */

struct X {
  int a;
  short b;
  int c;
} x = {0xa1a2a3a4, 0xb1b2, 0xc1c2c3c4};


/* parte 3: structs e unions com valores "reconhecíveis"              */

struct X1 {
  char c1;
  int i;
  char c2;
} x1 = {0xc1, 0x01020304, 0xc2};

struct X2 {
  long l;
  char c;
} x2 = {0x0102030405060708, 0xc1};

struct X3 {
  int i;
  char c1;
  char c2;
} x3 = {0x01020304, 0xc1, 0xc2};

struct X4 {
  struct X2 x;
  char c;
} x4 = {{0x0102030405060708, 0xc1}, 0xc2};

struct X5 {
  char c1;
  char c2;
  char c3;
} x5 = {0xc1, 0xc2, 0xc3};

struct X6 {
  short s1;
  int i;
  char c[3];
  short s2;
} x6 = {0x0102, 0x01020304, {0xc1, 0xc2, 0xc3}, 0x0102};

union U1 {
  int i;
  char c[5];
};

union U2 {
  short s;
  char c[5];
};

int main (void) {
  int i, j;

  /* ---------------- parte 1: arrays ---------------- */
  short a[2][3];
  int b[2];

  for (i = 0; i < 2; i++) {
    b[i] = i;
    for (j = 0; j < 3; j++)
      a[i][j] = 3*i + j;
  }

  printf("===================================\n");
  printf("PARTE 1 - ARRAYS\n");
  printf("===================================\n");

  printf("sizeof(b) = %zu\n", sizeof(b));
  printf("b:\n");
  dump(b, sizeof(b));

  printf("\nsizeof(a) = %zu\n", sizeof(a));
  printf("a:\n");
  dump(a, sizeof(a));

  /* ---------------- Parte 2: struct X (buraco) ---------------- */
  printf("\n===================================\n");
  printf("PARTE 2 - struct X (com buraco)\n");
  printf("===================================\n");
  printf("sizeof(x) = %zu\n", sizeof(x));
  printf("x:\n");
  dump(&x, sizeof(x));

  /* ---------------- Parte 3: structs X1..X6 ---------------- */
  printf("\n===================================\n");
  printf("PARTE 3 - structs X1 a X6\n");
  printf("===================================\n");

  printf("\nsizeof(x1) = %zu\n", sizeof(x1));
  printf("x1:\n");
  dump(&x1, sizeof(x1));

  printf("\nsizeof(x2) = %zu\n", sizeof(x2));
  printf("x2:\n");
  dump(&x2, sizeof(x2));

  printf("\nsizeof(x3) = %zu\n", sizeof(x3));
  printf("x3:\n");
  dump(&x3, sizeof(x3));

  printf("\nsizeof(x4) = %zu\n", sizeof(x4));
  printf("x4:\n");
  dump(&x4, sizeof(x4));

  printf("\nsizeof(x5) = %zu\n", sizeof(x5));
  printf("x5:\n");
  dump(&x5, sizeof(x5));

  printf("\nsizeof(x6) = %zu\n", sizeof(x6));
  printf("x6:\n");
  dump(&x6, sizeof(x6));

  /* ---------------- Parte 3: unions U1 e U2 ---------------- */
  printf("\n===================================\n");
  printf("PARTE 3 - unions U1 e U2\n");
  printf("===================================\n");

  union U1 u1;
  union U2 u2;

  printf("\nsizeof(u1) = %zu\n", sizeof(u1));
  u1.i = 0x01020304;
  printf("u1 (apos escrever em i):\n");
  dump(&u1, sizeof(u1));

  for (i = 0; i < 5; i++)
    u1.c[i] = 0xcc;
  printf("u1 (apos escrever em c[0..4]):\n");
  dump(&u1, sizeof(u1));

  printf("\nsizeof(u2) = %zu\n", sizeof(u2));
  u2.s = 0x0102;
  printf("u2 (apos escrever em s):\n");
  dump(&u2, sizeof(u2));

  for (i = 0; i < 5; i++)
    u2.c[i] = 0xcc;
  printf("u2 (apos escrever em c[0..4]):\n");
  dump(&u2, sizeof(u2));

  return 0;
}
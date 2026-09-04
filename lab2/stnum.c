#include <ctype.h>
#include <stdio.h>

int string2num_geral(char *s, int base) {
  int a = 0;
  for (; *s; s++) {
    int d = isdigit(*s) ? *s - '0' : tolower(*s) - 'a' + 10;
    a = a*base + d;
  }
  return a;
}

int main(void) {
    printf("%d\n",string2num_geral("1a",16));
    printf("%d\n",string2num_geral("a09b",16));
    printf("%d\n",string2num_geral("z09b",36));
    return 0;
}
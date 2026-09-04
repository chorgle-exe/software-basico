/*
int nums[] = {10, -21, -30, 45};   (agora armazenado como bytes)
int main() {
  int i;
  signed char *p;
  for (i = 0, p = nums; i != 4; i++, p++)
    printf("%d\n", *p);   // *p e' estendido de char (8 bits) para int (32 bits)
  return 0;
}
*/

.data
nums:  .byte  10, -21, -30, 45
Sf:  .string "%d\n"

.text
.globl  main
main:

/* prologo - nao mexa */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)
/* fim prologo */

  movl  $0, %ebx       /* i = 0 */
  movq  $nums, %r12    /* p = &nums */

L1:
  cmpl  $4, %ebx
  je    L2

  movsbl (%r12), %eax  /* eax = extensao de sinal do byte apontado por p */

/* imprime %eax - nao mexa */
  movq    $Sf, %rdi
  movl    %eax, %esi
  call  printf
/* fim impressao */

  addl  $1, %ebx        /* i++ */
  addq  $1, %r12         /* p++  (agora avanca 1 byte, nao 4) */
  jmp   L1

L2:
/* finalizacao - nao mexa */
  movq  $0, %rax
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  leave
  ret
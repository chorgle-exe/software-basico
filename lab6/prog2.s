/*
int nums[] = {10, -21, -30, 45};
int main() {
  int i, *p;
  int sum = 0;
  for (i = 0, p = nums; i != 4; i++, p++)
    sum += *p;
  printf("%d\n", sum);
  return 0;
}
*/

.data
nums:  .int  10, -21, -30, 45
Sf:  .string "%d\n"

.text
.globl  main
main:

/* prologo - nao mexa */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $32, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)
  movq    %r13, -24(%rbp)
/* fim prologo */

  movl  $0, %ebx        /* i = 0 */
  movq  $nums, %r12     /* p = &nums */
  movl  $0, %r13d       /* sum = 0 (registrador callee-saved) */

L1:
  cmpl  $4, %ebx        /* if (i == 4) */
  je    L2

  movl  (%r12), %eax    /* eax = *p */
  addl  %eax, %r13d     /* sum += *p */

  addl  $1, %ebx        /* i++ */
  addq  $4, %r12        /* p++ (int* -> soma 4 bytes) */
  jmp   L1

L2:
  movl  %r13d, %eax     /* eax = sum, para poder imprimir */

/* imprime %eax - nao mexa */
  movq    $Sf, %rdi
  movl    %eax, %esi
  call  printf
/* fim impressao */

/* finalizacao - nao mexa */
  movq  $0, %rax
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  movq  -24(%rbp), %r13
  leave
  ret
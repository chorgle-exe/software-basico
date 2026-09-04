/*
int nums[] = {10, -21, -30, 45};
int main() {
  int i, *p;
  for (i = 0, p = nums; i != 4; i++, p++)
    if ((*p % 2) == 0)
      printf("%d\n", *p);
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
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)
/* fim prologo */

  movl  $0, %ebx        /* i = 0 */
  movq  $nums, %r12     /* p = &nums */

L1:
  cmpl  $4, %ebx
  je    L3

  movl  (%r12), %eax        /* eax = *p */
  testl $1, %eax             /* testa bit 0 (paridade), sem alterar eax */
  jne   L2                   /* se bit0==1 (impar), pula a impressao */

  /* eax continua com *p (par) - imprime */
  movq    $Sf, %rdi
  movl    %eax, %esi
  call  printf

L2:
  addl  $1, %ebx
  addq  $4, %r12
  jmp   L1

L3:
/* finalizacao - nao mexa */
  movq  $0, %rax
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  leave
  ret
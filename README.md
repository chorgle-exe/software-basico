# Software Básico — Laboratório INF1018

Este repositório contém exercícios de compilação e organização de programas em C usando GNU GCC no Linux.

## Objetivo

Aprender a usar o terminal para compilar e executar programas em C, criar arquivos de código fonte, separar código em múltiplos arquivos e entender warnings do compilador.

## Estrutura dos exercícios

### ex1.c
- Programa único com função `foo` e `main` no mesmo arquivo.
- Compilação:
  ```bash
  gcc -Wall -o ex1 ex1.c
  ```
- Execução:
  ```bash
  ./ex1 4.0
  ```
- Teste também sem argumentos:
  ```bash
  ./ex1
  ```
- O exercício mostra como `argc` e `argv` funcionam.

### ex2.c e labaux.c
- Aqui o código foi dividido em dois arquivos.
- `labaux.c` contém a definição de `foo`.
- `ex2.c` contém `main` e apenas o protótipo de `foo`:
  ```c
  float foo(float pf);
  ```
- Compilação passo a passo:
  ```bash
  gcc -Wall -c labaux.c
  gcc -Wall -c ex2.c
  gcc -o ex2 labaux.o ex2.o
  ```
- Compilação em uma etapa:
  ```bash
  gcc -Wall -o ex2 labaux.c ex2.c
  ```
- Execução:
  ```bash
  ./ex2 4.0
  ```

### ex3.c
- Este arquivo é igual a `ex2.c`, mas sem o cabeçalho de `foo`.
- A compilação é:
  ```bash
  gcc -Wall -o ex3 labaux.c ex3.c
  ```
- O compilador pode emitir warnings, porque a declaração de `foo` não está visível em `ex3.c`.
- O programa ainda pode ser gerado e rodar, mas o aviso indica que o código pode estar incorreto ou ser indefinido.

### dump.c e ex4.c
- `dump.c` define uma função que imprime os bytes de um bloco de memória.
- `ex4.c` chama `dump` para mostrar como valores do tipo `char`, `int` e arrays de char são armazenados na memória.
- Compile e execute usando:
  ```bash
  gcc -Wall -o ex4 dump.c ex4.c
  ./ex4
  ```
- Este exercício ajuda a entender:
  - ponteiros
  - argumentos de função
  - `sizeof`
  - representação de dados em bytes

## Boas práticas usadas aqui

- Código fonte em arquivos `.c`
- Separar funções em arquivos diferentes quando faz sentido
- Usar `-Wall` para receber warnings do compilador
- Usar `.gitignore` para ignorar arquivos gerados por build (`*.o`, executáveis) e configurações de editor (`.vscode/`)

## Observações

- O comando `./ex1` funciona quando o executável está no diretório atual.
- Se o terminal não encontrar `ex1`, verifique se você está no diretório correto e se o arquivo existe.
- Warnings não são erros, mas devem ser lidos com atenção.

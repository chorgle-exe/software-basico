# Laboratório 1

Aquecimento — Compilação em Linux/GCC

### Diretório corrente
`pwd` mostra o diretório atual

`ls` lista seu conteúdo. 

`mkdir inf1018` (make directory) cria uma nova pasta chamada `inf1018` dentro do diretório corrente.

`cd inf1018` (change directory) move o usuário para dentro da pasta `inf1018`, tornando-a o novo diretório corrente.

`pwd` confirma a mudança do diretório, mostrando o caminho terminado em /inf1018.

### ex1.c
Programa que lê um valor float pela linha de comando (`argv[1]`), converte com `atof`,
soma 1 usando a função `foo` e imprime o resultado. 
`argc` conta quantos argumentos foram digitados; 
`argv` é o vetor de strings com esses argumentos.

Compilação: `gcc -Wall -o ex1 ex1.c` → gera o executável `ex1`.
Execução: `./ex1 4.0`.

**Por que `ex1` sozinho não funciona, mas `./ex1` funciona?**

O shell só procura executáveis nas pastas listadas em `PATH`, e o diretório corrente
normalmente não está lá. `./ex1` indica explicitamente "execute o arquivo `ex1` que
está aqui", por isso funciona.

### ex2.c / labaux.c (divisão em dois arquivos)
`labaux.c` guarda a implementação de `foo`; 
`ex2.c` guarda apenas o protótipo `float foo(float pf);`. 
Cada `.c` é compilado separadamente em um `.o`

(`gcc -Wall -c arquivo.c`) e depois ligados (`gcc -o ex2 labaux.o ex2.o`),
ou tudo em um só passo: `gcc -Wall -o ex2 labaux.c ex2.c`.

### ex3.c (sem o protótipo)
Ao compilar sem declarar `foo` antes de usá-la, o gcc emite **warnings**, pois não
sabe o tipo real de retorno/parâmetros da função. Isso faz o compilador tratar o
retorno como `int` em vez de `float`, e `./ex3 4.0` imprime um valor incorreto.

### dump.c
Função que recebe um ponteiro genérico `void *p` e um tamanho `n`, converte o
ponteiro para `unsigned char*` (1 byte) e imprime, byte a byte, o conteúdo bruto
da memória a partir de `p`.

### ex4.c — conclusões sobre a memória
- `c1` (char = 1): 1 byte, valor armazenado `1`.
- `c2` (char = '1'): 1 byte, valor armazenado na memória: `49` (código ASCII de `'1'`).
- `i` (int = 1): 4 bytes, mesmo valor lógico de `c1`, mas tipo maior. -> ( `1 0 0 0`)
- `v` (char[] = "1"): 2 bytes — o caractere `'1'` -> na memória: (49) + terminador `'\0'` (0).

**Conclusão:** o tipo da variável define quantos bytes ela ocupa; um mesmo
valor lógico pode ter representações binárias diferentes conforme o tipo e
strings em C sempre terminam com um byte nulo `\0`.

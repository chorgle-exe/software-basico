# Software Básico — Laboratório INF1018

esse repositório contém exercícios de compilação e organização de programas em C usando GNU GCC no Linux.

## Objetivo

aprender a usar o terminal para compilar e executar programas em C, criar arquivos de código fonte, separar código em múltiplos arquivos e entender warnings do compilador.

- mkdir inf1018: cria (make directory) uma nova pasta chamada inf1018 dentro do diretório corrente.

- cd inf1018 (change directory): move você "para dentro" dessa pasta, tornando-a o novo diretório corrente.

- pwd: confirma que o diretório corrente mudou, agora mostrando o caminho terminado em /inf1018.

- gcc: invoca o compilador GNU C.
  
-Wall (warnings all): pede ao compilador para exibir todos os avisos relevantes sobre possíveis problemas no código (mesmo que não impeçam a compilação).

-o ex1: define o nome do arquivo de saída (o executável) como ex1. Sem essa opção, o gcc geraria um arquivo padrão chamado a.out.

ex1.c: o arquivo-fonte a ser compilado.

./ex1 4.0: executa o programa ex1, passando "4.0" como argv[1]. O ./ indica explicitamente "execute o arquivo ex1 que está no diretório corrente".

ao digitar apenas ex1 (sem ./), o sistema procura um programa chamado ex1 nos diretórios listados na variável de ambiente PATH

a função dump.c percorre n bytes a partir do endereço p e imprime o valor numérico de cada byte — ou seja, mostra a representação "crua", em memória, de qualquer variável, independentemente do tipo que ela realmente tem.



O que se pode concluir sobre c1, c2, i e v na memória?

c1 ocupa 1 byte, e esse byte contém diretamente o valor numérico 1.

c2 também ocupa 1 byte, mas o valor armazenado é 49, o código ASCII do caractere '1' — evidenciando que, para o computador, caracteres são apenas números interpretados de forma especial ao serem exibidos como texto.

i ocupa 4 bytes (em máquinas típicas de 32/64 bits), mesmo armazenando o "mesmo valor lógico" (1) que c1. Isso mostra que tipos diferentes (char vs int) reservam quantidades diferentes de memória, mesmo para representar valores pequenos — o int usa mais bytes para poder representar uma faixa muito maior de números.

v ocupa 2 bytes: o caractere '1' (49) seguido do byte 0 ('\0'), o terminador que marca o fim da string. Isso confirma que toda string em C precisa desse byte extra além dos caracteres "visíveis", e é esse terminador que permite que funções como printf("%s", ...) saibam onde a string termina.

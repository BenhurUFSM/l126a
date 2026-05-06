## Strings

Uma *string* é uma sequência de caracteres, usada para representar palavras, textos, etc em um programa.
Várias linguagens de programação têm strings como um dos tipos de dados básicos da linguagem, como números inteiros ou em ponto flutuante.

Em um tipo numérico, o quantidade de memória necessária para representar um valor não depende desse valor, mas de seu tipo. Se um inteiro ocupa 4 bytes, esse será o espaço necessário para armazenar o valor 0 ou o valor 200 milhões, ou qualquer outro dos valores representáveis com esse tipo.
Com strings, é necessário um espaço para cada caractere que a string contém, fazendo com que o espaço necessário para a string "Oi" seja diferente do necessário para a string "Boa noite".
Foram criadas várias formas de se lidar com esse problema, nas várias linguagens de programação que já foram inventadas.

Na linguagem C, resolveu-se não tratar esse problema diretamente na linguagem. Ela não tem esse tipo de dados, e oferece algumas (poucas) facilidades para sua implementação.
As strings em C são geralmente colocadas em vetores de char.
Como qualquer vetor em C, vetores de char são de tamanho invariável, e esse tamanho não é facilmente acessável (uma função que recebe um vetor não tem como saber seu tamanho por métodos diretos, por exemplo).
Strings são tipicamente mais dinâmicas que vetores de char (em geral se pode alterar seu valor, e alterações no valor de uma string comumente alteram o número de caracteres que ela contém e o espaço necessário para representá-la.
O casamento dessas incompatibilidades é tarefa que a linguagem não resolve; seu controle deve ser realizado externamente, diretamente pelo programador e com a ajuda de funções de biblioteca.
Felizmente, a biblioteca padrão da linguagem oferece um conjunto de funções que facilitam o manuseio de strings.

A forma padrão de se representar uma string em C é colocar, logo após o fim da string (e para marcar esse final), um caractere especial que informa que a string terminou. Foi escolhido para isso o caractere com código 0. Como esse caractere serve para informar o final da string, essa representação tem a limitação de que não é possível ter esse caractere no interior de uma string. Essa limitação não é considerada muito importante, porque o caractere de código 0 (que foi criado para indicar uma operação nula a um dispositivo) tem um uso bastante infrequente.
Para chamar a atenção para o fato que se está tratando do caractere que tem o código 0 e não de um zero qualquer, é comum se representar esse caractere como `'\0'`.

Para ser armazenada em um vetor, uma string necessita portanto que o vetor tenha tamanho suficiente para conter todos os caracteres que constituem a string mais um para o caractere que representa o seu final.
Como o estouro de vetor (o acesso além dos limites do vetor) não é controlado pela linguagem, esse controle no caso de strings deve ser uma preocupação constante do programador, que sempre deve certificar-se que seus vetores têm capacidade suficiente para as strings que armazenam.
Essa é uma das principais fontes de erro em programas feitos na linguagem C, e considerado um de seus principais defeitos de projeto.

A linguagem oferece strings constantes, que são representadas entre aspas duplas. Uma sequência de caracteres entre aspas duplas é colocada na memória pelo compilador da forma esperada pelas funções, com um caractere extra de código 0 após o último caractere pertencente à string.
Um vetor de char pode ser inicializado por uma string constante, tomando-se cuidado para que o tamanho do vetor seja suficiente para todos os seus caracteres mais o '\0'.
```c
  char a[8] = "12345"; // ok, o vetor a tem 8 char, a string tem 5 caracteres e ocupa 6 (5+1); os dois char restantes serão preenchidos com 0
  char b[]  = "12345"; // ok, o vetor b será alocado com 6 posições e será inicializado com a string e seu marcador de fim
  char c[5] = "12345"; // mais ou menos ok, o vetor de 5 posições será inicializado com os caracteres, mas não será uma string porque nao terá o 0 final
  char d[4] = "12345"; // não ok, e será detectado como um erro pelo compilador, inicialização de mais elementos do que cabe no vetor
```

### Exercícios

1. Faça uma função que recebe um vetor de char contendo uma string e retorna um inteiro com o número de caracteres da string. É o número de caracteres antes do '\0'.
1. Faça uma função que recebe dois vetores de char. O segundo vetor contém uma string qualquer. A função deve copiar essa string para o primeiro vetor.
1. Faça uma função que recebe um inteiro e dois vetores de char. O segundo vetor contém uma string qualquer. O inteiro é o tamanho do primeiro vetor. A função deve copiar a string do segundo vetor para o primeiro. Caso não haja espaço suficiente, deve ser copiado só o início da string que cabe no vetor. A string deve ser corretamente terminada com o caractere '\0', que deve obviamente ser colocado em uma posição válida do vetor destino. Posições no vetor destino após esse '\0' (se houver), não devem ser alteradas.
3. Faça uma função que recebe um inteiro e dois vetores de char. Os vetores contêm strings. O inteiro contém o tamanho do primeiro vetor (o tamanho do vetor, não da string). A função deve copiar a string do segundo vetor no final da string do primeiro, sem escrever além do final do vetor, com a correta finalização da string. A cópia deve ser truncada caso o vetor seja muito pequeno. Por exemplo, se o primeiro vetor tem tamanho 10 e contém a string "Oi, ", e o segundo vetor tem a string "mundo maravilhoso!", ao final da execução da função o primeiro vetor deverá conter a string "Oi, mundo".
1. Faça uma função que recebe um vetor de char contendo uma string e retorna o número de palavras nessa string. Uma palavra é definida como uma sequência ininterrupta de letras (maiúsculas ou minúsculas). Por exemplo, tem uma palavra em "teste", duas em "outro teste ", três em "9-a.b_c". Teste sua função.
2. Faça uma função que recebe um vetor de char contendo uma string e altera essa string para que as palavras que ela contém fiquem todas com a primeira letra maiúscula e as demais minúsculas. Por exemplo, se a função receber um vetor com "onDE foi PARAR", deve alterar a string para "Onde Foi Parar". Palavras devem ser consideradas como no exercício anterior.
3. Faça uma função que recebe um vetor de char contendo uma string e altera essa string para manter somente as palavras que ela contém, separadas por espaços e alteradas como no exemplo anterior. Por exemplo, se a função receber um vetor com "='onDE,.   foi-PARAR935", deve alterar a string para "Onde Foi Parar".

### Algumas funções padronizadas para tratamento de strings

As funções printf e scanf têm suporte a strings, com o formato `%s`.
No caso do printf, ele imprimirá todos os caracteres encontrados no vetor que recebe como argumento, até encontrar um caractere de código 0 (que não é impresso por não pertencer à string).
Pode-se limitar o número de caracteres impressos: `%20s` imprime pelo menos 20 caracteres da string, preenchendo com espaços se a string for menor. `%.20s` imprime no máximo 20 caracteres (pode ser usado para limitar o acesso ao tamanho do vetor, mesmo que não contenha uma string corretamente delimitada). `%20.20s` imprime sempre 20 caracteres.

No caso do scanf, ele pula caracteres espaço da entrada (e fim de linha, tabulação), e coloca no vetor recebido os caracteres não espaço da entrada, até encontrar um caractere espaço, e termina a string com o '\0'. O scanf não tem como fazer verificação do tamanho do vetor, então pode escrever fora do vetor caso tenha na entrada mais caracteres que a capacidade do vetor. Por causa desse problema, não é recomendado usar scanf com %s puro para ler strings.
Pode-se limitar o número de caracteres a serem lidos pelo scanf, com um formato como `%29s`; nesse caso, o scanf lerá no máximo 29 caracteres, e não causará estouro ao ler uma string para um vetor com tamanho para 30 char.

O scanf tem também o formato `%[`, que lê uma string composta pelos caracteres da entrada que são iguais aos caracteres dentro dos colchetes, até encontrar um que não pertença a esse conjunto. Por exemplo, `%[abc, ]` vai ler caracteres até encontrar um que não seja abc nem vírgula nem espaço, e colocá-los no vetor (seguidos do '\0'). O conjunto de caracteres pode ser invertido, se começar com `^`, `%[^\n]` é comum, para dizer qualquer caractere exceto `\n`, ou para ler até o fim da linha. Um formato como `%10[^\n]` limita o número máximo de caracteres lidos.

Uma outra função padrão para a leitura de strings é a função `fgets`. Essa função recebe 3 argumentos, o primeiro é o vetor onde colocar a string, o segundo é o tamanho desse vetor (ou quantos caracteres no máximo a função pode escrever), e o terceiro representa de onde se quer ler (a entrada padrão, que é de onde todas as funções de entrada que usamos até agora lêm é representada por `stdin`). Os caracteres da entrada são lidos e armazenados no vetor (sem pular espaços no início), até que tenham sido lidos n-1 caracteres ou até que chegue no final da linha na entrada; a função põe então um caractere de código 0 no final. Se chegar ao final da linha, o caractere de final de linha ('\n') será o último caractere colocado por fgets na string (antes do '\0').
Tem uma função mais simples também para imprimir strings, que é `puts`. Abaixo um exemplo de uso das duas.
```c
  char nome[20];
  puts("Qual seu nome? ");
  fgets(nome, 20, stdin);
  printf("Seu nome é %s.\n", nome);
```
Outro cuidado a tomar no caso de usar scanf é que, como se está passando um vetor como argumento, não se deve colocar o `&` antes do nome do vetor, diferente dos demais tipos de dados:
```c
  scanf("%19s", nome);
```

Incluindo `<string.h>`, se tem acesso a um conjunto de funções para o manuseio de strings.
Entre elas:
- `strlen`: recebe uma string (o vetor que contém a string) e retorna o tamanho dessa string (o número de caracteres que ela contém). Para isso, conta todos os caracteres antes do '\0'.
- `strnlen`: recebe um vetor e um inteiro, e retorna o tamanho da string nesse vetor, limitado ao valor do inteiro (o inteiro é o tamanho do vetor, e a função não acessa além desse tamanho).
- `strcpy`: recebe dois vetores, e copia para o primeiro a string que está no segundo. Equivale a uma atribuição de strings, já que não existe atribuição de vetores na linguagem. Copia caractere a caractere, até copiar o '\0'. É responsabilidade do programador garantir que o vetor que recebe a string tem o espaço necessário.
- `strncpy`: recebe dois vetores e um inteiro. Funciona como strcpy, mas o inteiro tem o tamanho do primeiro vetor, e limita o número máximo de caracteres copiados. Infelizmente, se o tamanho não for suficiente, a função não termina a string no vetor destino! Dá para garantir isso assim: `strncpy(a, b, 20); a[19] = '\0';`.
- `strcat`: recebe duas strings, e concatena a segunda string à primeira (acrescenta os caracteres da segunda string ao final da primeira. É responsabilidade do programador garantir que tem espaço no vetor.
- `strncat`: recebe duas strings e um inteiro e concatena a segunda string à primeiro. O inteiro diz o número máximo de caracteres a concatenar. É responsabilidade do programador garantir que tem espaço no primeiro vetor. Acho que seria mais útil se o 'n' fosse o tamanho do primeiro vetor...

### Mais exercícios

1. Faça uma função que recebe um vetor de char contendo uma string e retorna um int que diz quantas letras a string possui. Considere só as 52 letras, sem acentos.
1. Implemente uma função que recebe um vetor de char que contém uma string, e retorna um bool que diz se essa string é ou não um palíndromo (se a sequência de caracteres é a mesma, lida da esquerda para a direita ou da direita pra esquerda). ```"AS SATAS SA"``` é um palíndromo, ```"OS SOTOS SA"``` não é. Faça um programa para testar sua função.
2. Faça uma função que copia uma string para um vetor, copiando somente as letras, e transformando minúsculas em maiúsculas. Usando essa função, o resultado da cópia de "Socorram-me, subi no onibus em Marrocos" deve ser um palíndromo.
1. Faça uma função que compara duas strings. A função deve receber duas strings e retornar um int, que deve ser 0 se as strings são iguais, um número negativo se a primeira string vem antes da segunda em um dicionário e positivo caso contrário. Uma forma simples de calcular é subtraindo o primeiro caractere diferente das duas strings (sem esquecer de parar no primeiro `'\0'`). A biblioteca padrão tem uma função para fazer isso, chamada `strcmp`, e é a forma de se comparar strings.
1. Faça uma função recebe um vetor de char, imprime a string que está nesse vetor, pede para o usuário digitar uma string com "sim" ou "não", e retorna `true` se for digitado "sim" ou `false` se for digitado "nao" ou "não". Se for digitado outro texto, volta a pedir ao usuário para digitar "sim" ou "não", até que o usuário faça o que é pedido. Use a função acima para verificar a string digitada.

### Mais exercícios ainda

1. Faça uma função que recebe um vetor com uma string e inverte os caracteres dessa string. Por exemplo, se receber "teste", deve alterar para "etset".
   Com essa função, dá para implementar a função de detecção de palíndromo assim (o fato de ser possível não quer dizer que seja recomendável, é uma forma desnecessariamente cara de detectar palíndromo):
   ```c
   bool palindromo(char s[])
   {
     char cp[strlen(s)+1];
     strcpy(cp, s);
     inverte(cp);
     return strcmp(cp, s) == 0;
   }
   ```
2. Faça uma função que recebe um vetor com uma string e um char, e retorna um int que diz em que posição da string está a primeira ocorrência do char, ou -1, caso a string não contenha o char. 
   Com essa função, seria possível implementar a função que diz se um char é uma vogal assim:
   ```c
   bool vogal(char c)
   {
     return achachar("aeiou", minusculiza1(c)) != -1;
   }
   ```
3. Faça uma função que recebe dois vetores com strings, e retorna um int que diz a posição no primeiro vetor onde está a primeira ocorrência de algum dos caracteres da segunda string, ou -1 caso a primeira string não contenha nenhum caractere da segunda.
   Por exemplo, chamando essa função com "teste 82.5" e "0123456789", retorna 6, a posição do primeiro dígito da primeira string.
4. Faça uma função que recebe um vetor com uma string e retorna um bool que diz se a string pode ser uma senha. Uma senha deve ter no mínimo 8 caracteres, pelo menos uma minúscula, uma maiúscula, um dígito e um caractere que não é nem letra nem dígito.
5. Faça uma função que recebe um inteiro e um vetor de char. O inteiro diz o tamanho do vetor. A função deve ler uma linha da entrada (ler caracteres com getchar até o `\n`) e colocar esses caracteres no vetor como uma string. A string deve ser corretamente terminada com '\0', não deve conter o '\n', não deve extrapolar a capacidade do vetor, deve descartar os caracteres que não cabem, caso a linha seja muito grande. Deve suportar uma linha vazia (se o primeiro caractere for '\n', deve retornar uma string vazia válida, com '\0' no início do vetor).
6. Faça uma função para ler uma nova senha do usuário. A função recebe o tamanho de um vetor e um vetor de char. O vetor contém uma string com a senha antiga do usuário. A função deve ler a senha 2 vezes, e só aceitar se as duas forem iguais, se for uma senha válida e se for diferente da senha antiga. Se a primeira senha digitada for vazia, a função deve retornar sem pedir a segunda digitação. Caso a primeira não seja válida, deve pedir novamente até que seja. Caso a segunda não seja igual à primeira, deve pedir novamente a primeira. A função deve retornar um `bool` que é `true` se foi digitada uma nova senha (e a nova senha deve ser colocada no vetor) ou `false` se a senha digitada for vazia (e nesse caso o vetor recebido não deve ser alterado).


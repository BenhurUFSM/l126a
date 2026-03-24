## Introdução à linguagem de programação C

Uma linguagem de programação de alto nível permite escrever programas de forma mais abstrata e simples que em linguagem de máquina ou de montagem.
Para que possa ser executado pelo computador, esse programa deve ser traduzido para um programa equivalente em linguagem de máquina.
O programa que realiza essa tradução se chama "compilador".

Para que a tradução não seja complicada demais, uma linguagem de programação geralmente é bastante restritiva sobre como o programa deve ser escrito e formatado.
A linguagem que vamos usar, chamada "C" não é exceção.

Um programa na linguagem C é dividido em subprogramas chamados **funções**.
Os comandos que representam ações a serem executadas pelo processador necessariamente devem estar em alguma função.
A execução de um programa C é entendida como a execução dos comandos de uma função.

Cada função de um programa é identificada por seu nome.
Um programa C pode ter quantas funções quiser, cada uma com um nome diferente.
Para que uma função seja executada, ela deve ser "chamada" por outra.
A chamada de uma função é a execução de um comando que pede que uma função seja executada, enquando a função chamadora aguarda, até que a função chamada encerre sua execução (se diz que a função chamada retorna), quando a função chamadora continua a executar.

Uma das funções é especial, e deve ter o nome `main`. 
Essa é a função principal do programa, e é a única função que é chamada automaticamente.
Dá para dizer que a função `main` de um programa é chamada pelo sistema operacional quando se pede ao sistema que esse programa seja executado.

Uma função é constituída de 4 partes:
- **tipo** — vamos ver mais tarde para que serve, por enquanto basta sabermos que para a função `main` o tipo tem que ser `int`;
- **nome** — identifica a função; é uma sequência de caracteres, o primeiro obrigatoriamente uma letra, os demais podem ser letras, números ou "_"
- **argumentos**, entre parênteses (por enquanto não vamos usar argumentos, mas os parênteses são obrigatórios)
- **corpo**, entre chaves, é aqui que vão os comandos.

Um programa pode não ter nenhum comando. Portanto, o menor programa C possível é um texto com:
```c
int main(){}
```
que instrui o computador para não fazer nada. Não é exatamente um programa útil...

Útil ou não, para poder ser executado, o programa em C deve ser traduzido para código de máquina. O programa em código de máquina deve então ser colocado em um local apropriado da memória, e o processador deve ser instruído a executar a partir desse local.

Temos então 3 tarefas distintas a realizar para executar um novo programa em C:
1. produzir um texto com o programa em C. Isso é feito com o auxílio de um programa, chamado editor de textos. Na aula, usamos o editor de textos `nano`, executado com a seguinte linha de comando no linux:
    ```
      nano nome.c
    ```
    onde `nome` é um nome qualquer, que vai ser usado para identificar o programa. Não use espaços no nome. `nano` e `.c` devem estar em minúsculas.
    
    Para sair do nano, use o comando `ctrl-X` (segure a tecla `ctrl` e aperte a tecla `X`).
    O nano vai pedir para confirmar a gravação do arquivo e oferecer a possibilidade para usar um novo nome ao gravá-lo.
2. compilar esse texto e produzir um arquivo com o programa executável equivalente. Isso é feito por um programa chamado compilador. Em aula, usamos o programa `gcc`, executado com a seguinte linha de comando no linux:
    ```
      gcc nome.c -o nome
    ```
    onde `nome` é o mesmo nome de antes. Esse comando está instruindo o gcc a compilar o programa em C que está no arquivo `nome.c` (chamado programa fonte) e colocar o resultado da compilação no arquivo `nome` (chamado programa executável). Atenção, o que vai depois de `-o` é o nome de um arquivo que será destruído caso já exista.

    Durante a execução, o compilador pode emitir mensagens de erro, caso o arquivo não contenha um programa 100% correto de acordo com as regras da linguagem.
    Nesse caso, o programa deve ser alterado e compilado novamente.
3. carregar o programa executável em memória e executá-lo. Isso é feito pelo sistema operacional, com uma linha de comando como abaixo:
    ```
      ./nome
    ```

* * *

A linguagem C é uma linguagem bastante simples, e com poucos recursos disponíveis diretamente na linguagem.
Diretamente na linguagem, não existem nem comandos para realizar entrada ou saída de dados.
Essa simplicidade é compensada com uma coleção de bibliotecas, que contêm funções já desenvolvidas, prontas para serem usadas por novos programas.
Para informar o compilador que nosso programa vai usar alguma dessas funções externas, devemos colocar no início do programa linhas pedindo para incluir as bibliotecas correspondentes.
Para entrada e saída, a biblioteca de funções padrão se chama `stdio`. O comando para incluí-la é
   ```c
   #include <stdio.h>
   ```
Após essa inclusão, o programa tem à sua disposição várias funções para realizar entrada e saída de dados. Uma dessas funções chama-se `putchar`, que envia um valor (um `char`) para o dispositivo de saída corrente do programa (que geralmente é o terminal de vídeo).

Para causar a execução de uma função em C, temos o comando de chamada de função. Ele é constituído pelo nome da função seguido de parênteses contendo os parâmetros da função (se ela for parametrizada) seguido pelo caractere `;`.
A função `putchar` necessita de um parâmetro, que é o valor a enviar para a saída.

Juntando tudo isso, podemos fazer um programa que envia o valor `50` para a saída assim:
```c
   #include <stdio.h>

   int main()
   {
       putchar(50);
   }
```

Compilando e executando esse programa, ele irá imprimir `2`.

Ele imprime `2` e não `50` porque um terminal de vídeo como qualquer dispositivo de saída, ao receber um número, interpreta esse número como o código de um comando.
A maior parte dos códigos recebidos por um terminal de vídeo representa um comando para colocar na tela um caractere. O caractere escolhido depende do código. Na quase totalidade dos computadores atuais, essa codificação segue a tabela ASCII, na qual o código 50 corresponde ao caractere `2`.
Caso tenha curiosidade, pode ver esses códigos por exemplo na [wikipédia](https://pt.wikipedia.org/wiki/ASCII).

Dos 128 códigos definidos no padrão ASCII, 95 representam caracteres e os demais representam controles ao terminal. A maior parte dos códigos de controle já não são mais usados. Os mais comuns que são usados representam algumas teclas de controle de um teclado (del, bs, enter, tab, esc) e alguns comandos simples ao terminal (recuar uma posição, recuar para o início da linha, avançar para a linha seguinte). Comandos mais complexos ao terminal (como posicionar o cursor ou trocar a cor dos símbolos) são realizados por sequências do códigos, geralmente iniciadas pelo código ESC.

Para que não necessitemos lembrar dos códigos da tabela, a linguagem permite representar esses valores de outra forma, com o símbolo que se quer entre aspas simples. Por exemplo, `'2'` representa o mesmo valor que `50`. O programa acima é equivalente ao abaixo:
```c
   #include <stdio.h>

   int main()
   {
       putchar('2');
   }
```
Alguns caracteres não são representáveis diretamente dessa forma, notamente os caracteres de controle. Esses valores são representados por 2 caracteres entre as aspas simples, o primeiro deles sempre `\`:
```c
   \n   avanço de linha
   \b   recuo de uma posição
   \a   alarme
   \r   recuo ao início da linha
   \\   \
   \'   '
   \"   "
```
O programa acima pode ser alterado para imprimir o `2` em uma linha inteira:
```c
   #include <stdio.h>

   int main()
   {
       putchar('2');
       putchar('\n');
   }
```

* * *

<a id="func"></a>

Além de usar funções de biblioteca, predefinidas, como `putchar`, podemos definir nossas próprias funções, além da `main`.
Todas as funções têm o mesmo formato: `tipo nome (parâmetros) {corpo}`.
No caso da `main`, o tipo obrigatoriamente é `int`, o que quer dizer que a função calcula um valor inteiro.
O valor calculado por main diz ao sistema operacional se a execução do programa ocorreu sem problemas (valor 0) ou se houve algum erro na execução do programa (qualquer outro valor).

Se uma função é declarada como calculando um valor (tendo o tipo `int` por exemplo), essa função deve ter um comando que calcula algum valor, ou o compilador detecta um erro.
A função main é uma exceção, e caso ela não contenha esse cálculo o compilador deve gerar automaticamente o cálculo do valor 0 para informar o sistema que não houve erro.

Para dizer que uma função não calcula nada, usa-se o tipo `void`.
Então, se quisermos fazer uma função que não calcula nada e só imprime uma linha com `2`, e depois chamarmos essa função na main, podemos fazer assim:

```c
   #include <stdio.h>

   void linha2()
   {
       putchar('2');
       putchar('\n');
   }

   int main()
   {
       linha2();
   }
```

#### Exercício

Complete o programa abaixo, substituindo as partes com `...`, para que ele imprima o seu primeiro nome e último sobrenome.
Não pode alterar o que tá fora do `...`, e só pode usar `putchar`.
Deve ter um espaço separando o nome do sobrenome, e um final de linha após o sobrenome.
```c
   #include <stdio.h>

   void nome()
   {
       ...
   }

   void sobrenome()
   {
       ...
   }

   int main()
   {
       nome();
       sobrenome();
   }
```


Uma função pode receber parâmetros. Quando uma função que recebe parâmetros é chamada, o valor desses parâmetros é colocado dentro dos parênteses no comando de chamada da função, como fizemos nas chamadas a `putchar` acima.
Para criar uma função que recebe parâmetros, coloca-se dentro dos parênteses da função que está sendo criada um nome, que será usado dentro da função toda vez que quisermos referenciar o valor desse parâmetro. Deve-se preceder esse nome de um tipo, que por enquanto usaremos `int` para representar valores que são números inteiros.

Por exemplo, se quisermos uma função que recebe um número como parâmetro e imprime o caractere correspondente entre colchetes, ppodemos fazer assim:

```c
   #include <stdio.h>

   void colch(int c)
   {
       putchar('[');
       putchar(c);
       putchar(']');
   }

   int main()
   {
       colch('X');
       colch('9');
   }
```

#### Exercício

Faça as seguintes alterações no programa que imprime teu nome:
- remova a parte do sobrenome — a função main só chama a função nome
- faça uma função que imprime `+---+` em uma linha
- faça uma função que recebe um número como argumento e imprime uma linha com o caractere codificado por esse número entre `|` e espaços
- altere a função que imprime o nome para usar essa última função para imprimir cada letra, em vez de usar putchar diretamente
- altere a função que imprime o nome para chamar a primeira função descrita, no início e no final do nome

Ao final dessas alterações, o programa deve imprimir como abaixo (para alguém que se chama Juca).
```
   +---+
   | J |
   | u |
   | c |
   | a |
   +---+
```


<a id="impnum"></a>

A função `putchar` envia um número ao terminal, que imprimirá o caractere que é codificado com esse número.
Por exemplo, se enviarmos o valor `50` será impresso o caractere `2`.

Gostaríamos de ter uma função que, quando enviássemos o valor `50`, ela imprima `50`, dois caracteres, representando o número recebido em decimal.

Vamos começar com um caso mais simples, uma função que recebe um valor entre `0` e `9`, que pode ser impresso em decimal só com um símbolo, e imprime o caractere correspondente. Em outras palavras, se a função receber `0` como parâmetro, deve chamar `putchar('0')`, se receber `1` deve chamar `putchar('1')`, se receber `5` deve chamar `putchar('5')` etc.

Na tabela ASCII, os caracteres que representam os dígitos têm códigos que estão em ordem: o código do `1` é um a mais que o código do `0`; o código do `7` é 7 a mais que o código do `0` etc.
Então, se tivermos o códivo do `0` e somarmos o valor 7, teremos o código do `7`, e essa lógica funciona para qualquer dos 10 dígitos (inclusive `0`).
Em outras palavras, para imprimir o dígito que corresponde ao valor `x` devemos enviar ao terminal um código que é `x` além do código do dígito `0`.

Em C, podemos realizar a soma de dois valores com uma expressão aritmética de soma.
O argumento em uma chamada de função em C pode conter um valor constante para ser passado para o parâmetro da função como usamos até agora, ou pode ter uma expressão aritmética para realizar esse cálculo. Por exemplo, `putchar(22 + 37)` irá passar o valor 59 para `putchar`.
A chamada `putchar('0' + 5)` irá passar para `putchar` o valor que é 5 a mais que o valor do código do caractere `0`, ou seja, é o código do caractere `5`.

Juntando isso tudo, podemos fazer uma função (chamada por exemplo `impnum`), que recebe como parâmetro um valor entre 0 e 9 e imprime o dígito decimal correspondente a esse valor. Em outras palavras, imprime o valor que queremos:
```c
   void impnum(int num)
   {
      putchar('0' + num);
   }
```

Podemos testar essa função com o seguinte programa, por exemplo:
```c
   #include <stdio.h>

   void impnum(int num)
   {
      putchar('0' + num);
   }

   void pulalinha()
   {
      putchar('\n');
   }

   int main()
   {
      impnum(0);
      pulalinha();
      impnum(9);
      pulalinha();
      impnum(3 + 2);
      pulalinha();
   }
```
Além da soma, temos mais operadores aritméticos:
| operação | operador |
| :---     | --- |
| soma | + |
| subtração | - |
| multiplicação | * |
| divisão | / |
| resto da divisão | % |

E podemos misturá-los em uma expressão aritmética — eles seguem as regras normais de precedência, e se pode usar parênteses para forçar essa precedência.
Podemos usar nosso computador como uma calculadora (um tanto restrita) alterando a função main:
```c
   int main()
   {
      impnum(3 * 3);
      pulalinha();
      impnum(2 + 18 / 9);
      pulalinha();
      impnum((7 + 5) / 2);
   }
```
Uma restrição importante é que nossa função `impnum` só tem uma chamada a `putchar`, o que quer dizer que ela só imprime um caractere. O que acontecerá se for feita uma chamada `impnum(12)`?

Precisamos aprimorar nossa função para que imprima números de dois dígitos. Como já sabemos imprimir números de um dígito, uma forma de atacar o problema é extrair os dígitos no número a imprimir e imprimir esses dígitos separados.
Para isso, usamos expressões aritméticas. Para calcular o valor do dígito das dezenas de um número de 2 dígitos, podemos dividir esse número por 10, e para as unidades, pegar o resto dessa divisão. Por exemplo, dividindo 12 por 10 tem-se quociente 1 e resto 2. Dividindo 58 por 10, temos 5 e resto 8 etc.

Vamos chamar nossa nova função de impnum2, e para manter a mesma lógica, renomear a função anterior para impnum1:
```c
   void impnum1(int num)
   {
      putchar('0' + num);
   }

   void impnum2(int num)
   {
      impnum1(num / 10);
      impnum1(num % 10);
   }
```
O nome de um parâmetro só é conhecido pela função que usa esse parâmetro, não há confusão quando duas funções usam o mesmo nome para seus parâmetros — apesar de terem o mesmo nome, são entidades diferentes e poder representar valores diferentes. O parâmetro de uma função só existe (só tem valor associado) enquanto essa função estiver sendo executada.

Agora podemos imprimir números entre 0 e 99. Faça um programa para testar.

Poderíamos implementar impnum2 sem a ajuda de impnum1, usando putchar diretamente:
```c
   void impnum2(int num)
   {
      putchar('0' + num / 10);
      putchar('0' + num % 10);
   }
```

E se tivermos números maiores que 99?
Precisamos extrair a centena. Fácil, `num/100`. Mas a extração da dezena tem que ser alterada para ficar limitada a 9: `num / 10 % 10`.

Para números de 4 dígitos, o milhar é `num/1000` e a centena tem que ser ajustada com `%10`. De forma geral, imprimir um dígito é:
```c
   putchar('0' + num / X % 10);
```
em que X é 1 para o dígito das unidades, 10 para o das dezenas, 100 para centena, 1000 para milhar etc.

Uma outra forma de pensar é tentando reutilizar as funções que já temos: se já tivermos uma função que imprime números de 1 dígito, simplifica a implementação de uma para imprimir números de 2 dígitos? 
Parece que sim:
```c
   void impnum1(int num)
   {
      putchar('0' + num % 10);
   }

   void impnum2(int num)
   {
      impnum1(num / 10);
      impnum1(num);
   }
```
E com 3? Mesma ideia:
```c
   void impnum3(int num)
   {
      impnum2(num / 10);
      impnum1(num);
   }
```
E assim por diante:
```c
   void impnum7(int num)
   {
      impnum6(num / 10);
      impnum1(num);
   }
```
Todas essas funções são muito parecidas, deve ter alguma forma de fazer uma genérica, que imprime números com qualquer quantidade de dígitos.
Uma forma é supor que essa função já existe, e usá-la para sua própria implementação (um pouco como podemos implementar a função de 7 dígitos supondo que a de 6 já exista). O que as funções acima fazem é chamar uma função para imprimir `num/10`, que é o número sem o último dígito, e depois imprime o dígito que falta. Essa impressão do número com um dígito a menos só é necessária se o número a imprimir for maior que 9, senão só precisa da impressão do último dígito.

Em C, podemos usar o comando `if` para realizar a execução condicional de comandos. No nosso caso, só queremos imprimir `num/10` se `num` for maior que `9` (ou maior ou igual a 10):
```c
   void impnum(int num)
   {
      if (num >= 10) {
         imprime_um_numero(num / 10);
      }
      putchar('0' + num % 10);
   }
```
A função que imprime um número qualquer é a própria `impnum`, então:
```c
   void impnum(int num)
   {
      if (num >= 10) {
         impnum(num / 10);
      }
      putchar('0' + num % 10);
   }
```
Se a função acima for chamada com o valor 3, a execução será:
```
   num vale 3
   num não é maior ou igual a 10, não executa o comando seguinte
   chama putchar para imprimir '0'+3%10  -->  '3'
```
Se ela for chamada com o valor 37, a execução será:
```
   num vale 37
   num é maior ou igual a 10, não pula o comando seguinte
   chama impnum com 37/10
      nesse ponto, é criada uma nova instância de impnum, a execução corrente fica suspensa
      num vale 3
      num não é maior ou igual a 10, não executa o comando seguinte
      chama putchar para imprimir '0'+3%10  -->  '3'
      nesse ponto, termina a segunda execução de impnum, a execução continua onde tinha ficado suspensa
   chama putchar para imprimir '0'+37%10  -->  '7'
```
Se ela for chamada com o valor 482, a execução será:
```
   num (da primeira instância) vale 482
   num é maior ou igual a 10, não pula o comando seguinte
   chama impnum com 482/10
      nesse ponto, é criada uma nova instância de impnum, a execução corrente fica suspensa
      num (da segunda instância) vale 48
      num é maior ou igual a 10, não pula o comando seguinte
      chama impnum com 48/10
         nesse ponto, é criada uma nova instância de impnum, a execução corrente fica suspensa
         num (da terceira instância) vale 4
         num não é maior ou igual a 10, não executa o comando seguinte
         chama putchar para imprimir '0'+4%10  -->  '4'
         nesse ponto, termina a terceira execução de impnum, a execução continua onde tinha ficado suspensa na segunda
      chama putchar para imprimir '0'+48%10  -->  '8'
      nesse ponto, termina a segunda execução de impnum, a execução continua onde tinha ficado suspensa na primeira
   chama putchar para imprimir '0'+482%10  -->  '2'
```

Exercício

Teste a função impnum acima, fazende um programa que imprime diversos valores. Imprima valores calculados por expressões.

Faça uma função impbin como a impnum acima, para imprimir números em binário. Em binário, os dígitos representam potências de 2, em decimal representam potências de 10 (por isso tem tantos números 10 em impnum). Teste sua função.

* * *

<a id="loop"></a>

Outra forma de imprimir números é implementando a repetição de comandos.
Para isso, necessitamos primeiramente ter comandos que sejam repetidor, uma sequência de comandos iguais que fazem o que queremos.

Para imprimir números, devemos imprimir os caracteres que correspondem a cada dígito. Para cada caractere a imprimir, devemos extrair o dígito correspondente e calcular o código do caractere correspondente.
Para extrair o valor de um dígito decimal de um número, podemos usar a seguinte expressão:
```c
   num / potência_de_10 % 10
```
onde `potência_de_10` é uma potência de 10 que varia conforme o dígito a extrair, 1 para a unidade, 10 para a dezena, 100 para a centena etc.

Tendo o valor do dígito, podemos calcular o código do caractere que representa esse dígito somando `'0'`, que é o código do dígito 0.
Por exemplo, para imprimir o dígito da centena do valor em `num`, podemos usar:
```c
   putchar('0' + num / 100 % 10);
```
Podemos imprimir um número de 4 dígitos com:
```c
   putchar('0' + num / 1000 % 10);
   putchar('0' + num / 100 % 10);
   putchar('0' + num / 10 % 10);
   putchar('0' + num / 1 % 10);
```

Uma *variável* em C é uma região de memória que possui um valor (é a abstração em C para a memória do computador). Uma variável possui um nome que a identifica. Usa-se esse nome toda vez que se quer acessar o valor dessa variável (corresponde à operação de leitura da memória) ou alterar esse valor (corresponde à operação de escrita na memória).
Para se poder usar uma variável, antes ela deve ser *declarada*, com um comando que possui o tipo dos valores que a variável irá conter e o seu nome. Por exemplo, o comando abaixo declara a variável `xis`, que conterá valores inteiros:
```c
   int xis;
```
A declaração de uma variável pode opcionalmente conter a sua *inicialização*, um valor inicial que é colocado na posição de memória que corresponde à variável, assim:
```c
   int xis = 125;
```
Se a variável não for inicializada, o valor que ela conterá será o valor que porventura estiver na posição de memória escolhida pelo compilador na hora que esse comando for executado.

Depois de declarada, podemos usar o valor de uma variável usando seu nome em uma expressão (da mesma forma que fizemos com os parâmetros de funções — na verdade, os parâmetros são um tipo especial de variável). Por exemplo, o comando abaixo irá imprimir o quadrado do valor da variável `xis`:
```c
   impnum(xis * xis);
```
A alteração do valor de uma variável se faz com o comando de *atribuição*, que é representado pelo sinal `=`, com o nome da variável que terá seu valor alterado à esquerda e uma expressão que calcula o valor a ser colocado nessa variável à direita. Por exemplo, o comando abaixo coloca o valor 17 na variável `xis`:
```c
   xis = 17;
```
O comando abaixo dobra o valor da variável `xis` (irá colocar 34 em `xis`, se for executado logo após o anterior);
```c
   xis = 2 * xis;
```
O comando abaixo não altera o valor de `xis`, só calcula o dobro do seu valor mas não faz nada com o resultado:
```@
   xis * 2;
```

Podemos usar uma variável para conter a potência de 10 usada para imprimir nosso número, e comandos de atribuição para alterar o valor da variável para conter a potência de 10 necessária para cada dígito:
```c
   int pot = 1000;
   putchar('0' + num / pot % 10);
   pot = pot / 10;
   putchar('0' + num / pot % 10);
   pot = pot / 10;
   putchar('0' + num / pot % 10);
   pot = pot / 10;
   putchar('0' + num / pot % 10);
```
Agora, temos um grupo de comandos idênticos que se repetem.
Podemos, em vez de ter várias cópias desses comandos no nosso programa, usar um comando que cause a repetição de sua execução.
Um dos comandos de repetição oferecidos pela linguagem C é o comando `while` (que significa "enquanto"). Ele tem a seguinte forma:
```c
   while (expressão) {
      comandos
   }
```
onde *`expressão`* é uma expressão lógica, que produz um valor que pode ser verdadeiro ou falso, e *`comandos`* é uma sequência de comandos da linguagem.
A forma de execução do comando *while* é:
1. o valor da expressão é calculado
2. se o valor calculado for "falso", todo o comando while termina, e a execução continua no comando seguinte (após o "}")
3. se o valor for "verdadeiro", a sequência de comandos no corpo do *while* é executada, e quando a execução desses comandos terminar, continua no passo 1.

Comandos de repetição implementam o que se chama de laços (ou "*loops*" em inglês).

Os *operadores de comparação* são exemplos de operadores que produzem valores lógicos (verdadeiro ou falso). São eles:
- `>` — maior que — produz o valor verdadeiro se o valor numérico à esquerda for maior que o da direita e falso caso contrário
- `<` — menor que — produz verdadeiro se o da esquerda for menor que o da direita
- `>=` — maior ou igual — verdadeiro se o da esquerda for maior ou igual ao da direita
- `<=` — menor ou igual
- `==` — igual
- `!=` — diferente

Podemos usar esses operadores na expressão do *while*. Como é a mesma expressão que é testada a cada vez, para que o resultado de uma execução da expressão possa ser diferente de outra, deve testar algum valor que é alterado pelos comandos no corpo do *while*.

No nosso caso, queremos executar os dois comandos para os valores de `pot` que sejam maiores ou iguais a 1:
```c
   int pot = 1000;
   while (pot >= 1) {
     putchar('0' + num / pot % 10);
     pot = pot / 10;
   }
```
A execução desse trecho de programa será:
1. encontra um local livre na memória, reserva ele, coloca o valor 1000 nele;
2. testa se o valor nesse local é maior ou igual a 1 (na primeira execução, `pot` vale 1000, que é maior ou igual a 1)
3. se não for, terminou a execução do trecho
4. se for,
    1. calcula e imprime o dígito de `num` que corresponde ao valor de `pot` (na primeira execução, o dígito dos milhares, já que pot vale 1000)
    2. calcula o valor de `pot/10`, e coloca o valor calculado no local de `pot` (na primeira execução, coloca o valor 100 em `pot`)
    3. continua no passo 2.

Juntando isso tudo, nossa função `impnum` fica:
```c
   void impnum(int num)
   {
      int pot = 1000;
      while (pot >= 1) {
         putchar('0' + num / pot % 10);
         pot = pot / 10;
      }
   }
```
E podemos usar ela para imprimir números de 4 dígitos. Ela tem alguns problemas:
- não dá para imprimir números com mais de 4 dígitos
- se o número a imprimir tem menos de 4 dígitos, vai ser impresso com zeros à esquerda.

Os dois problemas podem ser corrigidos alterando o valor 1000 que inicializa `pot`, aumentando o número de zeros para aumentar o número de dígitos ou diminuindo para ter menos dígitos.

Podemos automatizar o número de dígitos se calcularmos a potência de 10 que deve ser colocada, de acordo com o número a imprimir:
- se o número for menor que 10, `pot` deve ser 1
- se o número for entre 10 e 99, `pot` deve ser 10
- se o número for entre 100 e 999, `pot` deve ser 100 etc

se começarmos com `pot` em 1 e aumentarmos o número de zeros no final até que `pot` seja maior que o número a imprimir, teremos `pot` com um zero a mais.
```c
   int pot = 1;
   while (pot <= num) {
      pot = pot * 10;
   }
```
O menor valor que queremos para pot é 10 (um zero a mais que o valor que realmente queremos). Para economizar uma multiplicação por 10 e também evitar que pot possa sair desse laço com o valor 1, inicializamos pot em 10 em vez de 1.

Se invertermos a ordem dos comandos controlados pelo while, primeiro tirando um zero de pot e depois imprimindo o dígito correspondente, teremos a impressão que queríamos (após alterar o teste do while para parar em 10 e não mais em 1):
```c
   void impnum(int num)
   {
      int pot = 10;
      while (pot <= num) {
         pot = pot * 10;
      }
      while (pot >= 10) {
         pot = pot / 10;
         putchar('0' + num / pot % 10);
      }
   }

```
Agora sim, temos uma função que imprime qualquer número inteiro positivo.
Podemos fazer uma função main que imprime os números de 0 a 100:
```c
int main()
{
   int n = 0;
   while (n <= 100) {
      inpnum(n);
      putchar('\n');
      n = n + 1;
   }
}
```

### Exercícios

1. Faça uma função que recebe um número como parâmetro e imprime uma linha contendo esse número de asteriscos. Por exemplo, se a função for chamada com o valor 5 deve imprimir uma linha com:
```
   *****
```
2. O programa abaixo usa a função do exercício acima para imprimir um triângulo de asteriscos:
```c
   int main()
   {
      int n = 0;
      while (n < 5) {
         linha(n);
      }
   }
```
   Altere esse programa para imprimir esse triângulo de cabeça para baixo.
3. Altere novamente o programa do exercício anterior transformando a função `main` em uma função que recebe um argumento que é o número de asteriscos da maior linha do triângulo, e imprime o triângulo correspondente. Por exemplo, se ela receber 3 como argumento deve desenhar
```
   *
   **
   ***
```
4. Faça uma função como a anterior, para desenhar o triângulo invertido. Se receber 4 como argumento, deve desenhar:
```
   ****
   ***
   **
   *
```
5. Bla:
```
   ****
    ***
     **
      *
```
   Para isso, faça outra função que recebe um número como argumento e desenha tantos espaços.
6. Bla bla:
```
      *
     **
    ***
   ****
```

Em todos os desenhos de triângulos, a maior linha deve só conter asteriscos.

* * *

A função `puts`, também disponibilizada pela inclusão de `stdio.h` serve para imprimir uma sequência de caracteres (chamada *string*).
Ela recebe como argumento os caracteres a imprimir, entre *aspas duplas* (**`"`**). Depois de imprimir os caracteres, ela imprime um final de linha (`'\n'`). Por exemplo, o comando abaixo vai imprimir uma linha com "Olá mundo!":
```c
   puts("Olá mundo!");
```
Não podem ser aspas simples. Pode usar caracteres acentuados. Caracteres especiais são codificados com `\` como nas aspas simples.

#### Exercícios

Faça um programa com várias funções, cada uma para desenhar um dos desenhos abaixo, usando `puts` (talvez mais de uma chamada); faça uma `main` que chama elas:

Um gatinho:
```
=^..^=
```
Um ratinho:
```
<:3)~~~
```
Um gatão:
```
 /\_/\
( o.o )
 > ^ <
```
Um ratão:
```
 _   _
(_)_(_)
 (o o)
==\o/==
   "
```

<a id="for"></a>

* * *

A função `puts` imprime sequência de caracteres (uma string) seguida de um fim de linha (o caractere `\n`).
Uma outra função semelhante disponibilizada por `stdio.h` é `printf`.
O primeiro argumento dela é uma string, que é impressa na saída padrão.
Diferentemente de `puts`, não é impresso um `\n` a mais no final.
Outra diferença é que quando encontra um caractere `%`, esse caractere marca o início de um pedido de formatação (por isso o `f` no final do nome da função). A função printf realiza a formatação de um valor e imprime esse valor formatado no lugar do pedido de formatação iniciado por `%`.
Há vários tipos de formatação possíveis, por enquanto vamos usar o `%d`, que é um pedido para formatar um valor inteiro como uma sequência de dígitos decimais.
O valor a formatar é o argumento seguinte de `printf`.

Por exemplo,
```c
   printf("%d", 50);
```
escreve `50` no terminal;
```c
   printf("O valor é %d.\n", 42);
```
escreve `O valor é 42.` e um final de linha no terminal;
```c
   printf("%d+%d=%d", 10, a, 10+a);
```
escreve `10+`, seguido do valor de `a`, seguido de `=`, seguido do valor de `a` acrescido de 10.

#### O comando de repetição `for`

Nos exemplos anteriores de repetição usando `while`, era bem comum controlar a repetição com uma variável, da seguinte forma: a variável era inicializada com um valor inicial antes do while, o teste do while testava essa variável e no final do while havia um comando para alterar o valor dessa variável.

Essa forma de se estruturar uma repetição é tão comum que a linguagem possui um comando que serve para evidenciá-la. É o comando `for`, que tem a seguinte forma:
```
   for (inicialização; teste; incremento) {
     comandos
   }
```
onde:
- *inicialização* é um comando que inicializa (e geralmente declara) uma variável (chamada *variável de controle*)
- *teste* é uma expressão lógica, que geralmente faz alguma comparação com o valor da variável de controle
- *incremento* é um comando que altera o valor da variável de controle
- *comandos* são comandos da linguagem, cuja execução é controlada pelo `for`

Por exemplo,
```c
   for (int i = 0; i < 10; i = i + 1) {
      printf("%d\n", i);
   }
```
O funcionamento do `for` é:
1. o comando de inicialização é executado
2. o teste é calculado
3. se o valor do teste for falso, o comando `for` termina e a execução continua no comando seguinte ao `for` (após `}`)
4. executa os comandos
5. executa o incremento
6. continua no passo 2

O comando `for` do exemplo acima irá imprimir 10 números, entre 0 e 9.

#### Exercícios

Use o comando `for` para:
1. imprimir os números de 1 a 10, um por linha
1. imprimir os números de 1 a 10, todos na mesma linha, separados por espaço, com um final de linha no final
1. imprimir os números de 1 a 10, todos na mesma linha, separados por vírgula, com um final de linha no final (só pode ter vírgula entre dois números, não pode ter antes do primeiro nem após o último)
1. imprimir os números pares entre 1 e 100
1. fazer uma função que recebe um número como argumento e imprime os números ímpares menores que o número e maiores que a metade do número (por exemplo, se receber 10, deve imprimir `7 9`)


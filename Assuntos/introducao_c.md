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

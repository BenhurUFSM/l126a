## Expressões e operadores

Uma expressão em C permite produzir valores, com o uso de operadores.
Uma expressão pode produzir um valor à partir de um literal, de uma variável, de uma chamada de função ou de uma operação sobre valores produzidor por sub-expressões.

- literal inteiro:
  - sequência de dígitos iniciados por `1` a `9`: corresponde ao valor inteiro codificado em decimal. Tem o tipo `int` ou `long` ou `long long`, o menor que puder representar o valor. Se for seguido por `u` ou `U`, é `unsigned`. Se for seguido por `l` ou `L` é pelo menos `long` e se for seguido por `ll` ou `LL` é `long long`.
  - sequência de dígitos octais iniciados por `0`: corresponde ao valor inteiro codificado em octal.
  - sequência de dígitos binários iniciados por `0b` ou `0B`: corresponde ao valor inteiro codificado em binário.
  - sequência de dígitos hexadecimais iniciados por `0x` ou `0X`: correponde ao valor inteiro codificado em hexadecimal.
  - caractere ASCII entre aspas simples (`'X'`): corresponde ao valor do código do caractere com tipo `int`. Alguns caracteres são codificados precedidos por `\`, como `'\n'` para o fim de linha.
- literal de ponto flutuante, tem o tipo `double`, a não ser que seja seguido por `f` ou `F` para `float` ou `l` ou `L` para `long double`. Pode ser:
  - sequência de dígitos contendo um caractere `.`: valor codificado em decimal
  - sequência de dígitos contendo ou não o caractere `.`, seguida por `e` ou `E` e uma sequência de dígitos precedida ou não por `+` ou `-`. Valor codificado em decimal, com a vírgula deslocada tantas casas quanto indicado pelo valor após o `e`. Exemplo: `53e-1` codifica o mesmo que `5.3`.
- nome de variável: tem o valor e o tipo da variável
- chamada de função: tem o valor e o tipo retornado pela função

### Operadores

Os operadores em C podem ser unários (tem um só operando), binários (têm dois operandos) ou ternário (tem 3 operandos). Os operadores unários geralmente precedem seus operandos (mas existem dois operadores que antecedem o operando); os operadores binários são escritos entre seus operandos (como em `a + b`, em que o operador `+` opera sobre os operandos `a` e `b`). A maioria dos operadores opera sobre operandos e produz resultados de mesmo tipo.
Se for o caso de uma operação entre tipos diferentes, o valor do menor tipo é convertido para o maior, ou o valor inteiro é convertido para ponto flutuante antes da operação ser fiita. Essas conversões são decididas para cada operação, na ordem em que são executadas.
Os operandos aritméticos não operam sobre valores menores que `int`.
- unários aritméticos — o operando é um valor de tipo inteiro ou ponto flutuante, o resultado é do mesmo tipo:
  - `+` — não faz nada
  - `-` — inverte o sinal do operando. Se o operando for `unsigned`, o resultado é o valor `unsigned` que tem a mesma representação binária que o valor com o sinal negativo (-1u vai produzir o maior valor `unsigned` possível).
- binários aritméticos — os operandos são valores de mesmo tipo, inteiro ou ponto flutuante, o resultado é do mesmo tipo:
  - `+` — soma
  - `-` — subtração
  - `*` — multiplicação
  - `/` — divisão
  - `%` — resto da divisão - só para operandos inteiros
- binários de comparação — os operandos são valores de mesmo tipo, inteiro ou ponto flutuante, o resultado é lógico (um inteiro com valor 0 (`false`) ou 1 (`true`)):
  - `>` — `true` se o primeiro operando for maior que o segundo
  - `<` — `true` se o primeiro operando for menor que o segundo
  - `>=` — `true` se o primeiro operando for maior ou igual ao segundo
  - `<=` — `true` se o primeiro operando for menor ou igual ao segundo
  - `==` — `true` se os dois operandos tiverem o mesmo valor
  - `!=` — `true` se os dois operandos tiverem valores diferentes
- unário lógico — o operando é tratado como lógico, o resultado é lógico
  - `!` — `true` se o operando for `false` ou zero
- binário lógico — os operandos são tratados como lógicos, o resultado é lógico.
   Esses operadores operam em "curto circuito": se o valor do operando esquerdo é suficiente para deduzir o valor da operação, o segundo operando não é calculado (isso pode fazer uma grande diferença se o segundo operando envolver uma chamada de função)
  - `&&` — `true` se ambos os operandos forem `true` ou diferentes de zero
  - `||` — `true` se algum operando for `true` ou diferente de zero
- binários bit a bit - os operandos e resultado são inteiros. Os operandos operam em cada bit independentemente.
  - `&` — "e" bit a bit
  - `|` — "ou" bit a bit
  - `^` — "ou exclusivo" bit a bit
  - `>>` — rotação à direita - o resultado corresponde à deslocar os bits do operando da esquerda o número de bits correspondente ao operando da direita
  - `<<` — rotação à esquerda
- unário bit a bit
  - `~` — inverte todos os bits
- unários de incremento
  - `++` — incrementa (soma 1) o operando (que deve ser uma variável); o valor da operação é o valor da variável antes do incremento (se a variável estiver antes do operador) ou depois do incremento (se a variável estiver depois do operador)
  - `--` — decrementa (subtrai 1) o operando (que deve ser uma variável); o valor da operação é o valor da variável antes do decremento (se a variável estiver antes do operador) ou depois do decremento (se a variável estiver depois do operador)
- binários de atribuição — o operando esquerdo obrigatoriamente é uma variável, que receberá uma atribuição. O valor da expressão é o novo da variável. O valor do operando direito é convertido ao tipo da variável antes da operação ser realizada.
  - `=` — atribuição — a variável recebe o valor do segundo operando
  - `+=` — atribuição com soma — o valor do segundo operando é somado à variável
  - `-=` — atribuição com subtração — o valor do segundo operando é subtraído da variável
  - `*=` — atribuição com multiplicação — o valor do segundo operando é multiplicado à variável
  - `/=` — atribuição com divisão — o valor do segundo operando é dividido da variável
  - `%=` — atribuição com resto — o valor do resto da divisão do valor da variável pelo valor do segundo operando é atribuido à variável
  - `&=`, `|=`, `^=`, `>>=`, `<<=`
- binário de avaliação sequencial
  - `,` — avalia o operando da esquerda, joga fora o valor, avalia o operando da direita e esse é o valor da expressão. A vírgula que separa os argumentos em uma chamada de função não é este operador.
- ternário de seleção
  - `?:` — avalia o primeiro operando (o que está antes do `?`) se o valor for `true` ou diferente de zero, avalia o segundo operando (o que está entre o `?` e o `:`) e ignora o terceiro (que está após o `:`); senão, ignora o segundo operando e avalia o terceiro. O valor da expressão é o do segundo ou terceiro operando.
- unário de mudança de tipo (*cast*)
  - `(tipo)` — converte o valor do operando (que está após o operador) para o tipo entre parênteses, e esse é o valor da expressão
- unário de tamanho de dados
  - `sizeof` — o valor da expressão é o número de bytes ocupados pelo operando, que pode ser uma expressão ou um tipo entre parênteses
- unário de referência
  - `&` — obtém uma referência para o operando à direita, que deve ser uma variável
  - `*` — obtém o valor referenciado pelo operador à direita, que deve ser uma referência
- binários de acesso a variáveis compostas
  - `[]` — indexação de um vetor
  - `.` — acesso a campo de um registro
  - `->` — acesso a campo de um registro por referência
- chamada de função
  - `()` — à esquerda tem o nome de uma função ou uma referência a uma função, dentro dos parênteses uma lista de expressões separadas por vírgulas, que são os argumentos da função. Chama a função, o valor da expressão é o valor de retorno da função e o tipo é o tipo de retorno da função.

  ### Ordem de avaliação de uma expressão C

  A expressão é analisada da esquerda para a direita, e se verifica um operador com o operador seguinte. Se o operador da esquerda deve ser operado antes do da direita, essa operação é realizada, e substituída pelo valor e tipo que resultam da operação. Se o operador da direita deve ser operado antes, a análise continua entre o operador da direita e o operador seguinte.

  A ordem de operação entre dois operadores é decidida inicialmente pela precedência entre os operadores: se um deles tem precedência maior que o outro, é operado antes.
  Se os dois operadores têm a mesma precedência, a ordem é decidida pela associatividade.
  A tabela abaixo divide os operadores por nível de precedência, da maior para a menor. Em cada nível, tem a associatividade dos operadores desse nível.

  | operador | observações | associatividade |
  | :---: | :--- | :--- |
  | `[]` `()` `.` `->` `++` `--` | `++` e `--` após o operando | esquerda |
  | `sizeof` `&` `*` `+` `-` `~` `!` `++` `--` | unários; `++` e `--` antes do operando | direita |
  | `(tipo)` | unário | direita |
  | `*` `/` `%` | multiplicativo | esquerda |
  | `+` `-` | aditivo | esquerda |
  | `<<` `>>` | deslocamento de bit | esquerda |
  | `<` `>` `<=` `>=` | comparação | esquerda |
  | `==` `!=` | igualdade | esquerda |
  | `&` | **e** bit a bit | esquerda |
  | `^` | **ou exclusivo** bit a bit | esquerda |
  | `|` | **ou** bit a bit | esquerda |
  | `&&` | **e** lógico | esquerda |
  | `||` | **ou** lógico | esquerda |
  | `?:` | ternário de seleção | direita |
  | `=` `*=` `/=` `%=` `+=` `-=` `<<=` `>>=` `&=` `^=` `|=` | atribuição | direita |
  | `,` | avaliação sequencial | esquerda |

Por exemplo, se `a`, `b` e `c` são variáveis inteiras com valor 3, 4 e 5, a expressão `! a < b && c > b` será avaliada assim:
- entre `!` e `<`, a precedência é de `!`, o valor de `a` é tratado como lógico `V`, a expressão vira: `F < b && c > b`
- entre `<` e `&&` a precedência é de `<`, `F` é tratado como inteiro `0`, a expressão vira: `V && c > b`
- entre `&&` e `>` a precedência é de `>`, como não tem mais operadores à direita, vira: `V && V`
- não tem mais operador à direita de `&&`, vira: `V`, que é o resultado da expressão.

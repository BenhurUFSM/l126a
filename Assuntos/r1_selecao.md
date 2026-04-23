## Comandos de seleção

Os comandos de seleção permitem ao programa, durante sua execução, decidir:
- executar ou não determinado trecho de código (seleção simples);
- executar um ou outro trecho de código (seleção dupla);
- executar um entre vários trechos de código possíveis (seleção múltipla).

Existem dois comandos de seleção na linguagem C:
- o comando `if`, com o qual se pode implementar qualquer dos tipos de seleção;
- o comando `switch`, que permite implementar uma forma específica (mas bastante comum) de seleção múltipla.

### O comando de seleção `if`

O comando `if` decide sobre a execução de comandos que ele controla à partir do valor calculado por uma expressão lógica.
O comandos controlados pelo `if` são colocados em `blocos`, que podem seruma sentença simples ou preferencialmente um conjunto de sentenças delimitado por chaves (`{}`).
Pode ser usado para implementar:
- seleção simples
   ```c
   if (expressão)
     bloco
   ```
   Primeiramente, o valor da `expressão` é calculado, e se for verdadeiro, o `bloco` é executado; se for falso, o `bloco` é ignorado.
- seleção dupla
   ```c
   if (expressão)
     bloco1
   else
     bloco2
   ```
   Primeiro é calculado o valor da `expressão`. Se for verdadeiro, o `bloco1` é executado e o `bloco2` é ignorado; se for falso, o `bloco1` é ignorado e o `bloco2` é executado.
- seleção múltipla
   ```c
   if (expressão1) {
       bloco1
   } else if (expressão2) {
       bloco2
   } else if (expressão3) {
       bloco3
   //...
   } else {
       blocon
   }
   ```
   Primeiro é calculado o valor da `expressão1`. Se for verdadeiro, o `bloco1` é executado e o restante é ignorado. Se o valor da `expressão1` for falso, é calculado o valor da `expressão2`. Se o valor da `expressão2` for verdadeiro, o `bloco2` é executado e o restante é ignorado. Etc. Se nenhuma das expressões for verdadeira, o `blocon` é executado.

### O comando de seleção `switch`

Em alguns casos, o bloco a ser executado depende de um único valor.
Implementando essa seleção com `if`, todas as expressões seriam do tipo `if (variável == valor_i)`.
Para esses casos, criou-se o comando `switch`, que tem o seguinte formato:
```c
   switch (expressão) {
     case valor_1:
       comandos_1
       break:
     case valor_2:
       comandos_2
       break;
     //...
     default:
       comandos_n
   }
```
Primeiro, é calculado o valor da expressão (um valor inteiro).
Se houver um `case` com o valor correspondente, os comandos logo após o `case` são executados. Caso não haja valor correspondente ao valor da expressão, o controle é desviado para o primeiro comando após o `default:`.
A cláusula `default` é opcional e se não existir o comando `switch` não executa nada quando o valor da expressão não corresponder a nenhum dos valores dos `case`.
Para se executar o mesmo comando para mais de um valor, coloca-se cláusulas `case` com esses valores, uma após a outra, sem comandos entre elas.

Exemplo:
```c
   switch (opcao) {
     case 1:
       exec_opc1();
       break;
     case 2:
       exec_opc2();
       break;
     case 3:
     case 4:
       exec_opc3ou4(opcao);
       break;
     default:
       printf("opção inválida\n");
   }
```

# O comando de seleção `if`

O comando `if` permite selecionar se determinado trecho de código será ou não executado, conforme o valor de uma expressão.
Em sua forma mais simples:
```c
   if (expressão)
     bloco
```
Primeiramente, o valor da `expressão` é calculado, e se for verdadeiro, o `bloco` é executado; se for falso, o `bloco` é ignorado.
O `bloco` é ou uma sentença simples ou preferencialmente um conjunto de sentenças delimitado por chaves (`{}`).

O comando `if` pode ter uma cláusula `else` (que significa 'senão').
Nesse caso, ele controla dois blocos (geralmente entre chaves), e selecionla qual deles será executado (sempre um). O formato é:
```c
   if (expressão)
     bloco1
   else
     bloco2
```
Primeiro é calculado o valor da `expressão`. Se for verdadeiro, o `bloco1` é executado e o `bloco2` é ignorado; se for falso, o `bloco1` é ignorado e o `bloco2` é executado.

Exemplo:
```c
   if (a > b) {
       printf("%d é maior que %d\n", a, b);
   } else {
       printf("%d não é maior que %d", a, b);
   }
```

Pode-se agrupar comandos `if` para se implementar seleção múltipla, em que uma entre diversas opções é executada (de novo, exatamente uma).
Nesse caso, uma formatação comum é:
```c
   if (expressão1) {
       bloco1
   } else if (expressão2) {
       bloco2
   } else if (expressão3) {
       bloco3
   } else {
       blocon
   }
```
Primeiro é calculado o valor da `expressão1`. Se for verdadeiro, o `bloco1` é executado e o restante é ignorado. Se o valor da `expressão1` for falso, é calculado o valor da `expressão2`. Se o valor da `expressão2` for verdadeiro, o `bloco2` é executado e o restante é ignorado. Etc. Se nenhuma das expressões for verdadeira, o `blocon` é executado.

Exemplo:
```@
   if (imc < 17) {
      printf("muito abaixo");
   } else if (imc < 18.5) {
      printf("abaixo");
   } else if (imc < 25) {
      printf("normal");
   } else if (imc < 30) {
      printf("acima");
   } else if (imc < 35) {
      printf("obesidade I");
   } else if (imc < 40) {
      printf("obesidade II");
   } else {
      printf("obesidade III");
   }
```

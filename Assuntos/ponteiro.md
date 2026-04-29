## Ponteiros e referências

O valor de uma variável pode ser acessado diretamente, tanto para leitura como para escrita, usando o nome dessa variável. Por exemplo, se uma variável se chama `a` e outra `b`, podemos escrever em `b` o valor lido de `a` com uma expressão de atribuição: `a = b`.

Uma outra forma de se acessar uma variável é indiretamente, através de uma **referência** a essa variável.
Uma referência é composta pelo endereço da variável na memória (a posição da memória onde é colocado o valor da variável) e pelo seu tipo. Para se obter uma referência para uma variável, usa-se o operador unário `&`. Já usamos esse operador na função `scanf`, para informá-la onde deve colocar os valores obtidos à partir da conversão dos dados de entrada.
Se `a` é uma variável, `&a` produz uma referência ao local onde está o valor de `a`.

Para se acessar uma variável à partir de uma referência para ela, devemos ter acesso a essa referência. Uma variável que pode conter uma referência é chamada de **ponteiro**. Um ponteiro pode receber uma referência somente de um determinado tipo (um ponteiro só pode apontar para um tipo de dado). A declaração de uma variável do tipo ponteiro é composta pelo tipo de dados referenciado pelo ponteiro, pelo caractere `*` que designa ponteiro e pelo nome do ponteiro. Por exemplo, para declarar a variável `p` como sendo um ponteiro para uma variável do tipo inteiro, usa-se `int *p;`.

Para poder ser usado, um ponteiro deve receber uma referência. Isso é feito com uma operação de atribuição. Por exemplo, para fazer o ponteiro `p` apontar para a variável `a`, pode-se usar: `p = &a;`. Um ponteiro do tipo `int` só pode receber uma referência para uma variável do tipo `int`.

Se um ponteiro contém uma referência para uma variável, o valor dessa variável pode ser acessado, tanto para leitura quanto para escrita usando o **operador de dereferenciação** `*`. O comando `*p = 5;` coloca o valor 5 na variável referenciada pelo ponteiro `p`. O comando `b = *p;` coloca na variável `b` o valor da variável referenciada pelo ponteiro `p`.

Após a execução da sequência abaixo, o valor de `a` será 7 e o de `b` será 5.
```c
int *p;
int b = 67;
int a;

p = &b;

a = *p - 60;
*p = a - 2;
```

Um uso bem comum de referências e ponteiros é para permitir que uma função tenha acesso a variáveis de outra de forma controlada.
Normalmente, uma função não tem como acessar diretamente variáveis que foram declaradas em outra. A troca de valores entre funções se dá pela passagem de parâmetros (que só acontece no sentido da função chamadora para a função chamada) ou pelo valor de retorno da função chamada para a função chamadora, que é limitado a um único valor.
Caso uma função tenha que retornar mais de um valor, temos uma limitação.
Uma forma de resolver essa limitação é a função chamadora passar como argumento para a função chamada referências a variáveis, que poderão então ser alteradas indiretamente através de ponteiros, que são os argumentos da função chamada que receberáo essas referências.

Em aula, vimos um exemplo desse uso com uma função que calcula as raízes de uma equação quadrática.
Uma equação de segundo grau tem duas raízes, o que impede que se use o comando `return` para realizar o retorno da função, porque ele é limitado ao retorno de um só valor. Em vez disso, passa-se para a função duas referências, através das quais ela pode alterar duas variáveis, colocando as duas raízes calculadas.

Essa função tem ainda um outro problema, que é a possibilidade de que não exista raíz na equação fornecida. Para esse caso, implementamos o retorno de um valor lógico, que é `true` caso a equação possua raízes (e as raízes são colocadas nas variáveis referenciadas) ou `false` caso a equação não possua raízes reais (e as variáveis referenciadas não são alteradas). A implementação ficou como abaixo:
```c
// Faça uma função que calcula a raiz da equação
//   ax² + bx + c = 0
// usando o método de Bhaskara

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// cálculo de raízes de uma equação de segundo grau com
//   coeficientes a, b, c
// caso o cálculo seja possível, as raízes são colocadas
//   nas variáveis apontadas por r1 e r2 e retorna true
// caso contrário, retorna false
bool bhaskara(double a, double b, double c, 
              double *r1, double *r2)
{ 
  double delta = pow(b, 2) - 4 * a * c;
  if (delta < 0) return false;
  *r1 = (-b + sqrt(delta)) / (2 * a);
  *r2 = (-b - sqrt(delta)) / (2 * a);
  return true;
}

int main()
{
  double a, b, c;   // os coeficientes da equação  ax²+bx+c
  double raiz1, raiz2; // os raízes da equação
  // entrada dos coeficientes
  printf("Digite os valores dos coeficientes ");
  printf("a, b e c da equação 'a x² + b x + c'\n");
  scanf("%lf%lf%lf", &a, &b, &c);
  // chamada da função de cálculo das raízes.
  // envia-se a ela os valores dos coeficientes e referência para as
  //   variáveis onde ela pode colocar os valores das raízes;
  //   a função retorna true se as raízes foram calculadas e false se
  //   a equação não possui raízes reais.
  // imprime o resultado de acordo com o retorno da função de cálculo
  if (bhaskara(a, b, c, &raiz1, &raiz2)) {
    printf("As raízes são %f e %f\n", raiz1, raiz2);
  } else {
    printf("Equação sem raízes reais\n");
  }
}
```

### Exercícios

1. Faça uma função que recebe duas referências para inteiros, e altera as variáveis referenciadas para que a primeira tenha o menor valor e a segunda o maior. Em outras palavras, implemente a função `ordena` que completa o programa abaixo:
```c
// Faça uma função que recebe duas referências para 
// inteiros, e altera as variáveis referenciadas para 
// que a primeira tenha o menor valor e a segunda 
// o maior

#include <stdio.h>

int main()
{
  int a, b;
  printf("Digite dois inteiros ");
  scanf("%d%d", &a, &b);
  ordena(&a, &b);
  printf("%d não é maior que %d\n", a, b);
}
```
2. Implemente uma função que recebe duas referências para inteiros, e troca os valores nas variáveis referenciadas. Por exemplo, se `x` vale `5` e `z` vale `19`, após uma chamada `troca(&x, &z);`, `x` passa a valer `19` e `z` passa a valer `5`.
3. Reimplemente a função do exercício 1 para usar a função do exercício 2.
4. Altere a função de cálculo da raiz quadrada do trabalho 1 para retornar um bool que diz se a raiz pode ou não ser calculada, e recebe uma referência onde deve colocar a raiz caso seja possível calculá-la.


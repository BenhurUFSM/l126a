#include "tela.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

static unsigned char le_1()
{
  unsigned char c;
  if (read(0, &c, 1) != 1) return '\0';
  return c;
}

// ch é um dígito?
static bool digito(unsigned char ch)
{
  return ch >= '0' && ch <= '9';
}

// ch é um dígito. lê mais e forma o número em *pnum.
// retorna o primeiro byte lido que não é um dígito.
static unsigned char le_num(unsigned char ch, int *pnum)
{
  int n = ch - '0';
  while (true) {
    ch = le_1();
    if (!digito(ch)) break;
    n = n * 10 + ch - '0';
  }
  *pnum = n;
  return ch;
}

tecla_t testa()
{
  tecla_t ch;
  ch = le_1();
  if (ch != T_ESC) return ch;
  ch = le_1();
  if (ch != '[') return ch;
  ch = le_1();
  int n1 = 1;
  int n2 = 1;
  int n3 = 1;
  if (digito(ch)) ch = le_num(ch, &n1);
  if (ch == ';') ch = le_num('0', &n2);
  if (ch == ';') ch = le_num('0', &n3);
  if (ch < 'A' || ch > 'D') return T_NADA;
  int sh = n2 - 1;
  char n[4][4] = { "cim", "bai", "dir", "esq" };
  printf("%s %d %s-%s-%s-%s\r\n", n[ch-'A'], n2,
         sh&1?"Shift":"", sh&2?"Alt":"", sh&4?"Control":"", sh&8?"Super":"");
  return T_NADA;
}

int main()
{
  // inicializa a tela
  t_inicia();

  while (testa() != 'q')
    ;

  // retorna a tela ao modo normal
  t_fim();
}

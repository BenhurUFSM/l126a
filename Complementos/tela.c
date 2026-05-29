// tela.c
// 
// implementação de funções para acesso a tela e teclado em modo cru
// para l126a

#include "tela.h"
#include <stdlib.h>     // para ter 'system'
#include <unistd.h>     // para ter 'read'
#include <stdbool.h>    // para ter 'bool'
#include <stdio.h>      // para ter 'printf'

// função que coloca o teclado em modo cru
// deve ser chamada no início do programa
void t_inicia()
{
  // executa o programa stty para configurar o terminal
  //   raw - não processa os caracteres de entrada (nem de saída); o programa recebe todos
  //   -echo - não imprime os caracteres digitados
  //   min 0 - permite que a leitura possa ler 0 caracteres (não bloqueia o programa)
  //   time 1 - espera até 1 décimo de segundo antes de desbloquear o programa caso nada
  //            seja digitado. colocando 0 o programa não bloqueia.
  system("stty raw -echo min 0 time 1");
  printf("%c[18t", 27);  // pede o tamanho da tela
  fflush(stdout);    // força envio ao terminal
  printf("%c[?1049h", 27); // seleciona tela alternativa
  while (t_tecla() != T_NADA) {
    ; // esvazia a entrada, com sorte deve ter lido o tamanho
  }

}

// função que devolve o teclado para o modo normal
// deve ser chamada no final do programa
void t_fim()
{
  // chama o programa stty para configurar o terminal para um estado saudável
  system("stty sane");
  printf("%c[?1049l", 27); // recupera tela normal
  printf("%c[0q", 27); // cursor normal
}

// variáveis globais (para serem visíveis por várias funções),
//   estáticas (para não serem visíveis fora deste arquivo) com
//   o tamanho da tela
static int t_largura;
static int t_altura;
void t_tamanho(int *largura, int *altura)
{
  *largura = t_largura;
  *altura = t_altura;
}

// função que lê a próxima tecla digitada
// retorna T_NADA se não houver tecla digitada

// funções auxiliares
// (internas, declaradas `static` para não serem visíveis fora deste arquivo)
static tecla_t processa_teclado(); // faz todo o processamento da entrada
static unsigned char le_1(); // lê o próximo byte da entrada
static bool digito(unsigned char ch); // testa se um byte é dígito
static unsigned char le_num(unsigned char ch, int *pnum);
static tecla_t t_esc(); // foi lido um esc. lê mais e traduz numa tecla

// retorna o próximo char do teclado ou '\0'
// usa a função de baixo nível "read" para ler até 1 caractere da entrada 0 (entrada padrão)
// a função read retorna o número de caracteres lidos (pode ser 0) ou um número negativo
//   para indicar algum erro.
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

// a primeira tecla foi esc, traduz a sequência
static tecla_t t_esc()
{
  unsigned char ch = le_1();
  // só estão sendo tratadas algumas das sequências esc-[
  // as teclas F1-F4, por exemplo, usam outro prefixo
  // quando tem modificadores como shift ou control, é mais complicado e não está
  //   sendo tratado.
  if (ch == '\n') return T_ALT_ENTER;
  if (ch != '[') return T_ESC;
  // TODO: ler toda a sequência de acordo com a definição e depois
  //   interpretar o significado
  ch = le_1();
  int n1 = 1;
  int n2 = 1;
  int n3 = 1;
  if (digito(ch)) ch = le_num(ch, &n1);
  if (ch == ';') ch = le_num('0', &n2);
  if (ch == ';') ch = le_num('0', &n3);
  if (ch == 't' && n1 == 8) {
    // esc [ 8 ; alt ; larg t // tamanho da tela, pede com esc [ 1 8 t
    t_altura = n2;
    t_largura = n3;
    return processa_teclado();
  }
  int shift = 0;
  if (n2 == 2) shift = 4; // shift
  if (n2 == 3) shift = 8; // alt
  if (n2 == 5) shift = 12; // control
  if (ch == 'A') return shift + T_CIMA;
  if (ch == 'B') return shift + T_BAIXO;
  if (ch == 'C') return shift + T_DIREITA;
  if (ch == 'D') return shift + T_ESQUERDA;
  if (ch == 'F') return T_END;
  if (ch == 'H') return T_HOME;
  if (ch == '~') {
    if (n1 == 1) return T_HOME;
    if (n1 == 2) return T_INS;
    if (n1 == 3) return T_DEL;
    if (n1 == 4) return T_END;
    if (n1 == 5) return T_PGUP;
    if (n1 == 6) return T_PGDN;
    if (n1 == 7) return T_HOME;
    if (n1 == 8) return T_END;
  }

  // tem várias outras possibilidades, mas essas são suf, pelo menos por enquanto
  return T_NADA;
}

static tecla_t processa_teclado()
{
  tecla_t tec = le_1();
  if (tec == 127) tec = T_BS;
  else if (tec == '\r') tec = T_ENTER;
  else if (tec == T_ESC) {
    tec = t_esc();
  }
  return tec;
}

// a forma como as teclas são enviadas para um programa é arcaica e horrível.
// as teclas simples (ASCII) enviam o código ASCII
// as teclas acentuadas enviam uma sequência UTF8
// as teclas de controle mais comuns como enter ou backspace enviam um código de 1 byte,
//   em geral um código de controle padronizado ASCII
// as demais teclas enviam uma sequência de códigos, iniciada pelo caractere ESC (código 27)
// esta função traduz alguns desses códigos para valores T_* definidos
//   em tela.h
tecla_t t_tecla()
{
  printf("%c[18t", 27);  // pede o tamanho da tela
  fflush(stdout);  // envia para o SO alguma saída ainda não enviada
  return processa_teclado();
}


void t_lincol(int lin, int col)
{
  printf("%c[%d;%dH", 27, lin, col);
}

void t_limpa()
{
  t_cornormal();
  printf("%c[2J", 27); // limpa a tela
  printf("%c[H", 27);  // posicina o cursor no início da tela
}

void t_corfundo(int r, int g, int b)
{
  printf("%c[48;2;%d;%d;%dm", 27, r, g, b);
}

void t_cortexto(int r, int g, int b)
{
  printf("%c[38;2;%d;%d;%dm", 27, r, g, b);
}
void t_cornormal()
{
  printf("%c[m", 27);
}

void t_cursor(tipo_cursor formato, tipo_piscacao piscacao )
{
  if (formato == c_nada) {
    printf("%c[?25l", 27);
  } else {
    printf("%c[?25h", 27);
    printf("%c[%d q", 27, (formato-1)*2+1+piscacao);
  }
}

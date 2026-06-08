#include "janela.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// desenha um retângulo colorido com texto dentro
void desenha_ret(int l, int c, int dl, int dc,
                 int r, int g, int b,
                 char s[])
{
  cor_t cor_fundo = {r/255., g/255., b/255., 1.0 };
  cor_t cor_txt = { 0.1, 0.1, 0.4, 1.0 };
  if (r+g+b < 350) cor_txt = (cor_t){ 0.8, 0.8, 0.95, 1.0 };
  retangulo_t ret = { { c*7, l*10 }, { dc*7, dl*10 } };

  j_retangulo(ret, 1.5, cor_txt, cor_fundo);

  char txt[50];
  sprintf(txt, "%.49s", s);
  j_seleciona_fonte(NULL, 16);
  j_texto((ponto_t){ c*7+5, l*10+15 }, cor_txt, txt);
}

typedef enum { move, edita, fim } modo_t;

typedef struct {
  modo_t modo;
  int x, y, larg, alt;
} estado_t;

void muda_modo(estado_t *e, modo_t novo_modo)
{
  e->modo = novo_modo;
}

// modo "move"

void tela_move(estado_t *e)
{
  desenha_ret(2, 3, 20, 50, 10, 20, 30, "fundo");
  desenha_ret(e->y, e->x, e->alt, e->larg, 150, 49, 97, "teste");
  // põe o cursor no centro do retângulo
  retangulo_t cursor = { { (e->x + e->larg/2.0)*7, (e->y + e->alt/2.0)*10 }, { 10, 10 } };
  j_retangulo(cursor, 0, (cor_t){0}, (cor_t){ 0.8, 0.6, 0.4, 0.3 });
  j_mostra();
}

void move_direita(estado_t *e)
{
  e->x++;
  if (j_shift()) e->x++;
}

void move_esquerda(estado_t *e)
{
  e->x--;
  if (j_shift()) e->x--;
}

void exec_move(estado_t *e)
{
  // modo sem necessidade de manter valores locais, implementado sem
  //   laço próprio

  // desenha a tela
  tela_move(e);

  // lê um comando
  tecla_t tec = j_tecla();

  // realiza uma ação conforme o comando lido
  switch (tec) {
    case T_ESQUERDA:
      move_esquerda(e);
      break;
    case T_DIREITA:
      move_direita(e);
      break;
    case 'e':
      muda_modo(e, edita);
      break;
    case T_ESC:
      muda_modo(e, fim);
      break;
    default: ;
  }
}

// modo edita

void tela_edita(estado_t *e, char texto[])
{
  desenha_ret(2, 3, 20, 50, 10, 20, 30, "fundo");
  desenha_ret(e->y, e->x, e->alt, e->larg, 150, 49, 97, texto);
  j_mostra();
}

void remove_ultimo_caractere(char s[])
{
  int l = strlen(s);
  if (l > 0) {
    s[l - 1] = '\0';
  }
}

void insere_ultimo_caractere(char s[], char c)
{
  int l = strlen(s);
  s[l] = c;
  s[l + 1] = '\0';
}

void exec_edita(estado_t *e)
{
  // modo com necessidade de manter valores locais, implementado com
  //   laço próprio
  char txt[20] = "";

  while (e->modo == edita) {
    // desenha a tela
    tela_edita(e, txt);

    // lê um comando
    tecla_t tec = j_tecla();

    // realiza uma ação conforme o comando lido
    if (tec == T_ESC) {
      muda_modo(e, move);
    } else if (tec == T_BS) {
      remove_ultimo_caractere(txt);
    } else if (tec >= 'a' && tec <= 'z') {
      insere_ultimo_caractere(txt, tec);
    }
  }
}


int main()
{
  // inicializa a tela
  j_inicializa((tamanho_t){500, 400}, "teste");
  j_seleciona_fonte(NULL, 16);

  // variável contendo o estado do programa
  estado_t estado = { move, 10, 10, 30, 5 };

  while (estado.modo != fim) {
    switch (estado.modo) {
      case move:
        exec_move(&estado);
        break;
      case edita:
        exec_edita(&estado);
        break;
      default:
        break;
    }
    
  }
  // retorna a tela ao modo normal
  j_finaliza();
}


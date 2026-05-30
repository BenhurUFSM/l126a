#include "tela.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// desenha um retângulo colorido com texto dentro
void desenha_ret(int l, int c, int dl, int dc,
                 int r, int g, int b,
                 char s[])
{
  // desenha o retângulo com espaços, selecionando a cor como fundo
  t_corfundo(r, g, b);
  // imprime dl linhas com dc espaços cada
  for (int i = 0; i < dl; i++) {
    // posiciona o cursor onde inicia essa linha do retângulo
    t_lincol(l + i, c);
    // %10s imprime pelo menos 10 caracteres, completando com espaços
    //   se a string for menor
    // %.10s imprime no máximo 10 caracteres
    // %10.10s imprime exatamente 10 caracteres
    // se um número for substituído por '*', será pego no próximo argumento
    printf("%*s", dc, ""); // imprime dc espaços (podia tbém ser um for)
  }

  // escreve o tamanho da tela no canto do retângulo
  int alt, larg;
  t_tamanho(&alt, &larg);
  t_lincol(l, c);
  printf("%dx%d", alt, larg);

  // escreve s no centro do retângulo
  t_lincol(l + dl/2, c + dc/2 - strlen(s)/2);
  t_cortexto(0, 0, 0);
  printf("%s", s);
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
  t_limpa();
  desenha_ret(2, 3, 20, 50, 10, 20, 30, "fundo");
  desenha_ret(e->y, e->x, e->alt, e->larg, 150, 49, 97, "teste");
  // põe o cursor no centro do retângulo
  t_lincol(e->y + e->alt/2, e->x + e->larg/2);
}

void move_direita(estado_t *e)
{
  e->x++;
}

void move_esquerda(estado_t *e)
{
  e->x--;
}

void exec_move(estado_t *e)
{
  // modo sem necessidade de manter valores locais, implementado sem
  //   laço próprio

  // desenha a tela
  tela_move(e);

  // lê um comando
  tecla_t tec = t_tecla();

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
  t_limpa();
  desenha_ret(2, 3, 20, 50, 10, 20, 30, "fundo");
  desenha_ret(e->y, e->x, e->alt, e->larg, 150, 49, 97, texto);
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
    tecla_t tec = t_tecla();

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
  t_inicia();

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
  t_fim();
}

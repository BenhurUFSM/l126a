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

  // escreve s no centro do retângulo
  t_lincol(l + dl/2, c + dc/2 - strlen(s)/2);
  t_cortexto(0, 0, 0);
  printf("%s", s);

  // escreve o tamanho da tela no canto do retângulo
  int alt, larg;
  t_tamanho(&alt, &larg);
  t_lincol(l, c);
  printf("%dx%d", alt, larg);

  // põe o cursor no centro do retângulo
  t_lincol(l + dl/2, c + dc/2);
}

int main()
{
  // inicializa a tela
  t_inicia();

  // dados do retângulo
  int x = 10, y = 10, larg = 30, alt = 5;

  // flag de término do programa
  bool fim = false;
  while (!fim) {
    // desenha a tela
    t_limpa();
    desenha_ret(2, 3, 20, 50, 10, 20, 30, "fundo");
    desenha_ret(y, x, alt, larg, 150, 49, 97, "teste");

    // lê um comando
    tecla_t tec = t_tecla();

    // realiza uma ação conforme o comando lido
    if (tec == T_ESC) break;
    switch (tec) {
      case 'a': case T_ESQUERDA:      x--; break;
      case 'd': case T_SHIFT_DIREITA: x++; break;
      case 'x': case T_CTRL_BAIXO:    y++; break;
      case 'w': case T_ALT_CIMA:      y--; break;
      case 'b': t_cursor(c_bloco, c_pisca); break;
      case 's': t_cursor(c_sublinha, c_pisca); break;
      case 'l': t_cursor(c_barra, c_naopisca); break;
      default: ;
    }
  }
  // retorna a tela ao modo normal
  t_fim();
}

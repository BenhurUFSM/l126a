// teclado.h
// 
// declaração de constantes e funções para acesso ao teclado em modo cru
// para l126a

// proteção contra reinclusão:
//   se TELA_H não estiver definido, define e inclui o texto.
//   se TELA_H já estiver definido, ignora tudo até o endif no final
#ifndef TELA_H
#define TELA_H

// constantes para representar as teclas de controle.
// usa uma enumeração para dar nomes e valores para as teclas
// usa typedef para definir um tipo (tecla_t) que será usado para
//   declarar variáveis que recebem esses valores.
typedef enum {
  T_NADA = 0, // nenhuma tecla foi pressionada
  T_ESC = 27, // a tecla esc
  // as setas
  T_CIMA = 256,
  T_BAIXO,
  T_DIREITA,
  T_ESQUERDA,
  // setas com shift
  T_SHIFT_CIMA,
  T_SHIFT_BAIXO,
  T_SHIFT_DIREITA,
  T_SHIFT_ESQUERDA,
  // setas com alt
  T_ALT_CIMA,
  T_ALT_BAIXO,
  T_ALT_DIREITA,
  T_ALT_ESQUERDA,
  // setas com control
  T_CTRL_CIMA,
  T_CTRL_BAIXO,
  T_CTRL_DIREITA,
  T_CTRL_ESQUERDA,
  // outras teclas
  T_ENTER,
  T_ALT_ENTER,
  T_PGUP,
  T_PGDN,
  T_HOME,
  T_END,
  T_BS,
  T_BACKSPACE = T_BS,
  T_INS,
  T_DEL,
} tecla_t;

// funções

// função que coloca a tela e o teclado em modo cru
// deve ser chamada no início do programa
void t_inicia();

// função que devolve a tela e o teclado para o modo normal
// deve ser chamada no final do programa
void t_fim();

// retorna o tamanho da tela, em caracteres
void t_tamanho(int *largura, int *altura);

// retorna a próxima tecla digitada
// retorna T_NADA se não houver tecla digitada
tecla_t t_tecla();

// posiciona o cursor
// lin 1 col 1 é o canto superior esquerdo da tela
void t_lincol(int lin, int col);

// limpa a tela com a cor de fundo
void t_limpa();

// seleciona a cor de fundo para as próximas escritas
void t_corfundo(int r, int g, int b);

// seleciona a cor do texto para as próximas escritas
void t_cortexto(int r, int g, int b);

// seleciona a cor de texto e de fundo normais
void t_cornormal();

// seleciona o formato do cursor
typedef enum { c_nada, c_bloco, c_sublinha, c_barra } tipo_cursor;
typedef enum { c_pisca, c_naopisca } tipo_piscacao;
void t_cursor(tipo_cursor formato, tipo_piscacao piscacao );

#endif // TELA_H

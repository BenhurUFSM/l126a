// tela.h
// 
// declaração de constantes e funções para acesso à tela
//   e ao teclado em modo cru
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
  T_CTRL_A = 1,
  T_CTRL_B,
  T_CTRL_C,
  T_CTRL_D,
  T_CTRL_E,
  T_CTRL_F,
  T_CTRL_G,
  T_CTRL_H,
  T_CTRL_I,
  T_TAB = 9,
  T_CTRL_J,
  T_CTRL_K,
  T_CTRL_L,
  T_CTRL_M,
  T_CTRL_N,
  T_CTRL_O,
  T_CTRL_P,
  T_CTRL_Q,
  T_CTRL_R,
  T_CTRL_S,
  T_CTRL_T,
  T_CTRL_U,
  T_CTRL_V,
  T_CTRL_W,
  T_CTRL_X,
  T_CTRL_Y,
  T_CTRL_Z,
  T_ESC = 27, // a tecla esc
  // as setas
  T_CIMA = 256,
  T_BAIXO,
  T_DIREITA,
  T_ESQUERDA,
  // setas com shift
  T_S_CIMA,
  T_S_BAIXO,
  T_S_DIREITA,
  T_S_ESQUERDA,
  // setas com alt
  T_A_CIMA,
  T_A_BAIXO,
  T_A_DIREITA,
  T_A_ESQUERDA,
  // setas com shift+alt
  T_SA_CIMA,
  T_SA_BAIXO,
  T_SA_DIREITA,
  T_SA_ESQUERDA,
  // setas com control
  T_C_CIMA,
  T_C_BAIXO,
  T_C_DIREITA,
  T_C_ESQUERDA,
  // setas com shift+control
  T_SC_CIMA,
  T_SC_BAIXO,
  T_SC_DIREITA,
  T_SC_ESQUERDA,
  // setas com alt+control
  T_AC_CIMA,
  T_AC_BAIXO,
  T_AC_DIREITA,
  T_AC_ESQUERDA,
  // setas com shift+alt+control
  T_SAC_CIMA,
  T_SAC_BAIXO,
  T_SAC_DIREITA,
  T_SAC_ESQUERDA,
  // setas com meta (outro nome para super)
  T_M_CIMA = 256,
  T_M_BAIXO,
  T_M_DIREITA,
  T_M_ESQUERDA,
  // setas com shift+meta
  T_SM_CIMA,
  T_SM_BAIXO,
  T_SM_DIREITA,
  T_SM_ESQUERDA,
  // setas com alt+meta
  T_AM_CIMA,
  T_AM_BAIXO,
  T_AM_DIREITA,
  T_AM_ESQUERDA,
  // setas com shift+alt+meta
  T_SAM_CIMA,
  T_SAM_BAIXO,
  T_SAM_DIREITA,
  T_SAM_ESQUERDA,
  // setas com control+meta
  T_CM_CIMA,
  T_CM_BAIXO,
  T_CM_DIREITA,
  T_CM_ESQUERDA,
  // setas com shift+control+meta
  T_SCM_CIMA,
  T_SCM_BAIXO,
  T_SCM_DIREITA,
  T_SCM_ESQUERDA,
  // setas com alt+control+meta
  T_ACM_CIMA,
  T_ACM_BAIXO,
  T_ACM_DIREITA,
  T_ACM_ESQUERDA,
  // setas com shift+alt+control+meta
  T_SACM_CIMA,
  T_SACM_BAIXO,
  T_SACM_DIREITA,
  T_SACM_ESQUERDA,
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

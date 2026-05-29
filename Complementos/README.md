## controle de tela e teclado

Contém os seguintes arquivos:
- `tela.h`
  - definição do tipo `tecla_t` para representar uma tecla do teclado, incluindo algumas teclas de controle 
  - declaração de funções para ler o teclado, obter informações sobre a tela, selecionar cores e cursor, e posicionar o cursor
- `tela.c`
  - implementação das funções descritas em `tela.h`
- `ex_tela.c`
  - programa exemplificando o uso das funções em `tela.h`
  - compile com `gcc -o ex_tela ex_tela.c tela.c`
  - execute com `./ex_tela`
  - o programa desenha 2 retângulos, contendo um texto no centro e o tamanho da tela em um canto
  - o programa obedece algumas teclas, trocando a posição de um dos retângulos e alterando o formato do cursor
  - para as setas, uma é sozinha, outra com shift, outra com ctrl, outra com alt
  - para encerrar o programa, pressione ESC
  - caso interrompa a execução do programa, execute `stty sane` ou `reset` no terminal.

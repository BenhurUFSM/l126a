## Controle de tela e teclado

Contém os arquivos abaixo. Leia o conteúdo de `tela.h` e `ex_tela.c`. Não precisa olhar em `tela.c`.
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

## Controle de tela gráfica, teclado, mouse

Alternativamente, pode ser feita uma implementação usando modo gráfico.
Para isso, use os arquivos:
- `janela.h` — contém a definição de valores para as teclas e alguns outros tipos de dados, e a declaração de funções para criação de janela, acesso ao mouse, teclado e relógio;
- `janela.c` — implementação das funções em `janela.h`, usando a biblioteca `allegro5`.
- `exemplo_janela.c` — programa exemplo de uso de `janela.h`
- `DejaVuSans.ttf` — arquivo contendo uma fonte de caracteres, que é usada por default por `janela.c`.
- `compila` — script para facilitar a compilação.

Copie esses arquivos, instale a biblioteca allegro5 (se o seu sistema fizer a distinção, instale a versão com "dev").
Compile o programa exemplo com o comando:
```
   gcc -Wall -o exemplo_janela exemplo_janela.c janela.c -lallegro_font -lallegro_color -lallegro_ttf -lallegro_primitives -lallegro
```
ou com:
```
   source compila
```
Execute com:
```
   ./exemplo_janela
```

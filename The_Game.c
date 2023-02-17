#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int size = 15;

void imprimir(char cenario[size][size]) {

  for (int l = 0; l < size; l++) {
    for (int c = 0; c < size; c++) {

      printf("%c   ", cenario[l][c]);
    }

    printf("\n\n");
  }
}

int main(void) {

  srand(time(NULL));

  char cenario[size][size];

  // Inicialização da matriz disponível
  for (int l = 0; l < size; l++) {
    for (int c = 0; c < size; c++) {

      cenario[l][c] = '_';
    }
  }

  int rickL = rand() % size;
  int rickC = rand() % size;

  cenario[rickL][rickC] = 'R';

  // Inicialização dos 10 zumbis
  for (int z = 1; z <= 10;) {

    int zumbiL = rand() % size;
    int zumbiC = rand() % size;

    if (cenario[zumbiL][zumbiC] == '_') {

      cenario[zumbiL][zumbiC] = 'Z';
      z++;
    }
  }

  // Inicialização dos 20 obstáculos
  for (int o = 1; o <= 20;) {

    int obstL = rand() % size;
    int obstC = rand() % size;

    if (cenario[obstL][obstC] == '_') {

      cenario[obstL][obstC] = '@';
      o++;
    }
  }

  // Inicialização da saída
  for (int s = 1; s <= 1;) {

    int saiL = rand() % size;
    int saiC = rand() % size;

    if (cenario[saiL][saiC] == '_') {

      cenario[saiL][saiC] = '+';
      s++;
    }
  }

  // Inicialização das balas
  for (int b = 1; b <= 10;) {

    int balasL = rand() % size;
    int balasC = rand() % size;

    if (cenario[balasL][balasC] == '_') {

      cenario[balasL][balasC] = '.';
      b++;
    }
  }

  int balas = 0;
  int morreu = 0;
  int escapou = 0;

  do {

    char movimento;

    imprimir(cenario);
    printf("\n\nBalas: %i", balas);

    printf("\n> ");
    scanf("%c", &movimento);
    getchar();

    // Limpar a tela a cada atualização
    system("clear");

    switch (movimento) {
    case 'w':
      // Para não sair do mapa
      if (rickL - 1 >= 0) {

        // Poderá se movimentar se for diferente do obstáculo
        if (cenario[rickL - 1][rickC] != '@') {

          // Verificar se nova posição tinha bala
          if (cenario[rickL - 1][rickC] == '.') {
            balas++;

            // Rick vs Zumbi
          } else if (cenario[rickL - 1][rickC] == 'Z') {

            if (balas == 0) {
              morreu++;
              
            } else {
              balas--;
              
            }

            // Saída 
          } else if (cenario[rickL - 1][rickC] == '+') {

            escapou++;
          }
          
          // Posição antiga de Rick
          cenario[rickL][rickC] = '_';

          // Nova posição de Rick
          rickL--;
          cenario[rickL][rickC] = 'R';
          
        }
      }

      break;

    case 'a':
      // Para não sair do mapa
      if (rickC - 1 >= 0) {

        // Poderá se movimentar se for diferente do obstáculo
        if (cenario[rickL][rickC - 1] != '@') {

          // Verificar se nova posição tinha bala
          if (cenario[rickL][rickC - 1] == '.') {
            balas++;

            // Rick vs Zumbi
          } else if (cenario[rickL][rickC - 1] == 'Z') {

            if (balas == 0) {
              morreu++;
              
            } else {
              balas--;
              
            }

            // Saída
          } else if (cenario[rickL][rickC - 1] == '+') {

            escapou++;
          }

          // Posição antiga de Rick
          cenario[rickL][rickC] = '_';

          // Nova posição de Rick
          rickC--;
          cenario[rickL][rickC] = 'R';
          
        }
      }

      break;

    case 's':
      // Para não sair do mapa
      if (rickL + 1 < size) {

        // Poderá se movimentar se for diferente do obstáculo
        if (cenario[rickL + 1][rickC] != '@') {

          // Verificar se nova posição tinha bala
          if (cenario[rickL + 1][rickC] == '.') {
            balas++;

            // Rick vs Zumbi
          } else if (cenario[rickL + 1][rickC] == 'Z') {

            if (balas == 0) {
              morreu++;
              
            } else {
              balas--;
              
            }

            // Saída
          } else if (cenario[rickL + 1][rickC] == '+') {

            escapou++;
          }

          // Posição antiga de Rick
          cenario[rickL][rickC] = '_';

          // Nova posição de Rick
          rickL++;
          cenario[rickL][rickC] = 'R';
          
        }
      }

      break;

    case 'd':
      // Para não sair do mapa
      if (rickC + 1 < size) {

        // Poderá se movimentar se for diferente do obstáculo
        if (cenario[rickL][rickC + 1] != '@') {

          // Verificar se nova posição tinha bala
          if (cenario[rickL][rickC + 1] == '.') {
            balas++;

            // Rick vs Zumbi
          } else if (cenario[rickL][rickC + 1] == 'Z') {

            if (balas == 0) {
              morreu++;
              
            } else {
              balas--;
              
            }

            // Saída
          } else if (cenario[rickL][rickC + 1] == '+') {

            escapou++;
          }

          // Posição antiga de Rick
          cenario[rickL][rickC] = '_';

          // Nova posição de Rick
          rickC++;
          cenario[rickL][rickC] = 'R';
          
        }
      }

      break;
    }

  } while (morreu != 1 && escapou == 0);

  // Se Rick morreu
  if (morreu == 1) {

    printf("Rick morreu!");

    // Se Rick saiu
  } else if (escapou == 1) {

    printf("Rick escapou!");
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"
#include "teste.h"


int main() {


    tests();
    ESTADO *e = inicializar_estado();
    int res;
    srand(time(NULL));


    res = menu();
    switch (res) {
        case 1:
            //system("cls");
            mostrar_tabuleiro(e, stdout);
            while (game_over(e) == 0) {


                prompt(e, stdout);

                interpretador(e);

            }
            val_game_over(e);
            break;
        case 2:
            //system("cls");
            printf("(1)-Pure Luck\n(2)-Pro Player Bot\n");
            printf(">>");
            char *p, s[100];
            long n = 0;
            while (fgets(s, sizeof(s), stdin)) {
                n = strtol(s, &p, 3);
                if(n!=2&&n!=1)
                    printf("Please enter a valid number: ");
                else {
                    if (p == s || *p != '\n') {
                        printf("Please enter a valid number: ");
                    } else break;
                }
            }
            printf("You entered: %ld\n", n);
            e->bot=1;
            LISTA Head=NULL;
            mostrar_tabuleiro(e, stdout);
            while (game_over(e) == 0) {
                if(obter_jogador_atual(e)==1)
                {
                    prompt(e, stdout);
                    interpretador(e);
                } else
                    if(n==2){
                        jog2(Head,e);
                        mostrar_tabuleiro(e,stdout);
                    } else {
                        jog(Head,e);
                        mostrar_tabuleiro(e,stdout);
                    }

            }
            if(game_over(e)==1) {
                prompt(e, stdout);
                printf("\n");
                mostrar_tabuleiro(e, stdout);
            }
            val_game_over(e);
            break;
        default:
            break;
    }

    printf("\n======THANKS FOR PLAYING======\n");


    system("pause");
    return 0;
}
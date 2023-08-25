#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "interface.h"
#include "logica.h"
#include <unistd.h>
#include <string.h>


void mostrar_tabuleiro(ESTADO *e, FILE *file) {
    //system("cls");
    int i, j;
    int a = 8;
    CASA peca;


    for (i = 0; i < 8; i++) {
        if (file==stdout)
            fprintf(stdout, "%d|", a);

        for (j = 0; j < 8; j++) {
            peca = obter_estado_casa(e, (COORDENADA) {j, i});
            switch (peca) {
                case DOIS:
                    fputc(DOIS, file);
                    break;
                case UM:
                    fputc(UM, file);
                    break;
                case BRANCA:
                    fputc(BRANCA, file);
                    break;
                case PRETA:
                    fputc(PRETA, file);
                    break;
                case VAZIO:
                    fputc(VAZIO, file);
                    break;

                default:
                    break;
            }
        }
        fprintf(file, "\n");

        a--;
    }
    if (file==stdout)
        fprintf(stdout, " |abcdefgh\n");

}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char func[20];
    char filename[100];
    char num[20];
    LISTA Head = NULL;
    char path[100] = "../";


    if (fgets(linha, BUF_SIZE, stdin) == NULL) {
        return 0;
    }

    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {

        COORDENADA coord = {*col - 'a', *lin - '1'};
        coord.linha = 7 - coord.linha;
        if (jogar(e, coord) == 0) {
            printf("Impossible coordnate\n");
        } else
            update_com(e);

        if (e->bot == 0)
            mostrar_tabuleiro(e, stdout);
    }
    if (sscanf(linha, "%s", func)) {


        if (!strcmp(func, "Q")) {
            update_com(e);
            exit(0);
        }
        if (sscanf(linha, "gr %s", filename) == 1) {
            strcat(path, filename);
            if (access(path, F_OK) != -1) {

                printf("File is already created with that name\n");
                return 0;
            } else {
                update_com(e);
                gravar(e, filename);
            }
        }
        if (sscanf(linha, "ler %s", filename) == 1) {

            strcat(path, filename);

            if (access(path, F_OK) != -1) {
                update_com(e);
                ler(e, filename);
                printf("=====LOADED======\n");
                mostrar_tabuleiro(e, stdout);

            } else
                printf("File doesn t exit\n");
        }
        if (sscanf(linha, "pos %s", num) == 1) {

            int numero =atoi(num);//int numero = *num - '0';
            if(pos(e, numero)==1) {
                update_com(e);
                mostrar_tabuleiro(e, stdout);
            } else
                printf("Number is bigger than plays played\n");
        }
        if (!strcmp(func, "movs")) {

            update_com(e);
            movs(e, stdout);

        }
        if (!strcmp(func, "jog2")) {
            update_com(e);
            jog2(Head, e);
            if (e->bot == 0)
                mostrar_tabuleiro(e, stdout);


        }
        if (!strcmp(func, "jog")) {
            update_com(e);
            jog(Head, e);
            if (e->bot == 0)
                mostrar_tabuleiro(e, stdout);
        }


    }


    return 1;
}

void prompt(ESTADO *e, FILE *file) {

    fprintf(file, "#%02d PL%d (%02d)>", e->num_comando, obter_jogador_atual(e), obter_numero_de_jogadas(e));
}

void banner() {

    printf("\n\n########     ###     ######  ######## ########   #######   ###### \n");
    printf("##     ##   ## ##   ##    ##    ##    ##     ## ##     ## ##    ##\n ");
    printf("##     ##  ##   ##  ##          ##    ##     ## ##     ## ##  \n");
    printf("########  ##     ##  ######     ##    ########  ##     ##  ###### \n");
    printf("##   ##   #########       ##    ##    ##   ##   ##     ##       ## \n");
    printf("##    ##  ##     ## ##    ##    ##    ##    ##  ##     ## ##    ## \n");
    printf("##     ## ##     ##  ######     ##    ##     ##  #######   ######\n\n\n");
    printf("Press any key to continue . . . . . .  ");
}

void print_co(COORDENADA c) {
    printf("(%d,%d)\n", c.coluna, c.linha);

}

int menu() {

    char *p, s[100];
    long n = 0;
    /*banner();
    getchar();
    system("cls");*/
    printf("=======Menu======\n");
    printf("(1)-Player vs Player\n");
    printf("(2)-Player vs Bot\n");
    printf(">>");

    while (fgets(s, sizeof(s), stdin)) {
        n = strtol(s, &p, 3);
        if (n != 2 && n != 1)
            printf("Please enter a valid number: ");
        else {
            if (p == s || *p != '\n') {
                printf("Please enter a valid number: ");
            } else break;
        }
    }

    printf("You entered: %ld\n", n);
    return n;

}

int gravar(ESTADO *e, char filename[100]) {
    FILE *file;
    char path[100] = "../";
    strcat(path, filename);
    file = fopen(path, "w");
    mostrar_tabuleiro(e, file);
    //prompt(e, file);
    movs(e, file);
    if (file == NULL)
        return 0;
    else
        printf("\nSaved\n");


    fclose(file);
    return 1;
}


int ler(ESTADO *e, char filename[100]) {
    FILE *file;
    char path[100] = "../";
    strcat(path, filename);
    file = fopen(path, "r");
    char line[14];
    int i, j,k=0;
    int ln ;
    free(e);
    e = inicializar_estado();

    //memset(e->jogadas, 0, sizeof e->jogadas);

    for (i = 0; (fgets(line, sizeof line, file) != NULL); i++) {

        //fputs(line,stdout);
        //printf("[");
        ln=sizeof(line);
        for (j = 0; j < ln; j++) {


            if (i < 8) {
                //printf("%c(%d,%d) ", line[j],j,i);

                if (line[j] == '.') {
                    set_casa(e, (COORDENADA) {j , i}, VAZIO);
                }
                if (line[j] == '2') {
                    set_casa(e, (COORDENADA) {j , i}, DOIS);
                }
                if (line[j] == '*') {
                    set_casa(e, (COORDENADA) {j , i}, BRANCA);

                }
                if (line[j] == '1') {
                    set_casa(e, (COORDENADA) {j , i}, UM);
                }
                if (line[j] == '#') {
                    set_casa(e, (COORDENADA) {j , i}, PRETA);

                }

            }


        }
        if (i == 8) {
            //fputs(line,stdout);

            //e->num_comando = (line[1] - '0') * 10 + (line[2] - '0');
            //e->jogador_atual = (line[6] - '0');
            //e->num_jogadas = (line[9] - '0') * 10 + (line[10] - '0');


        }
        if (i >= 9) {

            //fputs(line,stdout);
            k = (line[0] - '0') * 10 + (line[1] - '0');
            //e->num_jogadas=j;

            int c = (line[4] - 'a');
            int l = 8 - (line[5] - '0');
            COORDENADA co = {c, l};
            e->jogadas[k].jogador1 = co;

            //printf ("\n (%d,%d) ", c,l);
            if(line[6]==(char)0||line[6]=='\n')
                e->jogador_atual=2;
            else {
                int c2 = (line[7] - 'a');
                int l2 = 8 - (line[8] - '0');
                COORDENADA co2 = {c2, l2};
                e->jogadas[k].jogador2 = co2;
            }


            //printf ("\n (%d,%d) ", c2,l2);




        }

        //printf("]\n");



    }
    if(e->jogador_atual==1)
        e->num_jogadas=k+1;
    else
        e->num_jogadas=k;
    e->num_comando=0;
    e->last_coord = coor_branca(e);
    fclose(file);
    return 1;
}

void val_game_over(ESTADO *e) {
    if (game_over(e) == 1)
        printf("\nJOGADOR 1 VENCEU !!\n");
    else if(game_over(e)==2)
        printf("\nJOGADOR 2 VENCEU !!\n");

}

int movs(ESTADO *e, FILE *file) {
    int i;
    int max = e->num_jogadas;
    int jogador = obter_jogador_atual(e);
    fprintf(file, "\n");
    if (max == 1 && jogador == 1) {
        return 0;
    } else {
        for (i = 1; i <= max; i++) {
            int c1 = e->jogadas[i].jogador1.coluna;
            int c2 = e->jogadas[i].jogador2.coluna;
            char cc1 = c1 + 'a';
            char cc2 = c2 + 'a';
            int l1 = 8 - (e->jogadas[i].jogador1.linha);
            int l2 = 8 - (e->jogadas[i].jogador2.linha);
            if (i == max && jogador == 1) {
                break;
            } else {
                if (i == max && jogador == 2) {
                    fprintf(file, "%02d: %c%d\n", i, cc1, l1);
                    break;
                } else {
                    fprintf(file, "%02d: %c%d", i, cc1, l1);
                    fprintf(file, " %c%d\n", cc2, l2);
                }

            }

        }
    }
    return 1;


}

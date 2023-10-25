#include <stdio.h>
#include <stdlib.h>
//TRABALHO POR LUIS FELIPE SIQUEIRA GOBETTI E MAURO EDUARDO GUSMAO

void cabecalho ()
{
printf("*****************************************************");
printf("\nAlunos: Luis Felipe Siqueira, Mauro Eduardo Gusmao");
printf("\nDisciplina: LINGUAGEM PROGRAMACAO");
printf("\nJOGO DA VELHA");
printf("\n*****************************************************\n");
}

//Variaveis globais
char nomeA[61], nomeB[61], escolha;
char p1, p2;

//Fun��o para definir P1
char jogadorA() {
    p1 =  ' ';
    cabecalho();
    printf("Informe o nome do primeiro jogador: ");
    scanf("%s", &nomeA);

    //Escolha entre X ou O
    do {
        system("cls");
        cabecalho();
        printf("%s escolha corretamente entre X ou O: ", nomeA);
        scanf(" %c", &escolha);
    }while(escolha != 'X' && escolha != 'x' && escolha != 'O' && escolha != 'o');

    if(escolha == 'X' || escolha == 'x') {
        p1 = 'X';
    }else {
        p1 = 'O';
    }

    return p1;

}

//fun��o para definir P2
char jogadorB() {
    char p2;
    printf("Informe o nome do segundo jogador: ");
    scanf("%s", &nomeB);

    //Verifica��o para ser o oposto da escolha do P1
    if(escolha == 'X' || escolha == 'x') {
        p2 = 'O';
    }else {
        p2 = 'X';
    }

    return p2;

}

//Fun��o com o jogo da velha
void jogo() {
    int jogada, nJogadas;
    char mesa[3][3];
    int ax = 14, verificador = 0;
    char bx;

    //Colocando caracter vazias na matriz
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            mesa[i][j] = ax;
            ax+=10;
        }
        ax-=29;
    }

    printf("\n");

    //Exibindo o tabuleiro
    printf("\t\t  1  2  3\n\t\t *-------*\n");
    for(int i = 0; i < 3; i++) {
            printf("\t\t%d|", i + 4);
        for(int j = 0; j < 3; j++) {
            if(j == 0)
                printf(" ");

            if(j == 0 || j == 1)
                printf(" |");
            else
                printf("  |");
        }
        if(i == 0 || i == 1)
        printf("\n\t\t |-------|\n");

        if(i == 2)
        printf("\n\t\t *-------*\n");
    }
    printf("\n");

    //For para perguntar as posi��es
    for(int x = 0; x < 9; x++) {
        printf("\n\t\t Jogada %d\n\n***Coloque os numeros da posicao juntos ex:14, primeiro a coluna depois a linha***\n",x+1);

        //Verifica��o se � a vez do P1 ou P2
        if(x % 2 == 0) {
            printf("\n\t%s escolha uma posicao  para colocar o %c:" ,nomeA, p1);
            scanf(" %d", &jogada);
            printf("\nEscolheu %d\n",jogada);
            bx = p1;
        }else {
            printf("\n\t%s escolha uma posicao para colocar o %c: ",nomeB, p2);
            scanf(" %d", &jogada);
            printf("\nEscolheu %d\n",jogada);
            bx = p2;
        }

        system("cls");
        cabecalho();

        printf("\n\t\t %s = %c\n\t\t %s = %c\n\n",nomeA, p1, nomeB, p2);

        //Verifica��o se a posi��o escolida est� correta

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(mesa[i][j] == jogada) {
                    mesa[i][j] = bx;
                    verificador++;
                    break;
                }
            }
        }

        if(verificador > 0) {
            //tudo ok
            verificador--;
        }else {
            printf("***Posicao ja foi escolhida ou Invalida! Jogue denovo***\n");
            x--;
        }

    //Exibe o tabuleiro com as altera��es
    printf("\t\t  1  2  3\n\t\t *-------*\n");
    for(int i = 0; i < 3; i++) {
            printf("\t\t%d|", i+4);
        for(int j = 0; j < 3; j++) {
            if(j == 0)
                printf(" ");

            if(j == 0 || j == 1)
                if(mesa[i][j] == 'X' || mesa[i][j] == 'O')
                printf("%c|",mesa[i][j]);
                else
                printf(" |");
            else
                if(mesa[i][j] == 'X' || mesa[i][j] == 'O')
                printf("%c |",mesa[i][j]);
                else
                printf("  |");
        }
        if(i == 0 || i == 1)
        printf("\n\t\t |-------|\n");

        if(i == 2)
        printf("\n\t\t *-------*\n");
    }
    //Verifica se ja teve no minimo 4 jogadas
    if(x >= 4) {
        for(int i = 0; i < 3; i++) {
                //Verifica se h� ganhador
                if(mesa[i][0] != ' ' && mesa[i][0] == mesa[i][1] && mesa[i][1] == mesa[i][2] || mesa[0][i] != ' ' && mesa[0][i] == mesa[1][i] && mesa[1][i] == mesa[2][i]) {
                    if(x % 2 == 0) {
                            printf("\t\t%s Ganhou!\tJogadas %d\n", nomeA, x+1);
                            x = 10;
                            break;
                    }else {
                            printf("\t\t%s Ganhou!\tJogadas %d\n", nomeB, x+1);
                            x = 10;
                            break;
                        }
                //Verifica se h� ganhador diagonal
                }else if(mesa[0][0] != ' ' && mesa[0][0] == mesa[1][1] && mesa[1][1] == mesa[2][2] || mesa[0][2] != ' ' && mesa[0][2] == mesa[1][1] && mesa[1][1] == mesa[2][0]) {
                    if(x % 2 == 0) {
                        printf("\t\t%s Ganhou!\tJogadas %d\n", nomeA, x+1);
                        x = 10;
                        break;
                    }else {
                        printf("\t\t%s Ganhou!\tJogadas %d\n", nomeB, x+1);
                        x = 10;
                        break;
                        }
                    }
            }
            if(x == 8) {
                        printf("\t\tDeu velha!Jogadas %d\n", x+1);
                    x = 10;
                    break;
                    }
        }

    printf("\n");

    }
}



int main() {

    char resposta;

    do {
        p1 =  ' ';

        p1 = jogadorA();

        system("cls");
        cabecalho();
        p2 = jogadorB();

        system("cls");
        cabecalho();
        printf("\n\t\t %s = %c\n\t\t %s = %c\n",nomeA, p1, nomeB, p2);

        jogo();

        do {
            printf("\nDeseja Jogar novamente? Se sim digite S se nao digite N\n");
            scanf(" %c",&resposta);
            system("cls");
        }while(resposta != 'N' && resposta != 'n' && resposta != 'S' && resposta != 's');

    }while(resposta != 'N' && resposta != 'n');
    printf("\nTCHAU!\n");
}


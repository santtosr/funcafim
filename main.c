#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* extansia o arquivo funcmat.h, no qual estão as funções responsáveis por resolver cada expressão
contidas nas opções desse arquivo*/
#include "funcmat.h"

int main(void) {
/*den e num é a abreviação de Numerador e Denominador.
op e op1 são responsáveis por guardar um valor para seleção uma opção para o usuário.
op3 é responsável por guarda um caractere para selecionar uma operação para o usuário*/
    int op, op1, op3;
    float a, b, x, y, mmc, den, num, den2, num2;

    do {

            printf("\n");
            printf("---------------Escolha uma Opção---------------\n");
            printf("      1 - Função AFIM. \n");
            printf("      2 - Função AFIM com números fracionarios. \n");
            printf("      3 - Calcular raiz ou zero da função do 1ºGrau.\n");
            printf("      0 - Encerrar programa. \n");
            printf("-----------------------------------------------\n");
            printf("  Qual operação deseja realizar: ");
            scanf("%d", &op);

        switch (op) {

            case 1:
                printf("\n");
                printf("  Função afim selecionada.\n");
                printf("\n");

                printf("   Informe o valor de A: ");
                scanf("%f", &a);
                printf("   Informe o valor de X: ");
                scanf("%f", &x);
                printf("   Informe o valor de B: ");
                scanf("%f", &b);

                if (b == 0 && a != 0) {
                    printf("                          ERROR !!\n");
                    printf("  A função informada é uma função linear! \n");
                    printf("  Este programa calcula apenas Função Afim e/ou Função do 1ºGrau. \n");
                }
                else{

                    // chama a função que realiza a soma e informa o valor de y como resultado.
                    y = soma (a, b, x);

                    // chama a função que verifica se a reta é constante, crescente ou decrescente.
                    verificareta (a);

                    // chama a função que verifica o quadrante que o ponto pertence.
                    quadrante (x, y);
                }
            break;

            case 2:
                printf("\n");
                printf("  Função do 1ºGrau selecionada.\n");
                printf("\n");

                printf("  Se A é um número fracionario digite 1.\n");
                printf("  Se B é um número fracionario digite 2.\n");
                printf("  Qual opção deseja realizar 1 ou 2: ");
                scanf("%d", &op3);

                // função que transforma o A em fração e retorna para o usuário
                if (op3 == 2) {
                    printf("\n");
                    printf("  Informe o valor de a: ");
                    scanf("%f", &a);
                    printf("  Informe o valor de x: ");
                    scanf("%f", &x);
                    printf("  Informe o numerador: ");
                    scanf("%f", &num);
                    printf("  Informe o denominador: ");
                    scanf("%f", &den);
                    printf("\n");

                     if (x != 0) {
                        // soma a Fração
                        y = somafracao(num, den, x, a, op3);
                    }
                    else {
                        y = num/den;
                    }

                    if (num > 0) {
                        printf("  A função Y = %.0f*%.0f + %.0f/%.0f é representada no plano cartesiano: \n", a, x, num, den);
                        printf("\n");
                    }
                    else {
                        printf("  A função Y = %.0f*%.0f %.0f/%.0f é representada no plano cartesiano: \n", a, x, num, den);
                        printf("\n");
                    }
                    // chama a função que verifica se a reta é constante, crescente ou decrescente.
                    verificareta (a);
                    //imprime y como número inteiro
                    quadrante (x, y);
                }
                if (op3 == 1) {
                    printf("\n");
                    printf("  Informe o numerador: ");
                    scanf("%f", &num);
                    printf("  Informe o denominador: ");
                    scanf("%f", &den);
                    printf("  Informe o valor de x: ");
                    scanf("%f", &x);
                    printf("  Informe o valor de b: ");
                    scanf("%f", &b);
                    printf("\n");

                    if (x != 0) {
                        //  soma a fração
                        y = somafracao(num, den, x, b, op3);
                    }
                    else {
                        y = b;
                    }

                    if (b > 0) {
                        printf("  A função Y = %.0f/%.0f*%.0f + %.0f é representada: \n", num, den, x, b);
                        printf("\n");
                    }
                    else {
                        printf("  A função Y = %.0f/%.0f*%.0f %.0f é representada: \n", num, den, x, b);
                        printf("\n");
                    }
                    // chama a função que verifica se a reta é constante, crescente ou decrescente.
                    verificareta (num);
                    //imprime y como número inteiro
                    quadrante (x, y);
                }
            break;

            case 3:
                printf("\n");
                printf("  Calcular raiz ou zero da função do 1ºGrau selecionada.\n");
                printf("\n");

                printf("  Informe o valor de A: ");
                scanf("%f", &a);
                printf("  Informe o valor de B: ");
                scanf("%f", &b);

                if (b < 0) {
                    b = b * (-1);
                    x = b / a;
                }else if (b == 0) {
                    x = 0;
                }
                else {
                    b = b * (-1);
                    x = b / a;
                }
                if (b < 0) {
                    printf("   A reta representada pela função Y = %.0fX %.0f\n", a, b);
                }
                else if (b > 0 || b == 0){
                    printf("   A reta representada pela função Y = %.0fX + %.0f\n", a, b);
                }
                printf("   Intersecta o eixo X no seguinte valor: %.2f\n", x);
            break;

            default:
                printf("\n");
                printf("  Programa finalizado. \n");
                printf("\n");
            break;
        }

    } while (op != 0);

    return 0;
}
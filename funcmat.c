
#include <stdio.h>
#include "funcmat.h"
// função que verifica o resultado e informa o quadrante que o ponto pertence
void quadrante (float x, float y){

    if (x >= 0 && y >= 0) {
        printf("  No ponto P(%.2f, %.2f) que pertence ao primeiro quadrante. \n", x, y);
    }
    else if (x <= 0 && y >= 0) {
        printf("  No ponto P(%.2f, %.2f) que pertence ao segundo quadrante. \n", x, y);
    }
    else if (x <= 0 && y <= 0) {
        printf("  No ponto P(%.2f, %.2f) que pertence ao terceiro quadrante. \n", x, y);
    }
    else if (x >= 0 && y <= 0) {
        printf("  No ponto P(%.2f, %.2f) que pertence ao quarto quadrante. \n", x, y);
    }
    return;
}

// função que verifica como a reta do grafico vai ser crescente, decrescente ou constante.
void verificareta (float a) {

    if (a > 0) {
        printf("  Por uma reta crescente.\n");
    }
    else if (a < 0) {
        printf("  Por uma reta decrescente.\n");
    }
    else if (a == 0) {
        printf("  Por uma reta constante. \n");
    }
    return;
}
// função que efetua a resolução da expressão Y = AX + B
float soma (float a, float b, float x) {

    double y = 0;
    // formula que resolve a função se a * x estiver somando b.
    if (b < 0) {
        b = b * (-1);
        y = (a * x) - b;
        b = b * (-1);
    }
    // formula para resolver a função se a * x estiver subtraindo b.
    else {
        y = (a * x) + b;
    }
    return y;
}
//função que efetua a resolução da expressão Y = AX + B com fração.
float somafracao (float num, float den, float x , float z, int op3) {

    float y = 0;
    // Resolve a função se o valor de B for uma fração, B é representado por NUM e DEN.
    if (op3 == 2) {
       /*se o X for 0, NUM vai ser atribuido no Y que vai ter como retorno Y/DEN
       que representa o potno Y por onde a reta passa */
        if (x == 0) {
            y = num / den;
        }
        /* nesse caso como NUM está representando B e com ele é o ultimo elemento da função,
        se caso ele for negativo usamos a expressão NUM = NUM * (-1) para que ele fique positivo, para que assim
        possamos subitrair ele depois dentro da espressão ax - b, se não fizer isso vamos ter
        como resultado um número positivo ao invés de um número negativo*/
        else if  (num < 0){
            num = num * (-1);
            z = z * x * den;
            y = (z + num) / den;
        }
        // se NUM for positivo segue a expressão, lembrando que Z representa A e NUM representa B nessa função.
        else {
            z = z * x * den;
            y = (z + num) / den;
        }
    }
    // Resolve a função se o valor de A for uma fração, A é representado por NUM e DEN.
    if (op3 == 1) {
        /*se o X for 0, NUM vai ser atribuido no Y que vai ter como retorno Y/DEN
       que representa o potno Y por onde a reta passa */
        if (x == 0) {
           y = z;
        }
        else if (x == 1) {
            y = (z + num) / den;
        }
        /* nesse caso como Z está representando B e como ele é o ultimo elemento da função,
        se caso ele for negativo usamos a expressao Z = Z * (-1) para que ele fique positivo, para que assim
        possamos subitrair ele depois dentro da espressão ax - b, se não fizer isso vamos ter
        como resultado um número positivo ao invés de um número negativo*/
        else if  (z < 0 ){
            z = z * (-1);
            num = num * x;
            y = (num - z) / den;

        }
        // se Z for positivo segue a expressão, lembrando que NUM representa Ae Z representa B nessa função.
        else{
            num = num * x;
            y = (num + z) / den;
        }
    }
    return y;
}


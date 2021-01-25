//Breve descrição da blibioteca


#define FUNCMAT_H_INCLUDED
#ifdef FUNCMAT_H_INCLUDED


// função que verifica o resultado e informa o quadrante que o ponto pertence
void quadrante (float x, float y);

// função que verifica como a reta do grafico vai ser crescente, decrescente ou constante.
void verificareta (float a);

// função que efetua a resolução da expressão Y = AX + B
float soma (float a, float b, float x);

//função que efetua a resolução da expressão Y = AX + B com fração.
float somafracao (float num, float den, float x , float z, int op3);

#endif
#include <stdio.h>

void funcaoNormal(int parametro)
{
    parametro = 1;
}

void funcaoPonteiro(int *parametro)
{
    *parametro = 1;
}

int main()
{
    int i = 0;
    printf("\nValor de i antes das funcoes %i", i);
    funcaoNormal(i);
    printf("\nValor de i depois e funcaoNormal %i", i);
    funcaoPonteiro(&i);
    printf("\nValor de i funcaoPonteiro %i", i);
}
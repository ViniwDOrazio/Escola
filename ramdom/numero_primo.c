/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    srand(time(NULL));   // Initialization, should only be called once.
    int numero = rand() % 100001; //929
    int operacoes = 1;
    bool primo = ((!(numero % 2 == 0)) || (numero < 2));
    int divisivelPor = 2;

    if (primo) {
        for (int i = 3; i < numero / 2; i = i + 2) {
            operacoes++;
            primo = (! (numero % i == 0));
            if (!primo) {
                divisivelPor = i;
                break;
            }
        }
    }
    if (primo){
        printf("%d É Primo, descobri em %d passos\n", numero,  operacoes);
    }
    else{
        printf("%d Não é Primo, divisivel por %d, descobri em %d passos\n", numero, divisivelPor, operacoes);
    }
    return 0;
}

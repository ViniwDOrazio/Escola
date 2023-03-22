#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void imprimirVetor(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void mesclarEContarInversoes(int vetor[], int inicioEsquerda, int finalEsquerda, int inicioDireita, int finalDireita, int *inversoesNoVetor)
{
    int tamanhoEsquerda = (finalEsquerda - inicioEsquerda) + 1;
    int tamanhoDireita = (finalDireita - inicioDireita) + 1;

    int esquerda[tamanhoEsquerda], direita[tamanhoDireita];

    for (int i = 0; i < tamanhoEsquerda; i++)
        esquerda[i] = vetor[inicioEsquerda + i];
        
    for (int i = 0; i < tamanhoDireita; i++)
        direita[i] = vetor[inicioDireita + i];

    int iEsq = 0, iDir = 0, i = inicioEsquerda;
    bool copiouTodaEsquerda = (!(iEsq < tamanhoEsquerda));
    bool copiouTodaDireita = (!(iDir < tamanhoDireita));

    while ((!copiouTodaEsquerda) || (!copiouTodaDireita))
    {
        bool proximoAhDireita = copiouTodaEsquerda;
        if ((! proximoAhDireita) && (! copiouTodaDireita))
            proximoAhDireita = (direita[iDir] < esquerda[iEsq]);

        if (! proximoAhDireita)
        {
            vetor[i] = esquerda[iEsq];

            iEsq++;
            copiouTodaEsquerda = (!(iEsq < tamanhoEsquerda));
        }
        else
        {
            vetor[i] = direita[iDir];

            iDir++;
            if (!copiouTodaEsquerda)
                *inversoesNoVetor = *inversoesNoVetor + (tamanhoEsquerda - iEsq);
                
            copiouTodaDireita = (!(iDir < tamanhoDireita));
        }
        i++;
    }
}

void ordenarEContarInversoes(int vetor[], int inicio, int final, int *trocasEfetuadas)
{
    if (inicio < final)
    {
        int meio = inicio + (final - inicio) / 2;

        ordenarEContarInversoes(vetor, inicio, meio, trocasEfetuadas);
        ordenarEContarInversoes(vetor, meio + 1, final, trocasEfetuadas);

        mesclarEContarInversoes(vetor, inicio, meio, meio + 1, final, trocasEfetuadas);
    }
}

int main()
{
    //Autor: Vinícius Mosna D'Orazio
    // Dos algoritmos estudados o merge sort possui a complexidade O(nlog2(n)), entretanto o caminho que segue não é o de inverter elemento a 
    //elemento, se assim o fizesse a complexidade provavelmente passaria a ser O(n²).
    // Para adapta-lo sem mudar a complexidade basta adicionar uma variável que conte a quantidade de inversões que seriam feitas no momento 
    //em que algoritmo faz a mesclagem dos vetores de esquerda e direita
    // O algoritmo adaptado seria basicamente o mesmo do mergesort com a adição de uma entrada/saída, que é o número de inversões necessárias
    //e seria necessário trocar a função mesclar para que uma que faça o mesmo e faça a contagem.
    //
    // Como não há um pseudocódigo do mesclar a alteração seria sempre que for pego um valor do vetor a direita a quantidade de elementos do 
    //vetores a esquerda que ainda não estiverem sido reescritos no vetor principal é somada como elementos de inversão.
    //
    //
    // Pseudocoódigo adaptado do ebook
    //
    // Algoritmo:  ordenarEContarInversoes
    // Entrada: Um vetor A[0 .. n - 1] de elementos ordenáveis e um inteiro que conte as inversoes
    //  Saída: Vetor A[0 .. n – 1] ordenado de maneira crescente e um  inteiro que conte as inversoes
    // 1.    se n > 1 então
    // 2.        Copiar A[0 .. ?n/2? - 1] para B[0 .. ?n/2? - 1]
    // 3.        Copiar A[?n/2? .. n - 1] para C[0 .. ?n/2? - 1]
    // 4.        ordenarEContarInversoes(B[0 .. ?n/2? - 1], inversoes)
    // 5.        ordenarEContarInversoes(C[0 .. ?n/2? - 1], inversoes)
    // 6.        MesclarEContarInversoes(B, C, A, inversoes)

    //Testes realizados
    // Exemplo 1: {1, 3, 5, 2, 4, 6}; 3 troca 1 e 5 troca 2 = 3(apostila)
    // Exemplo 2: {2, 4, 6, 1, 3, 5}; 1 troca 3,  3 troca 2 e 5 troca 1 = 6 inversões
    // Exemplo 3: {5, 1, 3, 6, 2, 4}; 5 e 6 trocam 2  + Exemplo 1 = 7
    // Exemplo 4: {6, 2, 4, 5, 1, 3}; 5 e 6 trocam 2  + Exemplo 2 = 10
    // Exemplo 5: {5, 3, 1, 6, 4, 2}; 5 e 6 trocam 2, 3 e 4 trocam 1  + exemplo 1 =  9
    // Exemplo 6: {6, 4, 2, 5, 3, 1}; 5 e 6 trocam 2, 3 e 4 trocam 1  + exemplo 2 =  12
    // Exemplo 7: {1, 2, 3, 4, 5, 6}; não troca =  0
    // Exemplo 8: {6, 5, 4, 3, 2, 1}; 6 e 3 trocam 2, 5 e 2 trocam 1 + 3 * 3 = 9 + 6 = 15 
    int vetorInicial[] = {1, 3, 5, 2, 4, 6};
    int tamanhoVetor = sizeof(vetorInicial) / sizeof(vetorInicial[0]);

    int inversoesNoVetor = 0;

    setlocale(LC_ALL, "Portuguese");

    printf("Vetor inícial:  \n");
    imprimirVetor(vetorInicial, tamanhoVetor);

    ordenarEContarInversoes(vetorInicial, 0, tamanhoVetor - 1, &inversoesNoVetor);

    printf("\nVetor ordenado: \n");
    imprimirVetor(vetorInicial, tamanhoVetor);

    printf("\nInversões no vetor: %d\n", inversoesNoVetor);

    return 0;
}
/************************************************************************************************************/
/*** DESCRICAO DO EXERCÍCIO                                                                              ****/
/************************************************************************************************************/
/*** Caro estudante,Em linguagens de programação estruturadas, tal como a linguagem C/C++ temos a        ****/
/*** possibilidade de organizar as informações a serem manipuladas sob dois aspectos: organização        ****/
/*** possibilidade de organizar as informações a serem manipuladas sob dois aspectos: organização        ****/
/*** homogênea e organização heterogênea. No viés homogêneo, todas as informações, possuidoras de um     ****/
/*** único tipo de dados, estão dispostas em uma estrutura denominada vetor. E, por sua vez, no viés     ****/
/*** heterogêneo, as informações, podendo possuir tipagens distintas, estão armazenadas em estruturas de ****/
/*** dados denominadas como “struct”.Com base nisso, suponha que é necessário armazenar informações      ****/
/*** relacionadas à veículos, totalizando, no máximo, 10 veículos. Para cada veículo, deverão ser        ****/
/*** fornecidos os seguintes dados:- marca do veículo- modelo - ano de fabricação- placa (formato        ****/
/*** XXX-YYYY; onde X denota as letras e Y denota os números da placa).                                  ****/
/*** O sistema deverá oferecer, ao usuário, as seguintes funcionalidades:                                ****/
/***    - Listar os veículos cadastrados;                                                                ****/
/***    - Inserir um novo veículo;                                                                       ****/
/***    - Listar os veículos filtrando-se por ano de fabricação;                                         ****/
/***    - Listar os veículos com o ano de fabricação acima de um certo valor especificado pelo usuário.  ****/
/***    - Listar os veículos filtrando-se pelo modelo.                                                   ****/ 
/*** O sistema deverá armazenar os veículos ordenados pelo ano de fabricação, ou seja, ao inserir um novo****/
/*** veículo, este deve ser inserido em ordem crescente de ano de fabricação.                            ****/
/*** Referência DEITEL, P. J.; DEITEL, H. C: Como Programar. 6. ed. São Paulo: Pearson Prentice Hall,    ****/
/*** 2011. [Recurso eletrônico, Biblioteca Virtual Universitária]                                        ****/
/************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#define TAMANHO_PADRAO 51
#define TAMANHO_PLACA 9
#define OPCAO_LISTAR 1
#define OPCAO_CADASTRAR 2
#define OPCAO_BUSCAR_ANO 3
#define OPCAO_BUSCAR_ANO_ACIMA 4
#define OPCAO_BUSCAR_MODELO 5
#define OPCAO_SAIR 6
#define QUANTIDADE_CARROS 10

struct veiculo
{
    char modelo[TAMANHO_PADRAO];
    char marca[TAMANHO_PADRAO];
    char placa[TAMANHO_PLACA];
    int ano;
} Veiculo;

struct veiculo ListaVeiculos[QUANTIDADE_CARROS];
int ProximoLista = 0;

int imprimirMenu();
void imprimirCarro(struct veiculo carro);
void removerQuebraLinha(char* Texto);
struct veiculo lerVeiculo();
void cadastrarCarro();
void ordenarLista();
void menu(int Opcao);
int main();
void limparTela();
void esperarInteracao();

void limparTela()
{
    system("cls");
}

void esperarInteracao()
{
    printf("\n");
    system("pause");
}

int imprimirMenu()
{
    limparTela();
    printf("\n============== SISTEMA DE LOCAÇÃO DE VEÍCULOS ================");
    printf("\n========================== MENU ==============================");
    printf("\n%i. Para Listar o(s) Veículo(s) cadastrado(s): ", OPCAO_LISTAR) ;
    printf("\n%i. Para cadastrar um Veículo: ", OPCAO_CADASTRAR);
    printf("\n%i. Para buscar Veículo por ano de fabricação: ", OPCAO_BUSCAR_ANO);
    printf("\n%i. Para buscar o(s) Veículo(s) acima do ano de fabricação especificado: ", OPCAO_BUSCAR_ANO_ACIMA);
    printf("\n%i. Para buscar o(s) modelo(s) do(s) Veículo(s): ", OPCAO_BUSCAR_MODELO);
    printf("\n%i. Para sair do menu: ", OPCAO_SAIR);
    printf("\n=============================================================");
    printf("\nOpção: ");
    int retorno;
    fflush(stdin);
    scanf("%i", &retorno);
    return retorno;
}

void imprimirCarro(struct veiculo carro)
{
    printf("\n%s (%i) - %s, placa %s\n", carro.modelo, carro.ano, carro.marca, carro.placa);
}

void imprimirLista(int OpcaoSelecionada)
{
    int ano;
    char modelo[TAMANHO_PADRAO];

    switch (OpcaoSelecionada)
    {
        case OPCAO_BUSCAR_ANO:
        case OPCAO_BUSCAR_ANO_ACIMA:
            printf("Digite o Ano:");
            scanf("%i", &ano);
        break;
        case OPCAO_BUSCAR_MODELO:
            printf("Digite o Modelo:");
            fflush(stdin);
            fgets(modelo, TAMANHO_PADRAO, stdin);
            removerQuebraLinha(modelo);
        break;
    }

    int QuantidadeImpressos = 0;
    for (int i = 0; (i < ProximoLista); i++)
    {
        bool PodeImprimir = true;

        switch (OpcaoSelecionada)
        {
            case OPCAO_BUSCAR_ANO:
                PodeImprimir = (ListaVeiculos[i].ano == ano);
            break;
            case OPCAO_BUSCAR_ANO_ACIMA:
                PodeImprimir = (ListaVeiculos[i].ano > ano);
            break;
            case OPCAO_BUSCAR_MODELO:
                PodeImprimir = (strcmp(strupr(modelo), strupr(ListaVeiculos[i].modelo)) == 0);
            break;
        }

        if (PodeImprimir)
        {

            imprimirCarro(ListaVeiculos[i]);
            QuantidadeImpressos++;
        }
    }
    if (QuantidadeImpressos == 0)
        printf("\nNenhum carro a imprimir.");

    esperarInteracao();
}

void removerQuebraLinha(char* Texto)
{
    size_t Ultimo = strlen(Texto) - 1;
    if (*Texto && Texto[Ultimo] == '\n') 
        Texto[Ultimo] = '\0';
    
}

struct veiculo lerVeiculo()
{
    struct veiculo Retorno;
    printf("\nDigite a modelo do veículo: ");
    fflush(stdin);
    fgets(Retorno.modelo, TAMANHO_PADRAO, stdin);

    printf("\nDigite a marca do veículo: ");
    fflush(stdin);
    fgets(Retorno.marca, TAMANHO_PADRAO, stdin);

    printf("\nDigite a placa do veículo (AAA-1111): ");
    fflush(stdin);
    fgets(Retorno.placa, TAMANHO_PLACA, stdin);

    printf("\nDigite o ano do veículo: ");
    scanf("%i", &Retorno.ano);

    removerQuebraLinha(Retorno.modelo);
    removerQuebraLinha(Retorno.marca);
    removerQuebraLinha(Retorno.placa);

    return Retorno;
}

void cadastrarCarro()
{
    if ((ProximoLista) >=  QUANTIDADE_CARROS)
    {
        printf("\nLista limitada a %i", QUANTIDADE_CARROS);
        esperarInteracao();
    }
    else
    {
        struct veiculo veiculo = lerVeiculo();
        ListaVeiculos[ProximoLista] = veiculo;
        ProximoLista++;
        ordenarLista();
    }
}

void ordenarLista()
{
    for (int i = 0; i < ProximoLista; i++)
    {
        for (int j = i; j < ProximoLista; j++)
        {
            if (ListaVeiculos[i].ano > ListaVeiculos[j].ano)
            {
                struct veiculo aux = ListaVeiculos[i];
                ListaVeiculos[i] = ListaVeiculos[j];
                ListaVeiculos[j] = aux;
            }
        }
    }
}

void menu(int Opcao)
{
    limparTela();
    switch (Opcao)
    {
        case OPCAO_CADASTRAR:
            cadastrarCarro();
        break;
        case OPCAO_LISTAR:
        case OPCAO_BUSCAR_ANO:
        case OPCAO_BUSCAR_ANO_ACIMA:
        case OPCAO_BUSCAR_MODELO:
            imprimirLista(Opcao);
        break;
        case OPCAO_SAIR:
        break;
        default:
            printf("Opção inválida.");
            esperarInteracao();
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int OpcaoMenu = 0;
    do
    {
        fflush(stdin);
        OpcaoMenu = imprimirMenu();
        menu(OpcaoMenu);
    } while (OpcaoMenu != OPCAO_SAIR);

    return 0;
}
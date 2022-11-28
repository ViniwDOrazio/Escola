/*************************************************************************************************************/
/**** DESCRICAO DO EXERCÍCIO                                                                              ****/
/*************************************************************************************************************/
/**** Em algumas situações, para a implementação de um sistema computacional, não se conhece, previamente,****/
/**** qual o tamanho da massa de dados que será efetivamente manipulada. Em tais casos, pode ser usado o  ****/
/**** recurso de alocação dinâmica de memória. Com tal recurso, uma região de memória poderá ser alocada, ****/
/**** sob demanda de modo a tornar o programa mais flexível em relação à quantidade de itens a serem      ****/
/**** manipulados. Essa flexibilidade torna o programa escalável.                                         ****/
/****                                                                                                     ****/
/**** O objetivo desta questão é exercitar a manipulação de ponteiros em um cenário onde se exige a       ****/
/**** alocação dinâmica de memória através da implementação de um programa computacional.                 ****/
/****                                                                                                     ****/
/**** Antes de falarmos das funcionalidades do programa a ser implementado, convém mencionar que, em      ****/
/**** algumas situações o espaço previamente alocado deve ser redimensionado devido, à por exemplo, um    ****/
/**** aumento ou diminuição inesperada na quantidade de itens manipulados. Para realizar o                ****/
/**** redimensionamento, pode-se, na linguagem C, utilizar a função “realloc()”. Essa função segue a      ****/
/**** seguinte sintaxe:                                                                                   ****/
/****                                                                                                     ****/
/****     void *realloc (void *ptr_original, size_t);                                                     ****/
/****                                                                                                     ****/
/**** A função “realloc()” retorna a posição do bloco realocado com a nova dimensão. No trecho de código  ****/
/**** acima, o parâmetro “ptr_original” representa o bloco previamente alocado com a função “malloc()” ou ****/
/**** “calloc()”. Detalhes destas funções, inclusive a “realloc()” poderão ser obtidas acessando-se       ****/
/****(GARCIA, 2016) através do link: <https://www.embarcados.com.br/ponteiro-em-c-alocacao-dinamica/>.    ****/
/****                                                                                                     ****/
/**** Para a realização desta atividade, suponha a necessidade de cadastrar clientes de uma loja. Por ser ****/
/**** uma loja nova e com produtos inovadores, pouco se sabe do mercado a ser atingido, sendo assim, não  ****/
/**** se sabe a quantidade de clientes poderão ser cadastrados. Estima-se, inicialmente, em 10 clientes.  ****/
/**** Cada cliente terá os seguintes campos:                                                              ****/
/****     - nome (suponha um nome com, no máximo, 30 caracteres)                                          ****/
/****     - ano de nascimento                                                                             ****/
/****     - montante de gastos realizados no mês (quanto o clinte pagou em suas compras dentro do mês     ****/
/****       corrente)                                                                                     ****/
/****                                                                                                     ****/
/**** Para tanto, o sistema deverá oferecer as seguintes funcionalidades:                                 ****/   
/****     - incluir um novo cliente                                                                       ****/
/****     - remover cliente                                                                               ****/
/****     - atualizar o montante de compras do cliente realizadas no mês corrente                         ****/
/****     - zerar todos os montantes de compras por ocasião da virada de mês                              ****/
/****     - listar o cliente melhor comprador                                                             ****/
/****     - exibir um montante de compras de um cliente específico.                                       ****/
/****                                                                                                     ****/
/**** O programa deverá, ainda, prever a situação que a quantidade de clientes a ser cadastrados supere a ****/
/**** previsão inicial. Neste caso, quando o espaço de memória destinado a receber dados dos clientes     ****/
/**** estiver cheia, deve-se ampliar esse espaço - sempre em blocos de 10.                                ****/
/**** Poste o código, implementado em C, em seu portfólio.                                                ****/
/************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#define TAMANHO_NOME 31
#define QUANTIDADE_INICIAL_CLIENTES 10
#define QUANTIDADE_EXPANCAO_CLIENTES 10

#define OPCAO_INCLUIR_CLIENTE 1
#define OPCAO_REMOVER_CLIENTE 2
#define OPCAO_ATUALIZAR_COMPRAS_CLIENTE 3
#define OPCAO_VIRAR_MES 4
#define OPCAO_TOP_3_COMPRADORES 5
#define OPCAO_CONSULTAR_COMPRAS_CLIENTE 6
#define OPCAO_SAIR 7

struct cliente
{
    char nome[TAMANHO_NOME];
    int ano;
    float valorGasto;
} Cliente;

int TamanhoLista = QUANTIDADE_INICIAL_CLIENTES, ProximoLista = 0;
struct cliente ListaClientes[QUANTIDADE_INICIAL_CLIENTES];

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
    printf("\n========================== MENU ==============================");
    printf("\n%i - Novo Cliente", OPCAO_INCLUIR_CLIENTE);
    printf("\n%i - Excluir Cliente", OPCAO_REMOVER_CLIENTE);
    printf("\n%i - Atualizar Compras", OPCAO_ATUALIZAR_COMPRAS_CLIENTE);
    printf("\n%i - Zerar Compras (Virar Mês)", OPCAO_VIRAR_MES);
    printf("\n%i - Melhores Compradores", OPCAO_TOP_3_COMPRADORES);
    printf("\n%i - Montante Gasto Pelo Cleinte", OPCAO_CONSULTAR_COMPRAS_CLIENTE);
    printf("\n%i - Sair", OPCAO_SAIR);
    printf("\n=============================================================");
    printf("\nOpção: ");
    int retorno;
    fflush(stdin);
    scanf("%i", &retorno);
    return retorno;
}

void removerQuebraLinha(char* Texto)
{
    size_t Ultimo = strlen(Texto) - 1;
    if (*Texto && Texto[Ultimo] == '\n') 
        Texto[Ultimo] = '\0';
}
struct cliente lerCliente()
{
    struct cliente Retorno;
    printf("\nNome: ");
    fflush(stdin);
    fgets(Retorno.nome, TAMANHO_NOME, stdin);
    removerQuebraLinha(Retorno.nome);

    printf("\nAno Nascimento: ");
    scanf("%i", &Retorno.ano);

    Retorno.valorGasto = 0;

    return Retorno;
}

void cadastrarCliente()
{

    if (ProximoLista >= TamanhoLista)
    {
        TamanhoLista += QUANTIDADE_EXPANCAO_CLIENTES;
        realloc(ListaClientes, TamanhoLista);
    }

    struct cliente clienteNovo = lerCliente();
    ListaClientes[ProximoLista] = clienteNovo;
    ProximoLista++;
}

void imprimirLista()
{
    for (int i = 0; i <= ProximoLista - 1; i++)
        printf("\n%i - %s\n", i, strupr(ListaClientes[i].nome));
}

void excluirCliente()
{
    if (ProximoLista == 0)
    {
        printf("\nLista Vazia\n");
        esperarInteracao();
    }
    else
    {
        printf("\nQual cliente deseja Excluir?\n");

        imprimirLista();

        printf("\nDigite o Indice para Excluir: ");

        int IndiceSelecionado = -1;
        scanf("%i", &IndiceSelecionado);

        if ((IndiceSelecionado >=0) && (IndiceSelecionado <= ProximoLista))
        {
            for (int i = IndiceSelecionado; i <= ProximoLista - 1 ; i++)
                ListaClientes[i] = ListaClientes[i + 1];

            ProximoLista--;
        }
        else
        {
            printf("\nIndice Fora da Lista\n");
            esperarInteracao();
        }
    }
}

void AtualizarComprasCliente()
{
    if (ProximoLista == 0)
    {
        printf("\nLista Vazia\n");
        esperarInteracao();
    }
    else
    {
        printf("\nQual Cliente deseja Adicionar uma Compra?\n");

        imprimirLista();

        int indiceSelecionado = -1;
        scanf("%i", &indiceSelecionado);

        if ((indiceSelecionado >=0) && (indiceSelecionado <= ProximoLista))
        {
            printf("\nO cliente \"%s\" gastou %.2f nesse mês, digite o valor da nova compra: ", strupr(ListaClientes[indiceSelecionado].nome), ListaClientes[indiceSelecionado].valorGasto);

            float valor;
            scanf("%f", &valor);

            ListaClientes[indiceSelecionado].valorGasto += valor;
        }
        else
        {
            printf("\nIndice Fora da Lista\n");
            esperarInteracao();
        }
    }
}

void VirarMes()
{
    if (ProximoLista == 0)
    {
        printf("\nLista Vazia\n");
        esperarInteracao();
    }
    else
    {
        for (int i = 0; i <= ProximoLista - 1 ; i++)
            ListaClientes[i].valorGasto = 0;
    }
}

void ListarTop3()
{
    if (ProximoLista == 0)
    {
        printf("\nLista Vazia\n");
        esperarInteracao();
    }
    else
    {
        int Maior = -1, SegundoMaior = -1, TerceiroMaior = -1;

        for (int i = 0; i <= ProximoLista - 1 ; i++)
        {
            if (Maior == -1)
                Maior = i;
            else
            {
                if (ListaClientes[i].valorGasto > ListaClientes[Maior].valorGasto)
                {
                    TerceiroMaior = SegundoMaior;
                    SegundoMaior = Maior;
                    Maior = i;
                }
                else
                if (SegundoMaior == -1)
                    SegundoMaior = i;
                else
                {
                    if (ListaClientes[i].valorGasto > ListaClientes[SegundoMaior].valorGasto)
                    {
                        TerceiroMaior = SegundoMaior;
                        SegundoMaior = i;
                    }
                    else
                    if (TerceiroMaior == -1)
                        TerceiroMaior = i;
                    else
                    {
                        if (ListaClientes[i].valorGasto > ListaClientes[TerceiroMaior].valorGasto)
                            TerceiroMaior = i;
                    } 
                } 
            }
        }

        if (Maior > -1)
            printf("\n1 - O cliente \"%s\" gastou %.2f nesse mês", strupr(ListaClientes[Maior].nome), ListaClientes[Maior].valorGasto);

        if (SegundoMaior > -1)
            printf("\n2 - O cliente \"%s\" gastou %.2f nesse mês", strupr(ListaClientes[SegundoMaior].nome), ListaClientes[SegundoMaior].valorGasto);

        if (TerceiroMaior > -1)
            printf("\n3 - O cliente \"%s\" gastou %.2f nesse mês", strupr(ListaClientes[TerceiroMaior].nome), ListaClientes[TerceiroMaior].valorGasto);

        esperarInteracao();
    }
}

void ConsultarComprasClientes()
{
    if (ProximoLista == 0)
    {
        printf("\nLista Vazia\n");
        esperarInteracao();
    }
    else
    {
        printf("\nSelecione o cliente\n");

        imprimirLista();

        int indiceSelecionado = -1;
        scanf("%i", &indiceSelecionado);

        if ((indiceSelecionado >=0) && (indiceSelecionado <= ProximoLista))
        {
            printf("\nO cliente \"%s\" gastou %.2f nesse mês, digite o valor da nova compra: ", strupr(ListaClientes[indiceSelecionado].nome), ListaClientes[indiceSelecionado].valorGasto);
            esperarInteracao();
        }
        else
        {
            printf("\nIndice Fora da Lista\n");
            esperarInteracao();
        }
    }
}

void menu(int Opcao)
{
    limparTela();
    switch (Opcao)
    {
        case OPCAO_INCLUIR_CLIENTE:
            cadastrarCliente();
        break;
        case OPCAO_REMOVER_CLIENTE:
            excluirCliente();
        break;
        case OPCAO_ATUALIZAR_COMPRAS_CLIENTE:
            AtualizarComprasCliente();
        break;
        case OPCAO_VIRAR_MES:
            VirarMes();
        break;
        case OPCAO_TOP_3_COMPRADORES:
            ListarTop3();
        break;
        case OPCAO_CONSULTAR_COMPRAS_CLIENTE:
            ConsultarComprasClientes();
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
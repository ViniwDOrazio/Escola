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

// includes que foram utilizados
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

// Definição de constantes, ao escrever um código a leitura para futura manutenção fica mais fácil quando temos um texto, por isso optei por usar por exemplo OPCAO_LISTAR em vez de 1
#define TAMANHO_PADRAO 51
#define TAMANHO_PLACA 9
#define OPCAO_LISTAR 1
#define OPCAO_CADASTRAR 2
#define OPCAO_BUSCAR_ANO 3
#define OPCAO_BUSCAR_ANO_ACIMA 4
#define OPCAO_BUSCAR_MODELO 5
#define OPCAO_SAIR 6
#define QUANTIDADE_CARROS 10

// Estrutura do veículo
struct veiculo
{
    char modelo[TAMANHO_PADRAO];
    char marca[TAMANHO_PADRAO];
    char placa[TAMANHO_PLACA];
    int ano;
} Veiculo;

// variáveis globais
// lista de carros
struct veiculo ListaVeiculos[QUANTIDADE_CARROS];
//proximo cadastro disponível
int ProximoLista = 0;

//Esse trexo parece estranho, mas como eu usei funções se não colocasse a declaração delas aqui a compilação me retorna um alerta
// para entender, aqui é só a primeira linha da função sem a implementação, serve pro compilador saber previamente quais as funções do arquivo
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

//implementação

//tem 2 caminhos, 
// - ir igual um computador, nesse caso comece pela função main, lá no fim
// - ir igual um humano, e continuar lendo linha a linha esse conteúdo
// dos dois jeitos da certo, mas no segundo se atente apenas que como eu estou trabalhando com funções saibe que os blocos só são executados quando são chamados

// função limparTela(), repare que o nome é auto explicativo kkkk
void limparTela()
{
    system("cls"); // e repare que esse recurso não é do c, ele está executando o prompt de comando, vc pode executar isso dentro do cmd
}

// função esperarInteração() quando chamo ela quero que o terminal fique parado até que o usuário aperte algo
void esperarInteracao()
{
    printf("\n"); // adicionei uma quebra de linha pq o pause vem acompanhado da mensagem: "Pressione qualquer tecla para continuar. . ."
                  // e essa mensagem vai na sequencia do que estiver lá
    system("pause");// o pause é o mesmo do cmd
}

//função imprimirMenu() novamente o nome auto explicativo, essa função imprime o menu
int imprimirMenu() // quer dizer ela também espera a seleção, eu poderia ter especificado isso no nome ou ter criado uma função mais especifica em pró da clareza? sim mas não fiz
{
    limparTela(); // antes de imprimir ele limpa a tela através da função
    printf("\n============== SISTEMA DE LOCAÇÃO DE VEÍCULOS ================");
    printf("\n========================== MENU ==============================");
    printf("\n%i. Para Listar o(s) Veículo(s) cadastrado(s): ", OPCAO_LISTAR) ;
    printf("\n%i. Para cadastrar um Veículo: ", OPCAO_CADASTRAR);
    printf("\n%i. Para buscar Veículo por ano de fabricação: ", OPCAO_BUSCAR_ANO);
    printf("\n%i. Para buscar o(s) Veículo(s) acima do ano de fabricação especificado: ", OPCAO_BUSCAR_ANO_ACIMA);
    printf("\n%i. Para buscar o(s) modelo(s) do(s) Veículo(s): ", OPCAO_BUSCAR_MODELO);
    printf("\n%i. Para sair do menu: ", OPCAO_SAIR);
    printf("\n=============================================================");
    //compliquei um pouco a impressão a mais a impressão, mas note que eu sei a OPCAO_LISTAR se refere a opção que lista os vaículos, é muito mais fácil de fazer essa associação mental
    // se eu deixar, por exemplo 1. Função eu tenho que toda hora voltar aqui nesse menu pra lembrar o que é o que
    //por exemplo, sem olhar, qual opção imprime os carros do ano de fabricação?
    // no meu código eu não preciso saber, epor iniciar igual, ao precisar dele posso só começar a digitar e encontrar na lista de sugestões qual nome se parece
    // mais com o que quero usar

    //Lê a opção que o usuário digitar
    printf("\nOpção: ");
    int retorno;
    fflush(stdin);
    scanf("%i", &retorno);
    
    // não faz nada com o que o usuário digitou, só manda de volta pra quem chamou a função
    return retorno;
}

// função imprimirCarro(), recebe um carro e imprime ele, sem segredos
void imprimirCarro(struct veiculo carro)
{
    // ah, fiz imprimir em uma linha só pq fica mais confortável de ler muita informação
    printf("\n%s (%i) - %s, placa %s\n", carro.modelo, carro.ano, carro.marca, carro.placa);
}

// Função imprimirLista(), existem 4 formas de imprimir a lista e essa função faz as 4, podia ser mais especializada? podia, mas ia ser meio repetitivo de mais 
void imprimirLista(int OpcaoSelecionada) // como estou imprimindo as 4 opções possíveis e a variavel opção não está disponível aqui eu preciso que quem chama essa 
                                         // função informe. 
{
    // declaro as variaveis que podem ser usadas como filtro
    int ano;
    char modelo[TAMANHO_PADRAO];

    //verifico se a opção do menu precisa preencher uma das opções acima
    switch (OpcaoSelecionada)
    {
        // caso a opção selecionada seja para listar modelos do ano, ou acima do ano o usuário precisa preencher o ano
        case OPCAO_BUSCAR_ANO:
        case OPCAO_BUSCAR_ANO_ACIMA:
            printf("Digite o Ano:");
            scanf("%i", &ano);
        break;

        //caso a opção selecionada seja para filtrar pelo Modelo o usuário precisa preencher o modelo
        case OPCAO_BUSCAR_MODELO:
            printf("Digite o Modelo:");
            fflush(stdin);
            fgets(modelo, TAMANHO_PADRAO, stdin);

            //chamo a função que tira aquele monte de quebra que fica no texto do fgets
            removerQuebraLinha(modelo);
        break;
    }
    
    // define a variável que vai contar quantos carros foram impressos
    int QuantidadeImpressos = 0;
    // o for percorre a lista de carros até chegar no ultimo cadastro disponível
    for (int i = 0; (i < ProximoLista); i++)
    {
        //declara a variável booleana para saber se pode ou não imprimir o vaículo corrente
        bool PodeImprimir = true; // inicia o entendimento como true, ou seja que sim, pode imprimir

        switch (OpcaoSelecionada) // verifica novamente de acordo com a opção e faz um teste pra cada opção que precisa de um teste
        {
            case OPCAO_BUSCAR_ANO:
                // se for essa opção o ano que é do carro tem que ser igual ao ano, caso for diferente o PodeImprimir passa a ser falso, ou seja não pode imprimir
                PodeImprimir = (ListaVeiculos[i].ano == ano);
                // quando estamos começando a escrever fontes acabamos tanto como a linha aqui em cima
                // normalmente esse fonte seria escrito assim
                //  if (ListaVeiculos[i].ano == ano)
                //      PodeImprimir = true;
                //  else
                //      PodeImprimir = false;
                // mas escrevendo assim estariamos sendo mais prolixos que o necessário, um if precisa de uma condição booleana para existir, e a variavel que eu criei também
            break;
            case OPCAO_BUSCAR_ANO_ACIMA:
                // se for essa opção o ano acima o ano maior qu o ano informado, caso seja menor ou igual o PodeImprimir passa a ser falso, ou seja não pode imprimir
                PodeImprimir = (ListaVeiculos[i].ano > ano);
            break;
            case OPCAO_BUSCAR_MODELO:
                // quando for buscar pelo modelo a comparação do texto modelo, precisa ser igual no informado do que está no veículo 
                PodeImprimir = (strcmp(strupr(modelo), strupr(ListaVeiculos[i].modelo)) == 0);
                // usei o strupr para não importar o case sencitive da digitação, sendo assim nesse caso CoRsA = cOrSa 
            break;
        }

        // note que a OPCAO_LISTAR não está em nenhum case, 
        // no primeiro deles pq quando é pra listar tudo não precisamos ler nenhuma variavel
        // e  no segundo pq como o padrão é que pode imprimir ao listar todos não precisamos alterar o padrão

        // se o pode imprimir continuar verdadeiro ele executa a ação, caso contrario não faz nada 
        if (PodeImprimir)
        {
            //caso possa imprimir manda o carro pra impressão 
            imprimirCarro(ListaVeiculos[i]);
            // e adiciona 1 na quantidade impressa
            QuantidadeImpressos++;
        }
    }
    //ao sair do for, se a quantidade impressa continuar 0 informamos o usuario
    if (QuantidadeImpressos == 0)
        printf("\nNenhum carro a imprimir.");

    // chama a função de esperar até que o usuario interaja
    esperarInteracao();
}

// void removerQuebraLinha(char* Texto)
//infelizmente não achei um jeito mais fácil de fazer isso aqui no C, por isso criei essa função, ela troca a ultima quebra de linha (\n) trocando por um arquivo de fim de linha (\0)
void removerQuebraLinha(char* Texto)
{
    size_t Ultimo = strlen(Texto) - 1;
    if (*Texto && Texto[Ultimo] == '\n') 
        Texto[Ultimo] = '\0';
}

//Função lerVeiculo(), ela literalmente retorna a struct veiculo, e para cada item ela pede pro usuario informar
struct veiculo lerVeiculo()
{
    // define a variavel retorno
    struct veiculo Retorno;
    //preenche
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

    //chamo a função que tira aquele monte de quebra que fica no texto do fgets
    removerQuebraLinha(Retorno.modelo);
    removerQuebraLinha(Retorno.marca);
    removerQuebraLinha(Retorno.placa);
    //acho que aqui vale a pena comentar do problema da quebra de linha
    // meu printf é assim:
    // printf("\n%s (%i) - %s, placa %s\n", carro.modelo, carro.ano, carro.marca, carro.placa);
    // antes de usar essa função ele ficava 
    //o resultado era assim
    // modelo
    //(2022) - 
    //marca
    //, placa placa
    //
    //depois dessa função ele imprime: 
    // modelo (2022) - marca, placa placa

    //devolve esse para quem chamou ele
    return Retorno;
}

//Função cadastrarVeiculo(), já leu no nome né kkk
void cadastrarCarro()
{
    // se o proximo disponível for 10 quer dizer que do 0 ao 9 já foi
    if ((ProximoLista) >=  QUANTIDADE_CARROS)
    {
        //caso não tem como cadastrar informa o usuario e 
        printf("\nLista limitada a %i", QUANTIDADE_CARROS);
        // chama a função de esperar até que o usuario interaja
        esperarInteracao();
    }
    else
    {
        //caso tenha espaço para cadastrar ele obtem a leiturara da função especializada em obter o veiculo do usuario
        struct veiculo veiculo = lerVeiculo();
        // e adiciona esse veiculo no fim da lista
        ListaVeiculos[ProximoLista] = veiculo;
        // aumenta o numero do proximo do proximo espaço vago na lista
        ProximoLista++;
        // e por fim pede pra uma função especializada ordenar a lista
        ordenarLista();
    }
}

//Função ordenarLista()
void ordenarLista()
{
    //faz um for I do começo ao utimo numero preenchido
    for (int i = 0; i < ProximoLista; i++)
    {
        //faz um for J do i ao utimo numero preenchido
        for (int j = i; j < ProximoLista; j++)
        {
            //compara o ano do veiculo em i com o ano do veiculo em j
            if (ListaVeiculos[i].ano > ListaVeiculos[j].ano)
            {
                //se o ano de i for maior que o de j ele inverte, pra inverter duas variaveis sempre precisa de 3
                struct veiculo aux = ListaVeiculos[i]; // no caso uma que receba o valor original, no caso o valor de i
                ListaVeiculos[i] = ListaVeiculos[j];   // feito isso uma das variaveis pode ser sobre escrita, no caso j joga seu valor em i
                ListaVeiculos[j] = aux;                // e por fim o valor original é jogado em j
            }
        }
    }
}

//função menu, executa alguma coisa de acordo com a opção enviada
void menu(int Opcao)
{
    // independente do que for ser executado limpa a tela antes
    limparTela();
    //faz um switch na opção de menu selecionada
    switch (Opcao)
    {
        case OPCAO_CADASTRAR:
            //caso seja a opção de cadastro chama função especializada em fazer de cadastro
            cadastrarCarro();
        break;
        case OPCAO_LISTAR:
        case OPCAO_BUSCAR_ANO:
        case OPCAO_BUSCAR_ANO_ACIMA:
        case OPCAO_BUSCAR_MODELO:
            //caso seja uma das opções que imprime uma lista (listar, buscar por ano, buscar por ano acima  ou buscar por modelo) ele chama o imprimeLista
            imprimirLista(Opcao);
        break;
        case OPCAO_SAIR:
            // não faz nada, nem precisava né?
            // precisa sim por causa da opção de baixo
        break;
        default:
            // quando a opção não estiver nesse switch, por exemplo 7, eu falo que essa é uma opção inválida
            printf("Opção inválida.");
            // chama a função de esperar até que o usuario interaja
            esperarInteracao();
        break;
    }
}

// essa você deve saber pra que que é
// é ela que vai executar quando vc abrir o executavel depois de compilado
int main()
{
    // pelo que vi esse arquivo ta formatado em UTF-8, pra esse setlocale funcionar precisa estar em Europa ocidental ISO-8959-1
    // não to afim de trocar as configurações do meu vsstudio, uso ele pra outras paradas
    setlocale(LC_ALL, "Portuguese");

    // define a variavel opção de menu
    int OpcaoMenu;
    do
    {
        fflush(stdin);

        //chama a função especializada em imprimir o menu e coloca o retorno dela na variavel que criamos acima
        OpcaoMenu = imprimirMenu();
        //chama a função especializada em executar o menu passando a opção obtida na linha de cima
        menu(OpcaoMenu);

        // note que a função especializada em imprimir o menu devolve um inteiro e a especialista em executar um meno precisa de um inteiro, nesse caso teria o mesmo resultado 
        // se executasse assim
        // menu(imprimirMenu());
        // ou seja uma que consome o resultado de outra função como parametros
        // mas creio que fique mais difícil de entender e nesse caso seria necessário também  while

    //continua a executar o a chamada das duas funções acima enquanto a opção selecionada não for a de sair.
    } while (OpcaoMenu != OPCAO_SAIR);

    return 0;
}
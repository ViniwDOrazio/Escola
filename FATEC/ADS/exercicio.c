/*******************************************************************************
    LISTA DE EXERCÍC10S - REPETIÇÃO 

 *******************************************************************************

    l. Faça um programa que determine o mostre os cinco primeiros múltiplos de 3. considerando números maiores que 0. 

    2. Escreva um programa que escreva na tela, de 1 até 100). de 1 em 1, 3 vezes. A primeira vez deve usar a estrutura de repetição for, a segunda while, e a terceira do while. 

    3. Faça um algoritmo utilizando o comando while que mostra uma contagem regressiva na tela, iniciando em 10 e terminando em 0. Mostrar uma mensagem "FIM!" após a contagem. 

    4. Escreva um programa que declare um inteiro, inicialize-o com 0, e incremente-o de 1000 em 1000, imprimindo seu valor na tela, até que seu valor seja 100000 (cem mil). 

    5. Faça um programa que peça ao usuário para digitar 10 valores e some-os. 

    6. Faça um programa que leia 10 inteiros e imprima sua média. 

    7. Faça um programa que leia 10 inteiros positivos, ignorando não positivos, e imprima sua média. 

    8. Escreva um programa que leia 10 números e escreva o menor valor lido e o maior valor lido. 

    9. Faça um programa que leia um número inteiro N e depois imprima os N primeiros números naturais ímpares. 

    10. Faça um programa que calcule e mostre a soma dos 50 primeiros números pares 

    11. Faça um programa que leia um número inteiro positivo N e imprima todos os números naturais de 0 até N em ordem ctvscente. 

    12. Faça um programa que leia um número inteiro positivo N e imprima todos os números naturais de 0 até N em ordem decrescente. 

    13. Faça um programa que leia um número inteiro positivo par N e imprima todos os números pares de 0 até N em ordem crescente. 

    14. Faça um programa que leia um número inteiro positivo par N e imprima todos os números pares de 0 até N em ordem decrescente. 

    15. Faça um programa que leia um número inteiro r»sitivo impar N e imprima todos os números impares de 1 até N em ordem crescente. 

    16. Faça um programa que leia um número inteiro positivo ímpar N e imprima todos os números impares de 1 até N em ordem decrescente_ 

    17. Faça um programa que leia um número inteiro positivo n e calcule a soma dos n primeiros números naturais. 

    18. Escreva um algoritmo que leia certa quantidade de números e imprima o maior deles e quantas vezes o maior número foi lido. A quantidade de números a serem lidos deve ser fornecida pelo usuáno. 

    19. Escreva um algoritmo que leia um número inteiro entre 100 e 999 e imprima na saida cada um dos algarismos que compõem o número. 

    20. Ler uma sequência de números inteiros e determinar se eles são pares ou não. Deverá ser informado o número de dados lidos e número de valores pares. O processo termina quando for digitado o número 

    21. Faça um programa que receba dois números. Calcule e mostre: 
    • a soma dos números pares desse intervalo de números, incluindo os números digitados;  
    • a multiplicação dos números ímpares desse intervalo. incluindo os digitados; 

    22. Escreva um programa completo que permita a qualquer aluno introduzir, pelo teclado, uma sequência arbitrária de notas (válidas no intervalo de 10 a 20) e que mostre na tela, como resultado, a correspondente média aritmética. O número de notas com que o aluno pretenda efetuar o cálculo não será fornecido ao programa, o qual terminará quando for introduzido um valor que não seja válido como nota de aprovação. 

    23. Faca um algoritmo que leia um número positivo e imprima seus divisores. 

    24. Escreva um programa que leia um número inteiro e calcule a soma de tcxlos os divisores desse número, com exceção dele próprio. Ex: a soma dos divisores do número 66 é 1 + 2 + 3 + 6 + 11 + 22 +33 = 78 

    25. Faça um programa que some todos os números naturais abaixo de que são múltiplos de 3 ou 5. 

    26. Faca um algoritmo que encontre o primeiro múltiplo de 11, 13 ou 17 após um número dado. 

    27. Em Matemática, o número harmónico designado por H(n) define-se como sendo a soma da série hannônica: H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + l/n  
    Faça um programa que leia um valor n inteiro e positivo e apresente o valor de H(n). 

    28. Faça um programa que leia um valor N inteiro e positivo, calcule o mostre o valor E, conforme a fórmula a seguir E = 1 + 1/1! + 1/2! + 1/3! 1/N! 

    29. Escreva um programa para calcular o valor da série, para 5 termos- 
    S = 0 + 1/2! + 2/4! + 3/6! + ...

    30. Faça programas para calcular as seguintes sequências: 
    1 + 2 + 3 + 4 + 5 + ... + n
    1 - 2 + 3 - 4 + 5 + ... + (2n -1)
    1 + 3 + 5 + 7 + ... + (2n -1)
 ******************************************************************************/

#include <stdio.h>
#include <limits.h>

void Exercicio01()
{
    printf("Exercicio 1 - 5 primeiros multiplos de 3: ");
    for (int i = 1; i <= 5; i++)
    {
        printf("%i", (i * 3));
        if (i == 5)
            printf(".\n");
        else
            printf(", ");
    }
}

void Exercicio02()
{
    printf("Exercicio 2 - 1 a 100, for: ");
    for (int i = 1; i <= 100; i++)
    {
        printf("%i", (i ));
        if (i == 100)
            printf(".\n");
        else
            printf(", ");
    }
}

void Exercicio03()
{
    printf("Exercicio 3 - Contagem regressiva 10 a 0 : ");
    {
        int i = 10;
        while (i >= 0)
        {
            printf("%i", (i));
            if (i == 0)
                printf(". FIM! \n");
            else
                printf(", ");
            i--;
        }
    }
}

void Exercicio04()
{
    printf("Exercicio 4 - inteiro 0 de 1000 até que (cem mil)): ");
    for (int i = 0; i <= 100000; i += 1000)
    {
        printf("%i", (i));
        if (i == 100000)
            printf(".\n");
        else
            printf(", ");
    }
}

void Exercicio05()
{
    printf("Exercicio 5 e 6 - Soma e média de 10 numeros informados pelo usuario: \n");
    int soma = 0;
    for (int i = 1; i <= 10; i++)
    {
        int leitura;
        printf("Digita o numero %d: ", i);
        scanf("%d", &leitura);
        soma += leitura;
    }
    printf("Soma total: %d\n", soma);
    printf("Média: %f\n", (soma / 10.0));
}

void Exercicio06()
{
    Exercicio05();
}

void Exercicio07()
{
    printf("Exercicio 7 - Médias de inteiro positivo: \n");
    int soma = 0, i = 1;
    while (i <= 10)
    {
        int leitura;
        printf("Digita o numero %d: ", i);
        scanf("%d", &leitura);
        if (leitura > 0)
        {
            soma += leitura;
            i++;
        }
        else 
            printf("%d é Inválido: ", leitura);
    }
    printf("Soma total: %d\n", soma);
    printf("Média: %f\n", (soma / 10.0));
}

void Exercicio08()
{
    printf("Exercicio 8 - Maior e menor numero lido: \n");
    float maior, menor;
    for (int i = 1; i <= 10; i++)
    {
        float leitura;
        printf("Digita o numero %d: ", i);
        scanf("%f", &leitura);
        if (i == 1)
        {
            maior = leitura;
            menor = leitura;
        }
        else
        {
            if (leitura > maior)
                maior = leitura;
            
            if (leitura < menor)
                menor = leitura;
        }
        
    }
    printf("Menor: %f\n", menor);
    printf("Maior: %f\n", maior);
}

void Exercicio09()
{
    printf("Exercicio 9 - N primeiros numeros ímpares: \n");
    int quantidade_impares;
    printf("Digita o numero: ");
    scanf("%d", &quantidade_impares);
    printf("Exercicio 9 - %i primeiros numeros ímpares: \n", quantidade_impares);
    for (int i = 0; i <= quantidade_impares - 1; i++)
    {
        printf("%i", (1 + (i * 2)));
        if (i == quantidade_impares - 1)
            printf(".\n");
        else
            printf(", ");
    }
}

void Exercicio10()
{
    printf("Exercicio 10 - Soma dos 50 primeiros numeros pares: ");
    int soma = 0;
    for (int i = 0; i < 50; i++)
        soma += (i*2);
    printf("%i \n", soma);

}

void Exercicio11()
{
    printf("Exercicio 11 e 12 - 0 a N e N a 0: ");
    int numero = 0;
    do{
        printf("Digita o numero inteiro positivo: ");
        scanf("%d", &numero);
    } while (numero <= 0);

    for (int i = 0; i <= numero; i++)
    {
        printf("%i", i);
        if (i == numero)
            printf(".\n");
        else
            printf(", ");
    }

    for (int i = numero; i >= 0; i--)
    {
        printf("%i", i);
        if (i == 0)
            printf(".\n");
        else
            printf(", ");
    }
}

void Exercicio12()
{
    Exercicio11();
}

void Exercicio13()
{
	printf("Exercicio 13 e 14 pares de  0 a N e N a 0: ");
    int numero = 0;
    do{
        printf("Digita o numero pares de inteiro positivo: ");
        scanf("%d", &numero);
    } while ((numero <= 0) || ((numero % 2) == 1));
    
    for (int i = 0; i <= numero; i += 2)
    {
        printf("%i", i);
        if (i == numero)
            printf(".\n");
        else
            printf(", ");
    }
    
    for (int i = numero; i >= 0; i -= 2)
    {
        printf("%i", i);
        if (i == 0)
            printf(".\n");
        else
            printf(", ");
    }
}

void Exercicio14()
{
    Exercicio13();
}

void Exercicio15()
{
    printf("Exercicio 15 e 16 impares de  1 a N e N a 1: ");
    int numero = 0;
    do{
        printf("Digita o numero impares de inteiro positivo: ");
        scanf("%d", &numero);
    } while ((numero <= 0) || ((numero % 2) == 0));
    
    for (int i = 1; i <= numero; i += 2)
    {
        printf("%i", i);
        if (i == numero)
            printf(".\n");
        else
            printf(", ");
    }
    
    for (int i = numero; i >= 1; i -= 2)
    {
        printf("%i", i);
        if (i == 1)
            printf(".\n");
        else
            printf(", ");
    }
}

void Exercicio16()
{
    Exercicio15();
}

void Exercicio17()
{
    printf("Exercicio 17 - Positivo n calcule a soma: ");
	int numero = 0, soma = 0;
	do{
		printf("\nDigita o numero inteiro positivo:");
		scanf("%d", &numero);
	} while (numero <= 0);
	
	for (int i = 1; i <= numero; i += 1)
	{
		soma += i;
	}
	
	printf("Soma e %i \n", soma);
}

void Exercicio18()
{
	printf("Exercicio 18 Maior e Repeticoes\n");
	#define REPETICOES 10
	int numero, maior = INT_MIN, repeticoes = 0;
	for (int i = 0; i <= REPETICOES - 1; i ++)
	{
		printf("\nDigita o numero inteiro positivo:");
		scanf("%d", &numero);
		if (numero == maior)
			repeticoes++;
		else if (numero > maior)
		{
			maior = numero;
			repeticoes = 1;
		}
	}
	printf("O Maior numero é o  %i e repetiu %i \n", maior, repeticoes);
}

void Exercicio19()
{
    printf("Exercicio 19 - Caracteres de um numero\n");
	int numero = 0;
	do{
		printf("\nDigita o numero inteiro positivo:");
		scanf("%d", &numero);
	} while ((numero < 100) || (numero > 999));

	int centena = 0, dezena = 0, unidade = 0;
	centena = numero / 100;
	dezena = (numero - (centena * 100)) / 10;
	unidade = numero - (centena * 100) - (dezena * 10);

	printf("centena: %i, dezena: %i, unidade: %i\n", centena, dezena, unidade);
}

void Exercicio20()
{
	printf("Exercicio 20 - Informar se e par ou impar até que informe 1000\n");
	int lido = 0, quantidade = 0;
	do{
		quantidade++;
		printf("\nNumero %i:", quantidade);
		scanf("%d", &lido);
		if (lido %2 == 0)
			printf(" e par");
		else
			printf(" e impar");
	} while (lido != 1000);
	printf(" \n");
}

void Exercicio21()
{
    printf("Exercicio 21 - em um intervalo, soma pares multiplica impares\n");
	int menor = INT_MAX, maior = INT_MIN, numero;
	printf("\nDigita um numero:");
	scanf("%d", &numero);
	menor = numero;
	maior = numero;
	printf("\nDigita outro numero:");
	scanf("%d", &numero);
	if (numero < menor)
		menor = numero;
	else 
	if (numero > maior)
		maior = numero;

	int soma = 0, multiplicacao = 1;
	for (int i = menor; i <= maior; i++)
	{
		if ((i % 2) == 0)
			soma += i;
		else
			multiplicacao *= i;
	}
	
	printf("\nSoma pares %i, multiplicacao impares: %i\n", soma, multiplicacao);

}

void Exercicio22()
{
	int nota = 0, somatorio = 0, quantidade = 0;
	#define menor_possivel 10
	#define maior_possivel 20
	do{
		printf("\nNota %i:", (quantidade + 1));
		scanf("%d", &nota);
		
		if ((nota >= menor_possivel) && (nota <= maior_possivel))
		{
			quantidade++;
			somatorio += nota;
		}
		float media = (somatorio / (quantidade + 0.0));
		printf("\nMedia: %f", media);

	} while ((nota >= menor_possivel) && (nota <= maior_possivel));
	printf(" \n");

}

void Exercicio23()
{
    printf("Exercicio 23 e 24 - Divisores e soma divisores\n");
	int numero = 0, soma = 0;
	do{
		printf("\nDigita o numero inteiro positivo:");
		scanf("%d", &numero);
	} while (numero <= 0);
	
    printf("\nDivisores: ");
	for (int i = 1; i <= ((numero / 2)); i += 1)
	{
        if ((numero % i) == 0)
        {
            printf("+ %i ", i);
            soma += i;
        }
	}
	
	printf("= %i ", soma);
}

void Exercicio24()
{
    Exercicio23();
}

void Exercicio25()
{
    int soma = 0;

    for (int i = 0; i <= 1000; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
            soma += i;
    }
    printf("Exercicio 25 - A soma multiplos de 3 e 5 até mil é: %i\n", soma);
}

void Exercicio26()
{
    printf("Exercicio 26 - proximo multiplo por 11, 13 ou 17\n");
	int numero = 0;
	do{
		printf("\nDigita o numero inteiro positivo:");
		scanf("%d", &numero);
	} while (numero <= 0);

   // if ((numero % 11 == 0) || (numero % 13 == 0) || (numero % 17 == 0))
        // printf("O numero %i é divisivel por 11, 13 ou 17", numero);

    do{
        numero++;
        if ((numero % 11 == 0) || (numero % 13 == 0) || (numero % 17 == 0))
            printf("O numero %i é divisivel por 11, 13 ou 17", numero);
    }
    while (!((numero % 11 == 0) || (numero % 13 == 0) || (numero % 17 == 0)));
}

void Exercicio27()
{
    printf("Exercicio 27 - Numero harmonico\n");

	int numero = 0;
	do{
		printf("\nDigita o numero inteiro positivo:");
		scanf("%d", &numero);
	} while (numero <= 0);

    float soma = 0;
    for (int i = 1; i <= numero; i++)
        soma += 1.0 / i;
    printf("\nNumero Harmonico de %i = %f", numero, soma);
}

void Exercicio28()
{
    printf("Exercicio 28 - Valor de E\n");

	int numero = 0;
	do{
		printf("\nDigita o numero inteiro positivo:");
		scanf("%d", &numero);
	} while (numero <= 0);

    float soma = 1;
    for (int i = 1; i <= numero; i++)
    {
        int fatorial = 1;
        for(int n = i; n > 1; n--)
            fatorial *= n;
        soma += 1.0 / fatorial;
    }
    printf("\nValor E(%i) = %f", numero, soma);
}

void Exercicio29()
{
    printf("Exercicio 29 - 5 termos\n");

    float soma = 0;
    for (int i = 1; i < 5; i++)
    {
        int fatorial = 1;
        for(int n = (i * 2); n > 1; n--)
            fatorial *= n;
        soma += 1.0 / fatorial;
    }
    printf("\nValor = %f", soma);
}

void Exercicio30()
{
    printf("Exercicio 30 - 3 sequencias\n");

	int numero = 0;
	do{
		printf("\nDigita o numero inteiro positivo:");
		scanf("%d", &numero);
	} while (numero <= 0);

    int somaseq1 = 0, somaseq2 = 0, somaseq3 = 0;
    for (int i = 1; i <= ((numero * 2) - 1); i++)
    {
        if (i <= numero)
            somaseq1 += i;
        if (i % 2 == 1)
        {
            somaseq2 += i;
            somaseq3 += i;
        }
        else 
            somaseq2 -= i;
    }
    printf("\nValor Sequencia 1 %i,  Sequencia 2 %i,  Sequencia 3 %i", somaseq1, somaseq2, somaseq3);
}


int main()
{
    int exercicio = 0;
	do
    {
		printf("\nQual exercicio deseja ver em execução");
		scanf("%i", &exercicio);
        switch (exercicio)
        {
            case 1:
                Exercicio01();
            break;

            case 2:
                Exercicio02();
            break;

            case 3:
                Exercicio03();
            break;

            case 4:
                Exercicio04();
            break;

            case 5:
                Exercicio05();
            break;
            
            case 6:
                Exercicio06();
            break;

            case 7:
                Exercicio07();
            break;

            case 8:
                Exercicio08();
            break;

            case 9:
                Exercicio09();
            break;

            case 10:
                Exercicio10();
            break;

            case 11:
                Exercicio11();
            break;

            case 12:
                Exercicio12();
            break;

            case 13:
                Exercicio13();
            break;

            case 14:
                Exercicio14();
            break;

            case 15:
                Exercicio15();
            break;
            
            case 16:
                Exercicio16();
            break;

            case 17:
                Exercicio17();
            break;

            case 18:
                Exercicio18();
            break;

            case 19:
                Exercicio19();
            break;

			case 20:
                Exercicio20();
            break;

            case 21:
                Exercicio21();
            break;

            case 22:
                Exercicio22();
            break;

            case 23:
                Exercicio23();
            break;

            case 24:
                Exercicio24();
            break;

            case 25:
                Exercicio25();
            break;
            
            case 26:
                Exercicio26();
            break;

            case 27:
                Exercicio27();
            break;

            case 28:
                Exercicio28();
            break;

            case 29:
                Exercicio29();
            break;

            case 30:
                Exercicio30();
            break;
        }
	} while ((exercicio >= 1) && (exercicio <= 30));

    return 0;
}

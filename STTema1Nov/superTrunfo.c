#include <stdio.h>

struct Carta
{
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    double area;
    double pib;
    int pontosTuristicos;
    double densidade;
};

double obterValor(struct Carta c, int opcao)
{
    switch (opcao)
    {
    case 1:
        return c.populacao;
    case 2:
        return c.area;
    case 3:
        return c.pib;
    case 4:
        return c.pontosTuristicos;
    case 5:
        return c.densidade;
    default:
        return 0;
    }
}

void mostrarAtributo(int opcao)
{
    switch (opcao)
    {
    case 1:
        printf("Populacao");
        break;
    case 2:
        printf("Area");
        break;
    case 3:
        printf("PIB");
        break;
    case 4:
        printf("Pontos Turisticos");
        break;
    case 5:
        printf("Densidade Demografica");
        break;
    }
}

int main()
{
    struct Carta carta1, carta2;
    int op1, op2;

    // ===== CADASTRO =====
    printf("\nCarta 1:\n");
    scanf(" %c", &carta1.estado);
    scanf("%s", carta1.codigo);
    scanf(" %[^\n]", carta1.nomeCidade);
    scanf("%lu", &carta1.populacao);
    scanf("%lf", &carta1.area);
    scanf("%lf", &carta1.pib);
    scanf("%d", &carta1.pontosTuristicos);

    carta1.densidade = carta1.populacao / carta1.area;

    printf("\nCarta 2:\n");
    scanf(" %c", &carta2.estado);
    scanf("%s", carta2.codigo);
    scanf(" %[^\n]", carta2.nomeCidade);
    scanf("%lu", &carta2.populacao);
    scanf("%lf", &carta2.area);
    scanf("%lf", &carta2.pib);
    scanf("%d", &carta2.pontosTuristicos);

    carta2.densidade = carta2.populacao / carta2.area;

    // ===== MENU 1 =====
    printf("\nEscolha o PRIMEIRO atributo:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade\n");
    scanf("%d", &op1);

    // ===== MENU 2 (DINÂMICO) =====
    printf("\nEscolha o SEGUNDO atributo:\n");

    for (int i = 1; i <= 5; i++)
    {
        if (i != op1)
        {
            printf("%d - ", i);
            mostrarAtributo(i);
            printf("\n");
        }
    }

    scanf("%d", &op2);

    if (op1 == op2)
    {
        printf("Erro: atributos iguais!\n");
        return 0;
    }

    // ===== VALORES =====
    double c1_a1 = obterValor(carta1, op1);
    double c2_a1 = obterValor(carta2, op1);

    double c1_a2 = obterValor(carta1, op2);
    double c2_a2 = obterValor(carta2, op2);

    // ===== COMPARAÇÃO INDIVIDUAL =====
    int pontos1 = 0, pontos2 = 0;

    // atributo 1
    if (op1 == 5) // densidade (menor vence)
    {
        if (c1_a1 < c2_a1)
            pontos1++;
        else if (c2_a1 < c1_a1)
            pontos2++;
    }
    else
    {
        if (c1_a1 > c2_a1)
            pontos1++;
        else if (c2_a1 > c1_a1)
            pontos2++;
    }

    // atributo 2
    if (op2 == 5)
    {
        if (c1_a2 < c2_a2)
            pontos1++;
        else if (c2_a2 < c1_a2)
            pontos2++;
    }
    else
    {
        if (c1_a2 > c2_a2)
            pontos1++;
        else if (c2_a2 > c1_a2)
            pontos2++;
    }

    // ===== SOMA =====
    double soma1 = c1_a1 + c1_a2;
    double soma2 = c2_a1 + c2_a2;

    // ===== RESULTADO =====
    printf("\n===== RESULTADO =====\n");

    printf("\nCarta 1: %s\n", carta1.nomeCidade);
    printf("Carta 2: %s\n", carta2.nomeCidade);

    printf("\nAtributos escolhidos: ");
    mostrarAtributo(op1);
    printf(" e ");
    mostrarAtributo(op2);
    printf("\n");

    printf("\nValores:\n");

    printf("%s -> %.2lf | %.2lf | Soma: %.2lf\n",
           carta1.nomeCidade, c1_a1, c1_a2, soma1);

    printf("%s -> %.2lf | %.2lf | Soma: %.2lf\n",
           carta2.nomeCidade, c2_a1, c2_a2, soma2);

    // ===== VENCEDOR =====
    if (soma1 > soma2)
        printf("\nVencedor: %s\n", carta1.nomeCidade);
    else if (soma2 > soma1)
        printf("\nVencedor: %s\n", carta2.nomeCidade);
    else
        printf("\nEmpate!\n");

    return 0;
}
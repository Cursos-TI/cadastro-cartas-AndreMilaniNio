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
    double pibPerCapita;
};

int main()
{
    struct Carta carta1, carta2;

    // ===== CARTA 1 =====
    printf("\nCarta 1:\n\n");

    printf("Estado: ");
    scanf(" %c", &carta1.estado);

    printf("Codigo: ");
    scanf("%s", carta1.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("Populacao: ");
    scanf("%lu", &carta1.populacao);

    printf("Area (km2): ");
    scanf("%lf", &carta1.area);

    printf("PIB (em bilhoes): ");
    scanf("%lf", &carta1.pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Cálculos
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000.0) / carta1.populacao;

    // ===== CARTA 2 =====
    printf("\nCarta 2:\n\n");

    printf("Estado: ");
    scanf(" %c", &carta2.estado);

    printf("Codigo: ");
    scanf("%s", carta2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("Populacao: ");
    scanf("%lu", &carta2.populacao);

    printf("Area (km2): ");
    scanf("%lf", &carta2.area);

    printf("PIB (em bilhoes): ");
    scanf("%lf", &carta2.pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculos
    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000.0) / carta2.populacao;

    // ===== COMPARAÇÃO (ATRIBUTO ESCOLHIDO: POPULAÇÃO) =====
    printf("\nComparacao de cartas (Atributo: Populacao):\n\n");

    printf("Carta 1 - %s (%c): %lu\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%c): %lu\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao)
    {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    }
    else if (carta2.populacao > carta1.populacao)
    {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    }
    else
    {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
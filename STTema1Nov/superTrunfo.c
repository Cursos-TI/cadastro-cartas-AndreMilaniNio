#include <stdio.h>

struct Carta
{
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao; // ALTERADO
    double area;
    double pib;
    int pontosTuristicos;
    double densidade;
    double pibPerCapita;
    float superPoder; // NOVO
};

int main()
{
    struct Carta carta1, carta2;

    // ===== CARTA 1 =====
    printf("\nCarta 1:\n\n");

    printf("Estado: ");
    scanf(" %c", &carta1.estado);

    printf("Codigo (ex: 01): ");
    scanf("%s", carta1.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("Populacao: ");
    scanf("%lu", &carta1.populacao); // ALTERADO

    printf("Area (km2): ");
    scanf("%lf", &carta1.area);

    printf("PIB (em bilhoes): ");
    scanf("%lf", &carta1.pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Cálculos carta 1
    carta1.densidade = (double)carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000.0) / carta1.populacao;

    carta1.superPoder =
        (float)carta1.populacao +
        carta1.area +
        carta1.pib +
        carta1.pontosTuristicos +
        carta1.pibPerCapita +
        (1.0 / carta1.densidade);

    // ===== CARTA 2 =====
    printf("\nCarta 2:\n\n");

    printf("Estado: ");
    scanf(" %c", &carta2.estado);

    printf("Codigo (ex: 02): ");
    scanf("%s", carta2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("Populacao: ");
    scanf("%lu", &carta2.populacao); // ALTERADO

    printf("Area (km2): ");
    scanf("%lf", &carta2.area);

    printf("PIB (em bilhoes): ");
    scanf("%lf", &carta2.pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculos carta 2
    carta2.densidade = (double)carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000.0) / carta2.populacao;

    carta2.superPoder =
        (float)carta2.populacao +
        carta2.area +
        carta2.pib +
        carta2.pontosTuristicos +
        carta2.pibPerCapita +
        (1.0 / carta2.densidade);

    // ===== COMPARAÇÕES =====
    printf("\nComparacao de Cartas:\n\n");

    printf("Populacao: Carta 1 venceu (%d)\n", carta1.populacao > carta2.populacao);
    printf("Area: Carta 1 venceu (%d)\n", carta1.area > carta2.area);
    printf("PIB: Carta 1 venceu (%d)\n", carta1.pib > carta2.pib);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", carta1.pontosTuristicos > carta2.pontosTuristicos);

    // REGRA DIFERENTE (menor vence)
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", carta1.densidade < carta2.densidade);

    printf("PIB per Capita: Carta 1 venceu (%d)\n", carta1.pibPerCapita > carta2.pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", carta1.superPoder > carta2.superPoder);

    return 0;
}
#include <stdio.h>

struct Carta // Estrutura para armazenar dados da carta
{
    char estado;          // Letra do estado
    char codigo[4];       // Código (ex: 01)
    char nomeCidade[50];  // Nome da cidade (com espaços)
    int populacao;        // População total
    float area, pib;      // Área e PIB
    int pontosTuristicos; // Quantidade de pontos turísticos
};

int main()
{
    struct Carta carta1, carta2; // Duas cartas
    char buffer[100];            // Buffer para leitura segura

    // Área para entrada de dados
    // ===== CARTA 1 =====
    printf("\nCarta 1:\n\n");

    printf("Estado: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, " %c", &carta1.estado); // Extrai 1 caractere

    printf("Codigo (ex: 01): ");
    fgets(carta1.codigo, 4, stdin); // Lê até 3 caracteres + \0

    printf("Nome da Cidade: ");
    fgets(carta1.nomeCidade, 50, stdin); // Aceita espaços

    printf("Populacao: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%d", &carta1.populacao); // Converte para int

    printf("Area (km2): ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%f", &carta1.area); // Converte para float

    printf("PIB (em bilhoes): ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%f", &carta1.pib);

    printf("Numero de Pontos Turisticos: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%d", &carta1.pontosTuristicos);

    // ===== CARTA 2 =====
    printf("\nCarta 2:\n\n");

    printf("Estado: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, " %c", &carta2.estado);

    printf("Codigo (ex: 02): ");
    fgets(carta2.codigo, 4, stdin);

    printf("Nome da Cidade: ");
    fgets(carta2.nomeCidade, 50, stdin);

    printf("Populacao: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%d", &carta2.populacao);

    printf("Area (km2): ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%f", &carta2.area);

    printf("PIB (em bilhoes): ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%f", &carta2.pib);

    printf("Numero de Pontos Turisticos: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%d", &carta2.pontosTuristicos);

    // Área para exibição dos dados da cidade
    // ===== SAIDA =====
    printf("\n\nCarta 1:\n\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %c%s", carta1.estado, carta1.codigo); // Junta estado + código
    printf("Nome da Cidade: %s", carta1.nomeCidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km2\n", carta1.area);
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta1.pontosTuristicos);

    printf("\nCarta 2:\n\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %c%s", carta2.estado, carta2.codigo);
    printf("Nome da Cidade: %s", carta2.nomeCidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km2\n", carta2.area);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta2.pontosTuristicos);

    return 0;
}
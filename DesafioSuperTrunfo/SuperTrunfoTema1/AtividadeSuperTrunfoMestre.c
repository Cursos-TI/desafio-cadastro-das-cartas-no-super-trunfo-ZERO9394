#include <stdio.h>
#include <string.h>

int main() {
    // Declaração das variáveis
    char estado1, estado2; // Variáveis para armazenar os estados das cidades
    char codigo1[4], codigo2[4]; // Vetores para armazenar os códigos das cartas (ex: A01)
    char cidade1[50], cidade2[50]; // Vetores para armazenar os nomes das cidades
    unsigned long int populacao1, populacao2; // Variáveis para armazenar a população das cidades (agora unsigned long int)
    float area1, area2, pib1, pib2; // Variáveis para armazenar a área (km²) e PIB (em bilhões de reais)
    int pontosTuristicos1, pontosTuristicos2; // Variáveis para armazenar o número de pontos turísticos
    
    // Variáveis para armazenar os cálculos
    float densidadePopulacional1, densidadePopulacional2;
    float pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;

    // Entrada de dados para a primeira carta
    printf("Digite o estado da primeira cidade (A-H): ");
    scanf(" %c", &estado1); // Lê o estado da primeira cidade
    printf("Digite o código da carta (ex: A01): ");
    scanf(" %s", codigo1); // Lê o código da carta da primeira cidade
    printf("Digite o nome da cidade: ");
    scanf(" "); // Consome o '\n' pendente
    fgets(cidade1, sizeof(cidade1), stdin); // Lê o nome da cidade (pode ter espaços)
    cidade1[strcspn(cidade1, "\n")] = 0; // Remove o '\n' no final da string lida pelo fgets
    printf("Digite a população: ");
    scanf("%lu", &populacao1); // Lê a população da primeira cidade como unsigned long int
    printf("Digite a área (em km²): ");
    scanf("%f", &area1); // Lê a área da primeira cidade
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1); // Lê o PIB da primeira cidade
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1); // Lê o número de pontos turísticos da primeira cidade

    // Calcular a densidade populacional e PIB per capita para a primeira cidade
    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = pib1 * 1000000000 / populacao1; // PIB per capita em reais

    // Calcular o Super Poder para a primeira carta
    superPoder1 = populacao1 + area1 + pib1 * 1000000000 + pontosTuristicos1 + pibPerCapita1 + (1 / densidadePopulacional1);

    printf("\n");

    // Entrada de dados para a segunda carta
    printf("Digite o estado da segunda cidade (A-H): ");
    scanf(" %c", &estado2); // Lê o estado da segunda cidade
    printf("Digite o código da carta (ex: B02): ");
    scanf(" %s", codigo2); // Lê o código da carta da segunda cidade
    printf("Digite o nome da cidade: ");
    scanf(" "); // Consome o '\n' pendente
    fgets(cidade2, sizeof(cidade2), stdin); // Lê o nome da cidade (pode ter espaços)
    cidade2[strcspn(cidade2, "\n")] = 0; // Remove o '\n' do final da string lida pelo fgets
    printf("Digite a população: ");
    scanf("%lu", &populacao2); // Lê a população da segunda cidade como unsigned long int
    printf("Digite a área (em km²): ");
    scanf("%f", &area2); // Lê a área da segunda cidade
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2); // Lê o PIB da segunda cidade
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2); // Lê o número de pontos turísticos da segunda cidade

    // Calcular a densidade populacional e PIB per capita para a segunda cidade
    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = pib2 * 1000000000 / populacao2; // PIB per capita em reais

    // Calcular o Super Poder para a segunda carta
    superPoder2 = populacao2 + area2 + pib2 * 1000000000 + pontosTuristicos2 + pibPerCapita2 + (1 / densidadePopulacional2);

    // Comparação dos atributos e exibição dos resultados
    printf("\nComparação de Cartas:\n");

    // Comparação de População
    printf("População: Carta 1 venceu (%d)\n", (populacao1 > populacao2));

    // Comparação de Área
    printf("Área: Carta 1 venceu (%d)\n", (area1 > area2));

    // Comparação de PIB
    printf("PIB: Carta 1 venceu (%d)\n", (pib1 > pib2));

    // Comparação de Pontos Turísticos
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", (pontosTuristicos1 > pontosTuristicos2));

    // Comparação de Densidade Populacional (a menor densidade vence)
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", (densidadePopulacional1 < densidadePopulacional2));

    // Comparação de PIB per Capita
    printf("PIB per Capita: Carta 1 venceu (%d)\n", (pibPerCapita1 > pibPerCapita2));

    // Comparação de Super Poder
    printf("Super Poder: Carta 1 venceu (%d)\n", (superPoder1 > superPoder2));

    return 0; // Finaliza o programa

}

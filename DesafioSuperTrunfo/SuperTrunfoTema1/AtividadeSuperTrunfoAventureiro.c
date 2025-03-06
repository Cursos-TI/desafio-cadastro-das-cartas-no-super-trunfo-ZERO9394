#include <stdio.h>
#include <string.h>

int main() {
    // Declaração das variáveis
    char estado1, estado2; // Variáveis para armazenar os estados das cidades
    char codigo1[4], codigo2[4]; // Vetores para armazenar os códigos das cartas (ex: A01)
    char cidade1[50], cidade2[50]; // Vetores para armazenar os nomes das cidades
    int populacao1, populacao2; // Variáveis para armazenar a população de cada cidade
    float area1, area2, pib1, pib2; // Variáveis para armazenar a área (km²) e PIB (em bilhões de reais)
    int pontosTuristicos1, pontosTuristicos2; // Variáveis para armazenar o número de pontos turísticos
    
    // Variáveis para armazenar os cálculos
    float densidadePopulacional1, densidadePopulacional2;
    float pibPerCapita1, pibPerCapita2;

    // Entrada de dados para a primeira carta
    printf("Digite o estado da primeira cidade (A-H): ");
    scanf(" %c", &estado1); // O " %c" permite capturar um caractere, com o espaço inicial para descartar qualquer caractere pendente (como '\n')
    printf("Digite o código da carta (ex: A01): ");
    scanf(" %s", codigo1); // Lê o código da carta da primeira cidade
    printf("Digite o nome da cidade: ");
    scanf(" "); // Consome o '\n' pendente do buffer de entrada
    fgets(cidade1, sizeof(cidade1), stdin); // Lê o nome da cidade (pode ter espaços)
    cidade1[strcspn(cidade1, "\n")] = 0; // Remove o '\n' no final da string lida pelo fgets
    printf("Digite a população: ");
    scanf("%d", &populacao1); // Lê a população da primeira cidade
    printf("Digite a área (em km²): ");
    scanf("%f", &area1); // Lê a área da primeira cidade
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1); // Lê o PIB da primeira cidade
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1); // Lê o número de pontos turísticos da primeira cidade

    // Calcular a densidade populacional e PIB per capita para a primeira cidade
    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = pib1 * 1000000000 / populacao1; // PIB per capita em reais, multiplicando PIB por 1 bilhão para converter para reais

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
    scanf("%d", &populacao2); // Lê a população da segunda cidade
    printf("Digite a área (em km²): ");
    scanf("%f", &area2); // Lê a área da segunda cidade
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2); // Lê o PIB da segunda cidade
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2); // Lê o número de pontos turísticos da segunda cidade

    // Calcular a densidade populacional e PIB per capita para a segunda cidade
    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = pib2 * 1000000000 / populacao2; // PIB per capita em reais

    // Exibição dos dados das duas cartas de forma estruturada
    printf("\n============================\n");
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1); // Exibe o estado da primeira cidade
    printf("Código: %s\n", codigo1); // Exibe o código da carta da primeira cidade
    printf("Nome da Cidade: %s\n", cidade1); // Exibe o nome da cidade
    printf("População: %d\n", populacao1); // Exibe a população da cidade
    printf("Área: %.2f km²\n", area1); // Exibe a área da cidade com 2 casas decimais
    printf("PIB: %.2f bilhões de reais\n", pib1); // Exibe o PIB da cidade com 2 casas decimais
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1); // Exibe o número de pontos turísticos
    // Exibe a densidade populacional e PIB per capita calculados
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\n============================\n");
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2); // Exibe o estado da segunda cidade
    printf("Código: %s\n", codigo2); // Exibe o código da carta da segunda cidade
    printf("Nome da Cidade: %s\n", cidade2); // Exibe o nome da cidade
    printf("População: %d\n", populacao2); // Exibe a população da cidade
    printf("Área: %.2f km²\n", area2); // Exibe a área da cidade com 2 casas decimais
    printf("PIB: %.2f bilhões de reais\n", pib2); // Exibe o PIB da cidade com 2 casas decimais
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2); // Exibe o número de pontos turísticos
    // Exibe a densidade populacional e PIB per capita calculados
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    return 0; // Finaliza o programa
}

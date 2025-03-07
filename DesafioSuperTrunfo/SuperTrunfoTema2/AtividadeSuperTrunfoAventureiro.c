#include <stdio.h>
#include <string.h>  // Necessário para a função strcspn

int main() {
    // Declaração das variáveis para armazenar os dados das cidades
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    
    float densidadePopulacional1, densidadePopulacional2;
    float pibPerCapita1, pibPerCapita2;

    // Entrada de dados para a primeira carta
    printf("Digite o estado da primeira cidade (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o código da carta (ex: A01): ");
    scanf(" %s", codigo1);
    printf("Digite o nome da cidade: ");
    getchar();  // Limpa o buffer de entrada
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = 0;
    printf("Digite a população: ");
    scanf("%lu", &populacao1);
    printf("Digite a área (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = pib1 * 1000000000 / populacao1;

    // Entrada de dados para a segunda carta
    printf("\nDigite o estado da segunda cidade (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o código da carta (ex: B02): ");
    scanf(" %s", codigo2);
    printf("Digite o nome da cidade: ");
    getchar();  // Limpa o buffer de entrada
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;
    printf("Digite a população: ");
    scanf("%lu", &populacao2);
    printf("Digite a área (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = pib2 * 1000000000 / populacao2;

    // Exibe um menu para o usuário escolher o atributo a ser comparado
    printf("\nEscolha o atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per Capita\n");
    printf("Digite a opção desejada: ");
    int atributo;
    scanf("%d", &atributo);

    switch (atributo) {
        case 1:
            printf("\nComparação de Cartas (Atributo: População):\n");
            printf("Carta 1 - %s: %lu\n", cidade1, populacao1);
            printf("Carta 2 - %s: %lu\n", cidade2, populacao2);
            if (populacao1 > populacao2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else if (populacao1 < populacao2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 2:
            printf("\nComparação de Cartas (Atributo: Área):\n");
            printf("Carta 1 - %s: %.2f km²\n", cidade1, area1);
            printf("Carta 2 - %s: %.2f km²\n", cidade2, area2);
            if (area1 > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else if (area1 < area2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 3:
            printf("\nComparação de Cartas (Atributo: PIB):\n");
            printf("Carta 1 - %s: %.2f bilhões de reais\n", cidade1, pib1);
            printf("Carta 2 - %s: %.2f bilhões de reais\n", cidade2, pib2);
            if (pib1 > pib2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else if (pib1 < pib2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 4:
            printf("\nComparação de Cartas (Atributo: Densidade Populacional):\n");
            printf("Carta 1 - %s: %.2f pessoas por km²\n", cidade1, densidadePopulacional1);
            printf("Carta 2 - %s: %.2f pessoas por km²\n", cidade2, densidadePopulacional2);
            if (densidadePopulacional1 < densidadePopulacional2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else if (densidadePopulacional1 > densidadePopulacional2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 5:
            printf("\nComparação de Cartas (Atributo: PIB per Capita):\n");
            printf("Carta 1 - %s: %.2f reais\n", cidade1, pibPerCapita1);
            printf("Carta 2 - %s: %.2f reais\n", cidade2, pibPerCapita2);
            if (pibPerCapita1 > pibPerCapita2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
            } else if (pibPerCapita1 < pibPerCapita2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }

    getchar();  // Aguarda a tecla enter para fechar a janela do console
    return 0;
}

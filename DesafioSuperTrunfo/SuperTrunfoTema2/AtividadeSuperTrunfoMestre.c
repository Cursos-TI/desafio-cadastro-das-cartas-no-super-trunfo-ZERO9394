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

    // Menu de escolha do primeiro atributo
    int atributo1;
    printf("\nEscolha o primeiro atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per Capita\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &atributo1);

    // Menu de escolha do segundo atributo, garantindo que não seja o mesmo que o primeiro
    int atributo2;
    printf("\nEscolha o segundo atributo para comparar as cartas (diferente do primeiro):\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per Capita\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &atributo2);

    // Verificar se o usuário escolheu o mesmo atributo
    while (atributo1 == atributo2) {
        printf("\nErro! Você não pode escolher o mesmo atributo para ambos. Tente novamente.\n");
        printf("Escolha o segundo atributo para comparar as cartas (diferente do primeiro):\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Densidade Populacional\n");
        printf("5 - PIB per Capita\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &atributo2);
    }

    // Função de comparação entre dois atributos
    float resultado1 = 0, resultado2 = 0;
    switch (atributo1) {
        case 1:
            resultado1 = populacao1;
            break;
        case 2:
            resultado1 = area1;
            break;
        case 3:
            resultado1 = pib1;
            break;
        case 4:
            resultado1 = densidadePopulacional1;
            break;
        case 5:
            resultado1 = pibPerCapita1;
            break;
    }

    switch (atributo2) {
        case 1:
            resultado2 = populacao2;
            break;
        case 2:
            resultado2 = area2;
            break;
        case 3:
            resultado2 = pib2;
            break;
        case 4:
            resultado2 = densidadePopulacional2;
            break;
        case 5:
            resultado2 = pibPerCapita2;
            break;
    }

    // Comparar os dois atributos selecionados
    printf("\nResultado da comparação de atributos:\n");
    printf("Atributo 1: ");
    switch (atributo1) {
        case 1: printf("População: %lu\n", populacao1); break;
        case 2: printf("Área: %.2f km²\n", area1); break;
        case 3: printf("PIB: %.2f bilhões de reais\n", pib1); break;
        case 4: printf("Densidade Populacional: %.2f pessoas por km²\n", densidadePopulacional1); break;
        case 5: printf("PIB per Capita: %.2f reais\n", pibPerCapita1); break;
    }

    printf("Atributo 2: ");
    switch (atributo2) {
        case 1: printf("População: %lu\n", populacao2); break;
        case 2: printf("Área: %.2f km²\n", area2); break;
        case 3: printf("PIB: %.2f bilhões de reais\n", pib2); break;
        case 4: printf("Densidade Populacional: %.2f pessoas por km²\n", densidadePopulacional2); break;
        case 5: printf("PIB per Capita: %.2f reais\n", pibPerCapita2); break;
    }

    // Comparação dos atributos escolhidos
    if (resultado1 > resultado2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (resultado1 < resultado2) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("\nResultado: Empate!\n");
    }

    // Soma dos atributos e comparação final
    float soma1 = 0, soma2 = 0;
    soma1 = resultado1 + resultado2;
    soma2 = resultado1 + resultado2;

    if (soma1 > soma2) {
        printf("\nSoma dos Atributos: Carta 1 (%s) venceu!\n", cidade1);
    } else if (soma1 < soma2) {
        printf("\nSoma dos Atributos: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("\nSoma dos Atributos: Empate!\n");
    }

    return 0;
}

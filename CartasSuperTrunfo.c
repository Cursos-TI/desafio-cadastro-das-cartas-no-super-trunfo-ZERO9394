#include <stdio.h>
#include <string.h>

// Definindo a estrutura para o estado
struct Estado {
    char nome[50];
    char capital[50];
    char cidadeDestaque[50];
    int populacao;
    float area;
    double pib; // PIB em bilhões
    char pontosTuristicos[200];
};

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(struct Estado estado) {
    // Densidade populacional = população / área
    return estado.populacao / estado.area;
}

// Função para calcular o PIB per capita
double calcularPibPerCapita(struct Estado estado) {
    // PIB per capita = (PIB em bilhões * 1 bilhão) / população
    return (estado.pib * 1000000000) / estado.populacao;
}

// Função para exibir os detalhes do estado
void exibirEstado(struct Estado estado) {
    printf("\nInformações encontradas:\n");
    printf("Estado: %s\n", estado.nome);
    printf("Capital: %s\n", estado.capital);
    printf("Cidade em Destaque: %s\n", estado.cidadeDestaque);
    printf("População: %d habitantes\n", estado.populacao);
    printf("Área: %.2f km²\n", estado.area);
    printf("PIB: R$ %.2f bilhões\n", estado.pib);
    printf("Pontos Turísticos: %s\n", estado.pontosTuristicos);

    // Exibindo a densidade populacional
    float densidade = calcularDensidadePopulacional(estado);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade);

    // Exibindo o PIB per capita
    double pibPerCapita = calcularPibPerCapita(estado);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    printf("\n");
}

int main() {
    // Criando um vetor de estados
    struct Estado estados[3];

    // Atribuindo valores aos estados
    strcpy(estados[0].nome, "Bahia");
    strcpy(estados[0].capital, "Salvador");
    strcpy(estados[0].cidadeDestaque, "Camacari");
    estados[0].populacao = 14930634;
    estados[0].area = 564692.669;
    estados[0].pib = 284.56; // PIB da Bahia em bilhões
    strcpy(estados[0].pontosTuristicos, "Pelourinho, Elevador Lacerda, Farol da Barra");

    strcpy(estados[1].nome, "Sao Paulo");
    strcpy(estados[1].capital, "Sao Paulo");
    strcpy(estados[1].cidadeDestaque, "Campinas");
    estados[1].populacao = 46289333;
    estados[1].area = 248209.426;
    estados[1].pib = 2384.78; // PIB de São Paulo em bilhões
    strcpy(estados[1].pontosTuristicos, "Avenida Paulista, Parque Ibirapuera, Mercadão Municipal");

    strcpy(estados[2].nome, "Rio de Janeiro");
    strcpy(estados[2].capital, "Rio de Janeiro");
    strcpy(estados[2].cidadeDestaque, "Niterói");
    estados[2].populacao = 17366189;
    estados[2].area = 43696.054;
    estados[2].pib = 758.45; // PIB do Rio de Janeiro em bilhões
    strcpy(estados[2].pontosTuristicos, "Cristo Redentor, Pão de Açúcar, Praia de Copacabana");

    // Loop principal do programa
    char nomeBusca[50];
    while (1) { // Loop infinito
        // Pedindo ao usuário para digitar o nome do estado, cidade ou capital
        printf("Digite o nome do estado, cidade ou capital (ou 'sair' para encerrar): ");
        scanf(" %[^\n]", nomeBusca); // Lê a entrada até encontrar uma nova linha

        // Verificando se o usuário quer sair
        if (strcmp(nomeBusca, "sair") == 0) {
            printf("Encerrando o programa...\n");
            break;
        }

        // Buscando o estado, cidade ou capital no vetor
        int encontrada = 0;
        for (int i = 0; i < 3; i++) {
            if (strcmp(estados[i].nome, nomeBusca) == 0 || 
                strcmp(estados[i].capital, nomeBusca) == 0 || 
                strcmp(estados[i].cidadeDestaque, nomeBusca) == 0) {
                exibirEstado(estados[i]);
                encontrada = 1;
                break;
            }
        }

        // Se o estado, cidade ou capital não for encontrado
        if (!encontrada) {
            printf("\nEstado, cidade ou capital não encontrado!\n");
        }
    }

    return 0;
}
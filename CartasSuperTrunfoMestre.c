#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para representar um Estado
struct Estado {
    char nome[50];  // Nome do estado
    char capital[50];  // Capital do estado
    char cidadeDestaque[50];  // Cidade em destaque no estado
    int populacao;  // População do estado
    float area;  // Área do estado em km²
    double pib;  // PIB do estado em bilhões
    char pontosTuristicos[200];  // Lista de pontos turísticos do estado
    float densidadePopulacional;  // Densidade populacional do estado (habitantes por km²)
    double pibPerCapita;  // PIB per capita do estado
    float superPoder;  // "Super Poder" do estado, uma métrica personalizada
    int numPontosTuristicos;  // Número de pontos turísticos
};

// Função para calcular a densidade populacional
// Justificativa: A densidade populacional é um dado importante para medir a concentração de habitantes em relação à área do estado
float calcularDensidadePopulacional(struct Estado estado) {
    return estado.populacao / estado.area;  // Densidade = População / Área
}

// Função para calcular o PIB per capita
// Justificativa: O PIB per capita é uma medida importante para comparar o desenvolvimento econômico de estados
double calcularPibPerCapita(struct Estado estado) {
    return (estado.pib * 1000000000) / estado.populacao;  // PIB per capita = PIB / População
}

// Função para contar pontos turísticos
// Justificativa: Contamos o número de pontos turísticos separando-os por vírgulas
int contarPontosTuristicos(const char *pontos) {
    int count = 1;  // Inicia com 1, pois sempre haverá pelo menos um ponto turístico
    for (int i = 0; pontos[i] != '\0'; i++) {
        if (pontos[i] == ',') {  // Se encontrar uma vírgula, é um novo ponto turístico
            count++;  // Incrementa o contador
        }
    }
    return count;
}

// Função para calcular o "Super Poder" (uma métrica personalizada para comparação entre estados)
// Justificativa: O "super poder" é uma métrica composta que leva em conta vários fatores (população, área, PIB, etc.)
// Ele é calculado como a soma de vários fatores para representar o "impacto" de um estado de forma global.
float calcularSuperPoder(struct Estado estado) {
    return estado.populacao + estado.area + estado.pib + estado.numPontosTuristicos + estado.pibPerCapita + (1 / estado.densidadePopulacional);
}

// Função para exibir informações do Estado
void exibirEstado(struct Estado estado) {
    // Exibe informações detalhadas sobre o estado
    printf("\n===================================\n");
    printf("Estado: %s\n", estado.nome);
    printf("Capital: %s\n", estado.capital);
    printf("Cidade em Destaque: %s\n", estado.cidadeDestaque);
    printf("População: %d habitantes\n", estado.populacao);
    printf("Área: %.2f km²\n", estado.area);
    printf("PIB: R$ %.2f bilhões\n", estado.pib);
    printf("Pontos Turísticos: %s\n", estado.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", estado.densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", estado.pibPerCapita);
    printf("Super Poder: %.2f\n", estado.superPoder);  // Exibe o super poder, que é uma métrica personalizada
    printf("===================================\n\n");
}

// Função para comparar dois estados e exibir o vencedor
// Justificativa: A comparação entre os estados é feita com base em várias categorias. A função exibe qual estado vence em cada categoria
// e, ao final, calcula o vencedor geral baseado em quantas categorias ele ganhou.
void compararEstados(struct Estado e1, struct Estado e2) {
    int pontosE1 = 0, pontosE2 = 0;
    
    printf("\nComparação de Cartas:\n");
    printf("-------------------------------------------------\n");
    
    // Categorias para comparação (População, Área, PIB, PIB per Capita, Densidade Populacional e Super Poder)
    struct {
        char nome[50];  // Nome da categoria
        int e1Maior;  // 1 se o estado 1 vencer a categoria, 0 caso contrário
    } categorias[] = {
        {"População", e1.populacao > e2.populacao},  // Categoria População
        {"Área", e1.area > e2.area},  // Categoria Área
        {"PIB", e1.pib > e2.pib},  // Categoria PIB
        {"PIB per Capita", e1.pibPerCapita > e2.pibPerCapita},  // Categoria PIB per Capita
        {"Densidade Populacional", e1.densidadePopulacional < e2.densidadePopulacional},  // Menor densidade populacional vence
        {"Super Poder", e1.superPoder > e2.superPoder}  // Categoria "Super Poder" (inovação)
    };

    // Itera sobre as categorias para comparar os estados
    for (int i = 0; i < 6; i++) {
        printf("%s: %s venceu\n", categorias[i].nome, categorias[i].e1Maior ? e1.nome : e2.nome);
        pontosE1 += categorias[i].e1Maior;  // Se o estado 1 venceu a categoria, incrementa os pontos de e1
        pontosE2 += !categorias[i].e1Maior;  // Se o estado 2 venceu, incrementa os pontos de e2
    }
    
    // Exibe o vencedor geral, baseado em quantas categorias cada estado venceu
    printf("-------------------------------------------------\n");
    printf("Vencedor Geral: %s\n\n", pontosE1 > pontosE2 ? e1.nome : e2.nome);
}

int main() {
    // Dados iniciais dos estados
    struct Estado estados[3] = {
        {"Bahia", "Salvador", "Camacari", 14930634, 564692.669, 284.56, "Pelourinho, Elevador Lacerda, Farol da Barra"},
        {"Sao Paulo", "Sao Paulo", "Campinas", 46289333, 248209.426, 2384.78, "Avenida Paulista, Parque Ibirapuera, Mercadao Municipal"},
        {"Rio de Janeiro", "Rio de Janeiro", "Niteroi", 17366189, 43696.054, 758.45, "Cristo Redentor, Pao de Acucar, Praia de Copacabana"}
    };
    
    // Preenche os dados adicionais para cada estado, como densidade populacional, PIB per capita, número de pontos turísticos e super poder
    for (int i = 0; i < 3; i++) {
        estados[i].densidadePopulacional = calcularDensidadePopulacional(estados[i]);
        estados[i].pibPerCapita = calcularPibPerCapita(estados[i]);
        estados[i].numPontosTuristicos = contarPontosTuristicos(estados[i].pontosTuristicos);
        estados[i].superPoder = calcularSuperPoder(estados[i]);
    }
    
    char entrada[10];
    int escolha1, escolha2;
    do {
        printf("\nEscolha um estado:\n");
        for (int i = 0; i < 3; i++) {
            printf("%d - %s\n", i + 1, estados[i].nome);
        }
        printf("Digite 'sair' para encerrar.\n");
        
        // Lê a escolha dos estados
        printf("\nEscolha o primeiro estado: ");
        scanf("%s", entrada);
        if (strcmp(entrada, "sair") == 0) break;
        escolha1 = atoi(entrada) - 1;
        
        printf("Escolha o segundo estado: ");
        scanf("%s", entrada);
        if (strcmp(entrada, "sair") == 0) break;
        escolha2 = atoi(entrada) - 1;
        
        // Valida se a entrada foi correta
        if (escolha1 < 0 || escolha1 >= 3 || escolha2 < 0 || escolha2 >= 3) {
            printf("Entrada inválida! Tente novamente.\n");
            continue;
        }
        
        // Exibe os estados e compara
        exibirEstado(estados[escolha1]);
        exibirEstado(estados[escolha2]);
        compararEstados(estados[escolha1], estados[escolha2]);
        
    } while (1);
    
    return 0;
}

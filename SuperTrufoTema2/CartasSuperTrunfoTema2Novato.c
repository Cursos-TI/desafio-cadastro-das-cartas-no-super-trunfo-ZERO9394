#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para representar um Estado
// Esta estrutura é usada para armazenar informações sobre um estado, como seu nome, cidade, população, PIB, entre outros dados
struct Estado {
    char nome[50];  // Nome do estado (exemplo: "São Paulo")
    char codigo[20];  // Código da carta (exemplo: "SP")
    char cidadeDestaque[50];  // Cidade em destaque no estado (exemplo: "São Paulo")
    int populacao;  // População do estado (exemplo: 46289333 para São Paulo)
    float area;  // Área do estado em km² (exemplo: 248209.426 km² para São Paulo)
    float pib;  // PIB do estado em bilhões de reais (exemplo: 2384.78 bilhões para São Paulo)
    int numPontosTuristicos;  // Número de pontos turísticos no estado (exemplo: 3 para São Paulo)
};

// Função para calcular a densidade populacional
// Fórmula: Densidade Populacional = População / Área
// Retorna o valor da densidade populacional do estado
float calcularDensidadePopulacional(struct Estado estado) {
    return estado.populacao / estado.area;  // Densidade populacional = População / Área
}

// Função para calcular o PIB per capita
// Fórmula: PIB per capita = PIB / População
// Retorna o valor do PIB per capita do estado
float calcularPibPerCapita(struct Estado estado) {
    return estado.pib * 1000000000 / estado.populacao;  // PIB per capita = PIB (em bilhões) * 1.000.000.000 / População
}

// Função para comparar dois estados em relação à População
// O programa escolhe o atributo População para fazer a comparação
// O estado com a maior população vence
void compararEstados(struct Estado e1, struct Estado e2) {
    printf("\nComparação de Cartas (Atributo: População):\n");
    printf("-------------------------------------------------\n");

    // Comparação da População entre os dois estados
    printf("Carta 1 - Estado: %s (%s) - População: %d\n", e1.nome, e1.codigo, e1.populacao);
    printf("Carta 2 - Estado: %s (%s) - População: %d\n", e2.nome, e2.codigo, e2.populacao);

    // Comparando as populações de e1 e e2 e exibindo o vencedor
    if (e1.populacao > e2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu! Maior População.\n", e1.nome);
    } else if (e1.populacao < e2.populacao) {
        printf("Resultado: Carta 2 (%s) venceu! Maior População.\n", e2.nome);
    } else {
        printf("Resultado: Empate! Ambos têm a mesma população.\n");
    }

    printf("-------------------------------------------------\n");
}

// Função principal onde o código é executado
int main() {
    // Dados iniciais dos estados: Bahia, São Paulo e Rio de Janeiro
    // Cada estado é representado por uma estrutura com as informações necessárias
    struct Estado estados[3] = {
        {"Bahia", "BA", "Salvador", 14930634, 564692.669, 284.56, 3},
        {"São Paulo", "SP", "Campinas", 46289333, 248209.426, 2384.78, 3},
        {"Rio de Janeiro", "RJ", "Niterói", 17366189, 43696.054, 758.45, 3}
    };

    // Preenchemos os dados calculados com base nas funções criadas
    // Calculamos a densidade populacional e o PIB per capita para cada estado
    for (int i = 0; i < 3; i++) {
        // Exibindo a densidade populacional calculada
        printf("Densidade Populacional do estado %s: %.2f\n", estados[i].nome, calcularDensidadePopulacional(estados[i]));
        
        // Exibindo o PIB per capita calculado
        printf("PIB per capita do estado %s: %.2f\n", estados[i].nome, calcularPibPerCapita(estados[i]));
    }

    // Comparação entre os dois primeiros estados (Bahia e São Paulo)
    // A comparação é feita com base na População (Atributo fixo)
    compararEstados(estados[0], estados[1]);

    return 0;  // Retorno do programa (indica que o programa foi executado com sucesso)
}

# Jogo de Comparação de Estados

Este projeto é um jogo de comparação entre estados brasileiros, onde você pode comparar dados como população, PIB, área, pontos turísticos e outras métricas. O objetivo do jogo é avaliar diferentes estados de acordo com várias categorias e determinar qual deles tem mais "potencial" com base nessas comparações.

## Funcionalidades

- **Exibição das informações dos estados**: Mostra detalhes sobre o estado escolhido, incluindo nome, capital, cidade em destaque, população, área, PIB, pontos turísticos, entre outros.
- **Comparação entre estados**: Permite comparar dois estados de forma dinâmica, exibindo quem vence em cada categoria (por exemplo, quem tem mais população, maior PIB, etc).
- **Métrica personalizada (Super Poder)**: Para tornar as comparações mais interessantes e criativas, introduzimos uma métrica inovadora chamada "Super Poder", que é calculada com base em fatores como PIB, população, área e outros indicadores.
- **Contagem de pontos turísticos**: O número de pontos turísticos é calculado automaticamente com base na lista de pontos turísticos fornecida, permitindo uma comparação objetiva entre os estados.

## Como Funciona

1. O programa apresenta uma lista de estados brasileiros.
2. O usuário escolhe dois estados para comparar.
3. As categorias de comparação incluem: população, área, PIB, PIB per capita, densidade populacional e super poder.
4. Ao final, o programa exibe o vencedor de cada categoria e, por fim, o vencedor geral.

**Exemplo de interações**: O programa pode pedir que o usuário escolha dois estados e compare as métricas entre eles, como:

```bash
Escolha um estado:
1 - Bahia
2 - São Paulo
3 - Rio de Janeiro

Escolha o primeiro estado: 1
Escolha o segundo estado: 2

População: São Paulo venceu
Área: Bahia venceu
PIB: São Paulo venceu
...
Vencedor Geral: São Paulo
Inovações no Código
Super Poder: Introduzi uma métrica chamada "Super Poder", que é calculada como a soma de vários indicadores, como PIB, população, área e densidade populacional. Isso permite uma comparação mais complexa entre os estados e torna o jogo mais dinâmico.
Contagem de pontos turísticos: A contagem dos pontos turísticos é feita de forma automática, o que simplifica a comparação entre os estados.
Funções modularizadas: O código foi estruturado de forma modular, com funções dedicadas ao cálculo de métricas como PIB per capita, densidade populacional e super poder.
Como Rodar
Siga as instruções abaixo para rodar o jogo de comparação de estados no seu computador.

Clone o repositório para sua máquina local:
bash
Copy
Edit
git clone https://github.com/seu-usuario/seu-repositorio.git
Acesse o diretório do projeto:
bash
Copy
Edit
cd seu-repositorio
Compile o código:
bash
Copy
Edit
gcc -o jogo_estado jogo_estado.c
Execute o programa:
bash
Copy
Edit
./jogo_estado
Siga as instruções no terminal para jogar.

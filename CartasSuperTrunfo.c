#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste Franklin

// Estrutura da Carta
struct Carta {
    char codigo[4];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
};

int main() {
    struct Carta carta1, carta2;

    // Cadastro da primeira carta
    printf("Cadastro da primeira carta:\n");
    printf("Codigo (ex:A01): ");
    scanf("%s", carta1.codigo);

    printf("Populacao: ");
    scanf("%lu", &carta1.populacao);

    printf("Area (km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (bilhões): ");
    scanf("%f", &carta1.pib);

    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Cadastro da segunda carta
    printf("\nCadastro da segunda carta:\n");
    printf("Codigo (ex:B02): ");
    scanf("%s", carta2.codigo);

    printf("Populacao: ");
    scanf("%lu", &carta2.populacao);

    printf("Area (km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (bilhões): ");
    scanf("%f", &carta2.pib);

    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculos - Carta 1
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

       carta1.superPoder = 
        (float)carta1.populacao +
        carta1.area +
        carta1.pib +
        (float)carta1.pontosTuristicos +
        carta1.pibPerCapita +
        (1.0f / carta1.densidade);

    // Para calcular o Super Poder, converti a população e os pontos turísticos para float,
    // pois o resultado final deve ser float. Isso evita perda de precisão ao somar tipos diferentes.
    // Também usei 1.0f no inverso da densidade para manter a consistência no tipo float,
    // se eu usasse 1 (int) ou 1.0 (double), o compilador poderia gerar perda de precisão.
    // Assim, mantenho o tipo consistente e evito possíveis erros.

    // Cálculos - Carta 2
    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;
    carta2.superPoder = 
        (float)carta2.populacao +
        carta2.area +
        carta2.pib +
        (float)carta2.pontosTuristicos +
        carta2.pibPerCapita +
        (1.0f / carta2.densidade);

    // Exibição dos dados da primeira carta
    printf("\n--- Dados da Primeira Carta ---\n");
    printf("Codigo: %s\n", carta1.codigo);
    printf("Populacao: %lu\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade);
    printf("PIB per Capita: %.6f bilhões/hab\n", carta1.pibPerCapita);
    printf("Super Poder: %.2f\n", carta1.superPoder);

    // Exibição dos dados da segunda carta
    printf("\n--- Dados da Segunda Carta ---\n");
    printf("Codigo: %s\n", carta2.codigo);
    printf("Populacao: %lu\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade);
    printf("PIB per Capita: %.6f bilhões/hab\n", carta2.pibPerCapita);
    printf("Super Poder: %.2f\n", carta2.superPoder);

    // Comparações
    printf("\nComparação de Cartas:\n");

    int venceu;

    venceu = (carta1.populacao > carta2.populacao);
    printf("População: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    venceu = (carta1.area > carta2.area);
    printf("Área: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    venceu = (carta1.pib > carta2.pib);
    printf("PIB: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    venceu = (carta1.pontosTuristicos > carta2.pontosTuristicos);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    venceu = (carta1.densidade < carta2.densidade); // MENOR vence
    printf("Densidade Populacional: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    venceu = (carta1.pibPerCapita > carta2.pibPerCapita);
    printf("PIB per Capita: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    venceu = (carta1.superPoder > carta2.superPoder);
    printf("Super Poder: Carta %d venceu (%d)\n", venceu ? 1 : 2, venceu);

    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}

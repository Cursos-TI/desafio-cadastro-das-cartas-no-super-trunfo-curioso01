#include <stdio.h>    // Biblioteca padrão para entrada e saída
#include <stdlib.h>   // Biblioteca para geração de números aleatórios (rand, srand)
#include <time.h>     // Biblioteca para obter o tempo atual (time)

int main() {
    srand(time(0)); // Inicializa o gerador de números aleatórios com o tempo atual

    // Declaração de variáveis para a carta do jogador
    char codigo1[4], estado1[30];               // Código e estado do jogador
    unsigned long int populacao1;             // População do jogador
    float area1, pib1;                        // Área e PIB do jogador
    int pontosTuristicos1;                    // Pontos turísticos do jogador

    // Geração de atributos aleatórios para o computador, todos começando do valor mínimo 1
    unsigned long int populacao2 = rand() % 9500000 + 1; // População aleatória do computador (>= 1)
    float area2 = rand() % 9900 + 1.0f;                  // Área aleatória do computador (>= 1.0)
    float pib2 = rand() % 95000 + 1.0f;                  // PIB aleatório do computador (>= 1.0)
    int pontosTuristicos2 = rand() % 50 +1;             // Pontos turísticos aleatórios do computador (>= 1)

    // Variáveis auxiliares para cálculos
    float densidade1, densidade2;                        // Densidade demográfica
    float pibPerCapita1, pibPerCapita2;                  // PIB per capita
    float superPoder1, superPoder2;                      // Super poder

    int opcao;                                           // Armazena a escolha do jogador no menu
    int pontosCarta1 = 0, pontosCarta2 = 0;              // Pontuação das cartas
    int opcoesUsadas[8] = {0};                           // Array para registrar opções já escolhidas

    // Entrada de dados do jogador
    printf("Cadastro da sua carta:\n");
    printf("Código: "); scanf("%s", codigo1);                 // Entrada do código da cidade
    printf("Estado: "); scanf("%s", estado1);                   // Entrada do nome do estado

    // Validação da população (deve ser maior ou igual a 1)
    printf("População (>= 1): ");
    scanf("%lu", &populacao1);
    while (populacao1 < 1) {
        printf("Valor inválido. Digite novamente (>= 1): ");
        scanf("%lu", &populacao1);
    }

    // Validação da área (deve ser maior que 0)
    printf("Área (> 0): ");
    scanf("%f", &area1);
    while (area1 <= 0) {
        printf("Valor inválido. Digite novamente (> 0): ");
        scanf("%f", &area1);
    }

    // Validação do PIB (deve ser maior que 0)
    printf("PIB (> 0): ");
    scanf("%f", &pib1);
    while (pib1 <= 0) {
        printf("Valor inválido. Digite novamente (> 0): ");
        scanf("%f", &pib1);
    }

    // Validação dos pontos turísticos (mínimo 1)
    printf("Pontos Turísticos (>= 1): ");
    scanf("%d", &pontosTuristicos1);
    while (pontosTuristicos1 < 1) {
        printf("Valor inválido. Digite novamente (>= 1): ");
        scanf("%d", &pontosTuristicos1);
    }

    // Cálculo dos atributos derivados com base nas entradas e nos dados aleatórios
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = pib1 / populacao1;
    pibPerCapita2 = pib2 / populacao2;
    superPoder1 = (densidade1 + pibPerCapita1 + pontosTuristicos1) / 3.0f;
    superPoder2 = (densidade2 + pibPerCapita2 + pontosTuristicos2) / 3.0f;

    // Loop para 3 rodadas de comparação entre os atributos
    for (int rodada = 1; rodada <= 3; rodada++) {
        printf("\n--- Rodada %d ---\n", rodada);                       // Exibe a rodada atual

        do {
            printf("Escolha um atributo para comparar:\n");
            printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n6 - PIB per Capita\n7 - Super Poder\n");
            printf("Digite a opção: ");
            scanf("%d", &opcao);                                         // Leitura da opção do jogador

            if (opcao < 1 || opcao > 7) {
                printf("Opção inválida. Digite um valor entre 1 e 7.\n");
            } else if (opcoesUsadas[opcao]) {
                printf("Esse atributo já foi escolhido. Escolha outro.\n");
                opcao = -1;
            }
        } while (opcao < 1 || opcao > 7);

        opcoesUsadas[opcao] = 1; // Marca a opção como usada

        // Estrutura de controle que direciona para o tipo de comparação escolhido pelo jogador
        switch (opcao) {
            case 1:
                printf("População - Jogador: %lu | Computador: %lu\n", populacao1, populacao2);
                pontosCarta1 += (populacao1 > populacao2) ? 1 : 0;      
                pontosCarta2 += (populacao2 > populacao1) ? 1 : 0;
                break;
            case 2:
                printf("Área - Jogador: %.2f | Computador: %.2f\n", area1, area2);
                pontosCarta1 += (area1 > area2) ? 1 : 0;
                pontosCarta2 += (area2 > area1) ? 1 : 0;
                break;
            case 3:
                printf("PIB - Jogador: %.2f | Computador: %.2f\n", pib1, pib2);
                pontosCarta1 += (pib1 > pib2) ? 1 : 0;
                pontosCarta2 += (pib2 > pib1) ? 1 : 0;
                break;
            case 4:
                printf("Pontos Turísticos - Jogador: %d | Computador: %d\n", pontosTuristicos1, pontosTuristicos2);
                pontosCarta1 += (pontosTuristicos1 > pontosTuristicos2) ? 1 : 0;
                pontosCarta2 += (pontosTuristicos2 > pontosTuristicos1) ? 1 : 0;
                break;
            case 5:
                printf("Densidade - Jogador: %.2f | Computador: %.2f\n", densidade1, densidade2);
                pontosCarta1 += (densidade1 > densidade2) ? 1 : 0;
                pontosCarta2 += (densidade2 > densidade1) ? 1 : 0;
                break;
            case 6:
                printf("PIB per Capita - Jogador: %.6f | Computador: %.6f\n", pibPerCapita1, pibPerCapita2);
                pontosCarta1 += (pibPerCapita1 > pibPerCapita2) ? 1 : 0;
                pontosCarta2 += (pibPerCapita2 > pibPerCapita1) ? 1 : 0;
                break;
            case 7:
                printf("Super Poder - Jogador: %.2f | Computador: %.2f\n", superPoder1, superPoder2);
                pontosCarta1 += (superPoder1 > superPoder2) ? 1 : 0;
                pontosCarta2 += (superPoder2 > superPoder1) ? 1 : 0;
                break;
        }
    }

    // Exibição do resultado final após as 3 rodadas
    printf("\nPlacar Final - Jogador: %d | Computador: %d\n", pontosCarta1, pontosCarta2);
    if (pontosCarta1 > pontosCarta2)
        printf("Você venceu o jogo!\n");
    else if (pontosCarta2 > pontosCarta1)
        printf("O computador venceu o jogo!\n");
    else
        printf("O jogo terminou empatado!\n");

    return 0; // Encerra o programa
}

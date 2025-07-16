#include <stdio.h>
#include <string.h>

struct Carta
{
    char estado;
    char cod[50];
    char city[50];
    unsigned long int population;
    float area;
    float pib_value;
    int quant_spaces_turistic;
};

float calcDensidade(struct Carta c)
{
    return c.population / c.area;
}

float calcSuperPoder(struct Carta c)
{
    float densidade = calcDensidade(c);
    float inversoDensidade = 1.0 / densidade;
    return inversoDensidade + c.area + c.pib_value + c.population + c.quant_spaces_turistic;
}

void exibirCarta(struct Carta c, int index)
{
    printf("\n--- Carta %d ---\n", index + 1);
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.cod);
    printf("Cidade: %s\n", c.city);
    printf("População: %lu\n", c.population);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f\n", c.pib_value);
    printf("Espaços Turísticos: %d\n", c.quant_spaces_turistic);
    printf("Densidade Populacional: %.4f hab/km²\n", calcDensidade(c));
    printf("Super Poder: %.2f\n", calcSuperPoder(c));
}

int main()
{
    struct Carta cartas[2];
    printf("\n--- Carta 1 ---\n");

    printf("Digite a sigla do estado (uma letra de A a H): ");
    scanf(" %c", &cartas[0].estado);

    printf("Digite o código da cidade (Ex: A01) : ");
    scanf("%s", cartas[0].cod);

    getchar();
    printf("Digite o nome da cidade: ");
    fgets(cartas[0].city, 50, stdin);
    cartas[0].city[strcspn(cartas[0].city, "\n")] = 0;

    printf("Digite a população: ");
    scanf("%lu", &cartas[0].population);

    printf("Digite a área da cidade: ");
    scanf("%f", &cartas[0].area);

    printf("Digite o valor do PIB: ");
    scanf("%f", &cartas[0].pib_value);

    printf("Digite a quantidade de espaços turísticos: ");
    scanf("%d", &cartas[0].quant_spaces_turistic);

    printf("\n--- Carta 2 ---\n");

    printf("Digite a sigla do estado (uma letra de A a H): ");
    scanf(" %c", &cartas[1].estado);

    printf("Digite o código da cidade (Ex: A01) : ");
    scanf("%s", cartas[1].cod);

    getchar();
    printf("Digite o nome da cidade: ");
    fgets(cartas[1].city, 50, stdin);
    cartas[1].city[strcspn(cartas[1].city, "\n")] = 0;

    printf("Digite a população: ");
    scanf("%lu", &cartas[1].population);

    printf("Digite a área da cidade: ");
    scanf("%f", &cartas[1].area);

    printf("Digite o valor do PIB: ");
    scanf("%f", &cartas[1].pib_value);

    printf("Digite a quantidade de espaços turísticos: ");
    scanf("%d", &cartas[1].quant_spaces_turistic);

    exibirCarta(cartas[0], 0);
    exibirCarta(cartas[1], 1);

    printf("\n=== Comparação ===\n");
    printf("PIB: Carta %d venceu\n",
           cartas[0].pib_value > cartas[1].pib_value ? 1 : 2);

    printf("População: Carta %d venceu\n",
           cartas[0].population > cartas[1].population ? 1 : 2);

    printf("Área: Carta %d venceu\n",
           cartas[0].area > cartas[1].area ? 1 : 2);

    printf("Espaços Turísticos: Carta %d venceu\n",
           cartas[0].quant_spaces_turistic > cartas[1].quant_spaces_turistic ? 1 : 2);

    float d1 = calcDensidade(cartas[0]);
    float d2 = calcDensidade(cartas[1]);
    printf("Densidade Populacional (menor vence): Carta %d venceu\n",
           d1 < d2 ? 1 : 2);

    float s1 = calcSuperPoder(cartas[0]);
    float s2 = calcSuperPoder(cartas[1]);
    printf("Super Poder: Carta %d venceu\n",
           s1 > s2 ? 1 : 2);

    return 0;
}

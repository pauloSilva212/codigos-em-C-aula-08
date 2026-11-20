#include <stdio.h>
#include <string.h>
#include <math.h>

long long fatorial(int n) {
    if (n <= 1) return 1;
    long long fat = 1;
    for (int i = 2; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

long long potencia(long long base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

double calcularMediaPonderada(double linha[], int qtd) {
    double somaProdutos = 0;
    int somaPesos = 0;
    for (int i = 0; i < qtd; i++) {
        int peso = i + 1;
        somaProdutos += linha[i] * peso;
        somaPesos += peso;
    }
    return somaProdutos / somaPesos;
}

int main() {
    char nomes[4][50];
    int idades[4];
    long long ids[4];
    int qtdValores;

    printf("Quantidade de valores por participante: ");
    scanf("%d", &qtdValores);

    double matriz[4][qtdValores];

    for (int i = 0; i < 4; i++) {
        printf("\nNome do %do participante: ", i + 1);
        scanf(" %[^\n]", nomes[i]);
        printf("Idade: ");
        scanf("%d", &idades[i]);

        long long idAtual = fatorial(idades[i]) / 2;
        int idadeBase = idades[i];
        int duplicado = 1;

        while (duplicado) {
            duplicado = 0;
            for (int j = 0; j < i; j++) {
                if (ids[j] == idAtual) {
                    duplicado = 1;
                    break;
                }
            }
            if (duplicado) {
                idadeBase = idadeBase / 2;
                idAtual = potencia(fatorial(idadeBase), qtdValores);
            }
        }
        ids[i] = idAtual;

        for (int j = 0; j < qtdValores; j++) {
            printf("Digite o %do valor para %s: ", j + 1, nomes[i]);
            scanf("%lf", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                char auxNome[50];
                strcpy(auxNome, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], auxNome);

                int auxIdade = idades[j];
                idades[j] = idades[j + 1];
                idades[j + 1] = auxIdade;

                long long auxId = ids[j];
                ids[j] = ids[j + 1];
                ids[j + 1] = auxId;

                for (int k = 0; k < qtdValores; k++) {
                    double auxVal = matriz[j][k];
                    matriz[j][k] = matriz[j + 1][k];
                    matriz[j + 1][k] = auxVal;
                }
            }
        }
    }

    double lados[2];
    int qtdLados = 0;
    for (int i = 0; i < 4 && qtdLados < 2; i++) {
        for (int j = 0; j < qtdValores && qtdLados < 2; j++) {
            if (matriz[i][j] >= 0) {
                lados[qtdLados] = matriz[i][j];
                qtdLados++;
            }
        }
    }

    printf("\n--- RESULTADO FINAL ---\n");
    if (qtdLados < 2) {
        printf("Nao foi possivel calcular a diagonal do retangulo.\n");
    } else {
        double diagonal = sqrt((lados[0] * lados[0]) + (lados[1] * lados[1]));

        for (int i = 0; i < 4; i++) {
            double media = calcularMediaPonderada(matriz[i], qtdValores);
            printf("%s - ", nomes[i]);
            if (media > diagonal) {
                printf("Acima da diagonal\n");
            } else if (media < diagonal) {
                printf("Abaixo da diagonal\n");
            } else {
                printf("Sobre a diagonal\n");
            }
        }
    }

    return 0;
}

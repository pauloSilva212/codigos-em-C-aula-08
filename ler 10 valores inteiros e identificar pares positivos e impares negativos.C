#include <stdio.h>

int main() {
    int val[10];
    int posPar[10], negImpar[10];
    int qtdPosPar = 0, qtdNegImpar = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite o %do valor: ", i + 1);
        scanf("%d", &val[i]);

        if (val[i] > 0 && val[i] % 2 == 0) {
            posPar[qtdPosPar] = val[i];
            qtdPosPar++;
        } else if (val[i] < 0 && val[i] % 2 != 0) {
            negImpar[qtdNegImpar] = val[i];
            qtdNegImpar++;
        }
    }

    for (int i = 0; i < qtdPosPar - 1; i++) {
        for (int j = 0; j < qtdPosPar - i - 1; j++) {
            if (posPar[j] > posPar[j + 1]) {
                int aux = posPar[j];
                posPar[j] = posPar[j + 1];
                posPar[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < qtdNegImpar - 1; i++) {
        for (int j = 0; j < qtdNegImpar - i - 1; j++) {
            if (negImpar[j] > negImpar[j + 1]) {
                int aux = negImpar[j];
                negImpar[j] = negImpar[j + 1];
                negImpar[j + 1] = aux;
            }
        }
    }

    printf("\nPositivos e pares (ordem crescente):\n");
    for (int i = 0; i < qtdPosPar; i++) {
        printf("%d ", posPar[i]);
    }

    printf("\n\nNegativos e impares (ordem crescente):\n");
    for (int i = 0; i < qtdNegImpar; i++) {
        printf("%d ", negImpar[i]);
    }
    printf("\n");

    return 0;
}

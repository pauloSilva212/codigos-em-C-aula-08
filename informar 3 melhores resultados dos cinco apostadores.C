#include <stdio.h>

long long somaFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    long long a = 1, b = 1, soma = 2;
    for (int i = 3; i <= n; i++) {
        long long prox = a + b;
        soma += prox;
        a = b;
        b = prox;
    }
    return soma;
}

int ehPrimo(long long num) {
    if (num <= 1) return 0;
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    char nomes[5][50];
    int valores[5];
    long long resultados[5];
    int premiado[5] = {0};

    int primeiro = -1, segundo = -1, terceiro = -1;

    for (int i = 0; i < 5; i++) {
        printf("Nome do %do apostador: ", i + 1);
        scanf(" %[^\n]", nomes[i]);
        
        do {
            printf("Valor inteiro positivo: ");
            scanf("%d", &valores[i]);
        } while (valores[i] <= 0);

        resultados[i] = somaFibonacci(valores[i]);
    }

    long long maiorPrimo = -1;
    for (int i = 0; i < 5; i++) {
        if (ehPrimo(resultados[i]) && resultados[i] > maiorPrimo) {
            maiorPrimo = resultados[i];
            primeiro = i;
        }
    }
    if (primeiro != -1) {
        premiado[primeiro] = 1;
    }

    long long maiorPar = -1;
    for (int i = 0; i < 5; i++) {
        if (!premiado[i] && resultados[i] % 2 == 0 && resultados[i] > maiorPar) {
            maiorPar = resultados[i];
            segundo = i;
        }
    }
    if (segundo != -1) {
        premiado[segundo] = 1;
    }

    double somaTotal = 0;
    for (int i = 0; i < 5; i++) {
        somaTotal += resultados[i];
    }
    double media = somaTotal / 5.0;

    long long maiorAcimaMedia = -1;
    for (int i = 0; i < 5; i++) {
        if (!premiado[i] && resultados[i] > media && resultados[i] > maiorAcimaMedia) {
            maiorAcimaMedia = resultados[i];
            terceiro = i;
        }
    }
    if (terceiro != -1) {
        premiado[terceiro] = 1;
    }

    printf("\n--- RESULTADO FINAL ---\n");
    if (primeiro != -1) {
        printf("1o Lugar: %s\n", nomes[primeiro]);
    } else {
        printf("1o Lugar: Sem vencedor\n");
    }

    if (segundo != -1) {
        printf("2o Lugar: %s\n", nomes[segundo]);
    } else {
        printf("2o Lugar: Sem vencedor\n");
    }

    if (terceiro != -1) {
        printf("3o Lugar: %s\n", nomes[terceiro]);
    } else {
        printf("3o Lugar: Sem vencedor\n");
    }

    return 0;
}

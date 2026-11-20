#include <stdio.h>
#include <string.h>

int main() {
    int num[12], dist[12], freq[12], pares[12];
    int qtdDist = 0, qtdPares = 0, qtdProd = 0;
    char nomes[12];
    float precos[12];
    int qtdCompra[12];

    for (int i = 0; i < 12; i++) {
        printf("Digite o %do numero: ", i + 1);
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < 12; i++) {
        int achou = 0;
        for (int j = 0; j < qtdDist; j++) {
            if (num[i] == dist[j]) {
                freq[j]++;
                achou = 1;
                break;
            }
        }
        if (!achou) {
            dist[qtdDist] = num[i];
            freq[qtdDist] = 1;
            qtdDist++;
        }
    }

    for (int i = 0; i < qtdDist; i++) {
        if (freq[i] % 2 == 0) {
            pares[qtdPares] = dist[i];
            qtdPares++;
        } else {
            printf("\nNumero %d (ocorrencia impar) -> Qtd a comprar: %d\n", dist[i], dist[i]);
            qtdCompra[qtdProd] = dist[i];
            printf("Nome do produto: ");
            scanf(" %[^\n]", nomes[qtdProd]);
            printf("Preco unitario: ");
            scanf("%f", &precos[qtdProd]);
            qtdProd++;
        }
    }

    for (int i = 0; i < qtdPares - 1; i++) {
        for (int j = 0; j < qtdPares - i - 1; j++) {
            if (pares[j] < pares[j + 1]) {
                int aux = pares[j];
                pares[j] = pares[j + 1];
                pares[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < qtdProd - 1; i++) {
        for (int j = 0; j < qtdProd - i - 1; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                char auxNome;
                strcpy(auxNome, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], auxNome);

                float auxPreco = precos[j];
                precos[j] = precos[j + 1];
                precos[j + 1] = auxPreco;

                int auxQtd = qtdCompra[j];
                qtdCompra[j] = qtdCompra[j + 1];
                qtdCompra[j + 1] = auxQtd;
            }
        }
    }

    printf("\na) Numeros informados:\n");
    for (int i = 0; i < 12; i++) {
        printf("%d ", num[i]);
    }

    printf("\n\nb) Frequencia de cada numero:\n");
    for (int i = 0; i < qtdDist; i++) {
        printf("Numero %d: %d vez(es)\n", dist[i], freq[i]);
    }

    printf("\nc) Produtos cadastrados (ordem alfabetica):\n");
    for (int i = 0; i < qtdProd; i++) {
        printf("%s - R$ %.2f (Qtd: %d)\n", nomes[i], precos[i], qtdCompra[i]);
    }

    printf("\nd) Numeros com ocorrencia par (decrescente):\n");
    for (int i = 0; i < qtdPares; i++) {
        printf("%d ", pares[i]);
    }
    printf("\n");

    return 0;
}

#include <stdio.h>

int main() {
    int num;
    int dist, freq;
    int qtdDist = 0;

    char animais;
    int qtdAnimais = 0;

    for (int i = 0; i < 15; i++) {
        printf("Digite o %do numero: ", i + 1);
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < 15; i++) {
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

    printf("\na) Numeros que aparecem mais de uma vez:\n");
    for (int i = 0; i < qtdDist; i++) {
        if (freq[i] > 1) {
            printf("Numero %d -> %d ocorrencias\n", dist[i], freq[i]);
        }
    }

    printf("\nb) Cadastro de animais (primos com ocorrencia impar):\n");
    for (int i = 0; i < qtdDist; i++) {
        if (freq[i] > 1 && freq[i] % 2 != 0) {
            int primo = 1;
            if (dist[i] <= 1) {
                primo = 0;
            } else {
                for (int d = 2; d < dist[i]; d++) {
                    if (dist[i] % d == 0) {
                        primo = 0;
                        break;
                    }
                }
            }

            if (primo) {
                int soma = dist[i] * freq[i];
                printf("\nNumero primo %d (%d ocorrencias) -> Soma = %d. Cadastre %d animal(is):\n", dist[i], freq[i], soma, soma);
                for (int k = 0; k < soma; k++) {
                    printf("Nome do animal %d: ", qtdAnimais + 1);
                    scanf(" %[^\n]", animais[qtdAnimais]);
                    qtdAnimais++;
                }
            }
        }
    }

    printf("\nc) e d) Correspondencia de animais para numeros com ocorrencia par:\n");
    if (qtdAnimais == 0) {
        printf("Nenhum animal foi cadastrado para fazer a correspondencia.\n");
    } else {
        for (int i = 0; i < qtdDist; i++) {
            if (freq[i] > 1 && freq[i] % 2 == 0) {
                printf("Numero %d (%d ocorrencias) aparece nas posicoes do vetor:\n", dist[i], freq[i]);
                for (int pos = 0; pos < 15; pos++) {
                    if (num[pos] == dist[i]) {
                        int indiceAnimal = pos % qtdAnimais;
                        printf(" - Posicao %d -> Animal: %s\n", pos, animais[indiceAnimal]);
                    }
                }
            }
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define ARQ_NUMEROS "numeros.bin"
#define ARQ_PARES "pares.bin"

main() {
    FILE *arquivoNumeros, *arquivoPares;
    int qtd, i, numero;

    printf("Quantos numeros deseja inserir? ");
    scanf("%d", &qtd);

    // 1 - Criar e gravar numeros.bin
    arquivoNumeros = fopen(ARQ_NUMEROS, "wb");
    if (arquivoNumeros == NULL) {
        printf("Erro: nao foi possivel criar o arquivo '%s'.\n", ARQ_NUMEROS);
    }

    for (i = 0; i < qtd; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numero);
        fwrite(&numero, sizeof(int), 1, arquivoNumeros);
    }
    fclose(arquivoNumeros);

    // 2 - Ler numeros.bin e gravar
    arquivoNumeros = fopen(ARQ_NUMEROS, "rb");
    if (arquivoNumeros == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo '%s'.\n", ARQ_NUMEROS);
    }

    arquivoPares = fopen(ARQ_PARES, "wb");
    if (arquivoPares == NULL) {
        printf("Erro: nao foi possivel criar o arquivo '%s'.\n", ARQ_PARES);
        fclose(arquivoNumeros);
    }

    while (fread(&numero, sizeof(int), 1, arquivoNumeros) == 1) {
        if (numero % 2 == 0) {
            fwrite(&numero, sizeof(int), 1, arquivoPares);
        }
    }

    fclose(arquivoNumeros);
    fclose(arquivoPares);

    printf("\nProcesso concluido!\n");
    printf("Arquivo '%s' contem todos os numeros.\n", ARQ_NUMEROS);
    printf("Arquivo '%s' contem apenas os pares.\n", ARQ_PARES);
}
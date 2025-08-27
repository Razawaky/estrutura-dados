#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct paciente {
    char nom[50];
    int idade;
    float altura;
    float peso;
    float imc;
};

main() {
    FILE *arquivoPacientes;
    int qtd, i;
    struct paciente p;

    printf("Quantos pacientes deseja cadastrar? ");
    scanf("%d", &qtd);

    arquivoPacientes = fopen(ARQ_PACIENTES, "wb"); // Cria e grava pacientes bin
    if (arquivoPacientes == NULL) {
        printf("Erro: nao foi possivel criar o arquivo '%s'.\n", ARQ_PACIENTES);
    }

    for (i = 0; i < qtd; i++) {
        printf("\n--- Paciente %d ---\n", i + 1);
        printf("Nome: ");
        fgets(p.nom, sizeof(p.nom), stdin);
        p.nom[strcspn(p.nom, "\n")] = '\0'; // remover \n do final

        printf("Idade: ");
        scanf("%d", &p.idade);

        printf("Altura (em metros, ex: 1.75): ");
        scanf("%f", &p.altura);

        printf("Peso (em kg): ");
        scanf("%f", &p.peso);

        // Calcular IMC
        p.imc = p.peso / (p.altura * p.altura);

        fwrite(&p, sizeof(struct paciente), 1, arquivoPacientes); 
    }
    fclose(arquivoPacientes);

    // ler pacientes e exibir
    arquivoPacientes = fopen(ARQ_PACIENTES, "rb");
    if (arquivoPacientes == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo '%s'.\n", ARQ_PACIENTES);
    }

    printf("\n===== Lista de Pacientes =====\n");
    while (fread(&p, sizeof(struct paciente), 1, arquivoPacientes) == 1) {
        printf("Nome: %s | Idade: %d | Altura: %.2f m | Peso: %.2f kg | IMC: %.2f\n",
               p.nom, p.idade, p.altura, p.peso, p.imc);
    }
    fclose(arquivoPacientes);
}
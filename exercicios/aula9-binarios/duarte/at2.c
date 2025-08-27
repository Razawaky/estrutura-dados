#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ_PACIENTES "pacientes.bin"

struct paciente {
    char nom[50];
    int idade;
    float altura;
    float peso;
    float imc;
};

main() {
    FILE *arquivoPacientes;
    struct paciente p;

    // Abrir o arquivo para leitura
    arquivoPacientes = fopen(ARQ_PACIENTES, "rb");
    if (arquivoPacientes == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo '%s'.\n", ARQ_PACIENTES);
        printf("Certifique-se de que o arquivo existe e que pacientes foram cadastrados antes.\n");
    }

    printf("\n===== Lista de Pacientes =====\n");
    int count = 0;
    while (fread(&p, sizeof(struct paciente), 1, arquivoPacientes) == 1) {
        printf("Nome: %s | Idade: %d | Altura: %.2f m | Peso: %.2f kg | IMC: %.2f\n",
               p.nom, p.idade, p.altura, p.peso, p.imc);
        count++;
    }

    if (count == 0) {
        printf("Nenhum paciente cadastrado.\n");
    }

    fclose(arquivoPacientes);
}
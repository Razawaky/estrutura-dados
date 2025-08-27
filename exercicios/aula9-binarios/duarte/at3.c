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

    arquivoPacientes = fopen(ARQ_PACIENTES, "rb");
    if (arquivoPacientes == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo '%s'.\n", ARQ_PACIENTES);
    }

    // fseek desloca o "cursor" do arquivo para o 3 registro
    if (fseek(arquivoPacientes, sizeof(struct paciente) * 2, SEEK_SET) != 0) {
        printf("Erro ao posicionar no 3 paciente.\n");
        fclose(arquivoPacientes);
    }

    // Ler o 3 paciente
    if (fread(&p, sizeof(struct paciente), 1, arquivoPacientes) == 1) {
        printf("\n===== Terceiro Paciente =====\n");
        printf("Nome: %s\n", p.nom);
        printf("Idade: %d\n", p.idade);
        printf("Altura: %.2f m\n", p.altura);
        printf("Peso: %.2f kg\n", p.peso);
        printf("IMC: %.2f\n", p.imc);
    } else {
        printf("Nao foi possivel ler o terceiro paciente (talvez o arquivo tenha menos de 3 registros).\n");
    }

    fclose(arquivoPacientes);
}
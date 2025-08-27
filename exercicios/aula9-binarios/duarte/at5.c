#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ "dados.bin"

typedef struct {
    int id;
    char nome[50];
    int idade;
} Pessoa;

void inserir();
void listar();
void alterar();
void excluir();

main() {
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir\n");
        printf("2 - Listar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // consumir '\n'

        switch(opcao) {
            case 1: inserir(); break;
            case 2: listar(); break;
            case 3: alterar(); break;
            case 4: excluir(); break;
            case 5: printf("Encerrando...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 5);
}

void inserir() {
    FILE *arquivoCadastro = fopen(ARQ, "ab"); 
    if (arquivoCadastro == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }

    Pessoa p;
    printf("ID: ");
    scanf("%d", &p.id);
    getchar();
    printf("Nome: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';
    printf("Idade: ");
    scanf("%d", &p.idade);

    fwrite(&p, sizeof(Pessoa), 1, arquivoCadastro);
    fclose(arquivoCadastro);
    printf("Registro inserido!\n");
}

void listar() {
    FILE *arquivoCadastro = fopen(ARQ, "rb");
    if (arquivoCadastro == NULL) {
        printf("Nenhum registro encontrado.\n");
        return;
    }

    Pessoa p;
    printf("\n--- Lista de Pessoas ---\n");
    while (fread(&p, sizeof(Pessoa), 1, arquivoCadastro) == 1) {
        printf("ID: %d | Nome: %s | Idade: %d\n", p.id, p.nome, p.idade);
    }
    fclose(arquivoCadastro);
}

void alterar() {
    FILE *arquivoCadastro = fopen(ARQ, "r+b");
    if (arquivoCadastro == NULL) {
        printf("Arquivo não encontrado.\n");
        return;
    }

    int id;
    printf("Digite o ID para alterar: ");
    scanf("%d", &id);
    getchar();

    Pessoa p;
    while (fread(&p, sizeof(Pessoa), 1, arquivoCadastro) == 1) {
        if (p.id == id) {
            printf("Novo nome: ");
            fgets(p.nome, sizeof(p.nome), stdin);
            p.nome[strcspn(p.nome, "\n")] = '\0';
            printf("Nova idade: ");
            scanf("%d", &p.idade);

            fseek(arquivoCadastro, -sizeof(Pessoa), SEEK_CUR);
            fwrite(&p, sizeof(Pessoa), 1, arquivoCadastro);
            printf("Registro alterado!\n");
            fclose(arquivoCadastro);
            return;
        }
    }
    printf("Registro não encontrado.\n");
    fclose(arquivoCadastro);
}

void excluir() {
    FILE *arquivoCadastro = fopen(ARQ, "rb");
    if (arquivoCadastro == NULL) {
        printf("Arquivo não encontrado.\n");
        return;
    }

    FILE *arquivoTemp = fopen("temp.bin", "wb");
    if (arquivoTemp NULL) {
        perror("Erro ao criar arquivo temporário");
        fclose(arquivoCadastro);
        return;
    }

    int id;
    printf("Digite o ID para excluir: ");
    scanf("%d", &id);

    Pessoa p;
    int encontrado = 0;

    while (fread(&p, sizeof(Pessoa), 1, arquivoCadastro) == 1) {
        if (p.id != id) {
            fwrite(&p, sizeof(Pessoa), 1, arquivoTemp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivoCadastro);
    fclose(arquivoTemp);

    remove(ARQ);
    rename("temp.bin", ARQ);

    if (encontrado)
        printf("Registro excluído!\n");
    else
        printf("ID não encontrado.\n");
}
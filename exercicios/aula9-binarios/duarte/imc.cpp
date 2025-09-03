#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <cstring>

int menu();
void gravarPaciente(void);
void listarTodosPacientes(void);
void listarPacientesObesos(void);
void listarPacientesAltos(void);
void listarPacientesVelhos(void);
void listarPacientesSaudaveis(void);
void sugestaoPeso(void);
void sugestaoAltura(void);
void pesquisarPaciente(void);
void alterarPaciente(void);
void excluirPaciente(void);
void apagarTodosPacientes(void);
void excluirPacienteMenosCinquenta(void);

struct paciente {
	char nome[50];
	int idade;
	float altura;
	float peso;
	float imc;
};

main()
{
	int opcao;
	do
	{
		opcao = menu();
		switch (opcao)
		{
			case 1:
			{
				gravarPaciente();
				break;
			}
			case 2:
				
				pesquisarPaciente();
				break;
			case 3:
				
				alterarPaciente();
				break;
			case 4:
				
				excluirPaciente();
			case 5:
			{
				listarTodosPacientes();
				break;
			}
			case 6:
			{
				apagarTodosPacientes();
				break;
			}
			case 7:
			{
				listarPacientesObesos();
				break;
			}
			case 8:
				
				listarPacientesAltos();
				break;
			case 9:
				
				listarPacientesVelhos();
				break;
			case 10:
				
				listarPacientesSaudaveis();
				break;
			case 11:
				
				excluirPacienteMenosCinquenta();
				break;
			case 12:
				
				sugestaoPeso();
				break;
			case 13:
				
				sugestaoAltura();
				break;
			case 0:
			{
				printf("Encerrando...");
				break;				
			}
			default:
			{
				printf("Opcao invalida. Redigite!!!");
				break;
			}
		}	
	} while (opcao != 0);
}

int menu(void)
{
	int op;
	system("cls");
	printf("Gestao de IMC - Estrutura de Dados AMS Fatec Lins");	
	printf("\n\n\n");	
	printf("1) Inserir paciente\n"); // ja foi
	printf("2) Pesquisar paciente por nome\n");
	printf("3) Alterar um paciente\n");
	printf("4) Excluir um paciente\n");
	printf("5) Listar todos os pacientes\n"); // ja foi
	printf("6) Excluir todos os pacientes\n");
	printf("7) Exibir pacientes obesos\n"); // ja foi
	printf("8) Exibir pacientes maiores que 1,70m\n"); // ja foi
	printf("9) Exibir pacientes entre 20 e 50 anos\n"); // ja foi
	printf("10) Exibir pacientes saudáveis\n"); // ja foi
	printf("11) Excluir pacientes com menos de 50kg\n");
	printf("12) Sugestão de peso pela altura\n"); // ja foi
	printf("13) Sugestão de altura e peso\n");// ja foi
	printf("0) Finalizar o sistema\n");
	printf("\n\nDigite a opcao desejada: ");
	scanf("%d", &op);
	return op;
}

void gravarPaciente(void)
{
	struct paciente newPac;
	FILE *arqimc;
	arqimc = fopen("imc.bin", "ab");
	printf("Nome do paciente: ");
	fflush(stdin);
	gets(newPac.nome);
	printf("Idade do paciente: ");
	scanf("%d", &newPac.idade);
	printf("Altura do paciente: ");
	scanf("%f", &newPac.altura);
	printf("Peso do paciente: ");
	scanf("%f", &newPac.peso);
	newPac.imc = newPac.peso / pow(newPac.altura, 2);
	printf("IMC do paciente: %.2f\n", newPac.imc);
	printf("\n\n Paciente cadastrado com sucesso!!! \n\n\n");
	fwrite(&newPac, sizeof(struct paciente), 1, arqimc);
	fclose(arqimc);
	getch();
}
void listarTodosPacientes(void)
{
	struct paciente listPac;
	FILE *arqimc;
	arqimc = fopen("imc.bin", "rb");
	printf("\nLista de pacientes cadastrados: \n\n");
	while((fread(&listPac, sizeof(listPac), 1, arqimc)) == 1)
	{
		printf("Nome do paciente: %s \n", listPac.nome);
		printf("Idade: %d \n", listPac.idade);
		printf("Peso: %.2f \n", listPac.peso);
		printf("Altura: %.2f \n", listPac.altura);
		printf("IMC: %.2f \n\n", listPac.imc);
	}
	fclose(arqimc);
	getch();
}
void listarPacientesObesos(void)
{
	struct paciente listPacObesos;
	FILE *arqimc;
	arqimc = fopen("imc.bin", "rb");
	printf("\nLista de pacientes obesos cadastrados: \n\n");
	while((fread(&listPacObesos, sizeof(listPacObesos), 1, arqimc)) == 1)
	{
		if(listPacObesos.imc > 30){ //obesidade 1 pra cima
			printf("Nome do paciente: %s \n", listPacObesos.nome);
			printf("Idade: %d \n", listPacObesos.idade);
			printf("Peso: %.2f \n", listPacObesos.peso);
			printf("Altura: %.2f \n", listPacObesos.altura);
			printf("IMC: %.2f \n\n", listPacObesos.imc);	
		}
	}
	fclose(arqimc);
	getch();
}
void listarPacientesAltos(void)
{
	struct paciente listPacAltos;
	FILE *arqimc;
	arqimc = fopen("imc.bin", "rb");
	printf("\nLista de pacientes altos cadastrados: \n\n");
	while((fread(&listPacAltos, sizeof(listPacAltos), 1, arqimc)) == 1)
	{
		if(listPacAltos.altura > 1.70){ //obesidade 1 pra cima
			printf("Nome do paciente: %s \n", listPacAltos.nome);
			printf("Idade: %d \n", listPacAltos.idade);
			printf("Peso: %.2f \n", listPacAltos.peso);
			printf("Altura: %.2f \n", listPacAltos.altura);
			printf("IMC: %.2f \n\n", listPacAltos.imc);	
		}
	}
	fclose(arqimc);
	getch();
}
void listarPacientesVelhos(void)
{
	struct paciente listPacVelhos;
	FILE *arqimc;
	arqimc = fopen("imc.bin", "rb");
	printf("\nLista de pacientes entre 20 e 50 anos cadastrados.\n\n");
	while((fread(&listPacVelhos, sizeof(listPacVelhos), 1, arqimc)) == 1)
	{
		if ((listPacVelhos.idade > 20) && (listPacVelhos.idade < 50)) {
            printf("Nome do paciente: %s\n", listPacVelhos.nome);
            printf("Idade: %d\n", listPacVelhos.idade);
            printf("Peso: %.2f\n", listPacVelhos.peso);
            printf("Altura: %.2f\n", listPacVelhos.altura);
            printf("IMC: %.2f\n\n", listPacVelhos.imc);
        }
	}
	fclose(arqimc);
	getch();
}
void listarPacientesSaudaveis(void)
{
	struct paciente listPacSaudaveis;
	FILE *arqimc;
	arqimc = fopen("imc.bin", "rb");
	printf("\nLista de pacientes saudaveis cadastrados: \n\n");
	while((fread(&listPacSaudaveis, sizeof(listPacSaudaveis), 1, arqimc)) == 1)
	{
		if((listPacSaudaveis.imc > 18.5) && (listPacSaudaveis.imc < 24.9)){ //obesidade 1 pra cima
			printf("Nome do paciente: %s \n", listPacSaudaveis.nome);
			printf("Idade: %d \n", listPacSaudaveis.idade);
			printf("Peso: %.2f \n", listPacSaudaveis.peso);
			printf("Altura: %.2f \n", listPacSaudaveis.altura);
			printf("IMC: %.2f \n\n", listPacSaudaveis.imc);	
		}
	}
	fclose(arqimc);
	getch();
}
void sugestaoPeso(void)
{
	float alturaTemporaria, imcTemporario;
	int p;
	
	printf("Por favor, digite uma altura: \n");
	scanf("%f", &alturaTemporaria);
	
	for(p=20;p<=100;p+=5){
		imcTemporario = p / (alturaTemporaria * alturaTemporaria);
		if((imcTemporario > 18.5) && (imcTemporario < 24.9)){
			printf("Sugestao de peso: %d kg\n", p);
		}
	}
	getch();
}
void sugestaoAltura(void)
{
	float pesoTemporario, imcTemporario, a;
	
	printf("Por favor, digite um peso: \n");
	scanf("%f", &pesoTemporario);
	
	for(a=1.20; a < 2.0;a+=0.05){
		imcTemporario = pesoTemporario / (a * a);
		if((imcTemporario > 18.5) && (imcTemporario < 24.9)){
			printf("Sugestao de altura: %.2f\n", a);
		}
	}
	
	getch();
}
// cu
void excluirPacienteMenosCinquenta(void) {
    struct paciente pac;
    FILE *arqimc = fopen("imc.bin", "rb");
    if (!arqimc) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *arqTemp = fopen("temp.bin", "wb");
    if (!arqTemp) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arqimc);
        return;
    }

    int excluidos = 0;

    while (fread(&pac, sizeof pac, 1, arqimc) == 1) {
        if (pac.peso >= 50) {
            fwrite(&pac, sizeof pac, 1, arqTemp);
        } else {
            excluidos++;
        }
    }

    fclose(arqimc);
    fclose(arqTemp);

    remove("imc.bin");
    rename("temp.bin", "imc.bin");

    printf("\n%d paciente(s) com peso menor que 50 kg foram excluídos com sucesso!\n", excluidos);
}

// não fiz, mas ta aqui
void pesquisarPaciente(void)
{
    struct paciente pac;
    FILE *arqimc;
    char nomeBusca[50];
    int encontrado = 0;

    arqimc = fopen("imc.bin", "rb");
    if (arqimc == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    printf("Digite o nome do paciente que deseja pesquisar: ");
    fflush(stdin);
    gets(nomeBusca);

    while (fread(&pac, sizeof(struct paciente), 1, arqimc) == 1) {
        if (strcmp(pac.nome, nomeBusca) == 0) {
            printf("\nPaciente encontrado!\n");
            printf("Nome: %s\n", pac.nome);
            printf("Idade: %d\n", pac.idade);
            printf("Altura: %.2f\n", pac.altura);
            printf("Peso: %.2f\n", pac.peso);
            printf("IMC: %.2f\n", pac.imc);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nPaciente não encontrado.\n");
    }

    fclose(arqimc);
    getch();
}


void excluirPaciente(void)
{
    struct paciente pac;
    FILE *arqimc, *arqTemp;
    char nomeBusca[50];
    int encontrado = 0;

    arqimc = fopen("imc.bin", "rb");
    

    arqTemp = fopen("temp.bin", "wb");
    if (arqTemp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arqimc);
        return;
    }

    printf("Digite o nome do paciente que deseja excluir: ");
    fflush(stdin);
    gets(nomeBusca);

    while (fread(&pac, sizeof(struct paciente), 1, arqimc) == 1) {
        if (strcmp(pac.nome, nomeBusca) == 0) {
            printf("\nPaciente %s excluído com sucesso!\n", pac.nome);
            encontrado = 1;
            // não grava no arquivo temporário
        } else {
            fwrite(&pac, sizeof(struct paciente), 1, arqTemp);
        }
    }

    fclose(arqimc);
    fclose(arqTemp);

    // Substitui o arquivo original pelo temporário
    remove("imc.bin");
    rename("temp.bin", "imc.bin");

    getch();
}
void alterarPaciente(void) {
    struct paciente pac;
    FILE *arqimc;
    char nomeBusca[50];

    arqimc = fopen("imc.bin", "r+b");
    if (!arqimc) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    printf("Digite o nome do paciente que deseja alterar: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; // remove '\n'

    while (fread(&pac, sizeof pac, 1, arqimc) == 1) {
        if (strcmp(pac.nome, nomeBusca) == 0) {
            printf("\nPaciente encontrado!\n");

            printf("Novo nome: ");
            fgets(pac.nome, sizeof(pac.nome), stdin);
            pac.nome[strcspn(pac.nome, "\n")] = '\0';

            printf("Nova idade: ");
            scanf("%d", &pac.idade);

            printf("Nova altura: ");
            scanf("%f", &pac.altura);

            printf("Novo peso: ");
            scanf("%f", &pac.peso);

            pac.imc = pac.peso / pow(pac.altura, 2);

            fseek(arqimc, sizeof pac, SEEK_CUR);
            fwrite(&pac, sizeof pac, 1, arqimc);

            printf("\nPaciente alterado com sucesso!\n");
            fclose(arqimc);
            return;
        }
    }

    printf("\nPaciente não encontrado.\n");
    fclose(arqimc);
    getch();
}

void apagarTodosPacientes(void)
{
    char opcao;

    printf("Tem certeza que deseja apagar TODOS os pacientes? (S/N): ");
    fflush(stdin);
    scanf("%c", &opcao);

    if (opcao == 'S' || opcao == 's') {
        FILE *arqimc = fopen("imc.bin", "wb"); 
        // "wb" recria o arquivo, apagando todo o conteúdo
        if (arqimc == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }
        fclose(arqimc);
        printf("\nTodos os pacientes foram apagados com sucesso!\n");
    } else {
        printf("\nOperação cancelada.\n");
    }

    getch(); // pausa antes de voltar ao menu
}


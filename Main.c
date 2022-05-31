#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
  char login[30];
  char senha[30];
} usuario; usuario u[1];

typedef struct {
  int id;
  char nome[255];
  int cpf;
  int tel;
  char endereco[255];
  char data_nascimento[255];
  char email[255];
  char data_diagnostico;
  char comorbidade;
} paciente; paciente Paciente;

void main() {
  SetConsoleOutputCP(65001);


  if(autenticar() == 0) {
    inserir_paciente();
  }

  SetConsoleOutputCP(GetConsoleOutputCP());
}

int autenticar() {
  strcpy(u[0].login, "admin");
  strcpy(u[0].senha, "1234");

  char login[30];
  char senha[30];

  printf("\nlogin:");
  scanf("%s", login);
  printf("\nsenha:");
  scanf("%s", senha);

  if(strcmp(login,u[0].login) == 0 && strcmp(senha,u[0].senha) == 0) {
    return 0;
  } else {
    printf("Usuário ou senha incorretos!");
    autenticar();
  }
}

void inserir_paciente() {   
  FILE *file;
  int *confirmar;
  char primeira_linha[100];
  char cabecalho = "ID\tNOME\tENDEREÇO";

  printf("\nDeseja adicionar um novo paciente?\n");
  printf("\n1 - Sim");
  printf("\n2 - Não\n\n");
  scanf("%d",confirmar);
  printf("\n");
  
  if(*confirmar == 1) {
    // printf("%d", verifica_cabecalho(cabecalho));
    file = fopen("Pacientes Diagnosticados - COVID-19.txt","r");

    fclose(file);
  } else {
    if(*confirmar == 2) {
      printf("Tudo certo por aqui! Volte sempre!\n\n");
      system("PAUSE");
    } else {
      printf("Valor inválido! O sistema foi encerrado!\n\n");
      system("PAUSE");
    }
  }
}

int verifica_cabecalho(char cabecalho) {
  FILE *file;
  char verifica;
  file = fopen("Pacientes Diagnosticados - COVID-19.txt","r");
  fgets(verifica,100,file);
  fclose(file);

  return strcmp(verifica,cabecalho);
}
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
  char nome[100];
  char cpf[11];
  char tel[20];
  char endereco[100];
  char cep[10];
  char data_nascimento[100];
  char email[100];
  char data_diagnostico[20];
  char comorbidade[100];
} paciente; paciente Paciente;

int main(void) {
  SetConsoleOutputCP(65001);

  if(autenticar() == 0) {
    inserir_paciente();
  }

  SetConsoleOutputCP(GetConsoleOutputCP());
}

int autenticar(void) {
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
  return 0;
}

int inserir_paciente(void) {   
  FILE *file;
  int *confirmar;
  char *filename = "Pacientes Diagnosticados - COVID-19.txt";

  printf("\nDeseja adicionar um novo paciente?\n");
  printf("\n1 - Sim");
  printf("\n2 - Não\n\n");
  scanf("%d",confirmar);
  printf("\n");
  getchar();
  
  if(*confirmar == 1) {
    file = fopen(filename,"a");
    int *id;
    char *cabecalho = "ID   NOME\tCPF\tTELEFONE\tENDEREÇO\tEMAIL\tDATA DE NASCIMENTO\tDATA DO DIAGNÓSTICO\tCOMORBIDADE\n";
    
    if(!get_size(filename)) {
      fprintf(file, cabecalho);
    }

    id = get_id(filename,cabecalho);
    // fprintf(file,"\n");
    fprintf(file,"%d",id);
    fprintf(file,"    ");

    printf("Digite o nome: ");
    fgets(Paciente.nome,100,stdin);
    Paciente.nome[strcspn(Paciente.nome, "\n")] = 0;
    fprintf(file,Paciente.nome);
    fprintf(file,"\t");

    printf("Digite o cpf: ");
    fgets(Paciente.cpf,100,stdin);
    Paciente.cpf[strcspn(Paciente.cpf, "\n")] = 0;
    fprintf(file,Paciente.cpf);
    fprintf(file,"\t");

    printf("Digite o telefone: ");
    fgets(Paciente.tel,100,stdin);
    Paciente.tel[strcspn(Paciente.tel, "\n")] = 0;
    fprintf(file,Paciente.tel);
    fprintf(file,"\t");

    printf("Digite o endereço: ");
    fgets(Paciente.endereco,100,stdin);
    Paciente.endereco[strcspn(Paciente.endereco, "\n")] = 0;
    fprintf(file,Paciente.endereco);
    fprintf(file,"\t");

    printf("Digite o cep: ");
    fgets(Paciente.cep,100,stdin);
    Paciente.cep[strcspn(Paciente.cep, "\n")] = 0;
    fprintf(file,Paciente.cep);
    fprintf(file,"\t");

    printf("Digite a data de nascimento: ");
    fgets(Paciente.data_nascimento,100,stdin);
    Paciente.data_nascimento[strcspn(Paciente.data_nascimento, "\n")] = 0;
    fprintf(file,Paciente.data_nascimento);
    fprintf(file,"\t");

    printf("Digite o e-mail: ");
    fgets(Paciente.email,100,stdin);
    Paciente.email[strcspn(Paciente.email, "\n")] = 0;
    fprintf(file,Paciente.email);
    fprintf(file,"\t");

    printf("Digite a data do diagnóstico: ");
    fgets(Paciente.data_diagnostico,100,stdin);
    Paciente.data_diagnostico[strcspn(Paciente.data_diagnostico, "\n")] = 0;
    fprintf(file,Paciente.data_diagnostico);
    fprintf(file,"\t");

    printf("Paciente possui alguma comorbidade? Qual? ");
    fgets(Paciente.comorbidade,100,stdin);
    // Paciente.comorbidade[strcspn(Paciente.comorbidade, "\n")] = 0;
    fprintf(file,Paciente.comorbidade);

    fclose(file);
    system("PAUSE");
  } else {
    if(*confirmar == 2) {
      printf("Tudo certo por aqui! Volte sempre!\n\n");
      system("PAUSE");
    } else {
      printf("Valor inválido! O sistema foi encerrado!\n\n");
      system("PAUSE");
    }
  }
  return 0;
}

int get_id(char *filename, char *cabecalho) {
  FILE *file = fopen(filename,"r");
  int id;
  char linha[100];
  char ultimo[5];

  while(!feof(file)) {
    fgets(linha,100,file);
  }

  if(isalnum(linha[0])) {
    int i;
    for(i = 0; i < 5; i++) {
      ultimo[i] = linha[i];
    }
    id = atoi(ultimo) + 1;
    return id;
  } else {
    id = 1;
    return id;
  }
}

int get_size(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}
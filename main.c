// importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

int main(void) {

  char nome_paciente[100];
  int ano, mes, dia;
  int max_mes[] = {31,28, 30, 30, 31, 29, 31, 31, 30, 31, 30, 31}; // número máximo de dias de cada mês do ano

  // leitura do nome completo do paciente
  printf("Informe o nome do paciente: ");
  fgets(nome_paciente, sizeof(nome_paciente), stdin);
  nome_paciente[strcspn(nome_paciente, "\n")] = 0;

  // leitura do ano de nascimento do paciente
  printf("Informe o ano de nascimento: ");
  scanf("%d",&ano);

  // leitura do mês de nascimento do paciente
  do {
    printf("Informe o mês de nascimento: ");
    scanf("%d",&mes);
  } while (mes < 1 || mes > 12);

  // leitura do dia de nascimento do paciente
  do {
    printf("Informe o dia de nascimento: ");
    scanf("%d",&dia);
  } while (verify_day(ano, mes, dia, &max_mes) != 1);
  printf("\n");

  // Definindo uma data de nascimento fictícia para o paciente
  struct tm birthdate = {0}; // Inicializar a estrutura com zeros
  birthdate.tm_year = ano - 1900;
  birthdate.tm_mon = mes - 1; 
  birthdate.tm_mday = dia; 

  // Criando um paciente
  Patient *patient = create_patient(1, nome_paciente, &birthdate);

  // Imprimindo informações do paciente criado

  char* day_string =  get_birthday_weekday(ano, mes, dia, patient);    
  printf("Paciente criado:\n");
  printf("ID: %d\n", get_patient_id(patient));
  printf("Nome: %s\n", get_patient_name(patient));
  printf("Data de Nascimento: %s %02d/%02d/%04d\n",day_string, dia, mes, ano);

  // Definindo uma data e hora fictícias para o exame
  time_t current_time;

  struct tm *exam_time;

  // Tempo do exame éo tempo atual
  current_time = time(NULL); // Obter o tempo atual em segundos desde 01/01/1970
  exam_time = localtime(&current_time); // Converter o tempo para a hora local

  //Criando um exame associado ao paciente criado
  Exam *exam = create_exam(101, get_patient_id(patient), 1, exam_time);

  // Imprimindo informações do exame criado
  printf("\nExame criado:\n");
  printf("ID: %d\n", get_exam_id(exam));
  printf("ID do Paciente: %d\n", get_exam_patient_id(exam));
  printf("ID do Aparelho de Raio-X: %d\n", get_exam_rx_id(exam));
  printf("Data e Hora do Exame: %s\n", asctime(get_exam_time(exam)));

  // Liberando a memória alocada
  destroy_exam(exam);
  destroy_patient(patient);
  return 0;
}

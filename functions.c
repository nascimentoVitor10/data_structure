#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// TIPOS ABSTRATOS DE DADOS

// TAD Patient
struct patient {
  int id;
  char *name;
  struct tm *birthdate;
};

// TAD Exam
struct exam {
  int id;
  int patient_id;
  int rx_id;
  struct tm *time;
};

// FUNÇÕES RELACIOINADAS AO PACIENTE

// cria paciente
Patient *create_patient(int id, const char *name, struct tm *birthdate) {
  Patient *patient =
      malloc(sizeof(struct patient)); // Alocar memória para a estrutura Patient
  // Verifica se a memória foi alocada corretamente
  if (patient == NULL) {
    printf("Erro ao alocar memória!\n");
    exit(1); // Abortar programa caso a memória não foi alocada corretamente
  }

  patient->id = id;               // Preencher ID do paciente
  patient->name = name;           // Preencher o nome do paciente
  patient->birthdate = birthdate; // Preencher a data de nascimento do paciente

  return patient;
}

// função para destruir a estrutura alocada para o paciente
void destroy_patient(Patient *patient) {
  if (patient != NULL) {
    free(patient); // Liberar mémoria alocada para estrutura Patient
  }
}

// função para retornar ID do paciente
int get_patient_id(Patient *patient) { return patient->id; }

// função para retornar o nome do paciente
const char *get_patient_name(Patient *patient) { return patient->name; }

// estrutura para retornar data de nascimento
struct tm *get_patient_birthdate(Patient *patient) {
  return patient->birthdate;
}

// FUNÇÕES RELACIONADAS AO EXAME

// cria o exame
Exam *create_exam(int id, int patient_id, int rx_id, struct tm *time) {
  Exam *exam =
      malloc(sizeof(struct exam)); // Alocar memória para a estrutura Exam
  // Verifica se a memória foi alocada corretamente
  if (exam == NULL) {
    printf("Erro ao alocar memória!\n");
    exit(1); // Abortar programa caso a memória não foi alocada corretamente
  }
  exam->id = id;
  exam->patient_id = patient_id;
  exam->rx_id = rx_id;
  exam->time = time;
  return exam; // Returning the pointer to the allocated memory
}

// função para destruir a estrutura alocada para o exame
void destroy_exam(Exam *exam) {
  if (exam != NULL) {
    free(exam); // Liberar mémoria alocada para estrutura exam
  }
}

// função para retornar ID do exame
int get_exam_id(Exam *exam) { return exam->id; }

// função para retornar ID do paciente do exame
int get_exam_patient_id(Exam *exam) { return exam->patient_id; }

// função para retornar ID do aparelho do exame
int get_exam_rx_id(Exam *exam) { return (*exam).rx_id; }

// estrutura para retornar data e hora do exame
struct tm *get_exam_time(Exam *exam) {
  return exam->time;
}

// FUNÇÕES UTILITÁRIAS

// função para verificar ano de nascimento do paciente
int verify_year(int ano) {
#define ano_atual 2024
  if (ano > ano_atual) {
    printf("Ano inválido\n");
    return 0;
  }
  return 1;
}

// função para verificar ano bissexto
int is_bissexto(int ano) {
  if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    return 1;
  return 0;
}

// função para verificar se o dia pertence ao mês informado
int verify_day(int ano, int mes, int dia, int *max_mes) {
  if (dia < 1 || dia > max_mes[mes - 1]) {
    return 0;
  }
  if (mes == 2 && is_bissexto(ano) && dia == 29) {
    return 1;
  }
  return 1;
}

char *get_birthday_weekday(int ano, int mes, int dia, Patient *patient) {

  int max_day[] = {31, 28, 30, 30, 31, 29, 31, 31, 30, 31, 30, 31};
  char *day[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                 "Thursday", "Friday", "Saturday"};

  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

  int y = ano - (mes < 3);

  int dow = (y + y / 4 - y / 100 + y / 400 + t[mes - 1] + dia) % 7;

  return day[(dow + 6) % 7 + 1];
}

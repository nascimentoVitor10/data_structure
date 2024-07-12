#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "exam.h"

// TAD Exam
struct exam{
  int id; 
  int patient_id; 
  int rx_id;
  struct tm* time;
};

//FUNÇÕES RELACIONADAS AO EXAME

// cria o exame
Exam* create_exam(int id, int patient_id, int rx_id, struct tm *time){
  // verifica se time é nulo
  if (time == NULL) {
    printf("Erro: o ponteiro name não aponta para nenhum endereço de memória corretamente\n");
    return NULL;
  }

  // aloca memória para a estrutura Exam
  Exam* exam = malloc(sizeof(struct exam)); 
  // Verifica se a memória foi alocada corretamente
  if (exam == NULL){
    printf("Erro ao alocar memória!\n");
    exit(1); // Abortar programa caso a memória não foi alocada corretamente
  }
  
  exam->id = id;
  exam->patient_id = patient_id;
  exam->rx_id = rx_id;
  exam->time = time;
  
  return exam;
}

// função para destruir a estrutura alocada para o exame
void destroy_exam(Exam *exam){
  if (exam != NULL){
    free(exam); // Liberar mémoria alocada para estrutura exam
  }
}

// função para retornar ID do exame
int get_exam_id(Exam *exam){
  // Verificar se o ponteiro exam é NULL
  if (exam == NULL) {
    printf("Erro: o ponteiro é NULL\n");
    return NULL; // Retorna NULL caso o ponteiro não aponte para nenhum endereço de memória corretamente
  }
  return exam->id;
}

// função para retornar ID do paciente do exame
int get_exam_patient_id(Exam *exam){
  // Verificar se o ponteiro exam é NULL
  if (exam == NULL) {
    printf("Erro: o ponteiro é NULL\n");
    return NULL; // Retorna NULL caso o ponteiro não aponte para nenhum endereço de memória corretamente
  }
  return exam->patient_id;
}

// função para retornar ID do aparelho do exame
int get_exam_rx_id(Exam *exam){
  // Verificar se o ponteiro exam é NULL
  if (exam == NULL) {
    printf("Erro: o ponteiro é NULL\n");
    return NULL; // Retorna NULL caso o ponteiro não aponte para nenhum endereço de memória corretamente
  }
  return (*exam).rx_id; 
}

// estrutura para retornar data e hora do exame
struct tm* get_exam_time(Exam *exam){
  // Verificar se o ponteiro exam é NULL
  if (exam == NULL) {
    printf("Erro: o ponteiro é NULL\n");
    return NULL; // Retorna NULL caso o ponteiro não aponte para nenhum endereço de memória corretamente
  }
  return exam->time; 
}

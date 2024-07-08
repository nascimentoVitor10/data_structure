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
  Exam* exam = malloc(sizeof(struct exam)); // Alocar memória para a estrutura Exam
  // Verifica se a memória foi alocada corretamente
  if (exam == NULL){
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
void destroy_exam(Exam *exam){
  if (exam != NULL){
    free(exam); // Liberar mémoria alocada para estrutura exam
  }
}

// função para retornar ID do exame
int get_exam_id(Exam *exam){
  return exam->id;
}

// função para retornar ID do paciente do exame
int get_exam_patient_id(Exam *exam){
  return exam->patient_id;
}

// função para retornar ID do aparelho do exame
int get_exam_rx_id(Exam *exam){
  return (*exam).rx_id; 
}

// estrutura para retornar data e hora do exame
struct tm* get_exam_time(Exam *exam){
  return exam->time; 
}

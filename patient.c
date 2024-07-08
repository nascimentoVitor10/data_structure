#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "patient.h"

// TAD Patient
struct patient{
  int id;
  char* name;
  struct tm* birthdate;
};

// FUNÇÕES RELACIOINADAS AO PACIENTE
// Cria paciente
Patient* create_patient(int id, const char *name, struct tm *birthdate){
  Patient* patient = malloc(sizeof(struct patient)); // Alocar memória para a estrutura Patient
  // Verifica se a memória foi alocada corretamente
  if (patient == NULL){
    printf("Erro ao alocar memória!\n");
    exit(1); // Abortar programa caso a memória não foi alocada corretamente
  }

  patient->id = id; // Preencher ID do paciente
  patient->name = name; // Preencher o nome do paciente
  patient->birthdate = birthdate; // Preencher a data de nascimento do paciente

  return patient; 
}

// função para destruir a estrutura alocada para o paciente
void destroy_patient(Patient *patient){
  if (patient != NULL){
    free(patient); // Liberar mémoria alocada para estrutura Patient
  }
}

// função para retornar ID do paciente
int get_patient_id(Patient* patient){
  return patient->id; 
}

// função para retornar o nome do paciente
const char* get_patient_name(Patient* patient){
  return patient->name; 
}

// estrutura para retornar data de nascimento
struct tm* get_patient_birthdate(Patient *patient){
  return patient->birthdate;
}

  #include "patient.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>

  // TAD Patient
  struct patient {
    int id;
    char *name;
    struct tm *birthdate;
  };

  // FUNÇÕES RELACIOINADAS AO PACIENTE
  // Cria paciente
  Patient *create_patient(int id, const char *name, struct tm *birthdate) {
    // Verifica se name e birthdate são nulos
    if (name == NULL) {
      printf("Erro: o ponteiro name não aponta para nenhum endereço de memória "
             "corretamente\n");
      return NULL; // Retorna NULL caso o ponteiro não aponta para nenhum endereço
                   // de memória corretamente
    } else if (birthdate == NULL) {
      printf("Erro: o ponteiro name não aponta para nenhum endereço de memória "
             "corretamente\n");
      return NULL; // Retorna NULL caso o ponteiro não aponta para nenhum endereço
                   // de memória corretamente
    }

    // Alocar memória para a estrutura Patient e verifica se a memória foi alocada corretamente
    Patient *patient = malloc(sizeof(struct patient));

    if (patient == NULL) {
      printf("Erro ao alocar memória\n");
      return NULL; // Retorna NULL caso a memória não foi alocada corretamente
    }

    // Atribui o ID do paciente
    patient->id = id;
    
    // Aloca memória para o nome do paciente e verifica se a memória foi alocada
    // corretamente
    patient->name = (char *)malloc(sizeof(char) * strlen(name) + 1);

    if (patient->name == NULL) {
      printf("Erro ao alocar memória\n");
      destroy_patient(patient); // Liberar a memória
      return NULL; // Retorna NULL caso a memória não foi alocada corretamente
    }

    // Copia o nome do paciente para a atribuição do nome do paciente
    strcpy(patient->name, name); 

    // Copia a estrutura tm para a atribuição da data de nascimento do paciente
    patient->birthdate = birthdate;

    return patient;
  }

  // função para destruir a estrutura alocada para o paciente
  void destroy_patient(Patient *patient) {
    if (patient != NULL) {
      free(patient); // Liberar mémoria alocada para estrutura Patient
    }
  }

  // função para retornar ID do paciente
  int get_patient_id(Patient *patient) {
    // Verificar se o ponteiro patient é NULL
    if (patient == NULL) {
      printf("Erro: o ponteiro é NULL\n");
      return NULL; // Retorna NULL caso o ponteiro não aponte para nenhum endereço de memória corretamente
    }

    return patient->id;
  }

  // função para retornar o nome do paciente
  const char *get_patient_name(Patient *patient) {
    // Verificar se o ponteiro patient é NULL
    if (patient == NULL) {
      printf("Erro: o ponteiro é NULL\n");
      return NULL; // Retorna NULL caso o ponteiro não aponte para nenhum endereço de memória corretamente
    }

    return patient->name; 
  }

  // estrutura para retornar data de nascimento
  struct tm *get_patient_birthdate(Patient *patient) { 
    // Verificar se o ponteiro patient é NULL
    if (patient == NULL) {
      printf("Erro: o ponteiro é NULL\n");
      return NULL; // Retorna NULL caso o ponteiro não aponte para nenhum endereço de memória corretamente
    }

    return patient->birthdate;
  }

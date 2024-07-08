// Cabeçalhos das funções e estruturas desenvolvidas
#ifndef PATIENT_H
#define PATIENT_H
#include <time.h>

// Tipos de dados abstratos
typedef struct patient Patient;

// Funções relacionadas ao paciente
Patient *create_patient(int, const char *, struct tm *birthdate);
void destroy_patient(Patient *patient);
int get_patient_id(Patient *patient);
const char *get_patient_name(Patient *patient);
struct tm *get_patient_birthdate(Patient *patient);

#endif

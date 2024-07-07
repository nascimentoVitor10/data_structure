// Cabeçalhos das funções e estruturas desenvolvidas
#inndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct patient Patient;
typedef struct exam Exam;
struct tm birthdate;

// Funções relacionadas ao paciente
Patient* create_patient(int, const char*, struct)
void destroy_patient(struct*)
int get_patient_id(Patient* patient)
const char* get_patient_name(Patient* patient)
struct tm* get_patient_birthdate(Patient *patient)

// Funções relacionadas ao exame
Exam* create_exam(int , int, int, struct tm *time)
void destroy_exam(Exam *exam)
int get_exam_id(Exam *exam)
int get_exam_patient_id(Exam *exam)
int get_exam_rx_id(Exam *exam)
struct tm* get_exam_time(Exam *exam)

// Funções utilitárias
int verify_year(int)
int is_bissexto(int)
int verify_day(int , int, int, int*)
char* get_birthday_weekday(int, int, int, Patient* patient)

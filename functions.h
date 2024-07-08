// Cabeçalhos das funções e estruturas desenvolvidas
#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct patient Patient;
typedef struct exam Exam;
extern int birthdate;

// Funções relacionadas ao paciente
Patient *create_patient(int, const char *, struct tm *birthdate);
void destroy_patient(Patient *patient);
int get_patient_id(Patient *patient);
const char *get_patient_name(Patient *patient);
struct tm *get_patient_birthdate(Patient *patient);

// Funções relacionadas ao exame
Exam *create_exam(int id, int patient_id, int rx_id, struct tm *time);
void destroy_exam(Exam *exam);
int get_exam_id(Exam *exam);
int get_exam_patient_id(Exam *exam);
int get_exam_rx_id(Exam *exam);
struct tm *get_exam_time(Exam *exam);

// Funções utilitárias
int verify_year(int ano);
int is_bissexto(int ano);
int verify_day(int ano, int mes, int dia, int *max_mes);
char *get_birthday_weekday(int ano, int mes, int dia, Patient *patient);

#endif

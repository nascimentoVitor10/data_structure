// Cabeçalhos das funções e estruturas desenvolvidas
#ifndef EXAM_H
#define EXAM_H
#include <time.h>

// Tipos de dados abstratos
typedef struct exam Exam;

// Funções relacionadas ao paciente
Exam *create_exam(int id, int patient_id, int rx_id, struct tm *time);
void destroy_exam(Exam *exam);
int get_exam_id(Exam *exam);
int get_exam_patient_id(Exam *exam);
int get_exam_rx_id(Exam *exam);
struct tm *get_exam_time(Exam *exam);

#endif

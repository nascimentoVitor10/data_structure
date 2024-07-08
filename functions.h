// Cabeçalhos das funções e estruturas desenvolvidas
#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "patient.h"

// Funções utilitárias
int verify_year(int ano);
int is_bissexto(int ano);
int verify_day(int ano, int mes, int dia, int *max_mes);
char *get_birthday_weekday(int ano, int mes, int dia, Patient *patient);

#endif

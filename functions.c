#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

//FUNÇÕES UTILITÁRIAS

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
int is_bissexto(int ano){
  if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    return 1;
  return 0;
}

// função para verificar se o dia pertence ao mês informado
int verify_day(int ano, int mes, int dia, int* max_mes){
  if (dia < 1 || dia > max_mes[mes -1]){
    return 0; 
  }
  if (mes == 2 && is_bissexto(ano) && dia == 29){
    return 1;
  }
  return 1;
}

char* get_birthday_weekday(int ano, int mes, int dia, Patient* patient) {

    int max_day[] = {31, 28, 30, 30, 31, 29, 31, 31, 30, 31, 30, 31};
    char* day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    int y = ano - (mes < 3);

    int dow = (y + y / 4 - y / 100 + y / 400 + t[mes - 1] + dia) % 7;

    return day[(dow + 6) % 7 + 1];
}

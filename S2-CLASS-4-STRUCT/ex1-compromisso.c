//1. Write a code snippet to create the new data types as requested below:
// • Hour: composed of hours, minutes and seconds.
// • Date: composed of day, month and year.
// • Appointment: composed of a date, time and text that describes the appointment.

// 1. Escreva um trecho de co´digo para fazer a criac¸a˜o dos novos tipos de dados conforme solicitado abaixo:
// • Hora´rio: composto de hora, minutos e segundos.
// • Data: composto de dia, meˆs e ano.
// • Compromisso: composto de uma data, hora´rio e texto que descreve o compromisso.

#include <stdio.h>

struct schedule // horário
{
    int hour; // hora

    int minutes; // minutos

    int seconds; // segundos

} schedule;

struct date // data
{
    int day; // dia

    int month; // mês

    int year; // ano

} date;

struct commitment // compromisso
{
    struct schedule *sch;

    struct date *dat;

    char description[100]; // descrição

} com;

int main()
{
    system("cls");

    com.dat = &date;

    com.sch = &schedule;

    printf("\n\nFor which date (DD MM YYYY) would you like to schedule your appointment?\n\n"); // Para qual data você gostaria de marcar o seu compromisso ?
    scanf("%d%d%d", &com.dat->day, &com.dat->month, &com.dat->year);

    printf("\n\nWhat time (HH MM SS) would you like to schedule??\n\n"); // Para qual horario você gostaria de agendar ?
    scanf("%d%d%d", &com.sch->hour, &com.sch->minutes, &com.sch->seconds);

   printf("\n\nYour appointment was scheduled to %d/%d/%d %d:%d:%d", com.dat->day, com.dat->month, com.dat->year, com.sch->hour, com.sch->minutes, com.sch->seconds); // Seu compromisso ficou agendado para

printf("\n\n");
    
    return 0;

}
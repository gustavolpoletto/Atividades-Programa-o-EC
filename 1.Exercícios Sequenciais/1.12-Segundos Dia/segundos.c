#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main ()
{
    int tot_seg;
    char* horario = malloc(9);
    printf("Horario (separado por ':')- ");
    fgets(horario, 9, stdin);
    horario[strcspn(horario, "\n")] = '\0';

    char* horas = strtok(horario, ":");
    char* min = strtok(NULL, ":");
    char* seg = strtok(NULL, ":");

    if (!horas || !min || !seg)
    {
        printf("Horario formatado errado");
        return;
    }

    tot_seg = atoi(seg);
    tot_seg += atoi(min) * 60;
    tot_seg += atoi(horas) * 3600;


    printf("se passaram %i segundos do dia\n", tot_seg);
    printf("Ainda faltam %i segundos do dia\n", 86400 - tot_seg);
    free (horario);
}

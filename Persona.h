#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
     char nombre[20];
     int edad;
} persona;

void mostrarPersonas (persona dato);


#endif // PERSONA_H_INCLUDED

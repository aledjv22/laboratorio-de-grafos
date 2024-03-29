#ifndef EstructuraGrafo24_H
#define EstructuraGrafo24_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;
typedef unsigned int color;


typedef struct VerticeSt {
    u32 id;
    u32 grado; // Grado de un vertice
    color color; // Color del vertice
    Vertice vecinos;
} VerticeSt;

//Vertice es un puntero a una estructura VerticeSt, la cual debe estar definida en el .h de arriba
typedef VerticeSt *Vertice;

typedef struct GrafoSt {
    u32 numVertices; // Cantidad de vertices total en el grafo
    u32 numLados; // Cantidad de lados total en el grafo
    u32 numColores; // Cantidad de colores con los que se puede pintar el grafo
    u32 delta; // Delta del grafo, mayor grado
    Vertice vertices[]; // Array de punteros a Vertice
} GrafoSt;


#endif
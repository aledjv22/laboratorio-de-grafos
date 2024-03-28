#ifndef EstructuraGrafo24_H
#define EstructuraGrafo24_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;
typedef unsigned int color;


typedef struct VerticeSt {
    u32 Id; // Identificador del vertice
    u32 grado; // Grado de un vertice
    color color; // Color del vertice
    Vertice vecino; // Vecinos
} VerticeSt;

typedef struct GrafoSt {
    u32 numVertices; // Cantidad de vertices total en el grafo
    u32 numLados; // Cantidad de lados total en el grafo
    u32 numColores; // Cantidad de colores con los que se puede pintar el grafo
    u32 delta; // Delta del grafo, mayor grado
    Vertice vertex; // Vertices
} GrafoSt;


#endif
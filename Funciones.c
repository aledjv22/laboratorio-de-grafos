#include "APIG24.h"
#include <string.h>

Grafo crear_Grafo(u32 n, u32 m) {
    Grafo grafo = malloc(sizeof(GrafoSt));
    grafo->numVertices = n;
    grafo->vertices = malloc(n * sizeof(VerticeSt));
    grafo->numLados = m;
    
    for (u32 i = 0; i < n; i++) {
        grafo->vertices[i] = malloc(sizeof(struct VerticeSt));
        grafo->vertices[i]->grado = 0;
        grafo->vertices[i]->color = 0;
        grafo->vertices[i]->vecinos = malloc(n * sizeof(u32));
    }


    return grafo;
}

void agregar_Vecino(Grafo grafo, u32 verticeActual, u32 idVecino) {
    grafo->vertices[verticeActual]->vecinos[grafo->vertices[verticeActual]->grado] = idVecino;
    grafo->vertices[idVecino]->vecinos[grafo->vertices[idVecino]->grado] = verticeActual;

    if (++(grafo->vertices[verticeActual]->grado) > grafo->delta)
        grafo->delta = grafo->vertices[verticeActual]->grado;
    if (++(grafo->vertices[idVecino]->grado) > grafo->delta)
        grafo->delta = grafo->vertices[idVecino]->grado;  
}

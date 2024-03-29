#include "APIG24.h"
#include <string.h>

Grafo crear_Grafo(u32 n) {
    Grafo Grafo = malloc(sizeof(GrafoSt) + n * sizeof(Vertice));
    Grafo->numVertices = n;
    u32 i;
    for (i = 0; i < n; ++i)
    Grafo->vertices[i] = NULL;
  
    return Grafo;
}

Vertice crear_Vertice(u32 v) {
    Vertice nuevoVertice = malloc(sizeof(VerticeSt));
    nuevoVertice->id = v;
    nuevoVertice->vecinos = NULL;
    return nuevoVertice;
}

void agregar_Vecino(Grafo grafo, u32 verticeActual, u32 idVecino) {

    Vertice nuevoVertice = crear_Vertice(idVecino);
    nuevoVertice->vecinos = grafo->vertices[verticeActual-1];
    grafo->vertices[verticeActual-1] = nuevoVertice;
}

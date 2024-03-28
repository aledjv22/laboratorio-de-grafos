#include "APIG24.h"
#include <string.h>

Grafo crear_Grafo(u32 n, u32 m) {
    Grafo grafo = malloc(sizeof(Grafo));
    grafo->delta = 0;
    grafo->numColores = 0;
    grafo->numVertices = n;
    grafo->numLados = m;
    grafo->vertex = malloc(sizeof(Vertice) * grafo->numVertices);
    return grafo;
}

void crear_vertice(Grafo grafo, u32 v) {
    // Reserva de memoria
    Vertice nuevoVertice = malloc(sizeof(Vertice));

    // Inicialización del vértice
    nuevoVertice->Id = v;
    nuevoVertice->grado = 0;
    nuevoVertice->color = 0;
    nuevoVertice->vecino = NULL;

    // Agregar el vértice al array de vértices
    grafo->vertex[v] = *nuevoVertice;

    // Actualizar la cantidad de vértices
    grafo->numVertices++;
}

void AgregarVecino(Grafo grafo, u32 verticeActual, u32 idVecino) {
    // Reserva de memoria
    Vertice nuevoVecino = malloc(sizeof(Vertice));

    // Inicialización del vecino
    nuevoVecino->Id = idVecino;
    nuevoVecino->grado = 0;
    nuevoVecino->color = 0;
    nuevoVecino->vecino = NULL;

    // Agregar el vecino a la lista
    Vertice actual = &grafo->vertex[verticeActual];
    while (actual->vecino != NULL) {
        actual = actual->vecino;
    }
    actual->vecino = nuevoVecino;

    // Actualizar el grado del vértice
    grafo->vertex[verticeActual].grado++;

    if (grafo->vertex[verticeActual].grado > grafo->delta)
        grafo->delta = grafo->vertex[verticeActual].grado;
}
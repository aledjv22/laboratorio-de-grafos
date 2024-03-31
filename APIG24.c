#include "APIG24.h"  // Incluye el archivo de encabezado APIG24.h
#include <string.h>    // Incluye la biblioteca estándar de cadenas de C

#define MAX_LINE_SIZE 100  // Define la constante MAX_LINE_SIZE para el tamaño máximo de línea (100 caracteres)

Grafo crear_Grafo(u32 n, u32 m);
void agregar_Vecino(Grafo grafo, u32 verticeActual, u32 idVecino);

// Función para crear un grafo vacío con n vértices y m lados.
Grafo crear_Grafo(u32 n, u32 m) {
    // Reserva memoria para la estructura GrafoSt.
    Grafo grafo = malloc(sizeof(GrafoSt));

    // Asigna el número de vértices al grafo.
    grafo->numVertices = n;

    // Reserva memoria para el array de vértices.
    grafo->vertices = malloc(n * sizeof(VerticeSt));

    // Asigna el número de lados al grafo.
    grafo->numLados = m;

    // Inicializa el delta del grafo a 0.
    grafo->delta = 0;
    grafo->inicializado = calloc(sizeof(u32), n);

    return grafo;
}

// Función para agregar una arista (v, w) al grafo.
void agregar_Vecino(Grafo grafo, u32 verticeActual, u32 idVecino) {
    if (grafo->inicializado[verticeActual] == 0) {
        grafo->inicializado[verticeActual] = 1;
        // Reserva memoria para la estructura VerticeSt.
        grafo->vertices[verticeActual] = malloc(sizeof(struct VerticeSt));

        // Inicializa el grado del vértice a 0.
        grafo->vertices[verticeActual]->grado = 0;

        // Inicializa el color del vértice a 0.
        grafo->vertices[verticeActual]->color = 0;

        // Reserva memoria para la lista de vecinos del vértice.
        grafo->vertices[verticeActual]->vecinos = malloc(grafo->numVertices * sizeof(u32));
    }
    if (grafo->inicializado[idVecino] == 0) {
        grafo->inicializado[idVecino] = 1;
        // Reserva memoria para la estructura VerticeSt.
        grafo->vertices[idVecino] = malloc(sizeof(struct VerticeSt));

        // Inicializa el grado del vértice a 0.
        grafo->vertices[idVecino]->grado = 0;

        // Inicializa el color del vértice a 0.
        grafo->vertices[idVecino]->color = 0;

        // Reserva memoria para la lista de vecinos del vértice.
        grafo->vertices[idVecino]->vecinos = malloc(grafo->numVertices * sizeof(u32));
    }
    
    // Agrega el vértice 'idVecino' a la lista de vecinos de 'verticeActual'.
    grafo->vertices[verticeActual]->vecinos[grafo->vertices[verticeActual]->grado] = idVecino;

    // Agrega el vértice 'verticeActual' a la lista de vecinos de 'idVecino'.
    grafo->vertices[idVecino]->vecinos[grafo->vertices[idVecino]->grado] = verticeActual;

    // Actualiza el grado de 'verticeActual'.
    if (++(grafo->vertices[verticeActual]->grado) > grafo->delta) {
        grafo->delta = grafo->vertices[verticeActual]->grado;
    }

    // Actualiza el grado de 'idVecino'.
    if (++(grafo->vertices[idVecino]->grado) > grafo->delta) {
        grafo->delta = grafo->vertices[idVecino]->grado;
    }
}

/* 
   O(ConstruirGrafo) = m, donde:
   - m es el número de lados del grafo
*/

Grafo ConstruirGrafo() {
    char line[MAX_LINE_SIZE];  // Crea una variable character line para almacenar la línea leída

    // Lee la primera línea del archivo de entrada estándar (stdin)
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return NULL;
    }

    // Ignora líneas que comiencen con 'c' (comentarios)
    while (line[0] == 'c') {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            return NULL;
        }
    }

    // Valida que la línea comience con 'p edge' (formato esperado para especificar número de vértices y lados)
    if (strncmp(line, "p edge", 6) != 0) {
        return NULL;
    }

    // Lee el número de vértices (n) y el número de lados (m) de la línea
    u32 n, m;
    if (sscanf(line + 6, "%d%*c%d", &n, &m) != 2) {
        return NULL;
    }

    // Crea un grafo utilizando la función crear_Grafo (definida presumiblemente en Funciones.c)
    Grafo grafo = crear_Grafo(n, m);
    if (grafo == NULL) {
        return NULL;
    }

    // Lee las líneas que representan las aristas del grafo
    u32 v, w;
    for (u32 i = 0; i < m; i++) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            DestruirGrafo(grafo);
            return NULL;
        }

        // Valida que la línea comience con 'e' (formato esperado para especificar una arista)
        if (line[0] != 'e') {
            DestruirGrafo(grafo);
            return NULL;
        }

        // Lee los identificadores (IDs) de los vértices de la arista de la línea
        if (sscanf(line + 1, "%d%*c%d", &v, &w) != 2) {
            DestruirGrafo(grafo);
            return NULL;
        }

        // Valida que los IDs de los vértices estén dentro del rango válido (0 a n-1)
        if (v >= n || w >= n) {
            DestruirGrafo(grafo);
            return NULL;
        }

        // Agrega la arista (v, w) al grafo utilizando la función agregar_Vecino (definida presumiblemente en Funciones.c)
        agregar_Vecino(grafo, v, w);
    }

    return grafo;  // Devuelve el grafo creado
}

/* 
   O(DestruirGrafo) = n, donde:
   - n es el número de vértices del grafoc 8 vertices, 10 lados, Delta 3. vertices 0-7.
*/
// Función para destruir un grafo.
void DestruirGrafo(Grafo G) {
    // Si el grafo es nulo, no hay nada que liberar.
    if (G == NULL) {
        return;
    }

    // Libera la memoria de la lista de vecinos para cada vértice.
    for (u32 i = 0; i < G->numVertices; i++) {
        // Si la lista de vecinos no es nula, libera la memoria.
        if (G->vertices[i]->vecinos != NULL) {
            free(G->vertices[i]->vecinos);
            G->vertices[i]->vecinos = NULL;
        }
        free(G->vertices[i]);
        G->vertices[i] = NULL;
    }
    free(G->inicializado);
    G->inicializado = NULL;
    // Libera la memoria del array de vértices.
    free(G->vertices);
    G->vertices = NULL;

    // Libera la memoria de la estructura GrafoSt.
    free(G);
    G = NULL;
}

/* 
   O(NumeroDeVertices) = 1
*/
// Función para obtener el número de vértices del grafo.
u32 NumeroDeVertices(Grafo G) {
    // Devuelve el número de vértices almacenado en la estructura GrafoSt.
    return G->numVertices;
}

/* 
   O(NumeroDeVertices) = 1
*/
// Función para obtener el número de lados del grafo.
u32 NumeroDeLados(Grafo G) {
    // Devuelve el número de lados almacenado en la estructura GrafoSt.
    return G->numLados;
}

/* 
   O(Delta) = 1
*/
// Función para obtener el delta del grafo.
u32 Delta(Grafo G) {
    // Devuelve el delta del grafo.
    return G->delta;
}

/* 
   O(Grado) = 1
*/
// Función para obtener el grado de un vértice.
u32 Grado(u32 i, Grafo G) {
    // Si el índice del vértice es válido, devuelve el grado del vértice.
    if (i < G->numVertices) {
        return G->vertices[i]->grado;
    }

    // Si el índice del vértice no es válido, devuelve 0.
    else {
        return 0;
    }
}

/* 
   O(Color) = 1
*/
// Función para obtener el color de un vértice.
color Color(u32 i, Grafo G) {
    // Si el índice del vértice es válido, devuelve el color del vértice.
    if (i < G->numVertices) {
        return G->vertices[i]->color;
    }

    // Si el índice del vértice no es válido, devuelve 4294967295 (2^32-1).
    else {
        return 4294967295; // 2^32-1
    }
}

/* 
   O(Vecino) = 1
*/
// Función para obtener el j-ésimo vecino de un vértice.
u32 Vecino(u32 j, u32 i, Grafo G) {
    // Valida que el índice del vértice sea válido.
    if (i >= G->numVertices) {
        return 4294967295; // Error: índice de vértice invalido, 2^32-1
    }

    // Valida que el índice del vecino sea válido.
    if (j >= G->vertices[i]->grado) {
        return 4294967295; // Error: índice de vecino invalido, 2^32-1
    }

    // Devuelve el j-ésimo vecino del vértice.
    return G->vertices[i]->vecinos[j];
}

/* 
   O(AsignarColor) = 1
*/
// Función para asignar un color a un vértice.
void AsignarColor(color x, u32 i, Grafo G) {
    // Si el índice del vértice es válido, asigna el color al vértice.
    if (i < G->numVertices) {
        G->vertices[i]->color = x;
    }
}

/* 
   O(ExtraerColores) = n, donde:
   - n es el número de vértices del grafo
*/
void ExtraerColores(Grafo G,color* Color) {
    // Recorrer todos los vértices
    for (u32 i = 0; i < G->numVertices; i++) {
    // Obtener el color del vértice
        u32 color = G->vertices[i]->color;

        // Asignar el color al array
        Color[i] = color;
    }
}

/* 
   O(ImportarColores) = n, donde:
   - n es el número de vértices del grafo
*/
void ImportarColores(color* Color,Grafo  G) {
    // Recorrer todos los vértices
    for (u32 i = 0; i < G->numVertices; i++) {
        // Asignar el color al vértice
        G->vertices[i]->color = Color[i];
    }
}


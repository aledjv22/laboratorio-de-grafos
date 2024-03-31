#include "APIG24.h"
#include "Funciones.c"
#include <string.h>


/*
O(ContruirGrafo) = m+n
*/

Grafo ConstruirGrafo() {
    char line[100];
    // Lee una linea de texto
    if (fgets(line, sizeof(line), stdin) == NULL) {
        printf("Error al leer stdin\n");
        return NULL;
    }

    // Vemos si la linea empieza con 'c'
    while (line[0] == 'c') { // Si la linea empieza con 'c'
        // Ignoramos la linea pues es un comentario
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Error al leer stdin\n");
            return NULL;
        }

    } 
    if(strncmp(line, "p edge", 6) == 0) { // Si empieza con 'p edge'
        u32 n = 0, m = 0;
        // Leemos los numeros n (numero de vertices) y m (numero de lados)
        if (sscanf(line + 6, "%d%*c%d", &n, &m) != 2) { // Con %*c ignoramos los espacios
            printf("Error al leer el numero de vertices y aristas\n");
            return NULL;
        }

        Grafo grafo = crear_Grafo(n, m);
        
        u32 v = 0, w = 0;
        
        for(u32 i = 0; i < m; i++) {
            if (fgets(line, sizeof(line), stdin) == NULL) {
                printf("Error al leer stdin\n");
                return NULL;
            }
            if(line[0] == 'e') { // Si empieza con 'e'
                    if (sscanf(line + 1, "%d%*c%d", &v, &w) != 2) {
                        printf("Error al leer los vertices de la arista %d\n", i + 1);
                        return NULL;
                    }
                    agregar_Vecino(grafo, v, w);
            }
            else {
                printf("Se esperaban %u lados, empezando con 'e' al ingresarlos\n", m);
                return NULL;
            }
        }
        return grafo;
    }
    else {
        printf("Se esperaba 'p edge' para ingresar el numero de vertices y el numero de lados\n");
        return NULL;
    }    
}

void print_grafo(Grafo g) {
    for (u32 i = 0; i < g->numVertices; i++) {
        printf("De %u \n", i);
        for (u32 j = 0; j < g->numVertices; j++) {
            if(g->vertices[i]->vecinos[j] == 1)
                printf("%u ", j);
        }
        printf("\n");
    }
}

int main() {
    Grafo g = ConstruirGrafo();
    print_grafo(g);
}

#include "APIG24.h"
#include "Funciones.c"
#include <string.h>


/*
O(ContruirGrafo) = 
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

        Grafo grafo = crear_Grafo(n);
        
        u32 v = 0, w = 0;
        
        for(u32 i = 0; i < m; i++) {
            if (fgets(line, sizeof(line), stdin) == NULL) {
                printf("Error al leer stdin\n");
                return NULL;
            }
            if(line[0] == 'e') { // Si no empieza con 'e'
                    if (sscanf(line + 1, "%d%*c%d", &v, &w) != 2) {
                        printf("Error al leer los vertices de la arista %d\n", i + 1);
                        return NULL;
                    }
                    AgregarVecino(grafo, v, w);
            }
            else {
                printf("Se esperaban %u lados, empezando con 'e' al ingresarlos\n", m);
                return NULL;
            }
        }
        if (fgets(line, sizeof(line), stdin) != NULL) {
            printf("Se encontraron datos adicionales después del grafo.\n");
            return NULL;
        }
    }
    else {
        printf("Se esperaba 'p edge' para ingresar el numero de vertices y el numero de lados\n");
        return NULL;
    }    
}


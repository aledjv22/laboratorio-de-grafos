#include "APIG24.h"

Grafo ConstruirGrafo() {
    char line[100];
    u32 n = 0, m = 0;
    // Lee una linea de texto
    if (fgets(line, sizeof(line), stdin) == NULL) {
        printf("Error al leer stdin\n");
        return -1;
    }

    // Vemos si la linea empieza con 'c'
    if (line[0] == 'c') { // Si la linea empieza con 'c'
        // Ignoramos la linea pues es un comentario
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Error al leer stdin\n");
            return -1;
        }
        if(strncmp(line, "p edge", 6) == 0) { // Si no empieza con 'p edge'
            // Leemos los numeros n (numero de vertices) y m (numero de lados)
            if (sscanf(line + 6, "%d%*c%d", &n, &m) != 2) { // Con %*c ignoramos los espacios
                printf("Error al leer el numero de vertices y aristas\n");
                return -1;
            }
            u32 v = 0, w = 0;
            for(int i = 0; i < m; i++) {
                if (fgets(line, sizeof(line), stdin) == NULL) {
                    printf("Error al leer stdin\n");
                    return -1;
                }
                if(line[0] == 'e') { // Si no empieza con 'e'
                    if (sscanf(line + 1, "%d%*c%d", &v, &w) != 2) {
                        printf("Error al leer los vertices de la arista %d\n", i + 1);
                        return -1;
                    }
                }
                else {
                    printf("Se esperaban %d lados, empezando con 'e' al ingresarlos\n", &m);
                    return -1;
                }
            }
        }
        else {
            printf("Se esperaba 'p edge' para ingresar el numero de vertices y el numero de lados\n");
            return -1;
        }
    } 
    else {
        printf("Se esperaba'c' al inicio del archivo\n");
        return -1;
    }
}


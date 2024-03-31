#include "APIG24.c"


int main() {
    Grafo G = ConstruirGrafo();
    if (G == NULL)
        return 0;
    printf("Numero de Vertices: %u\n", NumeroDeVertices(G));
    printf("Numero de Lados: %u\n", NumeroDeLados(G));
    printf("Delta: %u\n", Delta(G));
    for(u32 i = 0; i<G->numVertices; i++){
        printf("Vertice %u\n", i);
        u32 grado = Grado(i,G);
        printf("Grado: %u\n", grado);
        printf("Vecinos: ");
        for(u32 j=0; j<grado; j++)
            printf("%u ", Vecino(j, i ,G));
        printf("\n");
        AsignarColor(i*2, i, G);
        printf("Color: %u\n", Color(i,G));
    }
    color* colores = malloc(sizeof(color) * G->numVertices);
    ExtraerColores(G, colores);
    ImportarColores(colores, G);
    for(u32 i = 0; i<G->numVertices; i++){
        printf("Vertice %u\n", i);
        printf("Color2: %u\n", Color(i,G));
    }
    free(colores);
    printf("\n");

    DestruirGrafo(G);
}
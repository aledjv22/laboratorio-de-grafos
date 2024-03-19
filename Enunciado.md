# Proyecto de programación de Matemática Discreta II - 2024 - Primera Parte

## Contenido

1. [Introducción](#introducción)
   1. [Objetivos](#objetivos)
   2. [Testeo](#testeo)
   3. [Entrega](#entrega)
   4. [Restricciones generales](#restricciones-generales)
   5. [Formato de Entrega](#formato-de-entrega)
   6. [Compilación](#compilación)
2. [Tipos de Datos](#tipos-de-datos)
   1. [Grafo](#grafo)
   2. [GrafoSt](#grafoSt)
   3. [u32](#u32)
   4. [color](#color)
3. [Funciones De Construcción/Destrucción del grafo](#funciones-de-construcción/destrucción-del-grafo)
   1. [ConstruirGrafo()](#construirgrafo)
   2. [DestruirGrafo()](#destruirgrafo)
4. [Funciones para extraer información de datos del grafo](#funciones-para-extraer-información-de-datos-del-grafo)
   1. [NumeroDeVertices()](#numerodevertices)
   2. [NumeroDeLados()](#numerodelados)
   3. [Delta()](#delta)
5. [Funciones para extraer información de los vertices](#funciones-para-extraer-información-de-los-vertices)
   1. [Grado()](#grado)
   2. [Color()](#color)
   3. [Vecino()](#vecino)
6. [Funciones para asignar colores](#funciones-para-asignar-colores)
   1. [AsignarColor()](#asignarcolor)
   2. [ExtraerColores()](#extraercolores)
   3. [ImportarColores()](#importarcolores)
7. [Consideraciones finales para esta primera etapa](#consideraciones-finales-para-esta-primera-etapa)
8. [Formato de Entrada](#formato-de-entrada)

## Introducción
Este proyecto de programación tiene una nota entre 0 y 10 y deben obtener al menos un 4 para aprobar.
El proyecto estará dividido en varias etapas pero se evalua globalmente.
El proyecto puede ser hecho en forma individual o en grupos de 2 o 3 personas.

### Objetivos
Los objetivos en este proyecto son:
1. Implementar un tema enseñado en clase en un lenguaje, observando las dificultades de pasar de la teoria a un programa concreto.
2. Prácticar programar funciones adhiriendose a las especificaciones de las mismas.
3. Práctica de testeo de programas.

El tema concreto que usaremos este año es hacer un programa que coloree un grafo tratando de obtener un coloreo con la menor cantidad de colores posibles, o "cerca". 
La idea NO ES presentar un programa único completo que haga esto, sino programar funciones auxiliares que luego se pueden ensamblar en uno o mas mains que las use, de acuerdo de distintas estrategias.
El proyecto se dividirá en varias etapas. Este primer documento da las especificaciones de las funciones de la primera etapa. En esta primera etapa, simplemente especificamos funciones que permitan leer los datos del grafo que vamos a colorear, guardarlos en alguna estructura adecuada, y otras funciones que nos permitan acceder a esos datos, como el número de vertices y lados, los grados de cada vertice, y cuales son los vecinos de un vértice. 
Las etapas posteriores usaran estas funciones para hacer lo que deben hacer.
Si en las etapas posteriores uds programan sin hacer uso de estas funciones, el proyecto queda desaprobado.
Para evitar "acarreo" de errores de la primera etapa a las otras, las otras etapas las evaluaremos usando **nuestras** propias funciones de la 1era etapa.
El lenguaje es C. (C99, i.e., pueden usar comentarios // u otras cosas de C99).
Es crucial que programen las funciones de acuerdo con las especificaciones, este es uno de los objetivos de este proyecto, y será dificil o directamente imposible corregir las otras etapas si usan funciones que no satisfagan las especificaciones.

### Testeo
Deben testear la funcionalidad de cada una de las funciones que programan, con programas que testeen si las funciones efectivamente hacen lo que hacen o no, pero no deben entregar esos programas.
Obviamente nosotros no sabremos si testearon o no, o que tanto lo hicieron, o si testearon bien o mal, pero si entregan funciones con errores que obviamente hanrian sido descubiertos con un mínimo testeo, nos daremos cuenta que no testearon o no testearon adecuadamente. Por ejemplo, si la lista de vecinos de un vertice no es la correcta.
Habrá una lista de grafos de ejemplos para que testeen las funciones sobre ellos.
Programar sin errores es difícil, y algunos errores se les pueden pasar aún siendo cuidadosos y haciendo tests, porque somos humanos, y algunos errores son dificiles de detectar. Pero hay errores que no deberían quedar en el código que entreguen, porque son errores que son fácilmente detectables con un mínimo testeo.
De todos modos, no deberian encontrar mayores problemas en esta primera parte. Este año hemos reducido considerablemente la dificultad de esta primera parte de años anteriores.

### Entrega
Deberán entregar los archivos que implementan el proyecto en la forma y tiempo en que especifiquemos mas tarde en la página.
Las funciones que estan descriptas en esta etapa serán usadas luego por otras funciones que especificaremos mas adelante. Como dijimos arriba, en esta etapa las funciones consisten basicamente en las funciones que permiten leer datos de un grafo y cargarlos en una estructura adecuada, mas funciones que permiten acceder a esos datos.

### Restricciones generales
1. No se puede incluir **NINGUNA** librería externa que no sea una de las básicas de C. (eg, stdlib.h, stdio.h, string.h, stdbool.h, assert.h, etc., si, pero otras no. Especificamente, glibc **NO**).
2. El código debe ser razonablemente portable, aunque no es probable que testemos sobre Apple, y en general testearemos con Linux, quizas podamos testearlo desde Windows.
3. No pueden usar archivos llamados `aux.c` o `aux.h`.
4. No pueden tener archivos tales que la única diferencia en su nombre sea diferencia en la capitalización.
5. No pueden usar `getline`.
6. El uso de macros esta permitido pero como siempre, sean cuidadosos si lo usan.
7. Pueden consultar con otros grupos, pero no pueden tener grandes fragmentos de código iguales, o con cambios meramente cosméticos en el código de otro grupo. Consultar por ideas es aceptable, copiar código en bloque no.
8. Si tienen acceso a codigos de años anteriores y quieren usar ideas o fragmentos del código, ok, pero este año las especificaciones son distintas. Si entregan código que es obviamente un código de años anteriores sin haber sido adaptado a las exigencias de este año les descontaremos puntos o directamente serán desaprobados, dependiendo que tan grande sea la caradurez.
9. Si saben como usar ChatGPT y lo usan, está bien, pero deberian ser extra cuidadosos con el testeo.

### Formato de Entrega
Los archivos del programa deben ser todos archivos .c o .h.
Pueden entregar un sólo .c con todas las funciones si quieren, o separados en varios archivos, pero no debe haber ningun `include` de un .c.
No debe haber ningun ejecutable en los archivos entregados.
Los .c que entreguen deben hacer un include de un archivo API llamado [APIG24.h](./APIG24.h) donde se declaran las funciones.
[APIG24.h](./APIG24.h) tiene simplemente la declaración de las funciones, la declaración del tipo de datos [2.1](#grafo) definida mas abajo y un include de un .h, EstructuraGrafo24.h. Para evitar errores de tipeo con las declaraciones de las funciones, subiremos una copia de [APIG24.h](./APIG24.h) a la página del Aula Virtual. EstructuraGrafo24.h en cambio será particular de cada grupo, porque dependerá de la forma particular que cada grupo decida estructurar las cosas, asi que cada uno entregará una copia distinta.
Para testear deberán (o al menos, dberían) hacer por su cuenta uno o mas .c que incluyan un `main` que les ayude a testear deberán (o al menos, deberían) hacer por su cuenta uno o mas .c que incluyan `main` que les ayude a testear sus funciones, incluyendo funciones nuevas que ustedes quieran usar para testear cosas (pej, luego de cargar el grafo, imprimir los vertices y sus vecinos para chequear que sus funciones cargaron bien el grafo). Estos archivos **NO** deben ser entregados.
Deben adjuntar un archivo **ASCII** donde conste el nombre, apellido y email de todos los integrantes del grupo.
Esta parte es muy simple, asi que no deberían entregar un montón de archivos complicados. Si lo estan pensando muy complicadamente, probablemente esta mal.
Algunos grupos hacen funciones que tienen `prints` interiores para debuggear, pero no deben entregar esas versiones. Las que entregen deben cumplir con las especificaciones, las cuales no incluyen imprimir nada.

### Compilación
Compilaremos (con mains nuestros) usando `gcc`, `-Wall, -Wextra, -O3, -std=c99`. También haremos **-I** al directorio donde pondremos los .h.
Esas *flags* serán usadas para testear la velocidad, pero para testear grafos chicos podemos agregar otras flags. Por ejemplo, podemos usar **-DNDEBUG** si vemos que estan mal usados `asserts`.
También compilaremos, para testear grafos chicos, en particular con `-fsanitize=address`, `undefined`. Su programa **DEBE** compilar y correr correctamente con esa flag aunque para grafos grandes lo correremos con un ejecutable compilado sin esa flag, dado que esa flag provoca una gran demora en la ejecución.
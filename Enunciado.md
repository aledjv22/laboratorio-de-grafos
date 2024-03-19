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

## Tipos de Datos

### Grafo
Es un puntero a una estructura de datos *[GrafoSt](#grafoSt)*. Esto estará definido en [APIG24.h](./APIG24.h).
El resto de los tipos de datos deben estar definidos en su archivo EstructuraGrafo24.h.
EstructuraGrafo24.h lo tienen que definir uds de acuerdo con la estructura particular con la cual piensan guardar el grafo. 
También puede estar ahi cualquier declaración de funciones auxiliares que necesiten.

### GrafoSt
Es una estructura, la cual contendrá toda la información sobre el grafo necesaria para correr las funciones pedidas.
En particular, la definición interna debe contener como mínimo:
1. El número de vértices y lados del grafo.
2. Los grados y colores de todos los vértices.
3. El Delta del grafo (el mayor grado).
4. Quienes son los vecinos de cada vértice.
Los grafos que se carguen serán no dirigidos.
La estructura debe ser racional. Usar una estructura que demande Terabytes de almacenamiento no es racional (esto ha pasado antes).

### u32
Se utilizará el tipo de dato `u32` para especificar un entero de 32 bits sin signo.
Todos los enteros sin signo de 32 bits que aparezcan en la implementación y que no sean un color de un vértice deberán usar este tipo de dato.
Los grafos a colorear tendran una lista de lados cuyos vertices serán todos `u32`.
Pueden declarar `u32` como `unsigned int` o bien haciendo un include de int.h y declarandolo apropiadamente. `u32` **NO ES** un `long unsigned int` en computadoras modernas.

### color
El tipo de dato `color` es un `u32`.
Tiene qun nombre distinto como medida para evitar posibles errores de programación. Como el nombre lo indica, será usado solamente para los colores de los vértices, mientras que los vertices serán `u32`.

## Funciones De Construcción/Destrucción del grafo

### ConstruirGrafo()
Prototipo de función: 
`Grafo ConstruirGrafo();`
La función aloca memoria, inicializa lo que haya que inicializar de una estructura `GrafoSt`, lee un grafo **desde standard input** en el formatoindicado en la última sección, lo carga en la estructura, colorea todos los vertices con el color 0, y devuelve un puntero a la estructura.
En caso de error, la función devolverá un puntero `NULL`. Errores posibles pueden ser falla en alocar memoria, pero también que el formato de entrada no sea válido. Por ejemplo, en la última sección se dice que en una cierta linea se indicará un número *m* que indica cuantos lados habrá y a continuación debe haber *m* lineas cada una de las cuales indica un lado. Si no hay AL MENOS *m* lineas luego de esa, debe retornar `NULL` (si hay mas de *m* lineas luego de la primera, sólo debe leer las *m* primeras).
Dado que esta función debe como mínimo leer todos los lados de los datos de entrada, su complejidad n puede ser inferior a **O(m)**, pero esta función NO PUEDE ser **O(n²)** (y MENOS puede ser **O(mn)**) pues en los grafos de testeo habrá grafos con millones de vértices, y un grafo asi con un algoritmo **O(n²)** no terminará en un tiempo razonable.
En cuanto a *m*, puede estar en el orden de millones también, y puede ser *m = O(n²)*, pero sólo para *n* del orden de miles, mientras que cuando *n* sea del orden de millones, *m* no será *O(n²)* sino *O(n)*, pues como dijimos arriba esta función no puede tener complejidad menor a *O(m)* y un *m* de pej miles de millones haría que demorara mucho. 
Así que deberían pensar una estructura tal que esta función sea, idealmente, *O(m)*. En años anteriores, con las especificaciones dadas entonces, esto parecía ser muy difícil, así que *O(mlogm)* era perfectamente aceptable. Este año, con las especificaciones dadas, deberían poder hacerlo en tiempo O(m), pero también aceptaremos *O(mlogm)*. (el código para *O(mlogm)* es probablemente más corto, dependiendo como programen).

### DestruirGrafo()
Prototipo de función:
`void DestruirGrafo(Grafo G);`
Destruye G y libera la memoria que alocada.
Esta función también deberia tener una complejidad razonable, no hay razón para que sea mayor a **O(m)** e incluso puede ser menor, pero **O(m)** es aceptable.

## Funciones para extraer información de datos del grafo
Las funciones detallas en esta sección y las que siguen deben ser todas **O(1)**., pues serán usadas repetidamente por las funciones de la segunda etapa y si no son **O(1)** no podrán hacer correr las funciones en un tiempo razonable. No debería haber ningún problema con esto, basta con guardar la información en un campo adecuado en la estructura del grafo.

### NumeroDeVertices()
Prototipo de función:
`u32 NumeroDeVertices(Grafo G);`
Devuelve el número de vértices de G.

### NumeroDeLados()
Prototipo de función:
`u32 NumeroDeLados(Grafo G);`
Devuelve el número de lados de G.

### Delta()
Prototipo de función:
`u32 Delta(Grafo G);`
Devuelve ∆(G), es decir, el mayor grado.
Esta función esta detallada aca para ser usada en algunos casos y no tener que recalcular ∆, asi que si, en vez de hacer el cálculo una vez durante la construcción del grafo y guardar el resultado para que esta función lo pueda leer en **O(1)**, lo que hacen es recalcular ∆ cada vez que se llama a esta función, tendrán descuento de puntos.

## Funciones para extraer información de los vertices
En esta sección tenemos funciones que nos permitan saber el grado de un v ́ertice, y acceder a sus vecinos.
Los vertices ser ́an los números 0,1,...,n − 1.
Las funciones detalladas en esta sección, como en la anterior deben ser *O(1)*. De hecho, es mucho mas importante que sean *O(1)* estas, pues las anteriores probablemente sean usadas sólo una o dos veces en cada función, mientras que para colorear un vertice habrá que iterar sobre los vecinos de ese vértice repetidamente, y si la función que permite leer datos de vecinos no es *O(1)* para cada vecino, habrá problemas de velocidad.

### Grado()
Prototipo de función:
`u32 Grado(u32 i, Grafo G);`
Si `i` es menor que el número de vértices, devuelve el grado del vértice `i`.
Si `i` es mayor o igual que el número de vértices, devuelve 0. (esto nunca puede ser un grado en los grafos que testeemos, pues no habrá vertices aislados).

### Color()
Prototipo de función:
`color Color(u32 i, Grafo G);`
Si `i` es menor que el número de vértices, la función devuelve el color del vértice `i`.
Si `i` es mayor o igual que el número de vértices, la función devuelve 2³²-1.

### Vecino()
Prototipo de función:
`u32 Vecino(u32 j, u32 i, Grafo G);`
Esta función nos permite acceder a los vecinos de un vértice, para poder usar **SUS** datos.
Si `i` es mayor o igual que el número de vértices o `i` es menor que el número de vértices pero `j` es mayor o igual que el grado del vértice `i` entonces la función devuelve 2³²-1.(esto nunca puede ser un vecino porque necesitariamos un grafo inmunejablemente grande).
Si `i` es menor que el número de vértices y `j` es menor que el grado de vértice `i` y el vécino j-ésimo del vértice `i` es el vértice `k` entonces `Vecino(j, i, G)` es igual a `k`.
En esta función se habla del **vécino j-ésimo**.
Con esto nos referimos al vértice que es el j-ésimo vécino del vértice en cuestión donde el orden del cual se habla es el orden en el que ustedes hayan guardados los vecinos de un vértice en G, con el índice 0 indicando el primer vécino, el índice 1 el segundo, etc.
Este orden NO ESTA ESPECIFICADO, y un grupo puede tener un orden y otro grupo otro, asi que el retorno para valores individuales de estas funciones no será el mismo para un grupo que para otro, y no será necesariamente igual al retorno de nuesstras funciones.
Prodriamos especificar los vecinos deben estar guardados en algun orden particular, pero no es necesario para nuestros propositos, asi que les dejamos libertad para que lo hagan de la forma mas conveniente para su estructura.
Para que sirve una función que da valores distintos dependiendo de la implementación?
Esta función existe pues para colorear necesitamos iterar sobre **todos** los vecinos, y porque si queremos testear si la estructura del grafo esta bien guardada, necesitamos una función que nos permita "ver" cómo estan guardados los vecinos en esa estructura.
Pero no es importante el orden en que estan guardados, sólo importa que podamos recorrerlos a todos, por eso no especificamos el orden de los vecinos.
**IMPORTANTE:** si bien ya hemos dicho que todas las funciones de estas secciones deben ser *O(1)*, reiteraos, una vez mas, que esta función debe ser *O(1)*.
Como va a ser usada para iterar sobre los vecinos, probablemente dentro de un loop que ademas itere sobre todos los vértices, es **CLAVE** que esta función sea *O(1)* pues de lo contrario nada va a poder funcionar a una velocidad razonable. Asi que la estructura que armen del grafo debe ser tal que esta función sea *O(1)* y no tenga que hacer una iteración para ser calculada.

## Funciones para asignar colores

### AsignarColor()
Prototipo de función:
`void AsignarColor(color x, u32 i, Grafo G);`
Si `i` es mayor o igual que el número de vértices, esta función no hace nada.
Si `i` es menor que el número de vértices, la función asigna el color `x` al vértice `i`.

### ExtraerColores()
Prototipo de función:
`void ExtraerColores(Grafo G, color* Color);`
Si n es el número de vértices de G, esta función asigna a `Color[i]` el color que tiene el vértice `i` en *G*, para cada `i` entre 0 y n-1.
**SE ASUME** que Color es un array que apunta a un lugar de memoria con `n` lugares.
**NO ES REQUERIMIENTO** que la función preserve el color de los vértices. Es decir, luego de llamar a esta unción, los colores de los vértices de G pueden ser distintos de los originales. (dependiendo de quien implemente esta función).
Por lo tanto, el usuario de esta función debe tener en cuenta esto.

### ImportarColores()
Prototipo de función:
`void ImportarColores(color* Color, Grafo G);`
Si `n` es el número de vértices de *G*, esta función asigna al vértice `i` de *G* el color `Color[i]`, para cada `i` entre 0 y `n`-1.
**SE ASUME** que `Color` es un array que apunta a un lugar de memoria con `n` lugares.
**NO ES REQUERIMIENTO** que la función preserve los valores originales que tenia `Color`. Es decir, luego de llamar a esta función, el array `Color` puede tener cualquier cosa. (dependiendo de quien implemente esta función).
Por lo tanto, el usuario de esta función debe tener en cuenta esto.

## Consideraciones finales para esta primera etapa
En esta etapa, la mayoria de las funciones son muy fáciles si piensan primero bien la estructura con la cual van a cargar el grafo.
Las cosas mas dificiiles de esta primera etapa son:
1. Definir la estructura en forma adecuada para que las funciones de extracción de información sean *O(1)*.
2. Programar en forma eficiente la construccioón del grafo. Algunos grafos tendrán millones de vértices, por lo tanto una construcción que sea *O(n²)* no terminará de cargar el grafo en ningún tiempo razonable. No es necesario que sea hipereficiente, pues la construcción del grafo se hace una sola vez, mientras que la lectura de los datos múltiples veces, pero no puede ser tan ineficiente que demore horas o días en cargar un grafo.

## Formato de Entrada
El formato de entrada será una variación de **DIMACS**, que es un formato estandard para representar grafos, con algunos cambios.
1. Las lineas pueden tener una **cantidad arbitraria de caracteres**. (la descripción oficial de Dimacs dice que ninguna linea tendrá mas de 80 caracteres pero hemos visto archivos DIMACS en la web que no cumple esta especificación y usaremos algunos con lineas de mas de 80 caracteres).
2. Al principio habrá cero o mas lineas que empiezan con c las cuales son lineas de comentario y deben ignorarse.
3. Luego hay una linea de la forma:
   p edge n m
   donde n y m son dos enteros. Luego de m, y entre n y m, puede haber una cantidad arbitraria de espacios en blancos.
   Si bien hay ejemplos en la web en donde n es en realidad solo un COTA SUPERIOR del número de vertices y m una cota superior del número de lados, todos los grafos que nosotros usaremos para testear cumplirán que n será el número de vertices exacto y m el número de lados exacto.
4. Luego siguen m lineas todas comenzando con e y dos enteros, representando un lado. Es decir, lineas de la forma:
   e v w
   (luego de "w" y entre "v" y "w" puede haber una cantidad arbitraria de espacios en blanco).
5. Nunca fijaremos `m = 0`, es decir, siempre habrá al menos un lado. (y por lo tanto, al menos dos vértices).
6. Si bien en algunos ejemplos en algunas páginas hay vértices con grado 0, y que por lo tanto no aparecen en ningún lado en nuestros ejemplos no habrá vértices con grado 0: los únicos vértices que cuentan son los vértices que aparecen como extremos de al menos un lado.
7. Luego de esas m lineas puede haber una cantidad arbitraria de lineas de cualquier formato las cuales deben ser ignoradas. Es decir, se **debe detener la carga sin leer ninguna otra linea luego de las m lineas**, aún si hay mas lineas. Estas lineas extras pueden tener una forma arbitraria, pueden o no ser comentarios, o extra lados, etc. y deben ser ignoradas. Pueden, por ejemplo, tener un SEGUNDO grafo, para que si la función de carga de un grafo se llama dos
veces por algún programa, el programa cargue dos grafos. Por otro lado, el archivo puede efectivamente terminar en la  ́ultima de esas lineas, y su código debe poder procesar estos archivos también. En un formato válido de entrada habrá al menos *m* lineas comenzando con *e*, pero puede haber algún archivo
de testeo en el cual no haya al menos m lineas comenzando con e. En ese caso, como se especifica en 3.1, debe detenerse la carga y devolver un puntero a NULL.
O por ejemplo tambien podremos testear con archivos donde en vez de p edge n m tengan algo similar pero no correcto como p edgee n m, en cuyo caso tambien deben devolver NULL.
8. Los vertices serán 0,1,2,...,n-1. (nota: en muchos ejemplos de la web, los vértices son 1,2,...,n y en otros casos son cualesquiera n enteros de 32 bits. Este año elejimos 0,1,2,...,n-1 para que sea mas fácil cargar el grafo y para disminuir la posibilidad de error con indices de arrays en C).
9. En algunos archivos que figuran en la web, en la lista pueden aparecer tanto un lado de la forma
   e 7 9
   como el
   e 9 7
   Los grafos que usaremos nosotros **no son asi**.
   Es decir, si aparece el lado e v w **NO** aparecerá el lado e w v.
   Ejemplo:
   c grafo basado en una Mycielski transformation, pero con un lado extra
   c Triangle free (clique number 2) but increasing
   p edge 12 31
   e 1 2
   e 1 4
   e 1 7
   e 1 9
   e 2 3
   e 2 6
   e 2 8
   e 3 5
   e 3 7
   e 3 10
   e 4 5
   e 4 6
   e 4 10
   e 5 8
   e 5 9
   e 6 11
   e 7 11
   e 8 11
   e 9 11
   e 10 11
   e 0 10
10. El orden de los lados no tiene porqué ser en orden ascendente de los vertices, ni lo lados estar ordenados con el vértice mas chico primero.
   Ejemplo Válido:
   c lados no ordenados
   p edge 5 5
   e 3 0
   e 4 1
   e 2 4
   e 1 2
   e 3 1
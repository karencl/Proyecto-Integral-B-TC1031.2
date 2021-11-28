# TravelPlan - Proyecto-Integral-B-TC1031.2
El proyecto de "TravelPlan", desarrollado para el proyecto integrador B, busca trabajar con grafos y hashes a través de un programa que calcule las rutas más óptimas de viaje, de un país a otro.

El objetivo que tiene este proyecto, es poner en práctica el uso de estructuras como grafos, mapas y hashes, para resolver alguna problemática o eficientar el funcionamiento de algún programa.

En la parte de abajo, podremos encontrar la estructura con la que este programa fue hecho, el análisis de complejidad de los algoritmos usados, aclacariones sobre los casos de prueba y la explicación de algunos recursos extra usados en este trabajo, así como archivos *.txt* utilizados en este programa y un *menú* para facilitar la interacción del usuario con éste.

## SICT0302B: Toma decisiones

#### Usa grafos para hacer analisis de información.
Para el uso de grafos de este proyecto decidí utilizar una lista de adyacencia para el guardado y la manipulación de los datos.
Decidí hacer esto, debido a la forma en la que yo busco desplegar los datos y como es que se fcilitaría manejarlos. Es decir, al simular el despliegue de una ruta, no necesito utilizar una matriz, pues solo con tener los elementos dentro de otros (dependiendo de sus conexiones), se podría recorrer y mostrar de manera más sencilla.

En estos grafos se van encontrar países de los archivos *places_europe.txt* y *places_asia.txt*, que contienen parejas de países que son adyacientes, según su ubicación geográfica. (Estos se agregan al grafo en cuanto se inicia el programa).
Así mismo, se podrán acomodar y hacer consultas a éstas, con el fin de obtener las rutas de un país a otro.

#### Usa un algoritmo de búsqueda en grafos adecuado para resolver un problema.
En este caso decidí utilizar el "Depth first search" o "DFS" con el fin de mostrarle al usuario la cantidad de países que se podrían recorrer, en caso de no utilizar la ruta óptima propuesta por el programa. (Esto debido a que este método de búsqueda, lo que hace es que explora lo más lejos posible de inicio).

Por la parte de la complejidad no hay problema, ya que tanto el *DFS* como el *BFS* tienen la misma para el peor de los casos: *O(v + a)*. (Abajo está la expliación de esto).

#### Usa un algoritmo de hashing adecauado para resolver un problema.
Para esta parte del proyecto decidí utilizar un "unordered_map", ya que la forma en la que este está implementado, es a través del hashing.
Decidí utilzar este debido a que el grafo está implementado con *int* y la forma en la que pensé guardar los países, fue a través de el nombre de estos (*string*) y un id único para cada uno (*int*). Entonces... para el grafo guardo los países usando sus id, que en el hash serían los *values*.

La razón por la que implementé esto de esta manera, fue porque estos no siempre van a estar acomodados en orden y así puedo tener un manejo más fácil de los valores, y poder buscarlos o ubicar estos en una tabla, a través de una *key*, que serían los nombres por los que estos están ubicados.

El hash implementado en mi programa, fue utilizando la librería *<unordered_map>*. Estos se crean como atributos del grafo, con el fin de poder manejarlo (por el acceso) más facilmente dentro de los métodos de la clase.

## SEG0702A Tecnologías de Vanguardia

#### Investiga e implementa un algoritmo o una estructura de datos que no se vió durante el curso.
Como estructura de datos extra (no vista durante el curso), elegí utilizar un *set* usando la librería estándar de c++.
La razón principal por la que elegí este tipo de estructura, es porque necesitaba tener todos los países disponibles para mostrar al usuario, pero solamente 1 vez. Y como la función principal del *set* es funcionar como contenedor de elementos únicos, era exactamente lo que ocupaba para guardar estos, al recorrer el grafo completamente, sin preocuparme por tener que lidiar con valores que se repitieran.

Así mismo, para darle una mejor presentación, quería mostrar los países en orden alfabético; lo que el *set* ya hace al funcionar de esa forma y de esta manera, me evito utilizar algún otro algoritmo de ordenamiento, para lograr esto.

#### Describe cada algoritmo de la estructura (inserción, consulta, etc...).
- Como está basado en la implementación de un bst, el algoritmo de inserción en un set tiene una complejidad en el peor de los casos de *O(log(n))*, donde *n* es el tamaño de este. (Se mantiene balanceado por el orden que lleva).
- Para consultar si un elemento se encuentra dentro o no de la estructura (función "count()"), se busca de igual manera usando la lógica de un bst y regresa un verdadero o falso dependiendo de lo encontrado. Debido a esto, la complejidad de este algoritmo es de *O(log(n))*.
- Vaciar un set, requiere una iteración completa sobre este, por lo que tiene una complejidad de *O(n)*.
- Obtener su valor


## SICT0301B: Evalúa los componentes

#### Presenta Casos de prueba para todas las funciones y procedimientos del programa.
-> pendiente

#### Hace un análisis de complejidad (en el pero de los casos) correcto y completo para todo el programa y sus componentes.
- **Crear el grafo a partir de los datos en los archivos .txt:**
Para crear todo el gráfo en el inicio del programa, si necesitamos recorrer todo un archivo *.txt*. Es por ello que en este caso, el tiempo de complejidad es de *O(n)*. (El número de vueltas del ciclo depende del *n* número de líneas que contenta el archivo).

- **Método "addEdge()" (grafo):**
Este método es constante (*O(1)*), ya que solo se utilizan unas cuantas líneas de código para hacer la operación de agregar vértices o crear conexiones entre ellos. No hay necesidad de hacer vueltas/ ciclos.

- **Ordenar la lista de adyacencia (grafo):**
En este caso, se utiliza un ciclo for que da tantas vueltas como nodos tengamos y dentro de cada una, se manda a llamar la función *sort()* de la librería estándar de c++, que tiene una complejidad de *O(n log(n))*.
Entonces si juntamos esta complejidad con la del ciclo for (*O(n)*), obtendríamos una complejidad de tiempo de *O(n^2 log(n))*. 

(Esto se debe a que dentro de cada elemento de la lista, puede haber otra pequeña lista que tengamos que ordenar).

- **Imprimir lista de adyacencia/ path/ visited (grafo):**
En todos estos casos, vamos a tener una complejidad de *o(n)* ya que tenemos que ir obteneindo los valores en cada vuelta, para imprimir todos y cada uno de ellos.

- **DFS (grafo):**
Como en este caso se usa la lista de adyacencia, para la complejidad se toman en cuenta la cantidad de vértices/nodos que se van a visitar y la cantidad de aristas que estos tengan. Es por ello, que entonces la complejidad de tiempo se expresaría algo así como O(v) por el número de vértices y O(a) por el número de aristas; teniendo entonces la complejidad completa de: O(v) + O(a).

Esto de igual manera podría ser expresado de la siguiente manera: O(v + a).

- **Método "contains()" (grafo):**
Este método busca con un iterador el valor deseado, en una lista que se le pasa y regresa un valor booleano dependiendo si se encontró o no. 
Por ello, en el peor de los casos su complejidad siempre va a ser de *O(n)*, en caso de que se encuentre el valor al final o simplemente no se encuentre en absoluto. 

- **Insertar elemento (hash):**
Al insertar un nuevo "Key, Value" en el hash, se tiene que tomar en cuenta el tamaño de este en el peor de los casos. Esto pasa debido a que nos podemos encontrar con varias colisiones en una sola vuelta de inserción y por ende, necesitaríamos buscar posibles soluciones (usando prueba cuadrática en este caso), para poder colocar el nuevo "Key, Value". Entonces... podríamos decir que en el peor escenario, la complejidad del método put() es de O(n). (Aunque es más facil encontrarse con el caso promedio).

- **Obtener elemento (hash):**
Al utilizar la librería estándar, no hay un método específico en el programa que podemos ver tal cual (está, pero en la librería). Pero en este caso, tenemos que la complejidad en el peor de los casos sería de O(n), debido a que se podría llegar a recorrer toda la tabla hash, para encontrar el valor de una llave.

- **Obtener la lista de países disponibles (set):**
Para obtener el set completo, con la lista de todos los países, se tiene que recorrer todo el grafo. Es por ello, que la complejidad de esto en el peor de los casos podría ser *O(n^2)*, debido a que se utilizan dos ciclos for (uno para los valores iniciales de la lista de adyacencia y otro para las respectivas conexiones de dichos valores).

- **Insertar elemento (set):**
Al utilizar la librería estándar, no hay un método específico en el programa que podemos ver tal cual (está, pero en la librería). Pero en este caso, tenemos que la complejidad en el peor de los casos sería de *O(log(n))*, ya que utiliza la lógica del bst, al mantenerse balanceado. (Comoe sigue este orden, el tiempo de inserción no es tan elevado, ya que normalmente los elementos no se van a mandar hasta el final y más bien esto será guiado por su valor).

- **Extras (funciones del main):**
Imprimir el Menú es una operación constante (*O(1)*), ya que no requiere de ciclos ni nada por el estilo.

Obtener la información para sacar las rutas también tiene una complejidad de *O(1)*, debido a que solo se piden unos cuantos valores y se utilizan solamente unas cuantas condiciones. (Tampoco se usan ciclos o se requieren varias vueltas).

Imprimir los países que se encuentran en el *set*, tiene una complejidad de *O(n)* para todos los casos, ya que se recorre de principio a fin, cada vez que se llama a esta función.

## SICT0303B: Implementa acciones científicas (ya se entregó en el Proyecto Integral A)

#### Implementa mecanismos para consultar información de las estructuras correctos y útiles.
Como se mencionó en la parte de arriba, a pesar de que esta competencia ya se entregó en el proyecto integral A, decidí también agregar parte de ésta (solamente el menú como herramienta de consulta), con el fin de mejorar la experiencia del usuario y facilitar el entendimiento del programa.

Entonces... demás del archivo *.cpp* que contiene los casos de prueba, tenemos el archivo *main.cpp*, que contiene un menú con una serie de opciones, que nos van a permitir:

- Mostrar lista de países disponibles en el programa para viajar por europa.
- Mostrar lista de países disponibles en el programa para viajar por asia.
- Visualizar el grafo de los países del contienente europeo.
- Visualizar el grafo de los países del contienente asiático.
- Consultar la ruta más corta (óptima), para un viaje de un país de origen a uno de destino. 
- Consultar la ruta con la mayor cantidad posible de países a visitar (dependiendo de sus conexiones entre fronteras), para un viaje de un país de origen a uno de destino.
- Consultar ambas opciones de rutas anteriores, para un viaje de un país de origen a uno de destino.

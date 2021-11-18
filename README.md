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

## SICT0301B: Evalúa los componentes

#### Presenta Casos de prueba para todas las funciones y procedimientos del programa.
-> pendiente

#### Hace un análisis de complejidad correcto y completo para todo el programa y sus componentes.
-> pendiente

## SICT0303B: Implementa acciones científicas (ya se entregó en el Proyecto Integral A)

#### Implementa mecanismos para consultar información de las estructuras correctos y útiles.
Como se mencionó en la parte de arriba, a pesar de que esta competencia ya se entregó en el proyecto integral A, decidí también agregar parte de ésta (solamente el menú como herramienta de consulta), con el fin de mejorar la experiencia del usuario y facilitar el entendimiento del programa.

Entonces... demás del archivo *.cpp* que contiene los casos de prueba, tenemos el archivo *main.cpp*, que contiene un menú con una serie de opciones, que nos van a permitir:

- Visualizar el grafo de los países del contienente europeo.
- Visualizar el grafo de los países del contienente asiático.
- Consultar la ruta más corta (óptima), para un viaje de un país a otro.
- Consultar la ruta con la mayor cantidad posible de países a visitar, para un viaje de un país de origen a uno de destino. -> medio pendiente

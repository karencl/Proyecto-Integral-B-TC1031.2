/*
 * Proyecto TravelPlan
 * Karen Cebreros López
 * A01704254
 * 17/11/2021
 *
 * mainDePruebas.cpp
 * TravelPlan
 * Created by Karen CL on 17/11/21.
 * Copyright © 2021 KarenCbrs. All rights reserved.
 */

/*
 * Descripción:
 * Este es un proyecto para la clase de "Programación de estructuras de datos y
 * algoritmos fundamentales".
 * Es un programa que hace rutas para planes de viajes, con el fin de optimizar el
 * tiempo de traslado.
 * Esto se hace a través de las conexiones entre países que se pasan en un archivo
 * ".txt".
 * Tiene como objetivo aprender sobre las estructuras de datos como grafos,
 * mapas, hashes y más.
 *
 * En este main de pruebas, se encuentran algunas de estas para probar que las
 * salidas de las rutas y los países, son correctas y esperadas, según el
 * funcionamiento de las estructuras ya mencionadas.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include "Graph.h"

using namespace std;

bool getTripInfo(string&, string&, string&);
string printCountries(set<string>&);

int main() {
    
    // Se abren los archivos
    ifstream europe_file("places_europe.txt");
    ifstream asia_file("places_asia.txt");
    
    if (!europe_file.is_open() || !asia_file.is_open()) {
        cout << "Hubo algún error al abrir los archivos." << endl;
        return 1;
    }
    
    // Se un objeto "Graph" para Europa
    Graph europe(20);
    europe.createGraph(europe_file);
    
    // Se crea un objeto "Graph" para Asia
    Graph asia(14);
    asia.createGraph(asia_file);
    
    // Otras variables auxiliares
    string countries_in_set, path, visited, path_and_visited, graph, aux;
    set<string> aux_set;
    
    cout << "\n- - - - - - - - - - - - PRUEBA 1 - - - - - - - - - - - -" << endl;
    countries_in_set = "\t- austria\n\t- belgium\n\t- bulgaria\n\t- croatia\n\t- czechia\n\t- denmark\n\t- estonia\n\t- finland\n\t- france\n\t- germany\n\t- greece\n\t- hungary\n\t- italy\n\t- poland\n\t- portugal\n\t- romania\n\t- rusia\n\t- slovakia\n\t- spain\n\t- ukraine\n";
    aux_set = europe.getCountries();
    aux = printCountries(aux_set);
    cout << "RESPUESTA ESPERADA:" << endl;
    cout << countries_in_set << endl;
    cout << "PROGRAMA:" << endl;
    cout << aux << "\n" << endl;
    if (countries_in_set == aux)
        cout << "PRUEBA 1 -> SUPERADA" << endl;
    else
        cout << "PRUEBA 1 -> ¡ERROR!" << endl;
    
    cout << "\n- - - - - - - - - - - - PRUEBA 2 - - - - - - - - - - - -" << endl;
    countries_in_set = "\t- afghanistan\n\t- china\n\t- india\n\t- iran\n\t- kyrgyzstan\n\t- laos\n\t- malaysia\n\t- mongolia\n\t- myanmar\n\t- nepal\n\t- pakistan\n\t- tajikistan\n\t- thailand\n\t- vietnam\n";
    aux_set = asia.getCountries();
    aux = printCountries(aux_set);
    cout << "RESPUESTA ESPERADA:" << endl;
    cout << countries_in_set << endl;
    cout << "PROGRAMA:" << endl;
    cout << aux << "\n" << endl;
    if (countries_in_set == aux)
        cout << "PRUEBA 2 -> SUPERADA" << endl;
    else
        cout << "PRUEBA 2 -> ¡ERROR!" << endl;
    
    cout << "\n- - - - - - - - - - - - PRUEBA 3- - - - - - - - - - - -" << endl;
    graph = "* spain:\n\t -> france -> portugal\n* france:\n\t -> spain -> italy -> belgium -> germany\n* portugal:\n\t -> spain\n* italy:\n\t -> france -> austria\n* belgium:\n\t -> france\n* germany:\n\t -> france -> czechia -> denmark\n* austria:\n\t -> italy -> slovakia\n* czechia:\n\t -> germany\n* denmark:\n\t -> germany\n* slovakia:\n\t -> austria -> poland -> hungary\n* poland:\n\t -> slovakia\n* hungary:\n\t -> slovakia -> romania -> ukraine -> croatia\n* romania:\n\t -> hungary -> bulgaria\n* ukraine:\n\t -> hungary -> rusia\n* croatia:\n\t -> hungary\n* bulgaria:\n\t -> romania -> greece\n* greece:\n\t -> bulgaria\n* rusia:\n\t -> ukraine -> finland -> estonia\n* finland:\n\t -> rusia\n* estonia:\n\t -> rusia\n";
    aux = europe.printAdjList();
    cout << "RESPUESTA ESPERADA:" << endl;
    cout << graph << endl;
    cout << "\nPROGRAMA:" << endl;
    cout << aux << "\n" << endl;
    if (graph == aux)
        cout << "PRUEBA 3 -> SUPERADA" << endl;
    else
        cout << "PRUEBA 3 -> ¡ERROR!" << endl;
    
    cout << "\n- - - - - - - - - - - - PRUEBA 4 - - - - - - - - - - - -" << endl;
    graph = "* thailand:\n\t -> laos -> malaysia\n* laos:\n\t -> thailand -> vietnam -> myanmar\n* malaysia:\n\t -> thailand\n* vietnam:\n\t -> laos -> china\n* myanmar:\n\t -> laos\n* china:\n\t -> vietnam -> nepal -> mongolia -> kyrgyzstan -> tajikistan\n* nepal:\n\t -> china -> india\n* mongolia:\n\t -> china\n* kyrgyzstan:\n\t -> china\n* tajikistan:\n\t -> china\n* india:\n\t -> nepal -> pakistan\n* pakistan:\n\t -> india -> iran -> afghanistan\n* iran:\n\t -> pakistan\n* afghanistan:\n\t -> pakistan\n";
    aux = asia.printAdjList();
    cout << "RESPUESTA ESPERADA:" << endl;
    cout << graph << endl;
    cout << "PROGRAMA:" << endl;
    cout << aux << "\n" << endl;
    if (graph == aux)
        cout << "PRUEBA 4 -> SUPERADA" << endl;
    else
        cout << "PRUEBA 4 -> ¡ERROR!" << endl;
    
    cout << "\n- - - - - - - - - - - - PRUEBA 5 - - - - - - - - - - - -" << endl;
    visited = "Ruta con la mayor cantidad de países (conectados por frontera), posibles a visitar (siguiendo la ruta óptima):\n\t -> france -> germany -> denmark -> czechia -> belgium -> italy -> austria -> slovakia -> hungary -> croatia -> ukraine -> rusia\n";
    aux = europe.DFS("france", "rusia", 2);
    cout << "RESPUESTA ESPERADA:" << endl;
    cout << visited << endl;
    cout << "PROGRAMA:" << endl;
    cout << aux << "\n" << endl;
    if (visited == aux)
        cout << "PRUEBA 5 -> SUPERADA" << endl;
    else
        cout << "PRUEBA 5 -> ¡ERROR!" << endl;
    
    cout << "\n- - - - - - - - - - - - PRUEBA 6 - - - - - - - - - - - -" << endl;
    path = "Ruta más corta:\n\t -> malaysia -> thailand -> laos -> vietnam -> china";
    aux = asia.DFS("malaysia", "china", 1);
    cout << "RESPUESTA ESPERADA:" << endl;
    cout << path << endl;
    cout << "\nPROGRAMA:" << endl;
    cout << aux << "\n" << endl;
    if (path == aux)
        cout << "PRUEBA 6 -> SUPERADA" << endl;
    else
        cout << "PRUEBA 6 -> ¡ERROR!" << endl;
    
    cout << "\n- - - - - - - - - - - - PRUEBA 7 - - - - - - - - - - - -" << endl;
    path_and_visited = "Ruta con la mayor cantidad de países (conectados por frontera), posibles a visitar (siguiendo la ruta óptima):\n\t -> poland -> slovakia -> hungary -> croatia -> ukraine -> rusia -> estonia\nRuta más corta:\n\t -> poland -> slovakia -> hungary -> ukraine -> rusia -> estonia";
    aux = europe.DFS("poland", "estonia", 3);
    cout << "RESPUESTA ESPERADA:" << endl;
    cout << path_and_visited << endl;
    cout << "\nPROGRAMA:" << endl;
    cout << aux << "\n" << endl;
    if (path_and_visited == aux)
        cout << "PRUEBA 7 -> SUPERADA" << endl;
    else
        cout << "PRUEBA 7 -> ¡ERROR!" << endl;
    
    cout << "\n- - - - - - - - - - - - PRUEBA 8 - - - - - - - - - - - -" << endl;
    path = "Ruta más corta:\n\t -> portugal -> spain -> france -> germany -> czechia";
    aux = europe.DFS("portugal", "czechia", 1);
    cout << "RESPUESTA ESPERADA:" << endl;
    cout << path << endl;
    cout << "\nPROGRAMA:" << endl;
    cout << aux << "\n" << endl;
    if (path == aux)
        cout << "PRUEBA 8 -> SUPERADA" << endl;
    else
        cout << "PRUEBA 8 -> ¡ERROR!" << endl;
    
    cout << "\n- - - - - - - - - - - - PRUEBA 9 - - - - - - - - - - - -" << endl;
    visited = "Ruta con la mayor cantidad de países (conectados por frontera), posibles a visitar (siguiendo la ruta óptima):\n\t -> tajikistan -> china -> kyrgyzstan -> mongolia -> nepal -> india -> pakistan -> afghanistan -> iran -> vietnam -> laos -> myanmar -> thailand\n";
    aux = asia.DFS("tajikistan", "thailand", 2);
    cout << "RESPUESTA ESPERADA:" << endl;
    cout << visited << endl;
    cout << "\nPROGRAMA:" << endl;
    cout << aux << "\n" << endl;
    if (visited == aux)
        cout << "PRUEBA 9 -> SUPERADA" << endl;
    else
        cout << "PRUEBA 9 -> ¡ERROR!" << endl;
    
    cout << "\n- - - - - - - - - - - - PRUEBA 10 - - - - - - - - - - - -" << endl;
    path_and_visited = "Ruta con la mayor cantidad de países (conectados por frontera), posibles a visitar (siguiendo la ruta óptima):\n\t -> mongolia -> china -> tajikistan -> kyrgyzstan -> nepal -> india -> pakistan -> afghanistan -> iran\nRuta más corta:\n\t -> mongolia -> china -> nepal -> india -> pakistan -> iran";
    aux = asia.DFS("mongolia", "iran", 3);
    cout << "RESPUESTA ESPERADA:" << endl;
    cout << path_and_visited << endl;
    cout << "\nPROGRAMA:" << endl;
    cout << aux << "\n" << endl;
    if (path_and_visited == aux)
        cout << "PRUEBA 10 -> SUPERADA" << endl;
    else
        cout << "PRUEBA 10 -> ¡ERROR!" << endl;
    
    cout << "\n- - - - - - - - - - - - PRUEBA 11 - - - - - - - - - - - -" << endl;
    path = "Ruta más corta:\n\t -> portugal -> spain -> france -> belgium";
    aux = europe.DFS("portugal", "belgium", 1);
    cout << "RESPUESTA ESPERADA:" << endl;
    cout << path << endl;
    cout << "\nPROGRAMA:" << endl;
    cout << aux << "\n" << endl;
    if (path == aux)
        cout << "PRUEBA 11 -> SUPERADA" << endl;
    else
        cout << "PRUEBA 11 -> ¡ERROR!" << endl;
    
    
    cout << "\nFin de los casos de prueba.\n" << endl;
    europe_file.close();
    asia_file.close();
    
    return 0;
}

/*
 * @param string&, string&, string&
 * @return bool
 *
 * Obtiene los datos del viaje, que se van a ocupar para hacer los recorridos y
 * obtener las rutas.
 * Modifica las variables que se pasan por referencia, para ser usadas en la parte
 * del menú en las respectivas opcioens.
 *
 * La función regresa un bool, dependiendo si los valores ingresados son corrsctos
 * o no. Y dependiendo a eso, se hacen los recorridos más adelante.
 *
 */
bool getTripInfo(string &continente, string &start, string &end) {
    cout<<"\nContinente donde quiere realizar la búsqueda (en inglés): ";
    cin >> continente;
    cout << "\nIngrese el país de inicio (en inglés): ";
    cin >> start;
    cout << "Ingrese el país de destino (en inglés): ";
    cin >> end;
    
    transform(continente.begin(), continente.end(),continente.begin(), ::tolower);
    transform(start.begin(), start.end(), start.begin(), ::tolower);
    transform(end.begin(), end.end(), end.begin(), ::tolower);
    
    if (start != end) {
        if (continente == "europe" || continente == "asia")
            return true;
        else {
            cout << "\nContinente no encontrado." << endl;
            return false;
        }
    } else {
        cout<<"\nError: el punto de partida y llegada es el mismo."<<endl;
        return false;
    }
}

/*
 * @param set<string>&
 * @return string
 *
 * Imprime los todos los países que se encuentran en el set, ya que este contiene
 * todos los países disponibles para los viajes (una sola vez c/u), debido a que
 * es parte de su función.
 * (Están en orden).
 *
 */
string printCountries(set<string> &the_set) {
    stringstream aux;
    
    for (auto x : the_set) {
        aux << "\t- " << x << "\n";
    }
    
    return aux.str();
}

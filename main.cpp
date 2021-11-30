/*
 * Proyecto TravelPlan
 * Karen Cebreros López
 * A01704254
 * 17/11/2021
 *
 * main.cpp
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
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include "Graph.h"

using namespace std;

void showMenu();
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
    string continente, pos_inicial, pos_final;
    set<string> aux_set;
    
    // Menú
    int option = 1;
    while (option != 8) {
        showMenu();
        cout << "\nIngrese una opción: ";
        cin >> option;
        
        // Lista de países dosponibles para viajar (europa)
        if (option == 1) {
            cout << "\nPaíses disponibles para viajes en Europa (en orden";
            cout << "alfabético):" << endl;
            
            aux_set = europe.getCountries();
            cout << "\n" << printCountries(aux_set) << endl;
        }
        
        // Lista de países disponibles para viajar (asia)
        else if (option == 2) {
            cout << "\nPaíses disponibles para viajes en Asia (en orden";
            cout << "alfabético):" << endl;
            
            aux_set = asia.getCountries();
            cout << "\n" << printCountries(aux_set) << endl;
        }
        
        // Muestra el grafo de Europa
        else if (option == 3) {
            cout << "\nMostrando las conexiones de los países dependiendo de su ";
            cout << "ubicación geográfica..." << endl;
            cout << europe.printAdjList() << endl;
        }
        
        // Muestra el grafo de Asia
        else if (option == 4) {
            cout << "\nMostrando las conexiones de los países dependiendo de su ";
            cout << "ubicación geográfica..." << endl;
            cout << asia.printAdjList() << endl;
        }
        
        // Busca la ruta más corta de un país a otro de un continente específico
        else if (option == 5) {
            
            // Solo imorime el "path" -> opción 1 de ruta
            if (getTripInfo(continente, pos_inicial, pos_final)) {
                if (continente == "europe") {
                    cout << "\n" << europe.DFS(pos_inicial, pos_final, 1);
                    cout << endl;
                } else {
                    cout << "\n" << asia.DFS(pos_inicial, pos_final, 1);
                    cout << endl;
                }
            } else {
                cout << "\nIntente de nuevo..." << endl;
            }
            
        }
        
        // Busca ruta con mayor cantidad de países posibles a visitar en un viaje
        // siguiendo la ruta óptima
        else if (option == 6) {
            
            // Solo imorime "visited" -> opción 2 de ruta
            if (getTripInfo(continente, pos_inicial, pos_final)) {
                if (continente == "europe") {
                    cout << "\n" << europe.DFS(pos_inicial, pos_final, 2);
                    cout << endl;
                } else {
                    cout << "\n" << asia.DFS(pos_inicial, pos_final, 2);
                    cout << endl;
                }
            } else {
                cout << "\nIntente de nuevo..." << endl;
            }
        }
        
        // Busca ambos tipos de rutas (los dos anteriores
        else if (option == 7) {
            
            // Imprime "path" y "visited" -> opción 3 de ruta
            if (getTripInfo(continente, pos_inicial, pos_final)) {
                if (continente == "europe") {
                    cout << "\n" << europe.DFS(pos_inicial, pos_final, 3);
                    cout << endl;
                } else {
                    cout << "\n" << asia.DFS(pos_inicial, pos_final, 3);
                    cout << endl;
                }
            } else {
                cout << "\nIntente de nuevo..." << endl;
            }
        }
        
        // Sale del "while", cierra los archivos ".txt" y termina el programa
        else if (option == 8) {
            cout << "\nHa decidido salir.\n¡Hasta pronto!\n" << endl;
            europe_file.close();
            asia_file.close();
        }
        
        // Error -> opción no válida
        else {
            cout << "\nOpción no válida. Intente de nuevo.\n" << endl;
        }
    }
    
    return 0;
}

/*
 * @param
 * @return
 *
 * Muestra el menú
 *
 */
void showMenu() {
    cout<< "\n- - - - - - - - - - - - - menú - - - - - - - - - - - - - - -"<<endl;
    cout<<"1) Muestra la lista de países disponibles para viajes en Europa"<<endl;
    cout<<"2) Muestra la lista de países disponibles para viajes en Asia"<<endl;
    cout<<"3) Muestra grafo de Europa"<<endl;
    cout<<"4) Muestra grafo de Asia"<<endl;
    cout<<"5) Busca la ruta más corta de viaje entre dos puntos"<<endl;
    cout<<"6) Busca la ruta con mayor cantidad de países posibles a visitar (que";
    cout<<" estén conectados por frontera) en un viaje entre dos puntos,";
    cout<<" siguiendo la ruta óptima para éste."<<endl;
    cout<<"7) Muestra ambas opciones anteriores para un viaje"<<endl;
    cout<<"8) Salir"<<endl;
    cout<< "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
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

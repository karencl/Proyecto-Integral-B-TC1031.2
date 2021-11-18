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
#include <unordered_map>
#include <algorithm>
#include "Graph.h"

using namespace std;

void showMenu();
void createGraph(ifstream&, unordered_map<string,int>&, Graph&);

int main() {
    
    // Se abren los archivos
    ifstream europe_file("places_europe.txt");
    ifstream asia_file("places_asia.txt");
    
    if (!europe_file.is_open() || !asia_file.is_open()) {
        cout << "Hubo algún error al abrir los archivos." << endl;
        return 1;
    }
    
    // Se crea un mapa y un objeto "Graph" para Europa
    unordered_map<string,int> europe_map;
    Graph europe(20);
    createGraph(europe_file, europe_map, europe);
    
    // Se crea un mapa y un objeto "Graph" para Asia
    unordered_map<string,int> asia_map;
    Graph asia(14);
    createGraph(asia_file, asia_map, asia);
    
    // Menú
    int option = 1;
    while (option != 4) {
        showMenu();
        cout << "\nIngrese una opción: ";
        cin >> option;
        
        // Muestra el grafo de Europa
        if (option == 1) {
            cout << "\nMostrando las conexiones de los países dependiendo de su ";
            cout << "ubicación geográfica..." << endl;
            cout << europe.printAdjList(europe_map) << endl;
        }
        
        // Muestra el grafo de Asia
        else if (option == 2) {
            cout << "\nMostrando las conexiones de los países dependiendo de su ";
            cout << "ubicación geográfica..." << endl;
            cout << asia.printAdjList(asia_map) << endl;
        }
        
        // Busca la ruta más corta de un país a otro de un continente específico
        else if (option == 3) {
            string continente, pos_inicial, pos_final;
            cout<<"\nContinente donde quiere realizar la búsqueda (en inglés): ";
            cin >> continente;
            cout << "\nIngrese el país de inicio (en inglés): ";
            cin >> pos_inicial;
            cout << "Ingrese el país de destino (en inglés): ";
            cin >> pos_final;
            
            transform(continente.begin(), continente.end(),
                      continente.begin(), ::tolower);
            transform(pos_inicial.begin(), pos_inicial.end(),
                      pos_inicial.begin(), ::tolower);
            transform(pos_final.begin(), pos_final.end(),
                      pos_final.begin(), ::tolower);
            
            int c1, c2;
            if (continente == "europe") {
                c1 = europe_map[pos_inicial];
                c2 = europe_map[pos_final];
                if (c1 != c2)
                    cout << "\n" << europe.DFS(europe_map, c1, c2) << endl;
                else
                    cout<<"\nHubo un problema con los datos ingresados."<<endl;
                cout << endl;
            } else if (continente == "asia") {
                c1 = asia_map[pos_inicial];
                c2 = asia_map[pos_final];
                if (c1 != c2)
                    cout << "\n" << asia.DFS(asia_map, c1, c2) << endl;
                else
                    cout<<"\nHubo un problema con los datos ingresados."<<endl;
                cout << endl;
            } else {
                cout << "\nHubo un error al realizar la búsqueda.\n" << endl;
            }
            
        }
        
        // Sale del "while", cierra los archivos ".txt" y termina el programa
        else if (option == 4) {
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
    cout << "1) Muestra grafo de Europa" << endl;
    cout << "2) Muestra grafo de Asia" << endl;
    cout << "3) Busca la ruta más corta de viaje" << endl;
    cout << "4) Salir" << endl;
}

/*
 * @param ifstream&, unordered_map<string,int>&, Graph&
 * @return
 *
 * Se lee el archivo para llenar el mapa con key-values de los países y un id que
 * se crea para cada uno.
 * Se manda a llamar a la función "addEdgeAdjList()" para ir creando la lista de
 * adyacencia (el grafo).
 *
 */
void createGraph(ifstream& file, unordered_map<string,int> &map, Graph &g) {
    string country1, country2;
    int i = 0, k1, k2;
    
    while (!file.eof()) {
        getline(file, country1, ',');
        getline(file, country2, '\n');
        if (country1.length() == 0 || country2.length() == 0)
            break;
        
        if (map.find(country1) == map.end()){
            map.insert(make_pair(country1, i));
            k1 = i;
            i++;
        } else {
            k1 = map[country1];
        }
        
        if (map.find(country2) == map.end()){
            map.insert(make_pair(country2, i));
            k2 = i;
            i++;
        } else {
            k2 = map[country2];
        }
        
        g.addEdgeAdjList(k1, k2);
    }
}

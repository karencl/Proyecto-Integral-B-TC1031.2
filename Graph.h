/*
 * TravelPlan
 * Karen Cebreros López
 * A01704254
 * 17/11/2021
 *
 * Graph.h
 * TravelPlan
 * Created by Karen CL on 17/11/21.
 * Copyright © 2021 KarenCbrs. All rights reserved.
 */

/*
 * La clase Graph contiene los atributos del grafo (lista de adyacencia en este
 * caso) y los métodos que ayudan a ordenar, buscar, agregar, etc.
 * Como también trabaja con un "unordered_map", tiene un método privado que se
 * encarga de encontrar el nombre de un país (key) a partir de un id (value).
 * (Se utiliza el método de DFS en este caso).
 */

#ifndef Graph_h
#define Graph_h

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

// Clase Graph
class Graph {
    private:
        // Atributos privados
        int edgesList;
        int nodes;
        vector<int> *adjList;
    
        // Métodos privados
        string findKeyByValue(unordered_map<string,int>&, int);
    public:
        // Constructores
        Graph(int);
    
        // Métodos públicos para graph list
        void addEdgeAdjList(int, int);
        string printAdjList(unordered_map<string,int>&);
        void sortAdjList();
        
        string DFS(unordered_map<string,int>&, int, int);
        void dfsHelper(unordered_map<string,int>&, int, int, stack<int>&,
                       list<int>&, vector<vector<int>>&, stringstream&);
        void printPath(unordered_map<string,int>&, vector<vector<int>>&, int,
                       int, stringstream&);
        void printVisited(unordered_map<string,int>&, list<int>, stringstream&);
        bool contains(list<int>, int);
};

/*
 * @param int
 * @return
 *
 * Constructor para un objeto Graph
 *
 */
Graph::Graph(int _nodes) {
    nodes = _nodes;
    edgesList = 0;
    adjList = new vector<int>[nodes];
}

/*
 * @param int, int
 * @return
 *
 * Hace una conección entre los dos valores de los nodos que se le pasan (en la
 * lista).
 *
 */
void Graph::addEdgeAdjList(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    edgesList++;
}

/*
 * @param
 * @return string
 *
 * Imprime el grafo (la lista)
 *
 */
string Graph::printAdjList(unordered_map<string,int> &map){
    sortAdjList();
    stringstream aux;
    
    for (int i = 0; i < nodes; i++){
        aux << "* " << findKeyByValue(map, i) << ":\n\t";
        for (int j = 0; j < adjList[i].size(); j++) {
                aux << " -> " << findKeyByValue(map, adjList[i][j]);
        }
        aux << "\n";
    }
    
    return aux.str();
}

/*
 * @param
 * @return
 *
 * Ordena el grafo (la lista)
 *
 */
void Graph::sortAdjList() {
    for (int i = 0; i < nodes; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }
}

/*
 * @param int, int
 * @return string
 *
 * Inicializa las variables para realizar el DFS a partir de un nodo inicial y el
 * nodo meta (al que se quiere llegar).
 * Regresa un string con el path y los nodos visitados, desde el nodo_inicial
 * hasta el nodo_meta.
 *
 */
string Graph::DFS(unordered_map<string,int> &map, int nodo_inicial,
                  int nodo_meta) {
    stringstream aux;
    
    stack<int> my_stack;
    list<int> visited;
    vector<vector<int>> paths(nodes, vector<int>(1, -1));
    my_stack.push(nodo_inicial);
    
    dfsHelper(map, nodo_inicial, nodo_meta, my_stack, visited, paths, aux);
    printPath(map, paths, nodo_inicial, nodo_meta, aux);
    
    return aux.str();
}

/*
 * @param int, int, stack<int>&, list<int>&, vector<vector<int>>&, stringstream&
 * @return
 *
 * Esta es una función recursiva del algoritmo "dfs", que ace el recorrido por el
 * grafo buscando el nodo_meta.
 * Se van gardando los paths y los nodos visitados en otras estructuras, con el
 * fin de imprimirlos posteriormente.
 *
 */
void Graph::dfsHelper(unordered_map<string,int> &map, int current_node,
                      int nodo_meta, stack<int> &my_stack, list<int> &visited,
                      vector<vector<int>> &paths, stringstream &aux) {
    
    if (current_node == nodo_meta) {
        printVisited(map, visited, aux);
    } else if (my_stack.empty()) {
        aux << "";
    } else {
        current_node = my_stack.top();
        my_stack.pop();
        visited.push_back(current_node);
        for (int  i = 0; i < adjList[current_node].size(); i++) {
            if (!contains(visited, adjList[current_node][i])) {
                my_stack.push(adjList[current_node][i]);
                paths[adjList[current_node][i]][0] = current_node;
            }
        }
        dfsHelper(map, current_node, nodo_meta, my_stack, visited, paths, aux);
    }
}

/*
 * @param lis<int>, stringstream
 * @return
 *
 * Imprime los nodos que fueron visitados (guardados en una lista), para obtener
 * el camino del nodo_inicial al nodo_meta.
 *
 */
void Graph::printVisited(unordered_map<string,int> &map, list<int> visited,
                         stringstream &aux) {
    aux << "Países analizados para encontrar el camino:\n\t";
    while (!visited.empty()){
        aux << " -> " << findKeyByValue(map, visited.front());
        visited.pop_front();
    }
}

/*
 * @param vector<vector<int>>&, int, int, stringstream
 * @return
 *
 * Imprime el path del recorrido desde el nodo_incial, hasta el nodo_meta.
 *
 */
void Graph::printPath(unordered_map<string,int> &map, vector<vector <int>> &path,
                      int nodo_inicial, int nodo_meta, stringstream &aux) {
    aux << "\nRuta más corta:\n\t";
    int node = path[nodo_meta][0];
    
    stack<int> reverse;
    reverse.push(nodo_meta);
    
    while (node != nodo_inicial) {
        reverse.push(node);
        node = path[node][0];
    }
    
    reverse.push(nodo_inicial);
    while (!reverse.empty()) {
        aux << " -> " << findKeyByValue(map, reverse.top());
        reverse.pop();
    }
}

/*
 * @param list<int>, int
 * @return bool
 *
 * Checa si un nodo se encuentra en la lista que se pasa.
 *
 */
bool Graph::contains(list<int> lst, int node) {
    list<int>::iterator it;
    it = find(lst.begin(), lst.end(), node);
    
    return (it != lst.end());
}

/*
 * @param unordered_map<string,int>&, int
 * @return string
 *
 * Busca el "key" de un "value" del mapa y lo devuelve al método "printAdjList()"
 * para imprimirlo.
 *
 */
string Graph::findKeyByValue(unordered_map<string,int> &map, int val) {
    for (auto it = map.begin(); it != map.end(); ++it) {
        if (it->second == val)
            return it->first;
    }
    return ""; // Para que no haya error
}

#endif /* Graph_h */

/*
Uva 10496 : Collecting Beepers (ACEPTADO)
Codigo Propio
uva username: diturra2016
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef pair<int,int> Posicion;

//distancia manhattan entre dos posiciones
int manhathan_distance(Posicion p1 , Posicion p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main(){
    int numCasos,numBeepers;
    cin >> numCasos;

    while(numCasos--){
        Posicion espacio , partida;
        cin >> espacio.first >> espacio.second; //no es usado en la solucion final
        cin >> partida.first >> partida.second;
        cin >> numBeepers;
        vector<Posicion> beepers; //vector de posiciones de los beepers
        beepers.push_back(partida); //agregar el punto de partida
        int x,y;
        for(int i=0 ; i<numBeepers ; i++){ //leer las coordenadas de todos los beepers
            cin >> x >> y;
            beepers.push_back(make_pair(x,y));
        }
        beepers.push_back(partida); //se ingresa nuevamente como punto final

        //probando con next-permutation
        int minPath = INT_MAX;
        int sum = 0;
        do {
            /*Para cada permutacion vemos que el punto de partida sea igual al de de llegada,solo considerar esos casos*/
            if(beepers[0].first == partida.first && beepers[0].second == partida.second &&
              beepers[beepers.size()-1].first == partida.first && beepers[beepers.size()-1].second == partida.second){

              for(int i=0 ; i<beepers.size()-1 ; i++){
                  sum += manhathan_distance(beepers[i],beepers[i+1]);
              }
              minPath = min(minPath,sum);
              sum = 0;
            }
        } while(next_permutation(beepers.begin() , beepers.end()));

        cout << "The shortest path has length " << minPath << endl;
    }
    return 0;
}

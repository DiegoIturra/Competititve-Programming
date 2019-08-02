//Uva 11507 - Bender B. Rodríguez (ACEPTADO)
#include <iostream>
using namespace std;

int main(){
  int doblajes;
  while(cin>>doblajes){ //leemos cada entero , indicando la cantidad de doblajes
    if(doblajes > 0){
      doblajes = doblajes-1;
      string apuntando = "+x"; //al comienzo siempre apunta hacia el eje +x 
      //leemos todas las doblajes-1 iteraciones
      for(int i=0 ; i<doblajes ; i++){
        string ejeDoblaje;
        cin >> ejeDoblaje;
        //if el eje es No , no hacemos nada
        if(ejeDoblaje == "No") continue;
        //si el eje es +y y actualmente apuntamos a cierta direccion
        else if(ejeDoblaje == "+y"){
          if(apuntando == "+x") apuntando = "+y";
          else if(apuntando == "-x") apuntando = "-y";
          else if(apuntando == "+y") apuntando = "-x";
          else if(apuntando == "-y") apuntando = "+x";
          else if(apuntando == "+z") apuntando = "+z";
          else if(apuntando == "-z") apuntando = "-z";
        }
        //si el eje es -y
        else if(ejeDoblaje == "-y"){
          if(apuntando == "+x") apuntando = "-y";
          else if(apuntando == "-x") apuntando = "+y";
          else if(apuntando == "+y") apuntando = "+x";
          else if(apuntando == "-y") apuntando = "-x";
          else if(apuntando == "+z") apuntando = "+z";
          else if(apuntando == "-z") apuntando = "-z";
        }
        
        //si el eje es +z
        else if(ejeDoblaje == "+z"){
          if(apuntando == "+x") apuntando = "+z";
          else if(apuntando == "-x") apuntando = "-z";
          else if(apuntando == "+y") apuntando = "+y";
          else if(apuntando == "-y") apuntando = "-y";
          else if(apuntando == "+z") apuntando = "-x";
          else if(apuntando == "-z") apuntando = "+x";
        }
        //si el eje es -z
        else if(ejeDoblaje == "-z"){
          if(apuntando == "+x") apuntando = "-z";
          else if(apuntando == "-x") apuntando = "+z";
          else if(apuntando == "+y") apuntando = "+y";
          else if(apuntando == "-y") apuntando = "-y";
          else if(apuntando == "+z") apuntando = "+x";
          else if(apuntando == "-z") apuntando = "-x";
        }
      }
      cout << apuntando << endl;
    }
  }
  return 0;
}

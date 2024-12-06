#include "funciones.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

int main() {
  //Bienvenida 
  cout<<"\x1B[92m"<<setw(20)<<"\n \t BIENVENIDOS A SETTER STRATEGY!!!!.Una adaptacion del famoso tic-tac-toe. Que se diviertan! "<<"\033[37m"<<endl;

  //cout<<"\n Acaban de llegar al mundo de los espiritus por acidente! Ahora les toca trabajar en la casa de baño para poder acumular tokens y volver a su realidad. Yubaba les tiene un reto. El que pierda en el juego le toca prepar el baño para los espiritus por una semana y el que gane le tocan 100 tokens más su nombre. "<<endl; no creo q le haga la historia pero just in case 

  //funcion principal donde esta todo 
  menuSwitchChoice();

  cout<<"\n F I N !";
  
  return 0;
}

#include<iomanip>
#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<string>
#include<limits>
#include"funciones.h"

using namespace std;

//declarar el struct
struct Scoreboard{
  int puntosX;           //total de puntos del jugador X
  int puntosO;          //total de puntos del jugador O 
  string player1Name;   //Nombre del primer jugador
  string player2Name;   //Nombre del segundo jugador
};

//crear un objeto para el struct 
Scoreboard score;

                                 //FUNCIONES 

//input: arr 3x3 
//output: void display 
void tablero(char tabla[3][3]){
  cout<<setw(20)<<" \t \n                    - - - - - - - - - - - - - \n"<<"\033[37m"; // no me estaba saliendo como queria sorry :( last resort ill fixt it tho! 
 
  for (int i=0; i<3; i++){
    //linea del medio 
    cout<<"\x1B[36m"<<setw(20)<<"\t| "<<"\033[37m"; 

    for (int k=0; k<3; k++){
      cout<< setw(3)<<tabla[i][k] << "\x1B[36m"<<setw(2)<<"\t| "<<"\033[37m";
    }
    cout<<setw(20)<<" \t \n                    - - - - - - - - - - - - -\n"<<"\033[37m";
  }
}

//INPUT: NADA 
//OUTPUT: display the choices of the menu game 
void menu (){
  int space=3;
  cout << "\033[2J\033[1;1H";

  //cout << "\x1B[92m" <<setw(7)<<"\n ｡,｡･:*:･ﾟ☆｡･:*:･ﾟ★,｡･:*:･ﾟ☆ M E N U ｡･:*:･ﾟ★・゜・。..・。.・゜✭"<< "\033[37m" <<endl;

  cout<<"\nEscoja entre las siguintes opciones: "<<endl;

  cout<<setw(space)<<"\n \t (1) Instruciones. "<<endl;

  cout<<setw(space)<<"\n \t (2) Comenzar el juego! "<<endl;

  cout<<setw(space)<<"\n \t (3) Ver el tablero de puntos. "<<endl;

  cout<<setw(space)<<"\n \t (4) Salir del juego. EXIT! "<<endl;


  //cout<< "\x1B[92m"<<"\n .・。.・゜✭・.・✫・゜・。..・。.・゜✭・.・✫・゜・。..・。."<<"\033[37m"<<endl;
}

//IPUT: NADA FIX IT IT SOUDNS UGLY 
//OUTPUT: VOID 
void Instruciones(){

  int space=12; 

  //cout<<setw(space)<<"\n \t .・。.・゜✭・.・✫・゜・.Instruciones.・。.・゜✭・.・✫・゜・。. 。.・゜✭・.・.・。.・゜✭・.・✫・゜・.・。.・゜✭・.・✫・゜・"<<endl;

  cout<<"\n El juego consiste en que dos jugadores tomen turnos colocando sus fichas en un tablero de 3x3, cada uno representado por un 'X' o 'O'. Para lograr un punto el jugador debe conectar 3 fichas de manera diagonal, vertical, o horizontal. El perimero en lograr un punto gana! De no conectar ninguno será un empate. "<<endl;

  cout<<setw(5)<<" \n \t (1) Las celdas están identificadas por los número del 1 - 9."<<endl;
  
  cout<<setw(5)<<" \n \t (2) Primero va el jugador 'X' y luego el jugador 'O'. "<< endl;
  
  cout<<setw(5)<<" \n \t (3) Al comenzar el juego el jugador ingresará el número de la celda de dónde desee colocar su ficha."<<endl;
  
  cout<<setw(5)<<" \n \t (4) Una vez el tablero este lleno completamente, el juego indicará quíen ganó. De no haber un ganador indicará el empate."<<endl;
  
  cout<<setw(5)<<" \n \t (5) Al terminar el juego tendrán la opción de volver al menu principal para continuar jugando o salir del juego por completo."<<endl;
  
  cout<<setw(5)<<" \n \t E X Í T O !!"<<endl;

 // cout<<setw(space)<<"\n.・。.・゜✭・.・✫・゜・。..・。.・゜✭・.・✫・゜・。..・。.・゜✭・.・✫・゜・。.。.・゜✭・.・✫・゜・.・。.・゜✭・.・✫・゜・"<<endl;

}



//INPUT: void
//OUTPUT: nombre del 1er jugador 
string player1Name (){

  cout<<"\n Ingrese el nombre del primer jugador: "; 
  cin>>score.player1Name;

  return score.player1Name;
}

//INPUT: void
//OUTPUT: nombre del 2do jugador 
//no se si hacer punteros para los nombres 
string player2Name(){
  

  cout<<"\n Ingrese el nombre del segundo jugador: ";
  cin>>score.player2Name;

  return score.player2Name;
}



//Verificar si un jugador conecto 3
//INPUT: arr char 3x3, char jugador
//OUTPUT: si hizo un punto o no 
bool verifyjugada( char tabla [3][3], char jugador){

  //filas
  for ( int i =0; i<=3; i++){
     if (tabla[i][0] == jugador &&  tabla [i][1] == jugador && tabla[i][2] == jugador)
        return true;

    //columnas
  for(int k=0; k< 3; k++ ){ 
    if (tabla [0][k]== jugador && tabla[1][k]==jugador && tabla[2][k]== jugador)
      return true; 
    }  
  }

  //diagonal 
  if (tabla [0][2]==jugador && tabla[1][1]== jugador && tabla [2][0]==jugador)
    return true;

  if (tabla [0][0]==jugador && tabla[2][2]==jugador && tabla [1][1]==jugador)
    return true;


 return false;
}


//check if the game is a tie
//INPUT: arr 3x3, string player
//Output: si fue un empate o no 
bool checkTie(char tabla [3][3]){
  for (int i = 0; i < 3; i++){
    for (int j= 0; j< 3 ; j++){
      //cout<<" \n check la celda (" <<i << ","<< j<<")"<< tabla[i][j]<<endl; debug 
      if (tabla [i][j] !='X'  && tabla [i][j] != 'O')  {
        return false;
      }
    }
  }
  return true; 
}

//Tablero de puntos
//INPUT: total of points of players, players name's
//OUTPUT: void 
void scoreboard(int totalX,int total0, string player1Name, string player2Name){
  int S=20;
  cout<<setw(30)<<"\n \tJugador"<<setw(30)<<"Puntos"<<endl;

  cout<<setw(S)<<"\n_____________________________________________________________"<<endl;

  cout<<setw(S)<<"\n \t Juagdor X "<<score.player1Name<<right<<setw(20)<<score.puntosX<<endl;

  cout<<setw(S)<<"\n \t Jugador O "<<score.player2Name<<right<<setw(20)<<score.puntosO<<endl;

  cout<<setw(S)<<"\n_____________________________________________________________"<<endl;

}


//verificar si el usuario quiere seguir jugando
//INPUT: char 
//OUTPUT: stay in the main menu or not 
bool leaveCase (char stay){
  while (stay!= 'Y'&& stay!='y'&& stay!='N'&&stay!='n'){
    cout<<"\nIngreso un dato incorrecto. Trate de nuevo: ";
    cin>>stay;
  }
  //se queda en el lopp del menu 
  if (stay == 'Y' || stay== 'y'){
    return true;
  } 

  //termina el porgama 
  else if (stay=='N'|| stay=='n'){
    return false;
  }
  

  return true;
}


//INPUT: menu choice int 
//OUTPUT: GAME CHOICES LA OPCION DEL CASO 
void menuSwitchChoice(){
  int choice =0; 
  bool stay = true; 
  char salir;

  //pedrile los nombres a los jugadores 
  score.player1Name=player1Name();
  score.player2Name = player2Name();
  
  //loop del juego
   do {
    
    //desplegar el menu 
    menu();

    //pedir la opcion para els switch
    cout<<"\n Ingrese el número de la opción que desee: ";
    cin>>choice;

    switch(choice){

      //Ver instruciones
      case 1: {
        //clear console
        cout << "\033[2J\033[1;1H";
        cout<<"\n Eligió ver las instruciones."<<endl;
        Instruciones();

        //pregunar si quedarse o no ? 
        cout<<"\n Para salir ingrese 'Y' para volver al menu principal o ingrese 'N' salir del programa: ";
        cin>>salir; 

        //decidir si salir del programa o no
        stay=leaveCase(salir);

        break;     
        }

      //comenzar a jugar
      case 2 : 
      {
        //clear concole
        cout << "\033[2J\033[1;1H";

        //funcion del juego perse
        playJuego();
        
        //pregunar si quedarse o no ? 
        cout<<"\n Para salir ingrese 'Y' para volver al menu principal o ingrese 'N' salir del programa: ";
        cin>>salir; //esto lo hago aqui o en main o dentro del switch? 

        //decidir si salir del programa o no
        stay=leaveCase(salir);
        break;

      }
      
      //Ver Scoreboard
      case 3: {
        //clear console
        cout <<"\033[2J\033[1;1H";

        //funcion del scoreboard 
        cout<<"\n Eligio ver el tablero de puntos."<<endl;
        scoreboard( score.puntosX, score.puntosO, score.player1Name, score.player2Name); 

        //pregunar si quedarse o no ? 
        cout<<"\n Para salir ingrese 'Y' para volver al menu principal o ingrese 'N' salir del programa: ";
        cin>>salir; //no lo queria preguntar en casa caso y hacerlo en una funcion pero era para ver si funcionaba 

        //decidir si salir del programa o no
        stay=leaveCase(salir);
        break;
      }
      
      //Salir del programa 
      case 4: {
        //clear console
        cout <<"\033[2J\033[1;1H";
        cout<<"\n Eligió salir! Adíos!"<<endl;
        exit(0);
        break;
      }

      default: {
        //clear console
        cout<<"\n E R R O R Ingreso una opción incorrecta."<<endl;
        //desplegar error
        //cout << "\033[2J\033[1;1H";
        break;
        
      }
    }
     
  }
  while(stay);
}


//funcion del juego como tal 
//INPUT: nada 
//OUTPUT: Void
void playJuego (){

  cout<<"\n \t Comenzará el juego."<<endl;

  //asignar los simbolos y inizializar ganador 
  char jugador= 'X',ganador= ' ';

  //declarar fila,columna y la opcion para ficha 
  int row, col, choice;

  //var control del ciclo del juego 
  bool terminajuego = false;

  //inicializar el tablero 
  char tabla [3][3] = { { '1', '2', '3',},
                        { '4', '5', '6',},
                        { '7', '8', '9',},
                      };

  //ciclo del juego
  do
  {
    cout<<"\x1B[92m" <<"\n｡,｡･:*:･ﾟ☆｡･:*:･ﾟ★,｡･:*:･ﾟ☆｡,｡･:*:･ﾟ☆｡･:*:･ﾟ★,｡･:*:･ﾟ☆･:*:･ﾟ☆｡･:*:･ﾟ★,｡･:*:･ﾟ☆"<<"\033[37m"<<endl;
    //desplegar el tablero 
    tablero (tabla);

    cout<<"\x1B[92m" <<"\n｡,｡･:*:･ﾟ☆｡･:*:･ﾟ★,｡･:*:･ﾟ☆｡,｡･:*:･ﾟ☆｡･:*:･ﾟ★,｡･:*:･ﾟ☆･:*:･ﾟ☆｡･:*:･ﾟ★,｡･:*:･ﾟ☆"<<"\033[37m"<<endl;
    
    //pedirle la celda al usuario
    cout<<"\n \t Jugador "<<jugador<<" ingrese el numero de la celda de dónde desee colocar su ficha: "; 
    cin>>choice; 
    

    if (cin.fail())
    {
      cout<<"\n E R R O R no ingreso un numero."<<endl;

      //quitarle el error state 
      cin.clear();

      //descarata el caracter q no es 
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
     
    }

    //clear console
    cout<< "\033[2J\033[1;1H";
    
    //sacar la fila y la columna 
    row =(choice -1) / 3;
    col = (choice -1) % 3;

    
    //verificar que la celda este vacia
    if (tabla[row][col] != 'X' && tabla[row][col] !='O')
    {
  
      //colocar la ficha en la celda
      tabla[row][col] = jugador;
      
      //verificar la jugada 
      if (verifyjugada(tabla,jugador))
      {
        //desplegar el tablero
        tablero(tabla);
        //desplegar si gano 
        cout<<"\n \t Jugador " <<jugador<< " gana! "<< endl;

        //asignarle jugador a ganador para los puntos 
        ganador=jugador;

        //salir del loop del juego 
        terminajuego=true;
      }

      //verificar si el juego fue un empate 
      else if(checkTie(tabla))
      {
        //desplegar el tablero
        tablero(tabla);

        //si es un empate
        cout<<"\n \t El juego es un empate"<<endl;

        //salir del loop juego 
        terminajuego= true;
      }
        
      //cambiar de jugador 
      else{
        jugador = (jugador == 'X') ? 'O' : 'X';
      }
      
    }
    else
    {
       cout << " E R R O R Movimiento invalido. Intente de nuevo: " << endl;
    }
  
    
    //verificar de quien son los puntos 
    if (ganador == 'X'){
      score.puntosX ++;
    }
    
    if(ganador== 'O') {
    score.puntosO ++;
    }
    
    //cout << "\033[2J\033[1;1H";
  }
  while (!terminajuego);

  
 
}


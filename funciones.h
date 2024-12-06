#include<iostream>
#include<cstdlib>
#include<string>
#ifndef FUNCIONES_H
#define FUNCIONES_H

using namespace std;

//tablero plain 
void tablero ( char tabla [3][3]);

//ver el menu con las opciones 
void menu();

//instruciones
void Instruciones();

//swicth para la opcion 

void menuSwitchChoice();//int, int, string, string);

//while loop del swicth? 
bool leaveCase(char);
//inputvalmenu 
int inputValidationMenu(int);

//players name 
string player1Name();

//players name 
string player2Name();

//ver la jugada 
bool verifyjugada( char tabla [3][3], char jugador);

//verify si empate
bool checkTie(char tabla [3][3]);

//scoreboad 
void scoreboard( int, int, string , string);

//actual game
void playJuego();
#endif
//Aturo: Alejandro Correa Rocriguez; ALU 3495
//Implementacion de los metodos de la clase monomio.h

#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include "monomio.h"

using namespace std;

//Constructor por defecto
monomio::monomio () {
   coeficiente = 0;
   exponente = 0;
}


//Constructor
monomio::monomio(double coef, int exp) {
   coeficiente = coef;
   exponente = exp;
}

// Constructor de copia
monomio::monomio(const monomio& m) {
   coeficiente = m.coeficiente;
   exponente = m.exponente;
}

// Función que devuelve el valor del coeficiente
double monomio::getCoeficiente() const {

   return coeficiente;

}

// Función que devuelve el valor del exponente
int monomio::getExponente() const {

   return exponente;

}

//Funcion que evalua el valor del monomio en un punto dado
double monomio::evaluar(double X) {

   return (pow(X, exponente)) * coeficiente;

}

//Funcion que convierte un monomio en string
string monomio::toString() const {
   string sCoeficiente;
   string sIncognita;
   string sExponente;

   //Si el coeficiente es cero
   if (coeficiente == 0) {
      sCoeficiente = "0";
      sIncognita = "";
      sExponente = "";
   }
   //Coeficiente distinto de cero
   else {
      //Transforma el coeficiente en un string
         stringstream aux;
         aux<<coeficiente;
         aux>>sCoeficiente;
      //Valor de la incognita
      if (exponente != 0)
         sIncognita = "X";
      else
         sIncognita = "";

      //Valor del exponente
      if ((exponente == 0) || (exponente == 1))
         sExponente = "";
      else {
         //Transforma el exponente en un string
         stringstream aux2;
         aux2<<exponente;
         aux2>>sExponente;
      }
   }

   return sCoeficiente + sIncognita + sExponente;

}


//Operador de asignacion
void monomio::operator=(monomio m) {
   coeficiente = m.coeficiente;
   exponente = m.exponente;
}


//Operador de igualdad
bool monomio::operator==(const monomio &m) const {

     return ((m.coeficiente == coeficiente) && (m.exponente == exponente));

}

//Sobrecarga del flujo de salida
ostream &operator << (ostream &aux, const monomio &mon) {

     return aux << mon.toString();

}

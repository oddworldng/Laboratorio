 
//
// Autor del programa : Alejandro Correa Rodriguez
//
//
// Alu 3495
// Implementacio del fichero polinomio.C donde se encuentra
// el cuerpo de todos los metodos de la clase polinomio,
//************************************************************************
                
#include <iostream>
#include <math.h>
#include "polinomio.h"
#include "monomio.h"

using namespace std;

// constructor por defecto
polinomio::polinomio() {

   polinom = new monomio*[1];
   polinom[0] = new monomio(0,0);
   numTerminos = 1;
}

//Constructor
polinomio::polinomio(monomio **aux, int terminos) {
   int tamano = 0;

   for (int i = 0; i < terminos; i++) {
      if (aux[i]->getCoeficiente() != 0.0)
         tamano++;
   }

   polinom = new monomio*[tamano];
   numTerminos = 0;
   for (int i = 0; i < terminos; i++) {
      if (aux[i]->getCoeficiente() != 0.0) {
         polinom[numTerminos++] = new monomio(*aux[i]);
      }
   }
}

//Constructor
polinomio::polinomio(double *aux, int terminos) {
   int tamano = 0;

   for (int i = 0; i < terminos; i++) {
      if (aux[i] != 0.0)
         tamano++;
   }

   polinom = new monomio*[tamano];
   numTerminos = 0;
   for (int i = 0; i < terminos; i++) {
      if (aux[i] != 0.0) {
         polinom[numTerminos] = new monomio(aux[i], i);
         numTerminos++;
      }
   }
}

polinomio::polinomio(const polinomio &p){
 numTerminos = p.numTerminos;
 polinom = new monomio*[numTerminos];
 for (int i = 0; i < numTerminos; i++){
     polinom[i] = new monomio(p.polinom[i]->getCoeficiente(), p.polinom[i]->getExponente());
 }
}

// Destructor
polinomio::~polinomio() {

   for (int i = 0; i < numTerminos; i++)
      delete polinom[i];
   delete [] polinom;
}

//Funcion que evalua el polinomio en un punto
double polinomio::evaluar (double h){
   double temp = 0.0;

   for (int i = 0; i < numTerminos; i++)
      temp += polinom[i]->evaluar(h);

   return temp;

}

//Funcion para convertir el polinomio en un string
string polinomio::toString() const{
   string temp;

   for (int i = 0; i <= numTerminos - 1; i++) {
      string termino;

      //Solo muestra los terminos cuyo coef sea distinto de cero
      termino = polinom[numTerminos - 1 - i]->toString();
      if (termino != "0") {
         if (termino[0] == '-')
            temp += termino + " "; //Si el termino es negativo, no pongo signo, ya que aparecera por si solo
         else {
            if (temp == "")
               temp += termino + " "; //Si es el primer elemento no le pongo signo
            else
               temp += "+ " + termino + " ";
         }
      }
   }

   return temp;

}

//Operador de igualdad
bool polinomio::operator==(const polinomio &p) const {
   bool igualdad = true;

   for (int i = 0; ((i <= numTerminos - 1) && (igualdad)); i++) {
      igualdad &= (*polinom[i] == (*p.polinom[i]));
   }

   return igualdad;

}

// Operador de asignación
polinomio& polinomio::operator=(const polinomio &p) {

   numTerminos = p.numTerminos;
   for (int i = 0; i < numTerminos; i++)
      polinom[i] = new monomio(*p.polinom[i]);

   return *this;

}

//Operador de igualdad
bool polinomio::operator<(const polinomio &p) const {
   bool iguales = true;
   bool esMenor = false;
   int indMaxExponente = 1000;
   int indMaxExponente2 = 1000;

   while (iguales && indMaxExponente != -1 && indMaxExponente2 != -1) {
      indMaxExponente = mayorTermino(indMaxExponente);
      indMaxExponente2 = p.mayorTermino(indMaxExponente2);
      if (indMaxExponente != -1 && indMaxExponente2 != -1) {
         if (polinom[indMaxExponente]->getExponente() > p.polinom[indMaxExponente2]->getExponente()) {
            iguales = false;
            esMenor = false;
         }
         if (polinom[indMaxExponente]->getExponente() < p.polinom[indMaxExponente2]->getExponente()) {
            iguales = false;
            esMenor = true;
         }
         if (polinom[indMaxExponente]->getCoeficiente() > p.polinom[indMaxExponente2]->getCoeficiente()) {
            iguales = false;
            esMenor = false;
         }
         if (polinom[indMaxExponente]->getCoeficiente() < p.polinom[indMaxExponente2]->getCoeficiente()) {
            iguales = false;
            esMenor = true;
         }
      }
      else {
         iguales = false;
      }
   }

   if (indMaxExponente == -1)
      esMenor = true;
   else if (indMaxExponente2 == -1)
      esMenor = false;

   return esMenor;

}

// Devuelve el término del polinomio cuyo exponente sea menor que uno dado
int polinomio::mayorTermino(int exponente) const {
   int indice = -1;
   int maxExponente = -1;

   for (int i = 0; i < numTerminos; i++)
      if (polinom[i]->getExponente() < exponente && maxExponente < polinom[i]->getExponente())
         indice = i;

   return indice;

}

// Devuelve el menor exponente del polinomio
int polinomio::minimaDimension() const {
   int minDimension;

   if (numTerminos > 0) {
      minDimension = polinom[0]->getExponente();
      int i = 1;
      while (i < numTerminos) {
         if (minDimension > polinom[i]->getExponente())
            minDimension = polinom[i]->getExponente();
         i++;
      }
   }
   else
      minDimension = 0;

   return minDimension;

}

// Devuelve el mayor exponente del polinomio
int polinomio::maximaDimension() const {
   int maxDimension;

   if (numTerminos > 0) {
      maxDimension = polinom[0]->getExponente();
      int i = 1;
      while (i < numTerminos) {
         if (maxDimension < polinom[i]->getExponente())
            maxDimension = polinom[i]->getExponente();
         i++;
      }
   }
   else
      maxDimension = 0;

   return maxDimension;

}

// Operador de suma
polinomio& polinomio::operator+(const polinomio &p) {
   int minDimension, maxDimension;

   // Calcula las dimensiones que va a tener como máximo el resultado de la suma de polinomios
   minDimension = (minimaDimension() < p.minimaDimension()) ? minimaDimension() : p.minimaDimension();
   maxDimension = (maximaDimension() > p.maximaDimension()) ? maximaDimension() : p.maximaDimension();

   monomio **m = new monomio*[maxDimension - minDimension + 1];

   for (int i = minDimension; i <= maxDimension; i++) {
      double valor = 0.0;

      for (int j = 0; j < numTerminos; j++) {
         if (polinom[j]->getExponente() == i)
            valor += polinom[j]->getCoeficiente();
      }

      for (int k = 0; k < p.numTerminos; k++) {
         if (p.polinom[k]->getExponente() == i)
            valor += p.polinom[k]->getCoeficiente();
      }

      m[i - minDimension] = new monomio(valor, i);
   }

   return * new polinomio(m, maxDimension - minDimension + 1);

}

// Operador de resta
polinomio& polinomio::operator-(const polinomio &p) {
   int minDimension, maxDimension;

   // Calcula las dimensiones que va a tener como máximo el resultado de la suma de polinomios
   minDimension = (minimaDimension() < p.minimaDimension()) ? minimaDimension() : p.minimaDimension();
   maxDimension = (maximaDimension() > p.maximaDimension()) ? maximaDimension() : p.maximaDimension();

   monomio **m = new monomio*[maxDimension - minDimension + 1];

   for (int i = minDimension; i <= maxDimension; i++) {
      double valor = 0.0;

      for (int j = 0; j < numTerminos; j++) {
         if (polinom[j]->getExponente() == i)
            valor += polinom[j]->getCoeficiente();
      }

      for (int k = 0; k < p.numTerminos; k++) {
         if (p.polinom[k]->getExponente() == i)
            valor -= p.polinom[k]->getCoeficiente();
      }

      m[i - minDimension] = new monomio(valor, i);
   }

   return * new polinomio(m, maxDimension - minDimension + 1);

}

// Operador de multiplicación
polinomio& polinomio::operator*(const polinomio &p) {
   int minDimension, maxDimension;

   // Calcula las dimensiones máximas y mínimas de los dos polinomios implicados en la operación
   minDimension = minimaDimension() + p.minimaDimension();
   maxDimension = maximaDimension() + p.maximaDimension();

   double *resultado = new double[maxDimension - minDimension + 1];

   for (int i = 0; i < numTerminos; i++) {
      for (int j = 0; j < p.numTerminos; j++) {
         resultado[polinom[i]->getExponente() + p.polinom[j]->getExponente() - minDimension] += polinom[i]->getCoeficiente() * p.polinom[j]->getCoeficiente();
      }
   }

   monomio **m = new monomio*[maxDimension - minDimension + 1];
   for (int i = 0; i < maxDimension - minDimension + 1; i++)
      m[i] = new monomio(resultado[i], i + minDimension);

   return * new polinomio(m, maxDimension - minDimension + 1);

}

// Operador de insercion
ostream& operator<<(ostream &sout, const polinomio &c) {

   return sout << c.toString();

}


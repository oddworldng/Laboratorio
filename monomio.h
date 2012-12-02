//Autor: Alejandro Correa Rodriguez; ALU 3495
//Definicion de los metodos y atributos de la clase monomio

#ifndef MONOMIO_H
#define MONOMIO_H

#include <iostream>
#include <string.h>

using namespace std;

class monomio {

   private:
      double coeficiente;
      int exponente;

   public:
      monomio();
      monomio(const monomio& m);
      monomio(double coef, int exp);
      double getCoeficiente() const;
      int getExponente() const;
      double evaluar(double X);
      string toString() const;
      void operator=(monomio m);
      bool operator==(const monomio& m) const;

};

ostream &operator << (ostream &aux, const monomio &mon);

#endif


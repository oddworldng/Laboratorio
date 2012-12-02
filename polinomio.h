//
//
// Autor del programa : Alejandro Correa Rodriguez
//
// Alu 3495
// Implementacio del fichero de cabecera polinomio.h donde se
// especifican las cabeceras de los metodos de la clase polinomio,
// asi como sus miembros
//************************************************************************

#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <math.h>
#include <string>
#include "monomio.h"

using namespace std;

class polinomio {

   public:
      polinomio();
      polinomio(monomio **aux, int terminos);
      polinomio(double *aux, int terminos);
      polinomio(const polinomio &p);
      ~polinomio();
      double evaluar (double h);
      string toString() const;
      bool operator==(const polinomio &p) const;
      polinomio& operator=(const polinomio& p);
      polinomio& operator+(const polinomio& p);
      polinomio& operator-(const polinomio& p);
      polinomio& operator*(const polinomio& p);
      bool operator<(const polinomio &p) const;
      int minimaDimension() const;
      int maximaDimension() const;
      int numTerminos;

   private:
      monomio **polinom;
         int mayorTermino(int exponente) const;


};

ostream& operator<<(ostream &sout, const polinomio &c);


#endif

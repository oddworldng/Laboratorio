//Nombre : Alejandro Correa Rodriguez; ALU 3495
// Clase TestPolinomio.C donde se comprobara el correcto funcionamiento
// de la clase polinomio.C

#include <iostream>
#include <string>
#include "polinomio.h"
#include <set>

using namespace std;

set<polinomio>* generar (int veces){
   set<polinomio> conjunto;
   set<polinomio>::iterator it;
   for (int i=0; i<veces; i++){
      polinomio *p;
      if (i == 0){
        monomio **m;
        m = new monomio* [1];
        m[0] = new monomio(1,0);
        p = new polinomio(m, 1);

        cout<<"Polinomio p :"<< *p <<endl;
      }
      else if (i == 1){
        monomio **m;
        m = new monomio* [1];
        m[0] = new monomio (1,1);
        p = new polinomio(m,1);
        cout<<"Polinomio p :"<< *p <<endl;
      }
      else{   
         monomio **m;
         m = new monomio* [1];
         m[0] = new monomio(2,1);
         polinomio *pol = new polinomio(m,1);
         
         set<polinomio>::iterator it1 = conjunto.end();
         polinomio p1 = *(--it1);
         set<polinomio>::iterator it2 = --it1;
         polinomio p2 = *(--it2);
         p = new polinomio((*pol * p1) - p2);
        cout<<"Polinomio p :"<< *p <<endl;
      }
      
      it = conjunto.end();
      conjunto.insert(it, *p);
      cout<<"Tam: "<<conjunto.size()<<endl;
   }

   return new set<polinomio>(conjunto);
}


int main() {

    int pol;
    cout<<"Introduzca num de polinomios :"<<endl;
    cin>> pol;
    set<polinomio> *ret = generar(pol);
     polinomio *suma = new polinomio();
    for (set<polinomio>::iterator it = ret->begin(); it != ret->end(); it++){
           polinomio tmp = *it;
           *suma = (*suma) + tmp;
    }
    cout<<"Suma :"<< *suma<<endl;
/*   int grado;

   cout << "Introduzca grado maximo del polinomio P(9 como max): ";
   cin >> grado;
   double *aux = new double[grado + 1];
   int numTerminos = 0;
   for (int i = 0; i <= grado; i++) {
      cout<<"Introduzca elemento de grado "<< i << " :";
      cin>>aux[numTerminos];
      numTerminos++;
   }
   cout<<"Polinomio P :"<<endl;
   polinomio P(aux, numTerminos);
   cout <<""<<endl;
   cout<<P<<endl;

   cout << "Introduzca grado maximo del polinomio Q(9 como max): ";
   cin >> grado;
   double *aux2 = new double[grado + 1];
   numTerminos = 0;
   for (int i = 0; i <= grado; i++) {
      cout<<"Introduzca elemento de grado "<<i << " :";
      cin>> aux2[numTerminos];
      numTerminos++;
   }
   cout<<"Polinomio Q :"<<endl;
   polinomio Q(aux2, numTerminos);
   cout <<""<<endl;
   cout<<Q<<endl;

   cout<<"Introduzca punto donde evaluar ambos polinomios :"<<endl;
   double eval;
   cin>>eval;
   cout<<"Resultado del polinomio P :"<<endl;
   cout<<P.evaluar (eval)<<endl;
   cout<<"Resultado del polinomio Q :"<<endl;
   cout<<Q.evaluar (eval)<<endl;
   if (P == Q)
      cout<<"Los polinomios son iguales"<<endl;
   else
      cout<<"Los polinomios no son iguales"<<endl;

   polinomio R = P * Q;
   cout<<"Polinomio R:"<<endl;
   cout<<""<<endl;
   cout<<R<<endl;*/

   return 0;

}


#include "Nodo.h"   

template <class Tipo>
void Nodo<Tipo>::AsigInfo(Tipo in){
     info=in;
     };
     
template <class Tipo>
Tipo Nodo<Tipo>::ObtInfo(){
     return info;
     };
     
template <class Tipo>     
void Nodo<Tipo>::AsigIzq(Nodo<Tipo>* p){
     izq=p;
     };

template <class Tipo>     
Nodo<Tipo>* Nodo<Tipo>::ObtIzq(){
    return izq;
    };

template <class Tipo>    
void Nodo<Tipo>::AsigDer(Nodo<Tipo>* p){
     der=p;
     };

template <class Tipo>     
Nodo<Tipo>* Nodo<Tipo>::ObtDer(){
     return der; 
     };
     

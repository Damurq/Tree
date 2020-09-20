#ifndef ArbolBB_H
#define ArbolBB_H
#include "Arbol.h"

template <class Tipo>
class ArbolBB:public Arbol<Tipo>
{
typedef Nodo<Tipo>* Apuntador;      
public: 
   Nodo<Tipo>* Buscar(Nodo<Tipo>* p,Tipo valor);
   Nodo<Tipo>* BuscarRecursivo(Nodo<Tipo>* p, Tipo valor);
   bool Insertar(Tipo valor); //Hay que poner a p de salida para que se actualice el valor de p al comienzo
   bool InsertarRecursivo(Nodo<Tipo>* p, Tipo valor);
   bool Eliminar(Tipo &valor);
};
#include "ArbolBB.cpp"
#endif

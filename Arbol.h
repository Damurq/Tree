#ifndef ARBOLBINA
#define ARBOLBINA
//#include <stdlib>        // Para utilizar NULL
#include <iostream>
#include "Nodo.h"


/*Definicion de la Clase Arbol y sus Funciones Miembros                       */
template <class Tipo>
  class Arbol
  {
   typedef Nodo<Tipo>* Apuntador;
   private:
        Nodo<Tipo> *raiz;            /* Apuntador a Raiz del Arbol Binario  */       
   public:	
           
	Arbol(void);
	Arbol(Arbol<Tipo> &entrada);
	Nodo<Tipo>* ObtRaiz();
	void AsigRaiz(Nodo<Tipo> *p);
	void Liberar(Nodo<Tipo> *p);
	virtual ~Arbol(void);
	bool Vacio(void);
	bool Lleno(void);
	
	Nodo<Tipo> *CrearNodo(Tipo valor);
	bool InsIzquierdo(Nodo<Tipo> *P, Tipo valor);
	bool InsDerecho(Nodo<Tipo> *P, Tipo valor);
	Nodo<Tipo> *Combinar(Nodo<Tipo> *arbol1,Nodo<Tipo> *arbol2, Tipo valor);
	bool EliDerecho(Nodo<Tipo>*  p,Tipo &valor);
	bool EliIzquierdo(Nodo<Tipo>*  p,Tipo &valor);         
	bool Eliminar(Nodo<Tipo> *ap,Nodo<Tipo>* &p,Tipo &valor); 
	
	Nodo<Tipo> *CopiaArbol(Nodo<Tipo> *p);
	Arbol<Tipo> &operator = (Arbol<Tipo> &entrada);

	Nodo<Tipo> *ObtDer(Nodo<Tipo> *p);
	Nodo<Tipo> *ObtIzq(Nodo<Tipo> *p);
	Tipo ObtInfo(Nodo<Tipo> *p);
          		
  };

#include "Arbol.cpp"    // Inclusion Implementacion de Arbol Binario
#endif

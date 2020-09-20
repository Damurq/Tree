#include <stdlib.h>    // Para utilizar NULL
#include "Arbol.h" 

/* Funcion Miembro que Inicializa el Arbol Binario a traves del Apuntador Raiz*/
template<class Tipo>
Arbol<Tipo>::Arbol()
{
  raiz = NULL;
}

/* Miembro Constructor Copia, que crea e inicializa un nuevo objeto,        */
/* con la informacion del objeto Entrada                                    */ 
template<class Tipo>
Arbol<Tipo>::Arbol(Arbol<Tipo> &entrada)
{
  raiz = CopiaArbol(entrada.ObtRaiz());
}

template<class Tipo>
Nodo<Tipo>* Arbol<Tipo>::ObtRaiz(){
       return raiz;     
       };

template<class Tipo>       
void Arbol<Tipo>::AsigRaiz(Nodo<Tipo> *p){
     raiz = p;
     };


/* Funcion Miembro que Libera los Nodos del Arbol Binario,  e Inicializa el   */
/* Apuntador del Arbol Binario, utizando Recorrido Recursivo en PosOrden      */
template<class Tipo>
void Arbol<Tipo>::Liberar(Nodo<Tipo> *tree)
{
  if(tree != NULL){
    Liberar(tree->ObtIzq());
    Liberar(tree->ObtDer());
    delete tree;
  }
}

/* Funcion Miembro Destructor del Arbol Binario, Inicializa el Apuntador raiz */
template<class Tipo>
Arbol<Tipo>::~Arbol(void)
{
  Liberar(raiz);
  raiz = NULL;
}

/* Funcion Miembro que Chequea si el Arbol Binario  esta Vacio                */
template<class Tipo>
bool Arbol<Tipo>:: Vacio(void)
{
  return (raiz == NULL);
}

/* Funcion Miembro que Chequea si el Arbol Binario esta Lleno                 */
template<class Tipo>
bool Arbol<Tipo>::Lleno(void)
{
  Nodo<Tipo> *p;
  p = new Nodo<Tipo>;
  if (p != NULL)
    {
      delete p;
      return false;
    }
    else return true;
}


/* Funcion Miembro que permite Crear un Arbol Binario con un Nodo raiz        */
template<class Tipo>
Nodo<Tipo> *Arbol<Tipo>::CrearNodo(Tipo valor)
{
  if (!Lleno())
  	{ Nodo<Tipo> *nuevo;
     nuevo = new Nodo<Tipo>;
     
     nuevo->AsigInfo(valor);
     nuevo->AsigDer(NULL);
     nuevo->AsigIzq(NULL);
     return nuevo;
   }
   else
   { 
     return NULL;
   }
}

/* Funcion Miembro que permite Insertar un Hijo Izquierdo al Nodo P           */
template<class Tipo>
bool Arbol<Tipo>::InsIzquierdo(Nodo<Tipo> *p, Tipo valor)
{
  Nodo<Tipo> *nuevo;
  if (!Lleno())
            if ((p==NULL) || (p->ObtIzq()!=NULL))
               return false;
            else   
                 {
                  nuevo=CrearNodo(valor);
                  p->AsigIzq(nuevo);
                  return true;
                 }
	else {
     return false;
   }
}

/* Funcion Miembro que permite Insertar un Hijo Derecho al Nodo P             */
template<class Tipo>
bool Arbol<Tipo>::InsDerecho(Nodo<Tipo> *p, Tipo valor)
{
  Nodo<Tipo> *nuevo;
  if (!Lleno())
            if ((p==NULL) || (p->ObtDer()!=NULL))
               return false;
            else   
                 {
                  nuevo=CrearNodo(valor);
                  p->AsigDer(nuevo);
                  return true;
                 }
	else {
     return false;
   }
}

/* Funcion Miembro que permite Combinar dos Arboles en uno, con un Nodo raiz  */
/* con informacion contenida en Valor                                         */
template<class Tipo>
Nodo<Tipo> *Arbol<Tipo>::Combinar(Nodo<Tipo> *Arbol1, Nodo<Tipo> *Arbol2, Tipo Valor)
{
  if (!Lleno())
  { Nodo<Tipo> *nuevo;
    nuevo = CrearNodo(Valor);
    nuevo->AsigIzq(Arbol1);
    nuevo->AsigDer(Arbol2);
    return nuevo;
  }
  else {
    return NULL;
  }
}

//Otra propuesta, veamos, creo q si funciona!:
template <class Tipo>
bool Arbol<Tipo>::Eliminar(Nodo<Tipo> *ap,Nodo<Tipo>* &p,Tipo &valor){ 
      bool enc;
      if (ap->ObtIzq()==NULL && ap->ObtDer()==NULL && ap!=p) return false;
	  if ((p->ObtIzq()==NULL) && (p->ObtDer()==NULL))
	      {
	            valor=p->ObtInfo();            
	            if (p==raiz) {
   	                 delete p;
	                 p=NULL;
	                 return true;                                                  
                    }
                else if (ap->ObtIzq()==p ){
                     ap->AsigIzq(NULL);
   	                 delete p;
	                 p=NULL;
	                 return true;                     
                    }
                else if (ap->ObtDer()==p ){
                     ap->AsigDer(NULL);
   	                 delete p;
	                 p=NULL;
	                 return true;                                          
                     }
                else {
                     enc=Eliminar(ap->ObtIzq(),p,valor);
                     if (!enc) enc= Eliminar(ap->ObtDer(),p,valor);
                     return enc;
                     }                                            	            
	      }
	  else
	      return false;
	};


template <class Tipo>
bool Arbol<Tipo>::EliIzquierdo(Nodo<Tipo>* padre,Tipo &valor)	
	{
	  Nodo<Tipo>* p;
	  p=padre->ObtIzq();   
	  if ((p->ObtIzq()==NULL) && (p->ObtDer()==NULL))
	      {
	            valor=p->ObtInfo();
	            padre->AsigIzq(NULL);
	            delete p;
	            return true;
	      }
	  else
	      return false;
	};


template <class Tipo>
bool Arbol<Tipo>::EliDerecho(Nodo<Tipo>* padre,Tipo &valor)
{
  Nodo<Tipo>* p;
  p=padre->ObtDer();   
  if ((p->ObtIzq()==NULL) && (p->ObtDer()==NULL))
      {
            valor=p->ObtInfo();
            padre->AsigDer(NULL);
            delete p;
            return true;
      }
  else
      return false;
};
/* Funcion Miembro que asigna el contenido de Entrada al objeto activo  */
template<class Tipo>
Arbol<Tipo> &Arbol<Tipo>::operator = (Arbol<Tipo> &Entrada)
{
		raiz = CopiaArbol(Entrada.ObtRaiz());
      return *this;
}

template<class Tipo>
Nodo<Tipo> *Arbol<Tipo>::CopiaArbol(Nodo<Tipo> *tree)
{
	Nodo<Tipo> *arbolIzq, *arbolDer, *p;
   if (tree){
       arbolIzq = CopiaArbol(tree->ObtIzq());
       arbolDer = CopiaArbol(tree->ObtDer());
       p = Combinar(arbolIzq,arbolDer,tree->ObtInfo());
       return p;
      }
      else return NULL; 
}

template<class Tipo>
Nodo<Tipo> *Arbol<Tipo>::ObtDer(Nodo<Tipo> *p)
{
  Nodo<Tipo> *f;
  f=NULL;
  if(!Vacio())
  {
    if(p->ObtDer()!=NULL)
      f=p->ObtDer();
    else 
      f=NULL;
  }
  return f;
}


template<class Tipo>
Nodo<Tipo> *Arbol<Tipo>::ObtIzq(Nodo<Tipo> *p)
{
  Nodo<Tipo> *f;
  f=NULL;
  if(!Vacio())
  {
    if(p->ObtIzq()!=NULL)
      f=p->ObtIzq();
    else 
      f=NULL;
  }
  return f;
}

template<class Tipo>
Tipo Arbol<Tipo>::ObtInfo(Nodo<Tipo> *p)
{
  if(p!=NULL)
    return  p->ObtInfo();
}

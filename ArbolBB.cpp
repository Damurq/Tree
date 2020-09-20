#include "ArbolBB.h"

template <class Tipo>
Nodo<Tipo>* ArbolBB<Tipo>::Buscar(Nodo<Tipo>* p,Tipo valor)
{
  Tipo auxiliar;      
   
  while (p!=NULL)
     {
        auxiliar=p->ObtInfo();
        if (valor==auxiliar)
             return p;
       else 
           if (valor<auxiliar) 
              p=p->ObtIzq();
           else  
              p=p->ObtDer();
      };
  return NULL;      
};

//Buscar que sea recursivo:
template <class Tipo>
Nodo<Tipo>* ArbolBB<Tipo> :: BuscarRecursivo(Nodo<Tipo>* p, Tipo valor) {

      if (p!=NULL){
          if (valor==p->ObtInfo()){
                return p;
                }        
          else if (valor<p->ObtInfo()){
               return BuscarRecursivo(p->ObtIzq(),valor);
               }           
          else return BuscarRecursivo(p->ObtDer(),valor);
          }
      else return NULL;
    };

template <class Tipo>
bool ArbolBB<Tipo>::Insertar(Tipo valor)
{
  Apuntador p,nuevo,ant;
  Tipo auxiliar;

  nuevo=this->CrearNodo(valor);
  if (Arbol<Tipo>::ObtRaiz()==NULL)        
	    this->AsigRaiz(nuevo);
  else
  {
  p=Arbol<Tipo>::ObtRaiz();     	    
  while (p!=NULL)
    {     
      auxiliar=p->ObtInfo();      
      if  (valor==auxiliar)
           return false;  
      else
          if  (valor<auxiliar)
                {    	 
                  ant=p;     
                  p=p->ObtIzq();
                  if (p==NULL)
                    this->InsIzquierdo(ant,valor);
                }    
              else
                {
                  ant=p;
                  p=p->ObtDer();
                  if (p==NULL) 
                    this->InsDerecho(ant,valor);
                };
          };
  };	
  return true;	
};


//InsertarRecursivo, este metodo no permite actualizar la raiz!:
template <class Tipo>
bool ArbolBB<Tipo>::InsertarRecursivo(Nodo<Tipo>* p, Tipo valor){
     
     Tipo auxiliar;

     Nodo<Tipo>* nuevo;
     if (Arbol<Tipo>::ObtRaiz()==NULL)  
      {     
        nuevo=CrearNodo(valor); 
	    AsigRaiz(nuevo);
	    return true;
      }
     else {
          auxiliar = p->ObtInfo();
          if (valor==auxiliar) return false;
          else if (valor < auxiliar) {
               if (p->ObtIzq()==NULL) {
                   InsIzquierdo(p,valor);
                   return true;
                   }
               else InsertarRecursivo(p->ObtIzq(),valor);
               }
          else
              if (p->ObtDer()==NULL) {
                 InsDerecho(p,valor);
                 return true;
                 }
              else InsertarRecursivo(p->ObtDer(),valor);
          }
     };

template <class Tipo>
bool ArbolBB<Tipo>::Eliminar(Tipo &valor)
{
  Apuntador p,ant,temp;
  bool encontrado;
  Tipo auxiliar;
  p=Arbol<Tipo>::ObtRaiz(); 
  encontrado=false;
  while ((p!=NULL) && !(encontrado)) {
     auxiliar=p->ObtInfo();
   if  (valor==auxiliar)
	    encontrado=true;
     else {
           ant=p; //El padre de p
           if (valor< auxiliar)
                 p=p->ObtIzq();
          else 
                 p=p->ObtDer();
       };
   };
if (encontrado)   {   //la Clave esta en el arbol
        temp=p;   //Apuntador cuyo nodo va a ser eliminado       	            
        valor=auxiliar;     
         if (p->ObtDer()==NULL) {  //Tiene un posible Hijo Izquierdo:   
              if (p==Arbol<Tipo>::ObtRaiz())  //Caso Raiz
                AsigRaiz(p->ObtIzq());	         //Asigna el hijo izquierdo como Raiz	
              else    //Se actualiza el Der o Izq del padre seg�n sea el caso
                if (ant->ObtIzq()==p)  ant->AsigIzq(p->ObtIzq());
                else                    ant->AsigDer(p->ObtIzq());
        }
        else if (p->ObtIzq()==NULL) { 	 //Tiene un posible Hijo Derecho:
              if (p==Arbol<Tipo>::ObtRaiz()) //Caso Raiz
                 AsigRaiz(p->ObtDer()); //Asigna el hijo derecho como Raiz	
              else //Se actualiza el Der o Izq del padre seg�n sea el caso
            	  if (ant->ObtIzq()==p) ant->AsigIzq(p->ObtDer());
                  else  ant->AsigDer(p->ObtDer());

}
else  {	              // Caso dos hijos:				
                ant=p;
              //El nodo a eliminar ser� el mas a la derecha del subarbol izquierdo
                temp=p->ObtIzq(); 
                while (temp->ObtDer()!=NULL) {
                	    ant=temp;
                	    temp=temp->ObtDer();       
                   };
                 auxiliar=temp->ObtInfo();
                 p->AsigInfo(auxiliar);
                 if (ant==p)       ant-> AsigIzq(temp->ObtIzq());
                 else              ant-> AsigDer(temp->ObtIzq());
              };
           //Sucede para cualquiera de los tres casos
           delete temp;
           return true;    
           }
   else return false;    //En caso de que la clave no se encuentre!
};
     
/*
template <class Tipo>
bool ArbolBB<Tipo>::Eliminar(Tipo &valor)
{
  Apuntador p,ant,temp;
  bool encontrado;
  Tipo auxiliar;
  p=Arbol<Tipo>::ObtRaiz(); 
  encontrado=false;
  while ((p!=NULL) && !(encontrado)) {
     auxiliar=p->ObtInfo();
     if  (valor==auxiliar)
	    encontrado=true;
     else {
           ant=p; //El padre de p
           if (valor< auxiliar) 
                 p=p->ObtIzq();
          else 
                 p=p->ObtDer();
       };
   };
if (encontrado)   {   //la Clave esta en el arbol
        temp=p;   //Apuntador cuyo nodo va a ser eliminado       	            
        valor=auxiliar;     
         if (p->ObtDer()==NULL) {  //Tiene un posible Hijo Izquierdo:   
              if (p==Arbol<Tipo>::ObtRaiz())  //Caso Raiz
                AsigRaiz(p->ObtIzq());	         //Asigna el hijo izquierdo como Raiz	
              else    //Se actualiza el Der o Izq del padre seg�n sea el caso
                if (ant->ObtIzq()==p)  ant->AsigIzq(p->ObtIzq());
                else                    ant->AsigDer(p->ObtIzq());
        }
        else if (p->ObtIzq()==NULL) { 	 //Tiene un posible Hijo Derecho:
              if (p==Arbol<Tipo>::ObtRaiz()) //Caso Raiz
                 AsigRaiz(p->ObtDer()); //Asigna el hijo derecho como Raiz	
              else //Se actualiza el Der o Izq del padre seg�n sea el caso
            	  if (ant->ObtIzq()==p) ant->AsigIzq(p->ObtDer());
                  else  ant->AsigDer(p->ObtDer());

}
else  {	              // Caso dos hijos:				
                ant=p;
              //El nodo a eliminar ser� el mas a la derecha del subarbol izquierdo
                temp=p->ObtIzq(); 
                while (temp->ObtDer()!=NULL) {
                	    ant=temp;
                	    temp=temp->ObtDer();       
                   };
                 auxiliar=temp->ObtInfo();
                 p->AsigInfo(auxiliar);
                 if (ant==p)       ant->AsigIzq(temp->ObtIzq());
                 else              ant->AsigDer(temp->ObtIzq());
              };
           //Sucede para cualquiera de los tres casos
           delete temp;
           return true;    
           }
   else return false;    //En caso de que la clave no se encuentre!
};
*/


//===============================================================================================
//COMPARA 2 STRING Y RETORNA true SI EL PRIMER STRING VA ADELANTE O ES IGUAL -----------FUNCIONAL
//===============================================================================================
/*template <class Tipo>
bool ArbolBB<Tipo>::Comparar(string nom1,string nom2)
{
	int size1=nom1.size();
	int size2=nom2.size();
	int lim;
	if(size1<size2)
		lim=size1;
	else 
		lim=size2;
	for (int i = 0; i < lim; i++)
	{
		if (nom1[i]<nom2[i])
		{
			return true;
			//return nom1;
		}
		else if (nom1[i]>nom2[i])
		{
			return false;
			//retunr nom2;
		}
	}
	if (size1==size2)
	{
		return true;
	}
	else if(size1<size2)
		return true;
	else
	{
			return false;
	}
	
}*/

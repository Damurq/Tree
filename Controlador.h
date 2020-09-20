#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#include <string>
#include <iostream>
#include "ArbolBB.h"
#include "VGeneral.h"
//#include "Persona.h"

class Controlador
{
    typedef Nodo<Tipo>* Apuntador;     
    private:
        //ArbolBB<Persona> TreePers;
        ArbolBB<string> TreePers;
        VGeneral vg;
    public:
        Controlador();
        bool IncluirClnts(); 
        void Imprimir(int tipo);  
        void InOrden(ArbolBB<string> &ArbolBBper,Apuntador p);
        void PosOrden(ArbolBB<string> &ArbArbolBBperol,Apuntador p);
        void PreOrden(ArbolBB<string> &ArbolBBper,Apuntador p);                                 
        
};

#include "Controlador.cpp"
#endif /* CONTROLADOR_H_ */

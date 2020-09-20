#include "Controlador.h"
#include "VGeneral.h"
#include <string>
#include <iostream>


int main()
{
   int valor,valor2;
   string ced;
   Controlador c;
   VGeneral vg;
   do
   {
      vg.Limpiar();
      cout<<"=============================================================================="<<endl;
      cout<<"-----------------------------  MENU DE OPCIONES  -----------------------------"<<endl;
      cout<<"=============================================================================="<<endl;
      cout<<"\n1-) Registrar persona"<<endl;
      cout<<"2-) Imprimir"<<endl;
      cout<<"3-) Salir\n"<<endl;
      cout<<"=============================================================================="<<endl;
      valor= vg.LeerValidarNro("\n Opcion seleccionada : ",1,7);
      switch (valor)
   {
   case 1:
      vg.Limpiar();
      c.IncluirPrsn();
      break;
   case 2:
      vg.Limpiar();   	
      cout<<"=============================================================================="<<endl;   	
      cout<<"---------------------------  SUB-MENU DE OPCIONES  ---------------------------"<<endl;
      cout<<"=============================================================================="<<endl;
      cout<<"1-) Imprimir en PREORDEN"<<endl;
      cout<<"2-) Imprimir INORDEN"<<endl;
      cout<<"3-) Imprimir POSTORDEN"<<endl;
      cout<<"4-) Imprimir todo"<<endl;
      cout<<"5-) Atras\n"<<endl;
      valor2= vg.LeerValidarNro(" Opcion seleccionada : ",1,5);
      if(valor2!=5)
         c.Imprimir(valor2);         
      break;
   default:
      break;
   }
   }while(valor!=3);   
   return 0;
}

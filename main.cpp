#include "Controlador.h"
#include "VGeneral.h"
#include "Cola.h"
#include <string>
#include <iostream>


int main()
{
   int valor,valor2;
   string ced;
   Controlador c;
   VGeneral vg;
   do{
   vg.Limpiar();
   cout<<"=============================================================================="<<endl;
   cout<<"-----------------------------  MENU DE OPCIONES  -----------------------------"<<endl;
   cout<<"=============================================================================="<<endl;
   cout<<"\n1-) Registrar estudiantes"<<endl;
   cout<<"2-) Imprimir"<<endl;
   cout<<"3-) Ordenar alfabeticamente por nombre"<<endl;
   cout<<"4-) Total de Alumnos registrados"<<endl;
   cout<<"5-) Eliminar todos los alumnos"<<endl;
   cout<<"6-) Buscar"<<endl;
   cout<<"7-) Salir\n"<<endl;
   cout<<"=============================================================================="<<endl;
   valor= vg.LeerValidarNro("\n Opcion seleccionada : ",1,7);
   switch (valor)
   {
   case 1:
      vg.Limpiar();
      cout<<"=============================================================================="<<endl;
      cout<<"---------------------------  SUB-MENU DE OPCIONES  ---------------------------"<<endl;
      cout<<"=============================================================================="<<endl;
      cout<<"\n1-) Registrar estudiantes al final de la cola"<<endl;
      cout<<"2-) Registrar estudiantes de forma ordenada"<<endl;
      cout<<"3-) Atras\n"<<endl;
      cout<<"=============================================================================="<<endl;
      valor2= vg.LeerValidarNro("\n Opcion seleccionada : ",1,3);
      if(valor2==1)
         c.IncluirAlms(1);
      else if(valor2==2)
         c.IncluirAlms(2);
      break;
   case 2:
      vg.Limpiar();   	
      cout<<"=============================================================================="<<endl;   	
      cout<<"---------------------------  SUB-MENU DE OPCIONES  ---------------------------"<<endl;
      cout<<"=============================================================================="<<endl;
      cout<<"1-) Imprimir y vaciar"<<endl;
      cout<<"2-) Imprimir"<<endl;
      cout<<"3-) Atras\n"<<endl;
      valor2= vg.LeerValidarNro(" Opcion seleccionada : ",1,3);
      if(valor2==1)
         c.Imprimir(valor2);
      else if(valor2==2)
         c.Imprimir(valor2);
      break;
   case 3:
      c.OrdenarAlms();
      break;
   case 4:
      cout<<"\n Total de alumnos registrados hasta el momento: "<<c.Tolal()<<"\n "<<endl;
      vg.Pausa();
      break;
   case 5:
      c.EliminarAlumnos();
      break;
   case 6:
      c.Imp_ONE_Alm();
      break;
   default:
      break;
   }
   }while(valor!=7);   
   return 0;
}

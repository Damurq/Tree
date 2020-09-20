
#include "Persona.h"

//Constructor:
Persona::Persona()
{
}

//Set y get
void Persona::SetCedula(string ced){
   cedula = ced;
}
   
void Persona::SetNombre(string nomb){
   nombre = nomb;
}  



string Persona::GetCedula(){
   return cedula;
}     

string Persona::GetNombre(){
   return nombre;
}        


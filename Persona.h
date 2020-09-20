#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>
#include <string>

using namespace std;

class Persona
{
private:
	string cedula,nombre;
public:
	//Constructor:
	Persona();
	void SetCedula(string ced);
	void SetNombre(string nom);
	string GetCedula();
    string GetNombre();
	
};

#include "Persona.cpp"
#endif /* Persona_H_ */

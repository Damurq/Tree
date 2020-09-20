#include "Controlador.h"

Controlador::Controlador()
{
};


void InOrden(Arbol<char> &Arbol,Apuntador p)
{
char simbolo;
if (p!=NULL)
{
InOrden(Arbol,Arbol.ObtIzq(p));
simbolo=Arbol.ObtInfo(p);
cout << simbolo;
InOrden(Arbol,Arbol.ObtDer(p));
};
};
void PosOrden(Arbol<char> &Arbol,Apuntador p)
{
char simbolo;
if (p!=NULL)
{
PosOrden(Arbol,Arbol.ObtIzq(p));
PosOrden(Arbol,Arbol.ObtDer(p));
simbolo=Arbol.ObtInfo(p);
cout << simbolo;
};
};
void PreOrden(Arbol<char> &Arbol,Apuntador p)
{
char simbolo;
if (p!=NULL)
{
simbolo=Arbol.ObtInfo(p);
cout << simbolo;
PreOrden(Arbol,Arbol.ObtIzq(p));
PreOrden(Arbol,Arbol.ObtDer(p));
};
};
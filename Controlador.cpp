#include "Controlador.h"

Controlador::Controlador()
{
};


void Controlador::InOrden(ArbolBB<string> &ArbolBBper,Apuntador p)
{
	string nomb;
	if (p!=NULL)
	{
		InOrden(ArbolBBper,ArbolBBper.ObtIzq(p));
		nomb=ArbolBBper.ObtInfo(p);
		cout << nomb;
		InOrden(ArbolBBper,ArbolBBper.ObtDer(p));
	};
};
void Controlador::PosOrden(ArbolBB<string> &ArbolBBper,Apuntador p)
{
	string nomb;
	if (p!=NULL)
	{
		PosOrden(ArbolBBper,ArbolBBper.ObtIzq(p));
		PosOrden(ArbolBBper,ArbolBBper.ObtDer(p));
		nomb=ArbolBBper.ObtInfo(p);
		cout << nomb;
	};
};
void Controlador::PreOrden(ArbolBB<string> &ArbolBBper,Apuntador p)
{
	string nomb;
	if (p!=NULL)
	{
		nomb=ArbolBBper.ObtInfo(p);
		cout << nomb;
		PreOrden(ArbolBBper,ArbolBBper.ObtIzq(p));
		PreOrden(ArbolBBper,ArbolBBper.ObtDer(p));
	};
};
#include "Controlador.h"

Controlador::Controlador()
{
};

//===============================================================================================
//INCLUIR UN CLIENTE-----------NECESARIO
//===============================================================================================
bool Controlador::IncluirClnts()
{
	if(!TreePers.Lleno())
	{
		int resp;
		string nombre;
		vg.Limpiar();
		cout<<"=============================================================================="<<endl;
  		cout<<"----------------------------  DATOS DE LA PERSONA  -----------------------------"<<endl;
      	cout<<"=============================================================================="<<endl;
	do{
		nombre=vg.LeerString("Intoduzca Nombre:     ");
		TreePers.Insertar(nombre);
		cout<<"\n=============================================================================="<<endl;
		resp=vg.LeerValidarNro("\t\tDesea agregar otro Cliente a la cola 1[SI] 2[NO]: ",1,2);	
		cout<<"=============================================================================="<<endl;	
	}while(resp==1);
	return true;
	}
	else
	{
		vg.Limpiar();
		cout<<"\n=============================================================================="<<endl;
		vg.ImprimirMensaje("\t\t LA COLAP ESTA LLENA");
		cout<<"\n=============================================================================="<<endl;
		return false;
		vg.Pausa();
	}
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
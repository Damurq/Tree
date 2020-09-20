#include "Controlador.h"

Controlador::Controlador()
{
};

//===============================================================================================
//INCLUIR UNA PERSONA-----------NECESARIO
//===============================================================================================
bool Controlador::IncluirPrsn()
{
	if(!TreePers.Lleno())
	{
		int resp;
		string nombre;
		vg.Limpiar();
		cout<<"=============================================================================="<<endl;
  		cout<<"--------------------------  DATOS DE LA PERSONA  -----------------------------"<<endl;
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


//===============================================================================================
//IMPRIMIR EN PRE IN POST (1-IMPRIMIR Y VACIRA,2-IMPRIMIR)-----------FUNCIONAL
//===============================================================================================
void Controlador::Imprimir(int tipo)
{
	string nomb;
	if(TreePers.Vacio())
	{
		vg.Limpiar();
		cout<<"=============================================================================="<<endl;
  		cout<<"---------------------------  EL ARBOL ESTA VACIO  ----------------------------"<<endl;
      	cout<<"=============================================================================="<<endl;
		vg.Pausa();
	}
	else
	{
		//IMPRIMIR Y VACIAR LA COLA
		if (tipo==2)
		{
			vg.Limpiar();
			cout<<"=============================================================================="<<endl;
  			cout<<"--------------------------------  INORDEN  ----------------------------------"<<endl;
      		cout<<"=============================================================================="<<endl;
			InOrden(TreePers, TreePers.ObtRaiz());
			vg.Pausa();
		}
		//IMPRIMIR SIN VACIAR
		else if (tipo==3)
		{
			vg.Limpiar();
			cout<<"=============================================================================="<<endl;
  			cout<<"---------------------------------  POSORDEN  ----------------------------------"<<endl;
      		cout<<"=============================================================================="<<endl;
			PosOrden(TreePers, TreePers.ObtRaiz());
			vg.Pausa();
		}
		else if (tipo==1)
		{
			vg.Limpiar();
			cout<<"=============================================================================="<<endl;
  			cout<<"---------------------------------  PREORDEN ----------------------------------"<<endl;
      		cout<<"=============================================================================="<<endl;
			PreOrden(TreePers, TreePers.ObtRaiz());
			vg.Pausa();
		}
		else if (tipo==4)
		{
			vg.Limpiar();
			cout<<"=============================================================================="<<endl;
  			cout<<"---------------------------------  PREORDEN ----------------------------------"<<endl;
      		cout<<"=============================================================================="<<endl;
			PreOrden(TreePers, TreePers.ObtRaiz());
			cout<<"=============================================================================="<<endl;
  			cout<<"--------------------------------  INORDEN  ----------------------------------"<<endl;
      		cout<<"=============================================================================="<<endl;
			InOrden(TreePers, TreePers.ObtRaiz());
			cout<<"=============================================================================="<<endl;
  			cout<<"---------------------------------  POSORDEN  ----------------------------------"<<endl;
      		cout<<"=============================================================================="<<endl;
			PosOrden(TreePers, TreePers.ObtRaiz());
			vg.Pausa();			
		}
	}
};


void Controlador::InOrden(ArbolBB<string> &ArbolBBper,Apuntador p)
{
	string nomb;
	if (p!=NULL)
	{
		InOrden(ArbolBBper,ArbolBBper.ObtIzq(p));
		nomb=ArbolBBper.ObtInfo(p);
		//cout << nomb<<endl;
		cout << nomb<<"  ->  ";
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
		//cout << nomb<<endl;
		cout << nomb<<"  ->  ";
	};
};

void Controlador::PreOrden(ArbolBB<string> &ArbolBBper,Apuntador p)
{
	string nomb;
	if (p!=NULL)
	{
		nomb=ArbolBBper.ObtInfo(p);
		//cout << nomb<<endl;
		cout << nomb<<"  ->  ";
		PreOrden(ArbolBBper,ArbolBBper.ObtIzq(p));
		PreOrden(ArbolBBper,ArbolBBper.ObtDer(p));
	};
};

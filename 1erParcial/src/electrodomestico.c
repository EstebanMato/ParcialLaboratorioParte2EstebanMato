#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utnInputs.h"
#include "electrodomestico.h"
#include "reparacion.h"

int buscarElectroSerie(eElectrodomestico* list, int len, int id)
{
	int retorno = 0;
		if (list != NULL)
		{
			retorno=0;
			for(int i=0; i<len; i++)
			{
				if(list[i].serie==id)
				{
					retorno=-1;
					break;
				}
			}
		}
		else
		{
			retorno=-1;
		}

	return retorno;
}


int hardcodearElectrodomesticos(eElectrodomestico* listElec, int lenElec, int cantidad)
{//tenemos 10 electrodomesticos como maximo para hardcodear

	int contador=0;
	if(listElec != NULL && cantidad >0)
	{
	eElectrodomestico listaElectrodomesticosSuplente [] = {{1 ,1234,1000,2000,0},
														   {2 ,5487,1002,1993,0},
														   {3 ,1235,1002,2001,0},
														   {4 ,8484,1000,2001,0},
														   {5 ,3265,1001,2019,0},
														   {6 ,1313,1003,2020,0},
														   {7 ,1111,1004,2018,0},
														   {8 ,5656,1004,2018,0},
														   {9 ,9865,1002,2000,0},
														   {10,0002,1003,2002,0}
	};
		if(cantidad <= lenElec && cantidad <=10)
		{
			for(int i=0; i<cantidad; i++)
			{
				listElec[i]=listaElectrodomesticosSuplente[i];
				contador++;
			}
		}
	}
	return contador;
}


int initElectrodomesticos(eElectrodomestico* listElec, int lenElec)
{
	int retorno =-1;
	if(listElec != NULL && lenElec>0)
	{
		for (int i=0; i<lenElec; i++)
		{
			listElec[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}


int cargadoArrayElectrodomestico(eElectrodomestico* list, int len)
{
	int loaded=0;

	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==0)
		{
			loaded=1;
			break;
		}
	}
	return loaded;
}


int addElectrodomestico(eElectrodomestico* list, int id, int indice, int serie, int idMarca, int modelo)
{
	int retorno =-1;

	if(list != NULL)
	{
		list[indice].id=id;
		list[indice].idMarca=idMarca;
		list[indice].modelo=modelo;
		list[indice].serie=serie;
		list[indice].isEmpty=0;
		retorno=0;
	}
	return retorno;
}


int searchFree(eElectrodomestico* list, int len)
{
	int retorno = -1;

	if(list != NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}

	return retorno;
}


int searchMarca(eMarca* list, int len, int id)
{
	int retorno = -1;
	if (list != NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].id==id)
			{
				retorno=i;
				break;
			}

		}
	}
	return retorno;
}


void mostrarMarca(eMarca marca)
{
	printf("\n%-4d  %-10s",marca.id, marca.descripcion);
}


void mostrarMarcas(eMarca* list, int len)
{
	if(list != NULL)
	{
		printf("\n**Listado de marcas**");
		printf("\nId    Descripcion");

		for(int i=0; i<len; i++)
		{
			mostrarMarca(list[i]);
		}
	}
}


void ordenarElectrodomestico(eElectrodomestico* list, int len)
{
	int flagSwap;

	eElectrodomestico auxElectrodomestico;

	if(list != NULL && len >1)
	{
		do
		{
			flagSwap=0;
			for(int i=0; i<len; i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}

				if(list[i].modelo > list[i+1].modelo)
				{
					flagSwap = 1;
					auxElectrodomestico=list[i];
					list[i]=list[i+1];
					list[i+1]=auxElectrodomestico;
				}
				else
				{
					if(list[i].modelo == list[i+1].modelo)
					{
						if(list[i].serie > list[i+1].serie)
						{
							flagSwap = 1;
							auxElectrodomestico=list[i];
							list[i]=list[i+1];
							list[i+1]=auxElectrodomestico;
						}
					}
				}
			}
			len--;
		}while(flagSwap);
	}
}


void mostrarElectrodomestico(eElectrodomestico electrodomestico, eMarca* listMarca, int lenMarca)
{
	int indiceMarca;

	indiceMarca=searchMarca(listMarca, lenMarca, electrodomestico.idMarca);

	printf("\n%-2d   %04d      %-10s  %4d",electrodomestico.id, electrodomestico.serie, listMarca[indiceMarca].descripcion, electrodomestico.modelo);
}


void mostrarElectrodomesticos(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca)
{
	if(list != NULL)
	{
		ordenarElectrodomestico(list, len);
		printf("\n**Listado de electrodomesticos**");
		printf("\nId   NumSerie  Marca    Modelo(anio)");

		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==0)
			{
				mostrarElectrodomestico(list[i],listMarca, lenMarca);
			}

		}
	}
}


int altaElectrodomestico(eElectrodomestico* listElectro, int lenElec, int id, eMarca* listMarcas, int lenMarca)
{
	int todoOk=-1;
	int indice;
	int serie;
	int idMarca;
	int modelo;


	if((indice = searchFree(listElectro, lenElec))!=-1)
	{
		system("clear");
		printf("\n***Alta de electrodomestico***\n");

		todoOk=utn_getNumber(&serie, "\nIngrese el numero de serie (Rango entre 0001-9999): ", "\nERROR (Rango entre 0001-9999)", 1, 9999, 3);
		if(todoOk==0)
		{
			//VER SI HACE FALTA USAR
			//buscarElectroSerie(listElectro, lenElec, serie);

			int reintentos = 3;

			do
			{

				mostrarMarcas(listMarcas, lenMarca);
				printf("\n\nIngrese el numero de ID de marca: ");
				scanf("%d", &idMarca);
				todoOk=searchMarca(listMarcas, lenMarca, idMarca);
				if(todoOk!=-1)
				{
					todoOk=0;
					break;
				}
				else
				{
					printf("\nERROR. Id de marca no encontrado\n");
					reintentos--;
				}
			}while(reintentos>0);

			if(todoOk==0)
			{
				todoOk=utn_getNumber(&modelo, "\nIngrese el modelo del electrodomestico(1980-2020): ", "\nERROR (Rango entre 1980 - 2020", 1980, 2020, 3);
			}
		}

		if(todoOk==0)
		{
			todoOk=addElectrodomestico(listElectro,id, indice,serie,idMarca,modelo);
		}
	}
	else
	{
		printf("\nSistema de electrodomesticos completo\n");
	}

	return todoOk;
}


int buscarElectrodomesticoId(eElectrodomestico* list, int len, int id)
{
	int indice=-1;
	if(list != NULL)
	{
		for(int i=0;i<len;i++)
		{
			if (list[i].id==id && list[i].isEmpty==0)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}


void modifyElectrodomestico(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca)
{
	int idElectrodomestico;
	int indiceElectrodomestico;
	int option;
	int todoOk=-1;
	int serie;
	int modelo;
	char change = 'n';
	char salir='n';

	system("clear");
	printf("***Modificar electrodomestico***");
	mostrarElectrodomesticos(list, len, listMarca, lenMarca);

	printf("\n\nIngrese el Id del electrodomestico a modificar: ");
	__fpurge(stdin);
	scanf("%d",&idElectrodomestico);
	indiceElectrodomestico = buscarElectrodomesticoId(list, len, idElectrodomestico);
	if(indiceElectrodomestico == -1)
	{
		printf("\nNo existe electrodomectico con numero de Id ingresado");
	}else
	{
		do{
			todoOk=-1;
			change='n';
			system("clear");
			printf("\n***Modificar electrodomestico***\n");
			printf("\nId   NumSerie  Marca      Modelo(anio)");
			mostrarElectrodomestico(list[indiceElectrodomestico], listMarca, lenMarca);
			printf("\n\nQue desea modificar?");
			printf("\n1-Serie");
			printf("\n2-Modelo");
			printf("\n\n3-Salir");
			printf("\nIngrese opcion: ");
			scanf("%d",&option);

			switch(option)
			{

			case 1:
				todoOk=utn_getNumber(&serie, "\nIngrese el numero de serie (Rango entre 0001-9999): ", "\nERROR (Rango entre 0001-9999)", 1, 9999, 3);
				if(todoOk==0)
				{
					printf("\nEl nuevo numero de serie es '%d', desea continuar y efectuar el cambio? (s/n): ",serie);
					__fpurge(stdin);
					scanf("%c", &change);
					if(change =='s')
					{
						list[indiceElectrodomestico].serie=serie;
						printf("\nSe realizo el cambio corectamente!");
					}
					else
					{
						printf("\nSe cancelo la modificacion");
					}
				}
				else
				{
					printf("\nError! (no fue modificado ningun dato del empleado)");
				}
				break;

			case 2:
				todoOk=utn_getNumber(&modelo, "\nIngrese el modelo del electrodomestico(1980-2020): ", "\nERROR (Rango entre 1980 - 2020)", 1980, 2020, 3);
				if(todoOk==0)
				{
					printf("\nEl nuevo numero de modelo es '%d', desea continuar y efectuar el cambio? (s/n): ",modelo);
					__fpurge(stdin);
					scanf("%c", &change);
					if(change =='s')
					{
						list[indiceElectrodomestico].modelo=modelo;
						printf("\nSe realizo el cambio corectamente!");
					}
				}else
				{
					printf("\nError! (no fue modificado ningun dato del empleado)");
				}
				break;
			case 3:
				printf("\nConfirma que desea salir del sistema? (s/n): ");
				__fpurge(stdin);
				scanf("%c", &salir);
				break;
			default:
				printf("\nOpcion invalida");
			}

			__fpurge(stdin);
		}while(salir!='s');
	}
}


int lowElectrodomestico(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca)
{
	int idElectrodomestico=-1;

	system("clear");
	printf("\n***Baja de electrodomestico***\n");
	mostrarElectrodomesticos(list, len, listMarca, lenMarca);
	printf("\n\nIngrese el Id del electrodomestico a dar de baja: ");
	__fpurge(stdin);
	scanf("%d",&idElectrodomestico);

	if(!(removeElectrodomestico(list, len, listMarca, lenMarca, idElectrodomestico)))
	{
		printf("\nBaja exitosa!! ");
	}
	else
	{
		idElectrodomestico =-1;
		printf("\nERROR en la baja!! ");
	}


	return idElectrodomestico;
}


int removeElectrodomestico(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca, int idElectrodomestico)
{
	int retorno=-1;
	int indiceElectrodomestico;
	char borrar;

	indiceElectrodomestico = buscarElectrodomesticoId(list, len, idElectrodomestico);

	if(indiceElectrodomestico==-1)
	{
		printf("\nNo existe el electrodomestico con numero de Id ingresado");
	}
	else
	{
		printf("\nId   NumSerie  Marca    Modelo(anio)");
		mostrarElectrodomestico(list[indiceElectrodomestico], listMarca, lenMarca);
		printf("\n\nConfirma la baja del electrodomestico(s/n): ");
		__fpurge(stdin);
		scanf("%c",&borrar);

		if(borrar=='s')
		{
			list[indiceElectrodomestico].isEmpty=1;
			retorno=0;
		}
		else
		{
			printf("\nLa operacion se ha cancelado ");
		}
	}
	return retorno;
}


void mostrarElectro2020(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca , int anio)
{
	if (list != NULL)
	{
		printf("\n**Listado de electrodomesticos del anio 2020**");
		printf("\nId   NumSerie  Marca    Modelo(anio)");
		for(int i=0; i<len; i++)
		{
			if(list[i].modelo==anio)
			{
				mostrarElectrodomestico(list[i], listMarca, lenMarca);
			}

		}
	}

}


void mostrarElectroMarca(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca)
{
	if(list != NULL)
	{
		int indice=-1;
		int reintentos = 3;
		int idMarca;

		do
		{
			mostrarMarcas(listMarca, lenMarca);
			printf("\n\nIngrese el numero de ID de marca para mostrar electrodomesticos: ");
			scanf("%d", &idMarca);
			indice=searchMarca(listMarca, lenMarca, idMarca);
			if(indice!=-1)
			{
				printf("\n**Listado de electrodomesticos de marca %s**",listMarca[indice].descripcion);
				printf("\nId   NumSerie  Marca    Modelo(anio)");
				for(int i=0; i<lenMarca; i++)
				{
					if(list[i].idMarca == idMarca)
					{
						mostrarElectrodomestico(list[i], listMarca, lenMarca);
					}
				}

				break;
			}
			else
			{
				printf("\nERROR. Id de marca no encontrado\n");
				reintentos--;
			}
		}while(reintentos>0);
	}
}

//eReparacion* listRepar, int lenRepar, eCliente* listCliente, int lenCliente, eServicio* listServ, int lenServ
int getIdElectro(eElectrodomestico* listElec, int lenElec, eMarca* listMarcas, int lenMarcas)
{
	int idElectrodomestico;
	int indiceElectrodomestico=-1;

	printf("\nLista de reparaciones por electrodomestico");
	mostrarElectrodomesticos(listElec, lenElec, listMarcas, lenMarcas);
	printf("\n\nIngrese el Id del electrodomestico a listar: ");
	__fpurge(stdin);
	scanf("%d",&idElectrodomestico);
	indiceElectrodomestico = buscarElectrodomesticoId(listElec, lenElec, idElectrodomestico);
	if(indiceElectrodomestico == -1)
	{
		printf("\nNo existe electrodomestico con el numero de Id ingresado");
	}

return indiceElectrodomestico;
}












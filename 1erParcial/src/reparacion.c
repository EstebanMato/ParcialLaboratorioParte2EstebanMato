#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <stdio.h>
#include <time.h>
#include "electrodomestico.h"
#include "reparacion.h"
#include "utnInputs.h"


int hardcodearReparaciones(eReparacion* listRepar, int lenRepar, int cantidad)
{//tenemos 8 reparaciones como maximo para hardcodear

	int contador=0;
	if(listRepar != NULL && cantidad >0)
	{
		eReparacion listaReparSuplente [] = {{1,8484,20000,{22,12,2018},10,0},
											 {2,1111,20001,{1,11,2018},11,0},
											 {3,1313,20001,{31,12,2018},12,0},
											 {4,0002,20003,{12,3,2018},13,0},
											 {5,8484,20000,{22,12,2000},10,0},
											 {6,1111,20001,{1,11,2020},11,0},
											 {7,1111,20001,{31,12,2018},11,0},
											 {8,5656,20003,{22,12,2000},13,0}
	};
		if(cantidad <= lenRepar && cantidad <=10)
		{
			for(int i=0; i<cantidad; i++)
			{
				listRepar[i]=listaReparSuplente[i];
				contador++;
			}
		}
	}
	return contador;
}


int fechaActual(int* dia, int* mes, int* anio)
{
	int retorno=-1;

	time_t tiempoAhora;
	time(&tiempoAhora);
	//printf("%s\n",ctime(&tiempoAhora)); //aca printeamos la hora actual con formato en texto en ingles

	struct tm *miTiempo = localtime(&tiempoAhora);
	//printf("%d / %d / %d", miTiempo->tm_mday, miTiempo->tm_mon+1, miTiempo->tm_year+1900); printeamos con ints

	if(miTiempo != NULL)
	{
		*dia=miTiempo->tm_mday;
		*mes=miTiempo->tm_mon+1;
		*anio=miTiempo->tm_year+1900;

		retorno=0;
	}

	return retorno;
}


int pedirFecha(int* anio, int* mes, int* dia)
{
	int retorno=-1;
	int dia_maximo;

	if(anio != NULL && mes != NULL && dia != NULL)
	{
		retorno = utn_getNumber(mes, "\nIngrese el mes(numerico-MM): ", "\nError (Rango entre 1-12)", 1, 12, 3);

		if ( *mes >= 1 && *mes <= 12 && retorno == 0)
		{
			retorno =-1;
			switch ( *mes )
			{
			case  1 :
			case  3 :
			case  5 :
			case  7 :
			case  8 :
			case 10 :
			case 12 :
				dia_maximo = 31;
				retorno = utn_getNumber(dia, "\nIngrese el dia(AA): ", "\nError (Rango entre 1-31)", 1, dia_maximo, 3);
				break;

			case  4 :
			case  6 :
			case  9 :
			case 11 :
				dia_maximo = 30;
				retorno = utn_getNumber(dia, "\nIngrese el dia(AA): ", "\nError (Rango entre 1-30)", 1, dia_maximo, 3);
				break;

			case  2 :
				if( (*anio % 4 == 0 && *anio % 100 != 0) || *anio % 400 == 0)
				{
					dia_maximo=29;
					retorno = utn_getNumber(dia, "\nIngrese el dia(AA): ", "\nError (Rango entre 1-29)", 1, dia_maximo, 3);
				}else
				{
					dia_maximo=28;
					retorno = utn_getNumber(dia, "\nIngrese el dia(AA): ", "\nError (Rango entre 1-28)", 1, dia_maximo, 3);
				}
				break;
			}

			if(retorno == 0)
			{
				retorno = utn_getNumber(anio, "\nIngrese el anio(YYYY): ", "\nError (Rango entre 2000 - 2020)", 2000, 2020, 3);
			}
		}
	}

	return retorno;
}


void mostrarServicio(eServicio servicio)
{
	printf("\n%-5d   %-15s %-10.3f",servicio.id, servicio.descripcion, servicio.precio);
}


void mostrarServicios(eServicio* list, int len)
{
	if(list != NULL)
	{
		printf("\n**Listado de servicios**");
		printf("\nId      Descripcion     Precio");

		for(int i=0; i<len; i++)
		{
			mostrarServicio(list[i]);
		}
	}
}


void mostrarCliente(eCliente cliente)
{
	printf("\n%-3d %-15s %-15s",cliente.id, cliente.nombre, cliente.apellido);
}


void mostrarClientes(eCliente* list, int len)
{
	if(list != NULL)
	{
		printf("\n**Listado de clientes**");
		printf("\n\nId  Nombre          Apellido");

		for(int i=0; i<len; i++)
		{
			mostrarCliente(list[i]);
		}
	}
}


int searchFreeRepar(eReparacion* list, int len)
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


int cargadoReparaciones(eReparacion* list, int len)
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


int buscarReparacion(eReparacion* list, int len, int id)
{
	int retorno=-1;

		for(int i=0; i<len; i++)
		{
			if(list[i].serie==id)
			{
				retorno=0;
				break;
			}
		}
		return retorno;
}


int buscarServicioId(eServicio* list, int len, int id)
{
	int indice=-1;
		if(list != NULL)
		{
			for(int i=0;i<len;i++)
			{
				if (list[i].id==id)
				{
					indice=i;
					break;
				}
			}
		}
		return indice;
}


int buscarClienteId(eCliente* list, int len, int id)
{
	int indice=-1;
		if(list != NULL)
		{
			for(int i=0;i<len;i++)
			{
				if (list[i].id==id)
				{
					indice=i;
					break;
				}
			}
		}
		return indice;
}


int initReparaciones(eReparacion* list, int len)
{
	int retorno =-1;
		if(list != NULL && len>0)
		{
			for (int i=0; i<len; i++)
			{
				list[i].isEmpty=1;
			}
			retorno=0;
		}
		return retorno;
}


int altaReparacion(eReparacion* list, int len, eServicio* listServ, int lenServ, int id, eElectrodomestico* listElectrodomestico, int lenElectrodomestico, eMarca* listMarca, int lenMarca, eCliente* listCliente, int lenCliente)
{

	int todoOk=-1;
	int indice;
	int idElectrodomestico;
	int indiceElectrodomestico;
	int idServicio;
	int indiceServicio;
	int idCliente=-1;
	int indiceCliente;
	int anio;
	int mes;
	int dia;


	if((indice = searchFreeRepar(list, len))!=-1)
	{
		system("clear");
		printf("\n***Alta de reparacion***\n");
		printf("\nIndice %d",indice);

		mostrarElectrodomesticos(listElectrodomestico, lenElectrodomestico, listMarca, lenMarca);

		printf("\n\nIngrese el Id del electrodomestico a reparar: ");
		__fpurge(stdin);
		scanf("%d",&idElectrodomestico);
		indiceElectrodomestico = buscarElectrodomesticoId(listElectrodomestico, lenElectrodomestico, idElectrodomestico);
		if(indiceElectrodomestico == -1)
		{
			printf("\nNo existe electrodomestico con el numero de Id ingresado");
		}
		else
		{
			if(buscarReparacion(list, len, listElectrodomestico[indiceElectrodomestico].serie) != -1)
			{
				//si el electrodomestico ya fue reparado y tiene un cliente asignado
				printf("\nYa existen reparaciones para este electrodomestico");
				printf("\nId   Nombre y Apellido       NumSerie    Descripcion	  Fecha(dd/mm/aaaa)");
				for(int i=0; i<len; i++)
				{
					if(listElectrodomestico[indiceElectrodomestico].serie == list[i].serie)
					{
						indiceServicio = buscarServicioId(listServ, lenServ, list[i].idServicio);
						indiceCliente = buscarClienteId(listCliente, lenCliente, list[i].idCliente);
						mostrarReparacion(list[i], listCliente[indiceCliente], listServ[indiceServicio]);
					}
				}
				printf("\n\nEl cliente es:");
				mostrarCliente(listCliente[indiceCliente]);
				idCliente=listCliente[indiceCliente].id;
				printf("\n");
			}
			else
			{
				//primera reparacion del electrodomestico, pedimos cliente a quien pertenece
				mostrarClientes(listCliente, lenCliente);
				printf("\n\nIngrese el Id del cliente: ");
				__fpurge(stdin);
				scanf("%d",&idCliente);
				indiceCliente = buscarClienteId(listCliente, lenCliente, idCliente);
			}
			if(indiceCliente == -1)
			{
				printf("\nNo existe cliente con el numero de Id ingresado");
			}
			else
			{
				mostrarServicios(listServ, lenServ);
				printf("\n\nIngrese el Id del servicio a realizar: ");
				__fpurge(stdin);
				scanf("%d",&idServicio);
				indiceServicio = buscarServicioId(listServ, lenServ, idServicio);
				if(indiceServicio == -1)
				{
					printf("\nNo existe servicio con el numero de Id ingresado");
				}
				else
				{
					if(fechaActual(&dia, &mes, &anio)==-1)
					{
						printf("\nNo existe la fecha ingresada");
					}
					else
					{
						list[indice].id=id;
						list[indice].fecha.dia=dia;
						list[indice].fecha.anio=anio;
						list[indice].fecha.mes=mes;
						list[indice].idServicio=idServicio;
						list[indice].serie=listElectrodomestico[indiceElectrodomestico].serie;
						list[indice].idCliente=idCliente;
						list[indice].isEmpty=0;
						todoOk=0;
					}
				}
			}
		}
	}
	else
	{
		printf("\nSistema de reparaicones completo(expandir)");
	}

return todoOk;
}


void mostrarReparacion(eReparacion list, eCliente listCliente, eServicio listServ)
{
	printf("\n%-2d   %-12s %-9s  %04d        %-15s  %02d/%02d/%02d",list.id, listCliente.nombre, listCliente.apellido, list.serie, listServ.descripcion , list.fecha.dia, list.fecha.mes, list.fecha.anio);
}


void mostrarReparaciones(eReparacion* list, int len, eElectrodomestico* listElec, int lenElec, eServicio* listServ, int lenServ, eCliente* listCliente, int lenCliente)
{
	int indiceServicio;
	int indiceCliente;

	if(list != NULL)
	{
		printf("\n**Listado de reparaciones**");
		printf("\nId   Nombre y Apellido       NumSerie    Descripcion	  Fecha(dd/mm/aaaa)");

		for(int i=0; i<len; i++)
		{
			indiceServicio = buscarServicioId(listServ, lenServ, list[i].idServicio);
			indiceCliente = buscarClienteId(listCliente, lenCliente, list[i].idCliente);

			if(list[i].isEmpty==0)
			{
				mostrarReparacion(list[i], listCliente[indiceCliente], listServ[indiceServicio]);

			}
		}
	}
}

void mostrarReparacionesById(eReparacion* list, int len, eElectrodomestico* listElec, int lenElec, eServicio* listServ, int lenServ, eCliente* listCliente, int lenCliente, int serie)
{
	int indiceServicio;
	int indiceCliente;
	int flag=0;

	if(list != NULL)
	{
		printf("\n**Listado de reparaciones por electrodomestico**");
		printf("\nId   Nombre y Apellido       NumSerie    Descripcion	  Fecha(dd/mm/aaaa)");

		for(int i=0; i<len; i++)
		{
			indiceServicio = buscarServicioId(listServ, lenServ, list[i].idServicio);
			indiceCliente = buscarClienteId(listCliente, lenCliente, list[i].idCliente);
			if(list[i].serie==serie && list[i].isEmpty==0)
			{
				mostrarReparacion(list[i], listCliente[indiceCliente], listServ[indiceServicio]);
				flag=1;
			}
		}

		if(!flag)
		{
			printf("\nNo hay reparaciones para el electrodomestico seleccionado");
		}
	}
}


void mostrarElecNoRepar(eReparacion* list, int len, eElectrodomestico* listElec, int lenElec, eServicio* listServ, int lenServ, eCliente* listCliente, int lenCliente, eMarca* listMarca, int lenMarca)
{
	int flag=0;

	if(list != NULL)
	{
		printf("\n**Listado de electrodomesticos sin reparaciones**");
		printf("\nId   NumSerie  Marca    Modelo(anio)");

		for(int i=0; i<lenElec; i++)
		{
			flag=0;
			for(int j=0; j<len; j++)
			{
				if(listElec[i].serie==list[j].serie && listElec[i].isEmpty ==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				mostrarElectrodomestico(listElec[i], listMarca, lenMarca);
			}
		}
	}
}


void totalCostoReparById(eElectrodomestico* listElec, int lenElec, eReparacion* listRepar, int lenRepar, eServicio* listServ, int lenServ, eMarca* listMarcas, int lenMarcas)
{
	int serie;
	float acumulador=0;

	serie = getIdElectro(listElec, lenElec, listMarcas, lenMarcas);

	if(serie !=-1)
	{
		serie=listElec[serie].serie;
		for(int i=0; i<lenRepar; i++)
		{
			if(listRepar[i].serie==serie && listRepar[i].isEmpty==0)
			{
				for(int j=0; j<lenServ; j++)
				{
					if(listRepar[i].idServicio==listServ[j].id)
					{
						acumulador= acumulador + listServ[j].precio;
						break;
					}
				}

			}
		}
	}

	printf("\nEl coste total de las reparaciones para el electrodomestico seleccionado es: $ %f",acumulador);
}


int contarReparaciones(int idServicio, eReparacion* listRepar, int lenRepar)
{
	int cantidad=0;
	for(int i=0; i<lenRepar ;i++)
	{
		if(listRepar[i].idServicio == idServicio && listRepar[i].isEmpty==0)
		{
			cantidad++;
		}
	}

	return cantidad;
}


void servicioMasPedido(eServicio* listServ, int lenServ, eReparacion* listRepar, int lenRepar)
{
	int servicios[lenServ];
	int mayor;
	int flag=0;
	printf("\n**Servicio mas solocitado**");

	for(int i=0; i<lenServ;i++)
	{
		servicios[i]=contarReparaciones(listServ[i].id, listRepar, lenRepar);
	}

	for(int i=0; i<lenServ; i++)
	{
		if(mayor<servicios[i] || flag==0)
		{
			mayor=servicios[i];
			flag=1;
		}
	}

	for(int i=0; i<lenServ; i++)
	{
		if(servicios[i]==mayor)
		{
			printf("\nEl servicios mas solicitado es %s", listServ[i].descripcion);
		}
	}

	printf("\nCantidad de veces solicitado %d", mayor);
}


void totalCostoRepar(eElectrodomestico* listElec, int lenElec, eReparacion* listRepar, int lenRepar, eServicio* listServ, int lenServ, eMarca* listMarcas, int lenMarcas)
{
	float acumulador=0;

	for(int i=0; i<lenRepar;i++)
	{
		for(int j=0; j<lenServ; j++)
		{
			if(listRepar[i].idServicio==listServ[j].id)
			{
				acumulador= acumulador + listServ[j].precio;
				break;
			}
		}
	}
	printf("\nEl coste total de todas las reparaciones es: $ %f",acumulador);
}

void recaudacionByFecha(eServicio* listServ, int lenServ, eReparacion* listRepar, int lenRepar)
{
	int dia;
	int mes;
	int anio;
	int acumulador=0;
	int todoOk=-1;

	todoOk=pedirFecha(&anio, &mes, &dia);

	if(todoOk==0)
	{
		for(int i=0; i<lenRepar; i++)
		{
			if(listRepar[i].fecha.anio== anio)
			{
				if(listRepar[i].fecha.mes== mes)
				{
					if(listRepar[i].fecha.dia== dia)
					{
						for(int j=0; j<lenServ; j++)
						{
							if(listRepar[i].idServicio == listServ[j].id)
							{
								acumulador = acumulador + listServ[j].precio;
							}
						}
					}
				}
			}
		}
		printf("\nLa recaudacion total para la fecha %d/%d/%d fue de $%d",dia,mes,anio,acumulador);
	}
	else
	{
		printf("\nERROR al ingresar la fecha");
	}
}

void mostrarReparElectro2018(eCliente* listCliente, int lenCliente, eReparacion* list, int len, eElectrodomestico* listElec, int lenElec, eServicio* listServ, int lenServ, eMarca* listMarcas, int lenMarcas)
{

	int indiceServicio;
	int indiceCliente;
	if (list != NULL)
	{
		printf("\n**Listado de reparaciones a electrodomesticos del anio 2018(modelo)**");
		printf("\n**Listado de reparaciones**");
		printf("\nId   Nombre y Apellido       NumSerie    Descripcion	  Fecha(dd/mm/aaaa)");
		for(int i=0; i<len; i++)
		{
			for(int j=0; j<lenElec; j++)
			{
				if(list[i].serie==listElec[j].serie)
				{
					if(listElec[j].modelo==2018)
					{
						for(int k=0; k<lenServ; k++)
						{
							if(listServ[k].id==list[i].idServicio)
							{
								indiceServicio = buscarServicioId(listServ, lenServ, list[i].idServicio);
								indiceCliente = buscarClienteId(listCliente, lenCliente, list[i].idCliente);

								if(list[i].isEmpty==0)
								{
									mostrarReparacion(list[i], listCliente[indiceCliente], listServ[indiceServicio]);
								}
							}
						}
					}
				}
			}
		}
	}
}

void reparacionFecha(eCliente* listCliente, int lenCliente, eServicio* listServ, int lenServ, eReparacion* listRepar, int lenRepar, eElectrodomestico* listElec, int lenElec, eMarca* listMarca, int lenMarca)
{
	int indiceServicio;
	int indiceCliente;
	printf("\n**Listado de garantias**");
	printf("\nId   Nombre y Apellido       NumSerie    Descripcion	  Fecha(dd/mm/aaaa)");
	for(int i=0; i<lenRepar; i++)
	{
		if(listRepar[i].idServicio==20000)
		{
			for(int k=0; k<lenElec; k++)
			{
				if(listRepar[i].serie == listElec[k].serie)
				{
					indiceServicio = buscarServicioId(listServ, lenServ, listRepar[i].idServicio);
					indiceCliente = buscarClienteId(listCliente, lenCliente, listRepar[i].idCliente);

					if(listRepar[i].isEmpty==0)
					{
						mostrarReparacion(listRepar[i], listCliente[indiceCliente], listServ[indiceServicio]);

					}
				}
			}
		}
	}
}





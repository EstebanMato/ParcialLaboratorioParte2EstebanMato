#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utnInputs.h"
#include "reparacion.h"
#include "electrodomestico.h"
#define TAMMARCAS 5
#define TAMELEC 10
#define TAMSERV 4
#define TAMREPAR 25
#define TAMCLIE 5


int main(void) {
	setbuf(stdout, NULL);

	int todoOk;
	int todoOkRepar;
	int idElectrodomestico=1;
	int idReparacion = 1;
	int serie=-1;
	char salir ='n';
	char salirInformes='n';

	eMarca arrayMarcas[TAMMARCAS]= {{1000,"Whirpool"},
							        {1001,"Sony"},
							        {1002,"Liliana"},
							        {1003,"Gafa"},
							        {1004,"Philips"},
	};


	eServicio arrayServicios [TAMSERV] = {{20000,"Garantia",250},
									      {20001,"Mantenimiento",500},
									      {20002,"Repuesto",400},
									      {20003,"Refaccion",600},
	};


	eCliente arrayClientes [TAMCLIE] = {{10,"Franco","Armani"},
										{11,"Milton","Casco"},
										{12,"Ignacio","Fernandez"},
										{13,"Rafel Santos","Borre"},
										{14,"Marcelo","Gallardo"}
	};


	eElectrodomestico arrayElectrodomesticos [TAMELEC];
	eReparacion arrayReparaciones [TAMREPAR];

	todoOkRepar = initReparaciones(arrayReparaciones, TAMREPAR);
	//hardcodeo de reparacion max 8
	//idReparacion = idReparacion + hardcodearReparaciones(arrayReparaciones, TAMREPAR, 8);

	todoOk = initElectrodomesticos(arrayElectrodomesticos, TAMELEC);
	//hardcodeo de electro max 10
	//idElectrodomestico= idElectrodomestico + hardcodearElectrodomesticos(arrayElectrodomesticos, TAMELEC, 10);


	if(todoOk==0 && todoOkRepar ==0)
	{
		do{
			switch(menu()){
				case 1:
					if(altaElectrodomestico(arrayElectrodomesticos, TAMELEC, idElectrodomestico, arrayMarcas, TAMMARCAS)==0){
						idElectrodomestico++;
						printf("\nElectrodomestico dado de alta correctamente!");
					}else{
						printf("\nError! (no fue dado de alta ningun electrodomestico)");
					}
					break;

				case 2:
					if(cargadoArrayElectrodomestico(arrayElectrodomesticos, TAMELEC)){
						modifyElectrodomestico(arrayElectrodomesticos, TAMELEC, arrayMarcas, TAMMARCAS);
					}else{
						printf("\nError! (Primero debe darse de alta un electrodomestico)");
					}
					break;

				case 3:
					if(cargadoArrayElectrodomestico(arrayElectrodomesticos, TAMELEC)){
						lowElectrodomestico(arrayElectrodomesticos, TAMELEC, arrayMarcas, TAMMARCAS);
					}else{
						printf("\nError! (Primero debe darse de alta un electrodomestico)");
					}
					break;

				case 4:
					if(cargadoArrayElectrodomestico(arrayElectrodomesticos, TAMELEC)){
						mostrarElectrodomesticos(arrayElectrodomesticos, TAMELEC, arrayMarcas, TAMMARCAS);
					}else{
						printf("\nError! (Primero debe darse de alta un electrodomestico)");
					}
					break;

				case 5:
					mostrarMarcas(arrayMarcas, TAMMARCAS);
					break;

				case 6:
					mostrarServicios(arrayServicios, TAMSERV);
					break;

				case 7:
					if(cargadoArrayElectrodomestico(arrayElectrodomesticos, TAMELEC))
					{
						if(altaReparacion(arrayReparaciones, TAMREPAR, arrayServicios, TAMSERV, idReparacion, arrayElectrodomesticos, TAMELEC,  arrayMarcas, TAMMARCAS, arrayClientes, TAMCLIE)==0)
						{
							idReparacion++;
							printf("\nReparacion dada de alta correctamente!");
						}
						else
						{
							printf("\nError! (no fue dado de alta ninguna reparacion)");
						}
					}else
					{
						printf("\nError! (Primero debe darse de alta un electrodomestico)");
					}
					break;

				case 8:
					if(cargadoReparaciones(arrayReparaciones, TAMREPAR) && cargadoArrayElectrodomestico(arrayElectrodomesticos, TAMELEC) ){
						mostrarReparaciones(arrayReparaciones, TAMREPAR, arrayElectrodomesticos, TAMELEC, arrayServicios, TAMSERV, arrayClientes, TAMCLIE);
					}else{
						printf("\nError! (Primero debe darse de alta un electrodomestico y una reparacion)");
					}
					break;

				case 9:
					printf("\nConfirma que desea salir del sistema? (s/n): ");
					__fpurge(stdin);
					scanf("%c", &salir);
					break;

				case 10:
					do{
						switch(menuInformes()){
						case 1:
							mostrarElectro2020(arrayElectrodomesticos, TAMELEC, arrayMarcas, TAMMARCAS, 2020);
							break;

						case 2:
							mostrarElectroMarca(arrayElectrodomesticos, TAMELEC, arrayMarcas, TAMMARCAS);
							break;

						case 3:

							serie = getIdElectro(arrayElectrodomesticos, TAMELEC,arrayMarcas, TAMMARCAS);
							if(serie !=-1)
							{
								serie=arrayElectrodomesticos[serie].serie;
								mostrarReparacionesById(arrayReparaciones, TAMREPAR, arrayElectrodomesticos, TAMELEC, arrayServicios, TAMSERV, arrayClientes, TAMCLIE, serie );
							}
							break;

						case 4:
							mostrarElecNoRepar(arrayReparaciones, TAMREPAR, arrayElectrodomesticos, TAMELEC, arrayServicios, TAMSERV, arrayClientes, TAMCLIE, arrayMarcas, TAMMARCAS);
							break;

						case 5:
							totalCostoReparById(arrayElectrodomesticos, TAMELEC,arrayReparaciones, TAMREPAR, arrayServicios, TAMSERV, arrayMarcas, TAMMARCAS);
							break;

						case 6:
							servicioMasPedido(arrayServicios, TAMSERV, arrayReparaciones, TAMREPAR);
							break;

						case 7:
							recaudacionByFecha(arrayServicios, TAMSERV, arrayReparaciones, TAMREPAR);
							break;

						case 8:
							reparacionFecha(arrayClientes, TAMCLIE, arrayServicios, TAMSERV, arrayReparaciones, TAMREPAR, arrayElectrodomesticos, TAMELEC, arrayMarcas, TAMMARCAS);
							break;

						case 9:
							mostrarReparElectro2018(arrayClientes, TAMCLIE, arrayReparaciones, TAMREPAR, arrayElectrodomesticos, TAMELEC, arrayServicios, TAMSERV, arrayMarcas, TAMMARCAS);
							break;

						case 10:
							totalCostoRepar(arrayElectrodomesticos, TAMELEC,arrayReparaciones, TAMREPAR, arrayServicios, TAMSERV, arrayMarcas, TAMMARCAS);
							break;



						case 99:
							printf("\nConfirma que desea salir del sistema? (s/n): ");
							__fpurge(stdin);
							scanf("%c", &salirInformes);
							break;
						}

					__fpurge(stdin);
					getchar();
					}while(salirInformes!='s');
					break;

				default:
					printf("\nOPCION INVALIDA");
			}

			__fpurge(stdin);
			getchar();
		}while(salir!='s');
	}
	else
	{
		system("clear");
		printf("\nERROR AL INICIAR EL ARRAY\n\n");
		getchar();
	}

	getchar();
	return EXIT_SUCCESS;
}



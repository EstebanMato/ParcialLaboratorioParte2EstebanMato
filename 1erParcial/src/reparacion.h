#include "electrodomestico.h"

#ifndef REPARACION_H_
#define REPARACION_H_

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int id;//comienza en 20000
	char descripcion[26];
	float precio;
}eServicio;

typedef struct{
	int id;//autoincremental
	int serie;//validar
	int idServicio;//validar
	eFecha fecha;//validar dia mes y anio
	int idCliente;//id de cliente, validar que este
	int isEmpty;
}eReparacion;

typedef struct{
	int id;
	char nombre[51];
	char apellido[51];
}eCliente;

#endif /* REPARACION_H_ */


/** \brief Hardcodea un array
 *
 * @param listRepar
 * @param lenRepar
 * @param cantidad
 * @return
 */
int hardcodearReparaciones(eReparacion* listRepar, int lenRepar, int cantidad);


/** \brief Carga la fecha actual en las variables pasadas como parametro
 *
 * @param dia, int
 * @param mes, int
 * @param anio, int
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int fechaActual(int* dia, int* mes, int* anio);


/** \brief solicita una fecha al usuario
 *
 * @param anio
 * @param mes
 * @param dia
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int pedirFecha(int* anio, int* mes, int* dia);


/** \brief imprime por pantalla la entidad recibida por parametro
 *
 * @param servicio
 */
void mostrarServicio(eServicio servicio);


/** \brief imprime por pantalla el array pasado por parametro
 *
 * @param list puntero al array
 * @param len longitud de array
 */
void mostrarServicios(eServicio* list, int len);


/** \brief imprime por pantalla la entidad recibida por parametro
 *
 * @param cliente
 */
void mostrarCliente(eCliente cliente);


/** \brief imprime por pantalla el array pasado por parametro
 *
 * @param list
 * @param len
 */
void mostrarClientes(eCliente* list, int len);


/** \brief Busca la primer posicion libre en el array
 *
 * @param list puntero al array
 * @param len longitud del array
 * @return int Retorna -1 ERROR, indice del array libre de la primer posicion libre
 */
int searchFreeRepar(eReparacion* list, int len);


/** \brief Verifica si hay al menos una entidad cargada en el array, isEmpty en 0
 *
 * @param list puntero al array
 * @param len longitud del array
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int cargadoReparaciones(eReparacion* list, int len);


/** \brief busca la primera entidad en el array que coincida con el id pasado como parametro
 *
 * @param list
 * @param len
 * @param id
 * @return  int Retorna -1 ERROR, indice de la primera ocurrencia del array
 */
int buscarReparacion(eReparacion* list, int len, int id);


/** \brief busca una entidad por id, el cual es recibido como parametro
 *
 * @param list puntero al array
 * @param len longitud del array
 * @param id int
 * @return int Retorna -1 ERROR, indice del array donde coincide con el id pasado
 */
int buscarServicioId(eServicio* list, int len, int id);


/** \brief busca una entidad por id, el cual es recibido como parametro
 *
 * @param list puntero al array
 * @param len longitud del array
 * @param id int
 * @return int Retorna -1 ERROR, indice del array donde coincide con el id pasado
 */
int buscarClienteId(eCliente* list, int len, int id);


/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
 * 		   (isEmpty) en TRUE en todas las posiciones del array.
 *
 * @param list puntero al array
 * @param len longitud del array
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int initReparaciones(eReparacion* list, int len);


/** \brief pide los datos para la alta de una nueva entidad
 *
 * @param list puntero al array
 * @param len longitud del array
 * @param listServ
 * @param lenServ
 * @param id
 * @param listElectrodomestico
 * @param lenElectrodomestico
 * @param listMarca
 * @param lenMarca
 * @param listCliente
 * @param lenCliente
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int altaReparacion(eReparacion* list, int len, eServicio* listServ, int lenServ, int id, eElectrodomestico* listElectrodomestico, int lenElectrodomestico, eMarca* listMarca, int lenMarca, eCliente* listCliente, int lenCliente);


/** \brief imprime por pantalla la entidad recibida como parametro
 *
 * @param list puntero al array
 * @param listCliente
 * @param listServ
 */
void mostrarReparacion(eReparacion list, eCliente listCliente, eServicio listServ);


/** \brief imprime por pantalla el array pasado por parametro
 *
 * @param list puntero al array
 * @param len longitud del array
 * @param listElec
 * @param lenElec
 * @param listServ
 * @param lenServ
 * @param listCliente
 * @param lenCliente
 */
void mostrarReparaciones(eReparacion* list, int len, eElectrodomestico* listElec, int lenElec, eServicio* listServ, int lenServ, eCliente* listCliente, int lenCliente);

/**
 *
 * @param list
 * @param len
 * @param listElec
 * @param lenElec
 * @param listServ
 * @param lenServ
 * @param listCliente
 * @param lenCliente
 * @param serie
 */
void mostrarReparacionesById(eReparacion* list, int len, eElectrodomestico* listElec, int lenElec, eServicio* listServ, int lenServ, eCliente* listCliente, int lenCliente, int serie);


/**
 *
 * @param list
 * @param len
 * @param listElec
 * @param lenElec
 * @param listServ
 * @param lenServ
 * @param listCliente
 * @param lenCliente
 * @param listMarca
 * @param lenMarca
 */
void mostrarElecNoRepar(eReparacion* list, int len, eElectrodomestico* listElec, int lenElec, eServicio* listServ, int lenServ, eCliente* listCliente, int lenCliente, eMarca* listMarca, int lenMarca);


/**
 *
 * @param listElec
 * @param lenElec
 * @param listRepar
 * @param lenRepar
 * @param listServ
 * @param lenServ
 * @param listMarcas
 * @param lenMarcas
 */
void totalCostoReparById(eElectrodomestico* listElec, int lenElec, eReparacion* listRepar, int lenRepar, eServicio* listServ, int lenServ, eMarca* listMarcas, int lenMarcas);


/**
 *
 * @param idServicio
 * @param listRepar
 * @param lenRepar
 * @return
 */
int contarReparaciones(int idServicio, eReparacion* listRepar, int lenRepar);


/**
 *
 * @param listServ
 * @param lenServ
 * @param listRepar
 * @param lenRepar
 */
void servicioMasPedido(eServicio* listServ, int lenServ, eReparacion* listRepar, int lenRepar);


/**
 *
 * @param listElec
 * @param lenElec
 * @param listRepar
 * @param lenRepar
 * @param listServ
 * @param lenServ
 * @param listMarcas
 * @param lenMarcas
 */
void totalCostoRepar(eElectrodomestico* listElec, int lenElec, eReparacion* listRepar, int lenRepar, eServicio* listServ, int lenServ, eMarca* listMarcas, int lenMarcas);


/**
 *
 * @param listServ
 * @param lenServ
 * @param listRepar
 * @param lenRepar
 */
void recaudacionByFecha(eServicio* listServ, int lenServ, eReparacion* listRepar, int lenRepar);


/**
 *
 * @param listCliente
 * @param lenCliente
 * @param list
 * @param len
 * @param listElec
 * @param lenElec
 * @param listServ
 * @param lenServ
 * @param listMarcas
 * @param lenMarcas
 */
void mostrarReparElectro2018(eCliente* listCliente, int lenCliente, eReparacion* list, int len, eElectrodomestico* listElec, int lenElec, eServicio* listServ, int lenServ, eMarca* listMarcas, int lenMarcas);


/**
 *
 * @param listCliente
 * @param lenCliente
 * @param listServ
 * @param lenServ
 * @param listRepar
 * @param lenRepar
 * @param listElec
 * @param lenElec
 * @param listMarca
 * @param lenMarca
 */
void reparacionFecha(eCliente* listCliente, int lenCliente, eServicio* listServ, int lenServ, eReparacion* listRepar, int lenRepar, eElectrodomestico* listElec, int lenElec, eMarca* listMarca, int lenMarca);


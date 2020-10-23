#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

typedef struct{
	int id;//comienza en 1000
	char descripcion[21];
}eMarca;

typedef struct{
	int id;
	int serie;
	int idMarca; //validar
 	int modelo; //año de fabricacion
 	int isEmpty;
}eElectrodomestico;

#endif /* ELECTRODOMESTICO_H_ */


/** \brief busca la primer coincidencia en el array con el id pasado como parametro
 *
 * @param list puntero al array
 * @param len longitud del array
 * @param id int, id pasado por parametro
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int buscarElectroSerie(eElectrodomestico* list, int len, int id);


/** \brief Hardcodea un array
 *
 * @param listElec,
 * @param lenElec,
 * @param cantidad,
 * @return
 */
int hardcodearElectrodomesticos(eElectrodomestico* listElec, int lenElec, int cantidad);


/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
 * 		   (isEmpty) en TRUE en todas las posiciones del array.
 *
 * @param list,  Puntero al array
 * @param len, Longitud del array
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int initElectrodomesticos(eElectrodomestico* list, int len);


/** \brief Verifica si hay al menos una entidad cargada en el array, isEmpty en 0
 *
 * @param list, Puntero al array
 * @param len, longitud del array
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int cargadoArrayElectrodomestico(eElectrodomestico* list, int len);


/** \brief Agrega al array existente, los valores recibidos como parámetro en la primer posición libre.
 *
 * @param list longitud del array
 * @param id int
 * @param indice int
 * @param serie int
 * @param idMarca int
 * @param modelo int
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int addElectrodomestico(eElectrodomestico* list, int id, int indice, int serie, int idMarca, int modelo);


/** \brief Busca la primer posicion libre en el array
 *
 * @param list puntero al array
 * @param len longitud del array
 * @return int Retorna -1 ERROR, indice del array libre de la primer posicion libre
 */
int searchFree(eElectrodomestico* list, int len);


/** \brief busca la primer coincidencia en el array con el id pasado como parametro
 *
 * @param list puntero al array
 * @param len longitud del array
 * @param id int, id pasado por parametro
 * @return int Retorna -1 ERROR, indice del array donde coincide con el id
 */
int searchMarca(eMarca* list, int len, int id);


/** \brief imprime por pantalla la entidad recibida por parametro
 *
 * @param marca
 */
void mostrarMarca(eMarca marca);


/** \brief imprime por pantalla el array pasado por parametro
 *
 * @param list puntero al array
 * @param len longitud de array
 */
void mostrarMarcas(eMarca* list, int len);


/** \brief orderna el array pasado por parametro
 *
 * @param list puntero al array
 * @param len longitud del array
 */
void ordenarElectrodomestico(eElectrodomestico* list, int len);


/** \brief imprime por pantalla el array pasado por parametro
 *
 * @param electrodomestico
 * @param listMarca longitud del array
 * @param lenMarca
 */
void mostrarElectrodomestico(eElectrodomestico electrodomestico, eMarca* listMarca, int lenMarca);


/** \brief imprime por pantalla el array pasado por parametro
 *
 * @param list puntero al array
 * @param len longitud del array
 * @param listMarca
 * @param lenMarca
 */
void mostrarElectrodomesticos(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca);


/** \brief pide los datos para la alta de una nueva entidad
 *
 * @param listElectro puntero al array
 * @param lenElec
 * @param id
 * @param listMarcas
 * @param lenMarca
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int altaElectrodomestico(eElectrodomestico* listElectro, int lenElec, int id, eMarca* listMarcas, int lenMarca);


/** \brief busca una entidad por id, el cual es recibido como parametro
 *
 * @param list puntero al array
 * @param len longitud del array
 * @param id int
 * @return int Retorna -1 ERROR, indice del array donde coincide con el id pasado
 */
int buscarElectrodomesticoId(eElectrodomestico* list, int len, int id);


/** \brief realiza la modificacion de una entidad ya cargada en el array
 *
 * @param list puntero al array
 * @param len longitud del array
 * @param listMarca
 * @param lenMarca
 */
void modifyElectrodomestico(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca);


/** \brief realiza la baja logica de una entidad ya cargada en el array
 *
 * @param list puntero al array
 * @param len longitud del array
 * @param listMarca
 * @param lenMarca
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int lowElectrodomestico(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca);


/** \brief realiza la baja logica de una entidad ya cargada en el array, la cual recibe por parametro su id
 *
 * @param list ppuntero al array
 * @param len longitud del array
 * @param listMarca
 * @param lenMarca
 * @param idElectrodomestico int
 * @return int Retorna -1 ERROR, 0 EXITO
 */
int removeElectrodomestico(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca, int idElectrodomestico);

/**
 *
 * @param list
 * @param len
 * @param listMarca
 * @param lenMarca
 * @param anio
 */
void mostrarElectro2020(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca , int anio);


/**
 *
 * @param list
 * @param len
 * @param listMarca
 * @param lenMarca
 */
void mostrarElectroMarca(eElectrodomestico* list, int len, eMarca* listMarca, int lenMarca);


/**
 *
 * @param listElec
 * @param lenElec
 * @param listMarcas
 * @param lenMarcas
 * @return
 */
int getIdElectro(eElectrodomestico* listElec, int lenElec, eMarca* listMarcas, int lenMarcas);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int nextId);

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

int controller_removePassenger(LinkedList* pArrayListPassenger);

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_listPassenger(LinkedList* pArrayListPassenger);

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

int controller_findPassengerById(LinkedList* pArrayListPassenger, int id);

int controller_getNextId(LinkedList* pArrayListPassenger);


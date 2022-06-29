/*
 * controller.h
 *
 *  Created on: 28 jun. 2022
 *      Author: Hugo
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(LinkedList* pArrayListComputer);
int controller_listComputer(LinkedList* pArrayListComputer);
int controller_saveAsText(char* path, LinkedList* pArrayListComputer);


#endif /* CONTROLLER_H_ */

/*
 * stackinha.h
 *
 *  Created on: Aug 26, 2010
 *      Author: aurelio
 */

#ifndef STACKINHA_H_
#define STACKINHA_H_


typedef struct stinode {
	struct stinode* next;
	void* data;
} stinode;

int sticreate ( stinode **stack );
int stipush ( stinode **stack, void* data );
int stipop ( stinode **stack, void** data );
int stidestroy ( stinode **stack );

typedef void (*callback)(stinode** stack);
void traverse ( stinode** stack, callback func );



#endif /* STACKINHA_H_ */

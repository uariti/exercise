#include <stdlib.h>
#include "stackinha.h"

int sticreate ( stinode **stack )
{
	*stack = NULL;
	return 1;
}



int stipush(stinode **stack, void *data)
{
	stinode* el = *stack;
	*stack= (stinode*) malloc(sizeof(stinode));
	(*stack)->next = el;
	(*stack)->data = data;
	return 1;
}



int stipop(stinode **stack, void** data )
{
	data = (*stack)->data;
	stinode* el = (*stack);
	(*stack) = (*stack)->next;
	free( el );
	return 1;
}

int destroy ( stinode **stack ) {
	stinode* el;
	while ( *stack ) {
		el = (*stack)->next;
		free ( *stack );
        (*stack) = el;
	}
	return 1;
}

void traverse ( stinode** stack, callback func ) {
	while ( *stack ) {
		func( stack );
		*stack = (*stack)->next;
	}
}

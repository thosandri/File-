#include "file.h"
#include <stdio.h>
#include <stdlib.h>

// initialisation de la file

file* init(int x){
	
file* f=malloc(sizeof(file));           // allocation mémoire d'une file
element* elem=malloc(sizeof(element));	// allocation mémoire d'un élément

if ( f == NULL || elem == NULL)
{
	printf("Erreur allocation mémoire pile ou élément\n");
	exit(1);
}

elem->el=x;      // élément courant
elem->next=NULL;  // on pointe sur rien car premier élément

f->init=elem;   // premier élément de la file

return f;
	
}

void push(file* f,int x){
	


element* elem_new=malloc(sizeof(element));

if( f == NULL || elem_new == NULL )
{
	printf("Erreur pointeur sur file ou allocation élément \n");
	exit(1);
}

elem_new->el=x;
elem_new->next=NULL;

if (f->init != NULL)   // la liste n'est pas vide
{
	element* elem=f->init; // on pointe sur le premier
	
	while(elem->next != NULL)
	{
		elem=elem->next;
	}
	
	elem->next=elem_new;
}
else
{
	f->init=elem_new;
}
}
	
	
	

// fonction de supression du premier élément de la file
// paramètre : f pointeur sur file

void pop(file* f){
	
	if(f == NULL)
	{
		printf("Erreur pointeur sur file\n");
		exit(1);
	}
	
	// si il n'y a qu'un seul élément dans la file
	
	if( f->init->next == NULL)
	{
		free(f->init); // on libère la mémoire
	}
	else
	{
		element* elem=f->init->next; // on pointe sur le deuxième
		free(f->init);               // on libère la mémoire du premier élément de la liste
		f->init=elem;                // le premier devient  le second
	}
}

// supression de tous les éléments de la liste
// paramètre: f pointeur sur file

void delete(file* f){
	
	if(f == NULL)
	{
		printf("Erreur pointeur sur file\n");
		exit(1);
	}
	
	// Si il'y a qu'un seul élément dans la liste
	
	if(f->init->next == NULL)
	{
		free(f->init);  // on libère la mémoire du premier élément
		f=NULL;         // on libère la mémoire de la file
	}
	else
	{
		element* elem=f->init;  // on pointe sur le deuxième élément
		
		while( f->init != NULL)
		{
			elem=elem->next;
			free(f->init);   // on libère la mémoire du premier élément
			f->init=elem;    // on met à jour le premier
			
		}
		
		f=NULL;        // on libère la mémoire de la file
	}
}

// fonction d'affichage de la liste
// paramètre : f pointeur sur file

void print(file* f){
	
   if(f == NULL)
   {
	   printf("Erreur pointeur sur file\n");
	   exit(1);
   }
   
   element* elem=f->init;    // on pointe sur le premier
   
   while(elem != NULL)
   {
	   printf("%d\n",elem->el);
	   elem=elem->next;
   }
	
}

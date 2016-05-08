#ifndef FILE__
#define FILE__

/* création d'une structure file + 
   fonctions de gestion de la file */
   
typedef struct element element;
typedef struct file file;

// structure élément

struct element{
	
	int el;         // élément courant
	element* next; // pointeur sur l'élément suivant
};

struct file{
	
	element* init; // pointeur sur le premier élément de la liste
};

// fonctions de gestion de la liste

file* init(int x);  // initialisation de la file

void push(file* f,int x); // insertion d'un élément dans la file

void pop(file* f);   // supression du premier élément de la file

void delete(file* f);  // supression de tous lés éléments de la file

void print(file* f);   // affichage de la liste

#endif

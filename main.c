#include "file.h"
#include <stdio.h>

int main(int argc, char* argv[]){
	
	file* f=init(3);
	
	push(f,4);
	push(f,7);
	push(f,8);
	
	print(f);
	
	printf("\n");
	
	pop(f);
	
	print(f);
	
	delete(f);
	
	
	
	return 0;
}

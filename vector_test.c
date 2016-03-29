/**
 * Machine Problem 1
 * CS 241 - Spring 2016
 */
#include <stdio.h>
#include "vector.h"
#include "assert.h"
void help_print(Vector* vec)

{
	assert(vec); 
     if(vec->size==0)
     {puts("the vec is empty\n");
	return;		
	}
	int n= vec->size;
	for(int i=0; i<n; i++)
	{
		if(vec->array[i]!=NULL)
		printf("%s , %d \n", vec->array[i], i);
		else
		printf("this is entry is empty,%d\n",i);
	}
}



int main() { 
Vector* vec=Vector_create();
char a1[]="this is the first line.";
//append
for(int i=0; i<89;i++)
{
	Vector_append(vec,a1);
}
printf("capacity %zu\n",vec->capacity);
printf("size %zu\n",vec->size);

//help_print(vec);

Vector_resize(vec,170);

printf("capacity %zu\n",vec->capacity);
printf("size %zu\n",vec->size);

help_print(vec);



//delete

for(int i=0; i<14;i++)
{
Vector_delete(vec,0);
}
help_print(vec);

char a2[]="insert something here!";
Vector_insert(vec,0,a2);

char a3[]="";
Vector_insert(vec,2,a3);
help_print(vec);
Vector_insert(vec,26,a2);
help_print(vec);
const char* a4=Vector_get(vec,12);
printf("%s, %d\n",a4,12);//a4 can be null
char a5[]="set here";
Vector_set(vec, 34, a5);
printf("%zu\n",vec->capacity);
help_print(vec);

Vector_resize(vec, 67);
help_print(vec);
Vector_destroy(vec);
}

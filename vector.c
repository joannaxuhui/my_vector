<<<<<<< .mine
/**
 * Machine Problem 1
 * CS 241 - Spring 2016
 */

/* An automatically-expanding array of strings. */
#include "vector.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

#define INITIAL_CAPACITY 10

Vector *Vector_create() {
  // your code here
  Vector* a;
  a->capacity=10;
  a->array=(char**)calloc(10,char*);
  a->size=0;
  return a;
}

void Vector_destroy(Vector *vector) {
  assert(vector);
  for(int i=0;i<vector->size;i++)
  {
    //if(vector[i]!=NULL)
      //free(vector[i]);
    if(vector->array[i]!=NULL)
      free(vector->array[i]);
  }
  free(Vector->array);
  vector->size=0;
  vector->capacity=0;

}

size_t Vector_size(Vector *vector) {
  assert(vector);
  
  return vector->size;
}
//help function
/*void resize_(Vector* vector)
{    
  int ssize=vector->size;
  int cap=vector->capacity;

    char** a =(char**)calloc(2*vector->capacity,char*);
    for(int i=0;i < vector->capacity; i++)
    {
      a[i]=(char*)calloc(sizeof(vector[i]),char);
      for(int j=0; j<sizeof(vector[i]); j++)
      {
        a[i][j]=vector[i][j];
      }
    }
     Vector_destroy(vector);
     vector->array=a;
     vector->size=ssize;
     vector->capacity=2*cap;

}*/

void Vector_resize(Vector *vector, size_t new_size) {
  assert(vector);
  assert(new_size>=0);
  if(new_size==vector->size)
    return;
  if(new_size<vector->size)
  {
     for(int i=new_size; i<vector->size; i++)
      { if(vector->array[i]!=NULL)
        {
        free(vector->array[i]);
        vector->array[i]=NULL;
        }
      }
       vector->size=new_size;
  }
 else if(new_size>vector->size && vector->capacity>=new_size)
  {
    for(int i=vector->size; i<new_size; i++)
    {
        vector->array[i]=NULL;
    }
    vector->size=new_size;
  }
  else
  {
      while(new_size > vector->capacity)
      {  
       //resize_(vector);
        realloc(vector->array,2*vector->capacity);
         vector->capacity=2*vector->capacity;
      }
      for(int i=vector->size; i< new_size; i++)
      {
        vector->array[i]=NULL;
      }
      vector->size=new_size;
      }
}

void Vector_set(Vector *vector, size_t index, const char *str) {
  assert(vector);

 if(vector->size=capacity)
 {
      realloc(vector->array,2*vector->capacity);
      vector->capacity *=2;

    }
 if(index < vector->size)
 {
   
    for(int i=vector->size; i>index;i--)
    {
      vector->array[i]=vector->array[i-1];
    }
     if(str==NULL)
      vector->array[index]=NULL;
      else if(*str=='\0')
        vector->array[index]=NULL;
      else
      {

          vector[index]=malloc(sizeof(str),char);
          char * p=str;
          for(int j=0; j<sizeof(str);j++)
          {
            vector->array[index][j]=*p++;
          }
      }
      vector->size++;

 }
else if(index>=vector->size && index<vector->capacity)
 {
    if(str==NULL)
      vector->array[index]=NULL;
      else if(*str=='\0')
        vector->array[index]=NULL;
      else
      {

          vector[index]=malloc(sizeof(str),char);
          char * p=str;
          for(int j=0; j<sizeof(str);j++)
          {
            vector->array[index][j]=*p++;
          }
      }

      //default null
      vector->size= index+1;

 }
 else if(index>=vector->capacity)
 {
        
        while(index >=vector->capacity)
        {
            realloc(vector->array, 2*vector->capacity);
            vector->capacity=2*vector->capacity;
        }

        if(str==NULL)
      vector->array[index]=NULL;
      else if(*str=='\0')
        vector->array[index]=NULL;
      else
      {

          vector[index]=malloc(sizeof(str),char);
          char * p=str;
          for(int j=0; j<sizeof(str);j++)
          {
            vector->array[index][j]=*p++;
          }
      }

      vector->size=index+1;


 }
  // your code here
}

const char *Vector_get(Vector *vector, size_t index) {
  assert(vector);
  assert(index<vector->size);
  return vector->array[index];
}

void Vector_insert(Vector *vector, size_t index, const char *str) {
  assert(vector);
  if(vector->size==vector->capacity)
  {
    //resize_(vector);
    realloc(vector->array,vector->capacity*2);
    vector->capacity*=2;
  }
  if(index >= vector->capacity){
      while(index>=vector->capacity)
      {
        realloc(vector->array,vector->capacity*2);
        vector->capacity*=2;
      }
       if(str==NULL)
      vector->array[index]=NULL;
      else if(*str=='\0')
        vector->array[index]=NULL;
      else
      {

          vector[index]=malloc(sizeof(str),char);
          char * p=str;
          for(int j=0; j<sizeof(str);j++)
          {
            vector->array[index][j]=*p++;
          }
      }

      vector->size=index+1;
  }
 else  if(index>vector->size-1 && index <vector->capacity)
  {
    if(str==NULL)
    {
      vector->size=index+1;
    }
    else if(*str=='\0')
    {
      Vector->size=index+1;
    }
    else
    {
      vector[index]=(char*)calloc(sizeof(str),char);
      char* p=str;
      while(*p!='\0')
      {
        *vector[index]++=*p++;
      }
      vector->size=index+1;
    }

  }
  else //index< vector->size 
  {
    if(str==NULL)
      vector->array[index]=NULL;
    else if(*str=='\0')
      vector->array[index]=NULL;
    else
    {

          for(int i=vector->size; i>index; i--)
          {
            vector->array[i]=vector->array[i-1];

          }
          vector->array[index]=NULL;
            char* p=str;
            vector->array[index]=(char*)calloc(sizeof(str),char);
            while(*p!='\0')
            {
              *vector->array[index]++ = *p++;
            }

    }
    vector->size++;

  }
  
}

void Vector_delete(Vector *vector, size_t index) {
  assert(vector);

  assert(index<vector->size);
  assert(index >0);
  free(vector->array[index]);
  for(int i= index; i<vector->size;i++)
  {
    vector->array[i]=vector->array[i+1];
  }
  vector->size--;
  // your code here, what asserts might you want?
}

void Vector_append(Vector *vector, const char *str) {
  assert(vector);
  if(vector->size== vector->capacity)

    { 
      realloc(vector->array, vector->capacity*2);
      vector->capacity = vector->capacity *2;
    }
  int index=vector->size;
  if(str==NULL)
      vector->array[index]=NULL;
    else if(*str=='\0')
      vector->array[index]=NULL;
    else {vector[index]=malloc(sizeof(str),char);
          char * p=str;
          for(int j=0; j<sizeof(str);j++)
          {
            vector->array[index][j]=*p++;
          }
        }
        vector->size++;
  // your code here
}
=======
/**
 * Machine Problem 1
 * CS 241 - Spring 2016
 */
/* An automatically-expanding array of strings. */
#include "vector.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

#define INITIAL_CAPACITY 10
Vector *Vector_create() {
  Vector* a=malloc(sizeof(Vector));
  a->capacity=10;
  a->array=(char**)calloc(10,sizeof(char*));
  a->size=0;
  return a;
}

void Vector_destroy(Vector *vector) {
	assert(vector);
	for(size_t i=0;i<vector->size;i++)
	{
		if(vector->array[i]!=NULL)
		free(vector->array[i]);
	}
		free(vector->array);
		vector->size=0;
		vector->capacity=0;
		free (vector);
		vector=NULL;
}
size_t Vector_size(Vector *vector) {
  assert(vector);
  
  return vector->size;
}

void Vector_resize(Vector *vector, size_t new_size) {
  assert(vector);
  assert(new_size>=0);
	if(new_size==vector->size)
	return;
	if(new_size<vector->size)
	{
		for(size_t i=new_size; i<vector->size; i++)
		{ 
			if(vector->array[i]!=NULL)
			{
				free(vector->array[i]);
				vector->array[i]=NULL;
			}
		}
	vector->size=new_size;
	}
	else if(new_size>vector->size && vector->capacity>=new_size)
	{
   		for(size_t i=vector->size; i<new_size;i++)
		vector->array[i]=NULL;
		vector->size=new_size;
	}
	else
	{
			vector->array=realloc(vector->array,2*vector->capacity*sizeof(char*));
               for(size_t i=vector->capacity; i<2* vector->capacity; i++)
			vector->array[i]=NULL;
			
			vector->capacity=2*vector->capacity;
			Vector_resize(vector,new_size);	
	}
}

void Vector_set(Vector *vector, size_t index, const char *str) {
	assert(vector);
	assert(index>=0);
if(index < vector->capacity)
{
   if(vector->array[index]==NULL)
	{
		if(str!=NULL && *str!='\0')
		vector->array[index]=strdup(str);
	}
   else
	{
		free(vector->array[index]);
		vector->array[index]=NULL;
		if(str!=NULL && *str!='\0')
		vector->array[index]=strdup(str);
	}
    if(index >=vector->size)
	vector->size=index+1;
}
else
{  
	while(index >=vector->capacity)
	{
		 vector->array= realloc(vector->array, vector->capacity*2*sizeof(char*));
			 for(size_t i=vector->capacity; i<2* vector->capacity; i++)
			vector->array[i]=NULL;
		 vector->capacity*=2;
	}
	if(str!=NULL && *str!='\0')
	vector->array[index]=strdup(str);
	vector->size=index+1;
 }
}

const char *Vector_get(Vector *vector, size_t index) {
	assert(vector);
	assert(index<vector->size);
	assert(index>=0);
	return vector->array[index];
}

void Vector_insert(Vector *vector, size_t index, const char *str) {
  assert(vector);
  if(vector->size==vector->capacity)
  {
	vector->array= realloc(vector->array,vector->capacity*2*sizeof(char*));
	 for(size_t i=vector->capacity; i<2* vector->capacity; i++)
			vector->array[i]=NULL;
	vector->capacity*=2;
  }
  if(index >= vector->capacity){
 	while(index>=vector->capacity)
 	{
        vector->array= realloc(vector->array,vector->capacity*2*sizeof(char*));
		 for(size_t i=vector->capacity; i<2* vector->capacity; i++)
			vector->array[i]=NULL;
        vector->capacity*=2;
	}
	if(str==NULL)
	vector->array[index]=NULL;
	else if(*str=='\0')
	vector->array[index]=NULL;
	else
	{
		vector->array[index] = strdup(str); 
	}
	vector->size=index+1;
	}
else  if(index>vector->size-1 && index <vector->capacity)
	{
	if(str!=NULL && *str!='\0')
	vector->array[index]=strdup(str); 
	vector->size=index+1;
	}
  
	else //index< vector->size 
	{
		for(size_t i=vector->size; i>index; i--)
          {
		vector->array[i]=vector->array[i-1];
          }
          vector->array[index]=NULL;
          if(str!=NULL && *str!='\0')
          vector->array[index]=strdup(str);
		vector->size++;
	}
	//puts("insert!\n");
}

void Vector_delete(Vector *vector, size_t index) {
	assert(vector);
	assert(index<vector->size);
	assert(index >=0);
     
     char* p=vector->array[index];
     if(p==NULL)
	{
		;//puts("this is null!\n");
	}
     if(vector->array[index]!=NULL)
	{
		free(vector->array[index]);
		vector->array[index]=NULL;	
		//printf("delete !\n");	
     }
	for(size_t i= index; i<vector->size;i++)
	{
	vector->array[i]=vector->array[i+1];
	}
     
     vector->array[vector->size]=NULL;
	vector->size--;
}

void Vector_append(Vector *vector, const char *str) {
	assert(vector);
	if(vector->size == vector->capacity)
	{ 
		vector->array=(char**) realloc(vector->array, vector->capacity*2*sizeof(char*));
		vector->capacity = vector->capacity *2;
	}
	size_t index=vector->size;
	if(str==NULL)
		vector->array[index]=NULL;
	else if(*str=='\0')
		vector->array[index]=NULL;
	else {
		vector->array[index] = strdup(str);
	}
	vector->size+=1;
	//puts("append!");
}
>>>>>>> .r11717

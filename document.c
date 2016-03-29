/**
 * Machine Problem 1
 * CS 241 - Spring 2016
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "document.h"
#include "vector.h"

Document *Document_create() {
  Document *document = (Document *)malloc(sizeof(Document));
  document->vector = Vector_create();
  assert(document);
  return document;
}
/**
 * Writes the content of 'document' to a file named 'filename'.
 * For each line in 'document' write it to 'filename'.
 * If line exist then format it as so ("%s\n", line),
 * where line is a null terminated string.
 * If line does not exist, then simply write a new line in its place.
 *
 * Note that "" and NULL are considered equivalent by the vector.
 */

/**
 * Writes the content of 'document' to a file named 'filename'.
 * For each line in 'document' write it to 'filename'.
 * If line exist then format it as so ("%s\n", line),
 * where line is a null terminated string.
 * If line does not exist, then simply write a new line in its place.
 *
 * Note that "" and NULL are considered equivalent by the vector.
 */


void Document_write_to_file(Document *document, const char *filename) {
  assert(document);
  assert(filename);
<<<<<<< .mine

  
  // see the comment in the header file for a description of how to do this!
  // your code here!
=======
         {
			
	      fprintf(myfile,"%s\n", document->vector->array[i]);
		}
         else
	    fprintf(myfile,"\n");
	}
     
     fclose(myfile);
   
>>>>>>> .r18198
}

Document *Document_create_from_file(char *filename) {
   
  assert(filename);

  Document* document;
  document=Document_create();

  const char p ='r';
  FILE* myfile=fopen(filename,&p);

  assert(myfile!=NULL);
  
  char* a=NULL;
  size_t n=0;
  int read=0;
	while( (read=getline(&a,&n,myfile ) )!=-1)

	{
          if(a[read-1]=='\n')
		a[read-1]='\0';
		Vector_append(document->vector,a);
		
	}
	if(a!=NULL)
		free(a);	
	fclose(myfile);

	return document;

}

void Document_destroy(Document *document) {
  assert(document);
  Vector_destroy(document->vector);
  free(document);
}

size_t Document_size(Document *document) {
  assert(document);
  return Vector_size(document->vector);
}

void Document_set_line(Document *document, size_t index, const char *str) {
  assert(document);
  Vector_set(document->vector, index, str);
}

const char *Document_get_line(Document *document, size_t index) {
  assert(document);
  return Vector_get(document->vector, index);
}

void Document_insert_line(Document *document, size_t index, const char *str) {
  assert(document);
  Vector_insert(document->vector, index, str);
}

void Document_delete_line(Document *document, size_t index) {
  assert(document);
  Vector_delete(document->vector, index);
}

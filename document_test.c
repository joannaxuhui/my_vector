/**
 * Machine Problem 1
 * CS 241 - Spring 2016
 */

#include "document.h"
// test your document here

#include <stdio.h>
void help_print(Document* doc)
{
if(doc==NULL)
puts("failed.");
else
{
size_t size=doc->vector->size;
	for(size_t i=0; i<size; i++)
	{
		if(doc->vector->array[i]!=NULL)
			printf("%s\n",doc->vector->array[i]);
		else
		{
			puts("empty!\n");
		}
	}
}

}



int main() { 
	Document* doc=NULL;
	//Document* doc1=NULL;

	doc =Document_create_from_file("test.txt");
	//doc1=Document_create_from_file("test2.txt");
	//help_print(doc1);
     //help_print(doc);
	Document_write_to_file(doc,"write.txt");
    // Document_write_to_file(doc1,"write2.txt");
	Document_destroy(doc);
	//Document_destroy(doc1);
	return 0;
}

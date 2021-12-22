/*
 * Thao Phung
 * Robert Matthews
 * CS 250
 * November 12, 2018
 *
 * This module provides operations on a snippet list
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "snippet_list.h"

#define MAX_SNIPPETS 100

/* the struct that contains the information of a snippet */
struct snippet {
  char name[MAX_NAME_LENGTH];
  char addr[MAX_ADDRESS_LENGTH];
  char city[MAX_CITY_LENGTH];
  char state[STATE_LENGTH];
  unsigned int zip;
};

static struct snippet *snippet_list[MAX_SNIPPETS];
static int n_snippets = 0;

/* read the snippets in a text file into the snippet list */
void read_file (char *snippet_file)
{
   /* open the file to read */
  FILE *fp;
  fp = fopen(snippet_file, "r");

  /* check if file exist */
  if ( fp == NULL ) {
    printf("file not found");
    exit(-1);
  }

  char line[MAX_LINE_LENGTH];
  int initial_num_snippets;
  char name[MAX_NAME_LENGTH];
  char addr[MAX_ADDRESS_LENGTH];
  char city[MAX_CITY_LENGTH];
  char state[STATE_LENGTH];
  unsigned int zip;
  char *token;

  /* read the initial number of snippet from the text file */
  fgets(line, MAX_LINE_LENGTH,fp);
  sscanf(line, "%d\n", &initial_num_snippets);

  /* read the line that contains information of a snippet 
   * tokenize the line to get the desired information */
  while ( fgets(line, MAX_LINE_LENGTH,fp)) {
    token = strtok(line,":\n\t");
    strcpy ( name, token);  

    token = strtok(NULL, ":\n\t");   
    strcpy ( addr, token);

    token = strtok(NULL, ":\n\t");
    strcpy ( city, token);

    token = strtok(NULL, ":\n\t");
    strcpy ( state, token);

    token = strtok(NULL, ":\n\t");    
    sscanf(token, "%d", &zip);

    /* add the snippet with given information to the snippet list */
    add_snippet( name, addr, city, state, zip);
  }
  /* close the file */
  fclose (fp);
}
 
 /* add a snippet into the current snippet list */  
void add_snippet( char a_name[], char an_addr[], char a_city[],char a_state[]
		  , unsigned int a_zip)
{
  /* check if the list is full */
  if ( n_snippets == MAX_SNIPPETS ){
    printf("list full");
    return;
  }

  /* create a new snippet */
  /* declare a new struct pointer and allocate the memory for the struct it points to */
  struct snippet *new_snippet = (struct snippet*) malloc ( sizeof ( struct snippet));
  /* copy/assign the given information to the appropriate variable in the new struct */
  strcpy ( new_snippet -> name , a_name);
  strcpy ( new_snippet -> addr , an_addr);
  strcpy ( new_snippet -> city , a_city);
  strcpy ( new_snippet -> state , a_state);
  new_snippet -> zip = a_zip;

  /* add the new struct pointer to the struct pointer list */
  snippet_list[n_snippets] = new_snippet;
  /* up snippet count */
  n_snippets ++;
}

/* print the current list of snippets */
void print_list()
{
  int i;
  for (i = 0; i < n_snippets; i++) {
     printf ("%s\n%s.\n%s, %s %d\n\n", snippet_list[i] -> name,
	           snippet_list[i] -> addr,
	           snippet_list[i] -> city,
	           snippet_list[i] -> state,
	           snippet_list[i] -> zip);
  }
}

/* remove the snippet that contains a substring */
void remove_snippet ( char substring[] )
{
  int i;
  char zip[MAX_LINE_LENGTH];
  char line[MAX_LINE_LENGTH] ="";
  
  /* iterate through the snippet list */
  for ( i = 0 ; i< n_snippets; i++ ){
    /* convert the int zip in snippet to a char array */
    sprintf(zip, "%d", snippet_list[i] -> zip  );
    /* concatenate all information in the snippet to a new char array */
    strcat(line, snippet_list[i] -> name);
    strcat(line, snippet_list[i] -> addr);
    strcat(line, snippet_list[i] -> city);
    strcat(line, snippet_list[i] -> state);
    strcat(line, zip);

    /* check if the substring is in the new char array */
    if ( strstr ( line, substring) != NULL) {
      /* free the memory of the snippet that contains the substring */
      free(snippet_list[i]);
      /* remove the found snippet */
      int j;
      for ( j = i  ; j < ( n_snippets - 1) ; j++ ) {
        snippet_list[j] = snippet_list[j+1];
      }
      n_snippets--;
      i--;
    }
    line[0] = '\0';
  }
}

/* terminate the program
   write the number of snippets followd by each current snippet back to the file */
void terminate (char *snippet_file)
{
  /* open the file to write to*/
  FILE *fp;
  fp = fopen(snippet_file, "w");

  /* check if the file exists */
  if ( fp == NULL ) {
    printf("file not found");
    exit(-1);
  }

  /* print the number of snippet to the file */
  fprintf( fp, "%d\n", n_snippets );
  /* clode the file */
  fclose (fp);
  /* open the file to append to */
  fp = fopen(snippet_file, "a");
  int i;
  for (i = 0; i < n_snippets; i++) {
    fprintf(fp, "%s:%s:%s:%s:%d\n", snippet_list[i] -> name,
           snippet_list[i] -> addr,
           snippet_list[i] -> city,
           snippet_list[i] -> state,
           snippet_list[i] -> zip);
  } 
  /* close the file */
  fclose (fp);
}








	   

	  

	   
		 


	 
	  


	   



	   

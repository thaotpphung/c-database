/*
 * Thao Phung
 * Robert Matthews
 * CS 250
 * November 12, 2018
 *
 * This program serves as a simple database system
 * For each person, the program stores the person's information in a snippet
 * The user can perform actions on the database.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snippet_list.h"

#define MAX_ACTION_LENGTH 50
  
int main (int argc , char* argv[])
{
  /* read file */
  char *snippet_file = argv[1];
  read_file(snippet_file);

  /* perform actions */
  char action[MAX_ACTION_LENGTH]; 

  while (1) {
    /* prompt user for action */
    printf("Enter action: \n1.%s\n2.%s\n3.%s\n4.%s\n","list","add","remove","exit");
    scanf("%s", action);
    printf("\n");
    /* display list of snippets */
    if (strcmp ( action, "list") == 0 ){
      print_list();
    } 
    /* add a new snippet to the list */
    else if ( strcmp ( action, "add" ) == 0) {
      char line[MAX_LINE_LENGTH];
      char name[MAX_NAME_LENGTH];
      char addr[MAX_ADDRESS_LENGTH];
      char city[MAX_CITY_LENGTH];
      char state[STATE_LENGTH];
      unsigned int zip;
      fgets(line, MAX_LINE_LENGTH, stdin);

      /* prompt and get input from user */
      printf("Enter name:\n");
      fgets(name, MAX_NAME_LENGTH, stdin);
      name[strlen(name) -1] = '\0';

      printf("Enter address:\n");
      fgets(addr, MAX_ADDRESS_LENGTH, stdin);
      addr[strlen(addr) -1] = '\0';

      printf("Enter city:\n");
      fgets(city, MAX_CITY_LENGTH, stdin);
      city[strlen(city) -1] = '\0';

      printf("Enter state:\n");
      fgets(state, STATE_LENGTH, stdin);
      state[strlen(state) -1] = '\0';

      printf("Enter zip:\n");
      fgets(line, MAX_LINE_LENGTH, stdin);
      fgets(line, MAX_LINE_LENGTH, stdin);
      line[strlen(line) -1] = '\0';
      sscanf(line, "%d", &zip);

      /* add the snippet with the given input to the snippet list */
      add_snippet( name, addr, city, state, zip);  
      printf("\n");
    } 
    /* remove the snippet that contains a string from the list */
    else if ( strcmp ( action, "remove" ) == 0 ) { 
      char substring[MAX_LINE_LENGTH];
      fgets(substring, MAX_LINE_LENGTH, stdin);

      /* prompt and get the substring from user */
      printf("Enter substring:\n");   
      fgets(substring, MAX_LINE_LENGTH, stdin);
      substring[strlen(substring) -1] = '\0';

      /* remove the snippet that contains the given substring from the snippet list */
      remove_snippet(substring); 
      printf("\n");
    } 
    /*exit the program , update the snippet text file */
    else if ( strcmp ( action, "exit" ) == 0 ) {
      terminate(snippet_file);
      exit(0);
    }
  }
  return 0;
}




  

  

  

  
  

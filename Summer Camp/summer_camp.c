#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "readline.h"
#include "request.h"


/*
  Name: Amir Aslamov
  Description of Program: This program is designed  to manage registration requests
                          for a summer program, by requesting data for new requests
                          and storing the data in a dynamically allocated linked list
*/

/*
  main: Prompts the user to enter an operation code,      
        then calls a function to perform the requested   
        action. Repeats until the user enters the        
        command 'q'. Prints an error message if the user 
        enters an illegal code.                          
*/

int main(void) {

  char code;

  struct request *request_list = NULL;  
  printf("\nOperation Code: a for appending to the list, u for updating a request"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': request_list = append_to_list(request_list);
                break;
      case 'u': update(request_list);
                break;
      case 'p': print_list(request_list);
                break;
      case 'q': clear_list(request_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

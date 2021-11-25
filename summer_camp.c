#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EMAIL_LEN 100
#define NAME_LEN 30
#define STATUS_LEN 30


/*
  Name: Amir Aslamov
  Description of Program: This program is designed  to manage registration requests
                          for a summer program, by requesting data for new requests
                          and storing the data in a dynamically allocated linked list
*/




struct request{
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];
	int age;
	char status[STATUS_LEN+1];
	struct request *next;
};

/*the function "append_to_list" below is of type struct request and 
  and accepts a pointer of type struct request. It returns the list
  pointed to by the argument pointer without changes if 
  no space can be allocated or if the data entered by the user
  is already in the linked list; otherwise, it returns
  this list with a new node added at the end of the list*/
struct request *append_to_list(struct request *list);

/*the function "update" below is of type void and accepts a parameter
  of type struct request. This function does not return anything, but 
  overwrites an element of a node if this node is found in the linked list;
  if the node is not found, the function does nothing*/
void update(struct request *list);

/*the function "print_list" below is of type void and does not 
  return anything. This function cycles through the linked list
  and just prints each node one by one from the linked list*/
void print_list(struct request *list);

/*the function "clear_list" below is of type void and does not 
  return anything. This function loops through each node of the 
  linked list and frees up memory from each of the nodes*/
void clear_list(struct request *list);

/*the function below is of type int and returns the number of 
  characters in a string which it reads from user entry.
  Alhough it does return this number, the return value of this
  function is not catched at any point in the program - 
  its functionality to read a line of characters is utilized */
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
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



struct request *append_to_list(struct request *list) {

  struct request *new_request = malloc(sizeof(struct request));
  if (new_request == NULL) {
    printf("\nError! Malloc failure in appending to the list!");
    return list;
  }

  struct request *p;  //to iterate through the linked list

 //information collection
 printf("\nEnter the following information to complete a new request:");
 printf("\nFirst name: ");
 read_line(new_request -> first, NAME_LEN);
 printf("Last name: ");
 read_line(new_request -> last, NAME_LEN);
 printf("Email: ");
 read_line(new_request -> email, EMAIL_LEN);
 printf("Age: ");
 scanf("%d", &new_request -> age);
 //status is "pending" by default
 strcpy(new_request -> status, "pending"); 

//iterating through the list to check if the new node in the list
 for(p = list; p != NULL; p = p -> next) {
    //if struct request is already in the list
    if (!strcmp(p -> first, new_request -> first) && !strcmp(p -> last, new_request -> last)
        && !strcmp(p -> email, new_request -> email) && (p -> age == new_request -> age)) {
            printf("\nError! The request is already in the list.");
            return list;
        }
 }

//setting the new request to the end
 new_request -> next = NULL;

 //if list empty, new request is the only node in the list
 if (list == NULL) {
    return new_request;
 }

 p = list;
 while (p -> next != NULL) {
   p = p -> next;
 }

 p -> next = new_request;

 return list;
}



void update(struct request *list) {

  struct request *req_toupdate = malloc(sizeof(struct request));
  if (req_toupdate == NULL) {
    printf("\nError! Malloc failure in updating a node in the list!");
    return;
  }

  struct request *p;

  int flag = 0;  //will indicate if a request is found in the list

  //information collection
  printf("\nEnter the following information to find the request in the list:\n");
  printf("Enter first name: ");
  read_line(req_toupdate->first, NAME_LEN);
  printf("Enter last name: ");
  read_line(req_toupdate -> last, NAME_LEN);
  printf("Enter email: ");
  read_line(req_toupdate -> email, EMAIL_LEN);

  //iterating through the list to see if the enterred request is in the list
  for(p = list; p!=NULL; p = p -> next) {
    if (!strcmp(p -> first, req_toupdate -> first) && !strcmp(p -> last, req_toupdate -> last)
        && !strcmp(p -> email, req_toupdate -> email)) {
            flag = 1; //found the request in the list
            break; //so p will not point to "p -> next" after the loop updates
        }
  }
  
  if (flag) {
    printf("\nSuccess! Request found.");
    printf("\nEnter status: ");
    read_line(p -> status, STATUS_LEN);
    printf("\nSuccess! Status updated.");
  } 
  else {
    printf("\nFailure! Request not found.");
  }
}



void print_list(struct request *list) {

  struct request *p;
  printf("First name             Last name                   Email            Age"
          "          Status\n\n");

  for (p = list; p != NULL; p = p -> next) {
    printf("%-15s %15s %25s %12d %15s\n", p -> first, p -> last, p -> email,
           p -> age, p -> status);
  }
}



void clear_list(struct request *list) {

  struct request *p;
  while(list != NULL) {
    p = list;
    list = list -> next;
    if (p!= NULL) {
      free(p);
    }
  }
}



int read_line(char str[], int n) {

  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}

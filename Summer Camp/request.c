#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "request.h"
#include "readline.h"


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

 //iterating through the list to check if the new node in the list
 for(p = list; p != NULL; p = p -> next) {
    //if struct request is already in the list
    if (!strcmp(p -> first, new_request -> first) && !strcmp(p -> last, new_request -> last)
        && !strcmp(p -> email, new_request -> email)) {
            printf("\nError! The request is already in the list.");
            return list;
        }
 }

 printf("Age: ");
 scanf("%d", &new_request -> age);
 //status is "pending" by default
 strcpy(new_request -> status, "pending"); 

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
    printf("\nThe new status: %s", p -> status);
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

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

 //data collection
 printf("\nEnter the following information to complete a new request:");
 printf("\nLast name: ");
 read_line(new_request -> last, NAME_LEN);
 printf("First name: ");
 read_line(new_request -> first, NAME_LEN);
 printf("Email: ");
 read_line(new_request -> email, EMAIL_LEN);
 
 //to iterate through the linked list
 struct request *p;  
 
 //iterating through the list to check if the new node in the list
 for(p = list; p != NULL; p = p -> next) {

    //if struct request is already in the list
    if (!strcmp(p -> first, new_request -> first) && !strcmp(p -> last, new_request -> last)
        && !strcmp(p -> email, new_request -> email)) {
            printf("\nError! The request is already in the list.\n");
            free(new_request);
            return list;
        }
 }

 printf("Age: ");
 scanf("%d", &new_request -> age);

 //status is "pending" by default
 strcpy(new_request -> status, "pending"); 

 struct request *curr, *prev;

 /*the flag below will determine if the outer must be broken based on certain 
   conditions in the inner loop*/
 int flag = 0; 

 /*this outer loop will go trough entries and determine if the last name of the
   new entry is greater or less than each entry of the list, and if any one of 
   these equals the last name of the new entry a new loop will be activated*/
 for (curr = list, prev = NULL; curr != NULL; prev = curr, curr = curr -> next) {

        //if last name of the new request is bigger, we just cycle to the next entry
        if (strcmp(new_request -> last, curr -> last) > 0) {
            continue;
        }

        /*if the last name of the new cycle is smaller than some entry's last name,
          we break out of the outter loop*/
        else if (strcmp(new_request -> last, curr -> last) < 0) {
            break;
        }

        /*if the last name of the new request is equal to that of some entry, program 
          plunges into an inner loop*/
        else if (strcmp(new_request -> last, curr -> last) == 0) {

            /*inner loop does not need to have initialized variables, but proceed with 
              current entry and previous entry from the outer loop*/
            for( ; curr != NULL; prev = curr, curr = curr -> next) {

                /*if the last name of the new entry is greater than that of the current 
                  entry in the inner loop, the inner loop cycles*/
                if (strcmp(new_request -> first, curr -> first) > 0) {

                    /*if the next node of the current is NULL, the end of the list will 
                      be reached in the next cycle but instead of letting the update of 
                      the inner loop update the current entry to the next entry,
                      both the inner loop and outer loop by the flag will be broken, 
                      after new node is added at the end of the list*/
                    if (curr -> next == NULL) {
                        prev = curr;
                        curr = curr -> next;
                        flag = 1;
                        break;
                    }

                    /*if the last name of the current entry is the same as that of the new entry,
                      but the next entry's last name is different from that of the new entry, 
                      not matter the size of the first names, the new entry will be placed
                      after the current entry, becuase the outer loop will ensure entries are in 
                      ascending order based on just last names both inner and upper loops will be
                      broken*/
                    if (strcmp((curr -> next) -> last, curr -> last) != 0) {
                        flag = 1;
                        prev = curr;
                        curr = curr -> next;
                        break;
                    }

                    //if none of the above conditions are met, the inner loop just cycles to the next entry
                    if (flag == 0) {
                        continue;
                    }
                }

                /*if the first name of the entry that has the same last name as that of the new entry
                  is greater than that of the new request, the new request is placed before that entry
                  both the outer and the inner loops be broken by flag*/
                else if (strcmp(new_request -> first, curr -> first) < 0) {
                    flag = 1;
                } 

                /*if the last name of the new entry is turns out to be different from that of the
                  current entry in the row, no matter the size of the first names, both the outer 
                  and inner loops will just be broken*/
                else if (strcmp(new_request -> last, curr -> last) != 0) {
                    flag = 1;
                }

                /*if at least one of the conditions above necessitate the breaking of the loops,
                  first the inner will be broken*/
                if (flag == 1) {
                    break;
                }
            }
        }

        /*if at least one of the condtions inside the inner loop neccessitate the breaking of
          the loops, now the outer loop will be broken*/
        if (flag == 1) {
        break;
        }    
}

new_request -> next = curr;

 /*in case when the list is initially empty
   new entry will be return as the head of the list*/
 if (prev == NULL) {
     printf("\nSuccess! Entry successfully entered into the list of requests.\n");
     return new_request;
 }

 //inserting the new entry into the list
 else {
     prev -> next = new_request;
     printf("\nSuccess! Entry successfully entered into the list of requests.\n");
     return list;
 }
}



void update(struct request *list) {

  struct request *req_toupdate = malloc(sizeof(struct request));
  if (req_toupdate == NULL) {
    printf("\nError! Malloc failure in updating a node in the list!\n");
    return;
  }

  struct request *p;

  //will indicate if a request is found in the list
  int flag = 0;  

  //information collection
  printf("\nEnter the following information to find the request in the list:\n");
  printf("Enter last name: ");
  read_line(req_toupdate->last, NAME_LEN);
  printf("Enter first name: ");
  read_line(req_toupdate -> first, NAME_LEN);
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
  printf("Last name            First name                    Email           Age"
          "          Status\n\n");

  for (p = list; p != NULL; p = p -> next) {
    printf("%-15s %15s %25s %12d %16s\n", p -> last, p -> first, p -> email,
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



struct request *delete_from_list(struct request *list) {

  struct request *req_to_delete = malloc(sizeof(struct request));
  if (req_to_delete == NULL) {
    printf("\nError! Malloc failure in deleting a node from the list!");
    return list;
  }
  //data collection
  printf("\nEnter the following information to find the request in the list:\n");
  printf("Enter last name: ");
  read_line(req_to_delete->last, NAME_LEN);
  printf("Enter first name: ");
  read_line(req_to_delete -> first, NAME_LEN);
  printf("Enter email: ");
  read_line(req_to_delete -> email, EMAIL_LEN);

  /*the following two pointers will help keep track of entries in the list
    prev will be pointing to a node one before the one that the loop cycles 
    to find, while curr will point to the entry that the user requested to
    have deleted from the list*/
  struct request *prev, *curr;
  for (curr = list, prev = NULL; curr != NULL && (strcmp(curr -> last, req_to_delete -> last) != 0
        || strcmp(curr -> first, req_to_delete -> first) != 0 || strcmp(curr -> email, req_to_delete 
        -> email)) != 0; prev = curr, curr = curr -> next) {
          ;
        }

  /*if the curr points to NULL after the loop terminates, this means that 
    the loop went through the whole list and did not break because it found
    the entry requested, but because it went through all entries and reached 
    the end, which is NULL*/
  if (curr == NULL) {
    printf("\nError! Request not found!\n");
    return list;
  }

  /*the condtion below takes care of the case when the entry to be deleted 
    is the first one, in which case the loop gets broken, while prev will
    be left as NULL*/
  if (prev == NULL) {
    list = list -> next;
    printf("\nSuccess! Request deleted from the list.\n");
    return list;
  }

  /*the condition below is a regular case, when the entry to be deleted is found
    in the list and the loop got broken. In this case, prev will be pointing to 
    a node before the node found by the loop, which will be pointed to by curr.
    First, prev's next will be set to point to the curr's next, so curr will be 
    left out of the linkage of the nodes. Then, the curr will be freed from 
    memory*/
  else {
    prev -> next = curr -> next;
    free(curr);
    printf("\nSuccess! Request deleted from the list.\n");
    return list;
  }
}

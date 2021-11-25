#ifndef REQUEST_H
#define REQUEST_H

#include <string.h>

#define EMAIL_LEN 100
#define NAME_LEN 30
#define STATUS_LEN 30


struct request {
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

#endif

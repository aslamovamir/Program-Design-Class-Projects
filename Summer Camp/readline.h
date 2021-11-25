#ifndef READLINE_H
#define READLINE_H

#include <string.h>
#include <ctype.h>


/*the function below is of type int and returns the number of 
  characters in a string which it reads from user entry.
  Alhough it does return this number, the return value of this
  function is not catched at any point in the program - 
  its functionality to read a line of characters is utilized */
int read_line(char str[], int n);

#endif

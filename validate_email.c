#include <stdio.h>


/*
    Name: Amir Aslamov
    Description of Program: This program is designed to verify an email 
                            address input by a user, to check whether this 
                            email address ends with ".usf". If it does,
                            email address is validated, otherwise verification fails.

*/

#define MAX_SIZE 1000
#define SCHOOL_ADDRESS 5    //.edu


/*the function "validate" below has a return value of integer type, and its purpose is
  to extract some part of a string provided as an argument and compare it to a string
  with the values of interest. If a match is met, a flag is return with a value of 1,
  otherwise 0 is returned*/
int validate(char *s);

/*the function "read_line" below has a return value of integer type, and its purpose
is to read a line of characters and store them in a string. The function accepts
a string in which store the characters and the size of the string as parameters so as \
not to cause an overflow*/
int read_line(char str[], int n);



int main() {

    char input[MAX_SIZE];

    printf("Input: ");
    read_line(input, MAX_SIZE);  //a function call to read into a string

    //if the return value is 0, that is null, we print failure, and the opposite otherwise
    (validate(input)) ? printf("Output: Verification successful"): printf("Output: Not eligible for discount code");

    return 0;  
}



int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {  //a new line character will stop reading
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';      //the null is included at the end to validate the string

    return i;           //the length of the string is returned
}


/*no any function call will be performed in the function below so as to
  keep this function discrete and independent: therefore, the length of
  a string provided as an argument will be independently determined again,
  rather then determined from a function call of "read_line"; of course,
  the assumption is this string has a length determined by characters it is
  filled up with*/
int validate(char *s) {

    int size = 0;

    //first we determine the size of the string
    char *p;
    for (p = s; ; p++) {
        if (*p == '\0') {
            size++;  //+1 for the null terminator
            break;
        }
        else {
            size++;
        }
    }

    /*now we determine the last 5 characters of the input address(including the null)
      we will point p to the last 5 characters of the string now, and store the last 
      5 characters in a seperate string*/

    char end_address[SCHOOL_ADDRESS];                
    char *k;
    int copy = 0;

    /*"s + size - 5" to account for the null with 4 characters being ending of domain
       address*/
    for (p = s + size - SCHOOL_ADDRESS, k = end_address; p < s + size; p++, k++) {       
        *k = *p;                                                            
        copy++;                                                             
    }

    /*now we will create yet another string with the values being checked for
      and comparison between the above string and this string will be performed
      one character at a time. If at least one character is different, a flag 
      will be set to 0, else remain at 1*/
    
    char school_address[SCHOOL_ADDRESS] = ".edu";
    int flag = 1;

    for (k = end_address, p = school_address; k < end_address + SCHOOL_ADDRESS; k++, p++) {
        if (*p != *k) {
            flag = 0;
        }
    }

    return flag;
}

#include <stdio.h>

/*
    Name: Amir Aslamov
    Description of Program: This program is designed to translate a phone
                            number with letters to a phone number with digits.
                            The program will accept this phone number as a 
                            command line argument.
*/

//assumption that no phone number exceeds 40 in size
#define MAX_SIZE 41 


/*this function below is of type void and does not return anything;
  instead it is designed to accept two string as arguments and to modify 
  the string pointed to by the "phone_number" pointer 
  according to the letters the string pointed to by the pointer "word* 
  contains*/
void translate(char *word, char *phone_number);


/*to keep the main function prestine, the function below is 
  created, which is of type void, and accepts two strings,
  one of which is a command line argument, while the other
  is a string defined in the main function to represent a phone 
  number; this function fills up the former with characters other than
  the null, so its length can be known after a call to it in the main*/
void copy_arg_to_str(char *argument, char *letter_phone);


int main(int argc, char *argv[]) {

    /*check for the correct number of coomand line arguments:
      there should be one argument representing run a file command 
      and one more argument representing a phone number*/
    
    if (argc == 2) {
        
        char letter_phone[MAX_SIZE];
        char digit_phone[MAX_SIZE];
        
        copy_arg_to_str(argv[1], letter_phone);
        /*the function call above will fill up the "letter_phone"
          string so the function call below can determine its size*/
        translate(letter_phone, digit_phone);

     //output of results with the help of a pointer
     char *p;
     for (p = digit_phone; ;p++) {
         if (*p == '\0') {
             break;
         }
         printf("%c", *p);
     }
    }
    else {
        printf("Incorrect number of arguments. Usage: ./a.out phoneNumber\n");
    }

    return 0;
}


void copy_arg_to_str(char *argument, char *letter_phone) {
    char *p;
    int size = 0;

    //first, we determine the size of the argument string
    for(p = argument; ; p++) {
        if (*p == '\0') {
            ++size;         //size will include the null
            break;
        }
        ++size;
    }

    /*second, we copy the argument string to the string 
      defined in the main once character at a time*/
    char *t; 

    //a null terminator will also be copied to the string defined in main
    for (p = argument, t = letter_phone; p < argument + size; p++, t++) {  
        *t = *p;
    }
}

/*assuming a call to the above function is already made
  the string pointed to by the pointer word contains
  characters other than the null terminator, so we
  can find its size; no function is performed inside 
  this function to keep it discrete*/
void translate(char *word, char *phone_number) {

    char *p; char *t;  
    int size = 0;
    for (p = word; ; p++) {
        if (*p == '\0') {
            ++size;   //will include the null
            break;
        }
        else {
            ++size;
        }
    }

    for (p = word, t = phone_number; p < word + size; p++, t++) {

        /*a switch block will be placed in this loop to check characters
          for letters from the string pointed to by "word". If found,
          the corresponding digits will be placed in the characters
          of the string pointed to by "phone_number". Else, the characters
          will be placed in the string pointed to by "phone-number"*/ 

        switch(*p) {
            case 'A': case 'B': case 'C':
                *t = '2'; break;
            case 'D': case 'E': case 'F':
                *t = '3'; break;
            case 'G': case 'H': case 'I':
                *t = '4'; break;
            case 'J': case 'K': case 'L':
                *t = '5'; break;
            case 'M': case 'N': case 'O':
                *t = '6'; break;
            case 'P': case 'Q': case 'R': case 'S':
                *t = '7'; break;
            case 'T': case 'U': case 'V':
                *t = '8'; break;
            case 'W': case 'X': case 'Y': case 'Z':
                *t = '9'; break;
            /*default makes sure anything other than above cases
              get copied to the string pointed to by the 
              "phone_number", including the null*/
            default:                     
                *t = *p;
        }    
    }
}


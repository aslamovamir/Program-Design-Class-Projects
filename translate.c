#include <stdio.h>
/*
    Name: Amir Aslamov
    Description of Program: This program reads an input of a phone number in letters
                            and outputs the equivalent phone number in numbers
*/

int main()
{
    char phone_char;  
    
    /*the main structure of the program is to keep reading a character in a variable, while converting 
      this character to its corresponding digit number, outputting this corresponding digit number,
      and keep updating the variable with input in a loop.*/ 

    printf("Please enter a phone number in letters to convert to its equivalent in digits: ");

    //a new line corresponds to the user's click on enter, which should stop the input process
    while (phone_char != '\n')  {
        phone_char = getchar();

        /*if the input character is a number or '(', '-', ')', this character has to be printed as it is; an if
          statement will check for this and if it is a letter, a block of switch will determine the 
          respective character number*/

        //the decimal equivalents of character digits are from 48 to 57, inclusive
        if ((phone_char >= 48 && phone_char <= 57) || phone_char == '-' || phone_char == '(' || phone_char == ')')   {
            printf("%c", phone_char);
        }
        else    {
            switch (phone_char) {
                case 'A': case 'B': case 'C':
                    printf("%d", 2); break;
                case 'D': case 'E': case 'F':
                    printf("%d", 3); break;
                case 'G': case 'H': case 'I':
                    printf("%d", 4); break;
                case 'J': case 'K': case 'L':
                    printf("%d", 5); break;
                case 'M': case 'N': case 'O':
                    printf("%d", 6); break;
                case 'P': case 'Q': case 'R': case 'S':
                    printf("%d", 7); break;
                case 'T': case 'U': case 'V':
                    printf("%d", 8); break;
                case 'W': case 'X': case 'Y': case 'Z':
                    printf("%d", 9); break;
            }
        }
    }
    return 0;
}

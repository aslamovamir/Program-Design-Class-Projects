#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Name: Amir Aslamov
    Description of Program: This program is designed to generate a random sequence of 
                            digits, with no repeatition of any of the digits in the 
                            sequence, given an input number of digits by the user. 
                            The program contains a special function designed to
                            generate digits with the above requirements.
*/


/*the max size of the sequence is 8, so an array of size 8 
  is created with a macro definition. Only the indicated 
  number of digits by the user will be filled up with
  random digits and displayed*/

#define MAX_SIZE 8
int main(){

    int list_digs [MAX_SIZE];
    int num_digs;

    void create(int a[], int n);

    printf("Please enter the number of digits to be generated: ");
    scanf("%d", &num_digs);

    //input validation - the input has to be in the range [2, 8];
    while (num_digs < 2 || num_digs > 8) {
        printf("Invalid entry!\nPlease enter a number between 2 and 8, inclusive:");
        scanf("%d", &num_digs);
    } 

    create(list_digs, num_digs);

    return 0;
}
void create(int a[], int n) {
    /*to ensure that a randomly different digit is generated each time the function is
     run srand method is used as each digit has to be from 0 to 9; lower and upper
     variables are used to constrain the range of random numbers*/
    int lower=0, upper=9, dig;
    srand(time(NULL));
    
    /*to ensure that each digit is unique, an inner loop is placed inside the loop,
      which causes i to be decremented back if the current digit is met in the digits
      entered so far, so next random number overrides the current one*/
    int i,j;
    for (i = 0; i < n; i++) {
         dig = (rand()%(upper - lower + 1) + lower);
         a[i] = dig;
         for (j = 0; j < i; j++) {
             if (a[i] == a[j]){
                 --i;
                 break;
             }
        }
    }
    //display of the results
    int k;
    for (k = 0; k < n; k++) {
        printf("%d", a[k]);
    }
}

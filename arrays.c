#include <stdio.h>

/*
    Name: Amir Aslamov
    Description of Program: This program is designed to rearrange a list of integers
                            input by the user so that a particular integer input 
                            by the user is located in this list in way that 
                            all the integers less than that integer are placed 
                            in front of that integer while the integers greater
                            than the integer are placed after the integer in a list.
*/

void rearrange(int *a, int n, int insert, int *b);

int main() {

    int size, insert;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int input[size]; int rearranged[size + 1];

    printf("Enter the integers of the array: ");
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &input[i]);
    }
    printf("Enter the integer to insert: ");
    scanf("%d", &insert);

    rearrange(input, size, insert, rearranged);

    printf("Output: ");
    for (i = 0; i < size + 1; i++) {
        printf("%d ", rearranged[i]);
    }

    return 0;
}

/*The function "rearranger" below is of void type and does not return anything.
  This function is meant to modify variables passed as arguments, and its overall
  functionality is three-dimensional: first, all elements less than or equal to
  'insert' are placed consecutively in the 'rearranged' array, while ignoring
  those greater than 'insert'; second, 'insert' is placed where
  a counter variable will show where it should be placed; third,
  all values greater than 'insert' are placed, ignoring those that 
  are less than 'insert', finally making up the complete array pointed to
  by the pointer "*b".*/

void rearrange(int *a, int n, int insert, int *b) {

    int *p;     //a pointer to loop through arrays
    int t = 0;  //a counter, indicating the index at which 'insert' is to be placed
    int *r;     //this pointer will help manupulate the elements of the 'rearranged' array;

    for (p = a, r = b; p < a + n; p++, r++) {

        if (*p <= insert) {     //if an element is less or equal, it is stored
            *r = *p;
            t++;
        }
        else if (*p > insert) {
            r--;    //if an element is greater, the index at 'b' is decremented back, so as   
        }           //to store less or equal elements consecutively
    }

    //inserting the 'insert' in the array 'b'
    int *u;
    u = b + t;  //the index at which 'insert' should be is t: b is at index 0
    *u = insert;

    //putting the rest of elements in the array 'b'
    int *l;
    l = b + t + 1;
    for (p = a, r = b; p < a + n + 1; p++, r++, l++) {
        if (*p <= insert) {
            l--;
            continue; 
        }
        else if (*p > insert) {
            *l = *p;
        }
    }
}

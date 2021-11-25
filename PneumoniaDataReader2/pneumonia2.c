#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*
    Name: Amir Aslamov
    Description of Program: This program is designed to access a user-indicated 
                            file, reads the data about hospitals, sorts the data, which
                            meet the requirements for the quality and overall rating, 
                            according to the pneumonia costs in each hospital in
                            ascending order and finally writes the sorted data 
                            in a user-indicated file 
*/

//assuming the number of hospitals is no more than 300
#define NUM_HOSP 300 
//assuming the name of each hospital contains no more than 150 characters
#define NAME_HOS 150 
//assuming the name of the city and state of each hospital has no more than 50 characters
#define LOCATION 50 



struct hospital {
    char name[NAME_HOS];
    char city[LOCATION];
    char state[LOCATION];
    int rating;
    int cost;
    char quality[10];
    char value[10];
};

/*
    Overiew of the logic of the program:

        First, all the data are fetched and stored in
        a struct array. Second, data are shrinked,
        including only hospials that are "qualified",
        meeting the requirements for the quality and
        overall rating, and stored in another struct
        array. Third, in order to sort the needed 
        data according to cost in ascending order
        two more functions, one of which is
        a built-in function "qsort", and the other
        is built in the program to return either a 
        positive, a negatiove value or a zero for
        the functionality of the "qsort" function,
        are employed. Finally,another function is created 
        to write the now-sorted data into the file "output.csv"
*/


/*the function "qualify" below is of type int, and takes in 
  a struct array of the data fetched, a struct array of 
  data that meet the critaria, and the size of the 
  original data, and returns the size of the 
  "qualified data after it fills it in*/
int qualify(struct hospital data[], struct hospital qualified[], int size);

/*the function "ouput_file" below is of type void,
  takes in the struct array of the sorted data
  and its size, creates a file of scv format
  and prints the sorted data onto it*/
void output_file(struct hospital sorted[], int size);

/*prototype of a generic compare function, "hosps_compare",
  is of type int and returns an int value. The function uses 
  casting to convert the generic pointer parameters "p" and 
  "q" to stuct hospitals and then simply return the subtraction
  of p's cost from q's cost. If the return value is positive
  , the cost of p's is greater than that of q's, and if it is less
  than that of the other, the return value is negative. If the 
  return value is 0, the costs of both are equal*/
int hosps_compare(const void *p, const void *q);



int main() {

    struct hospital data[NUM_HOSP];
    char file_name[200];
    FILE *pfile;

    /*the variable below will serve to keep track of the 
      number of hospitals read from the file as well as
      to help in indexing the struct array*/
    int indexing = 0;


    printf("Enter the file name: ");
    scanf("%s", file_name);

    //opening this file for read purpose
    pfile = fopen(file_name, "r"); 
    if (pfile == NULL) {
        printf("\nError in opening the file!");
        return -1;
    }

    //given no errors, data are fetched and saved into the struct array
    while (!feof(pfile) && !ferror(pfile)) {
        //set specification ensures no commas
        if ((fscanf(pfile, "%[^,], %[^,], %[^,], %d, %d, %[^,], %s\n", 
                data[indexing].name, data[indexing].city,              
                data[indexing].state, &data[indexing].rating,
                &data[indexing].cost, data[indexing].quality,
                /*if fscanf confirms 7 data items have been read, 
                  indexing is incremented to fill in the struct array*/
                data[indexing].value)) == 7) {   
                    ++indexing;                
                }
    }

    
    //data of "qualified" hospitals
    struct hospital qualified[NUM_HOSP];
   
    int size = qualify(data, qualified, indexing); 

    //sorting of the data
    qsort(qualified, size, sizeof(struct hospital), hosps_compare);

    //outputing the "sorted" data to the file
    output_file(qualified, size);

    return 0;
}



int qualify(struct hospital data[], struct hospital qualified[], int size) {

    /*the critaria for the qualification are that both: 
        1. The quality of the hospital has to be "Better" or "Average"
        2. The rating of the hospital has to be 3 or higher
    */
   //the variable below will help with indexing of the struct array "qualified"
   int indexing = 0;

   int i;
   for (i = 0; i < size; i++) {
        if ((strcmp((data[i].quality), "Better") == 0 ||   //if qualified data copied 
            strcmp((data[i].quality), "Average") == 0) &&  //to the "qualified" struct array
            (data[i].rating >= 3)) {
                strcpy(qualified[indexing].name, data[i].name);
                strcpy(qualified[indexing].city, data[i].city);
                strcpy(qualified[indexing].state, data[i].state);
                qualified[indexing].rating = data[i].rating;
                qualified[indexing].cost = data[i].cost;
                strcpy(qualified[indexing].quality, data[i].quality);
                strcpy(qualified[indexing].value, data[i].value);
                ++indexing;
            } 
  }
  return indexing; //the size of the "qualified" struct array returned
}



void output_file(struct hospital sorted[], int size) {

    FILE *pfile_w;
    pfile_w = fopen("output.csv", "w");
    if (pfile_w == NULL) {
        printf("\nError creating the file!");
    }
    int indexing = 0;
    while(!feof(pfile_w) && !ferror(pfile_w)) {
        if (indexing == size) {
            break;
        }
        fprintf(pfile_w, "%s,%s,%s,%d,%d,%s,%s\n", sorted[indexing].name, 
                    sorted[indexing].city, sorted[indexing].state, sorted[indexing].rating,
                    sorted[indexing].cost, sorted[indexing].quality, sorted[indexing].value);
                    ++indexing;
    }

    printf("\nData fetched successfully!");
}



int hosps_compare(const void *p, const void *q) {
    return ((((struct hospital *) p) -> cost) - (((struct hospital *) q) -> cost));
}

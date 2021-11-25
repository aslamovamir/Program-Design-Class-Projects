#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
        two more functions are employed. Finally,
        another function is created to write the 
        now-sorted data into the file "output.csv"
*/


/*the function "qualify" below is of type int, and takes in 
  a struct array of the data fetched, a struct array of 
  data that meet the critaria, and the size of the 
  original data, and returns the size of the 
  "qualified data after it fills it in*/
int qualify(struct hospital data[], struct hospital qualified[], int size);

/*the function "sort_hosp" below is of type void,
  takes in the struct array of the sorted data and
  its size, and then sorts the data in ascending 
  order in terms of the costs of each hospital.
  This function is recursive and depends on one 
  more function called "index_largest"*/
void sort_hosp(struct hospital qualified[], int n); 

/*the function "index_largest" is of type int,
  takes in the struct array of the sorted data
  and its size, finds the index of a hospital
  with the greatest cost and returns this index*/
int index_largest(struct hospital qualified[], int size);

/*the function "ouput_file" below is of type void,
  takes in the struct array of the sorted data
  and its size, creates a file of scv format
  and prints the sorted data onto it*/
void output_file(struct hospital sorted[], int size);


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
        if ((fscanf(pfile, "%[^,], %[^,], %[^,], %d, %d, %[^,], %s\n", //set specification
                data[indexing].name, data[indexing].city,              //ensures no commas
                data[indexing].state, &data[indexing].rating,
                &data[indexing].cost, data[indexing].quality,
                data[indexing].value)) == 7) {  //if fscanf confirms 7 data items have been read, 
                    ++indexing;                //indexing is incremented to fill in the struct array
                }
    }

    
    //data of "qualified" hospitals
    struct hospital qualified[NUM_HOSP];
   
    int size = qualify(data, qualified, indexing); 

    //ordering the "qualified" data
    sort_hosp(qualified, size);

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



int index_largest(struct hospital qualified[], int size) {

    int largest_cost = qualified[0].cost;
    int cost, index_of_largest;

    int i;
    for (i = 1; i < size; i++) {
        cost = qualified[i].cost;
        if (cost > largest_cost) {
            largest_cost = cost;
            index_of_largest = i;
        }
    }

    return index_of_largest;
}




/* this function will call itself recursively until it arrives at the size of the struct 
   array that holds just 1 hospital */
void sort_hosp(struct hospital qualified[], int n) {

    if (n == 1) {
        return;     //if size is 1, the function just terminates its operation
    }
    else {
        /*the two structs are created to swap the data
          of the hospital with greatest cost with the
          data of the last hospital in the array so far*/
        struct hospital temp;
        struct hospital largest_cost;

        int index_of_largest = index_largest(qualified, n);\

        //data of the hospital with the largest case are copied
        strcpy(largest_cost.name, qualified[index_of_largest].name);
        strcpy(largest_cost.city, qualified[index_of_largest].city);
        strcpy(largest_cost.state, qualified[index_of_largest].state);
        largest_cost.rating = qualified[index_of_largest].rating;
        largest_cost.cost = qualified[index_of_largest].cost;
        strcpy(largest_cost.quality, qualified[index_of_largest].quality);
        strcpy(largest_cost.value, qualified[index_of_largest].value);

        //data of the last hospital in the array are copied
        strcpy(temp.name, qualified[n - 1].name);
        strcpy(temp.city, qualified[n - 1].city);
        strcpy(temp.state, qualified[n - 1].state);
        temp.rating = qualified[n - 1].rating;
        temp.cost = qualified[n - 1].cost;
        strcpy(temp.quality, qualified[n - 1].quality);
        strcpy(temp.value, qualified[n - 1].value);

        //swapping of the data obtained above
        strcpy(qualified[index_of_largest].name, temp.name);
        strcpy(qualified[index_of_largest].city, temp.city);
        strcpy(qualified[index_of_largest].state, temp.state);
        qualified[index_of_largest].rating = temp.rating;
        qualified[index_of_largest].cost = temp.cost;
        strcpy(qualified[index_of_largest].quality, temp.quality);
        strcpy(qualified[index_of_largest].value, temp.value);

        strcpy(qualified[n - 1].name, largest_cost.name);
        strcpy(qualified[n - 1].city, largest_cost.city);
        strcpy(qualified[n - 1].state, largest_cost.state);
        qualified[n - 1].rating = largest_cost.rating;
        qualified[n - 1].cost = largest_cost.cost;
        strcpy(qualified[n - 1].quality, largest_cost.quality);
        strcpy(qualified[n - 1].value, largest_cost.value);

        //a recursive call to itself but with the size 1 less
        //so that the hospital with the largest cost so far
        //is left out
        return sort_hosp(qualified, n - 1); 
    }
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

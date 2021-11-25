#include <stdio.h>
#include <string.h>


/*
    Name: Amir Aslamov
    Description of Program: This program is designed to indicate the number of
                            times a user-enterred sequence of DNA, STR, is
                            repeated in a file indicated by the user.
*/

#define MAX_FName 100
#define MAX_DNA 20000

/*The function below, "count_repeats", is of type int, and
  is designed to return the number of times a string
  passed in as argument for the parameter "STR" appears in
  another string passed in as argument for the parameter
  "sequence". The function modifies the "sequence" parameter
  but this side effect is not important in this program.*/
int count_repeats(char *sequence, char *STR);



int main() {

    char STR[MAX_DNA];
    char DNA[MAX_DNA];
    char file_name[MAX_FName];
    FILE *pFile;

    printf("Enter the file name for the DNA sequence: ");
    scanf("%s", file_name);

    //validation of the file access
    pFile = fopen(file_name, "r");
    if (pFile == NULL)
    {
        printf ("Error opening file!\n");
        return 1;
    }
    //if file access successful, data is stored in DNA
    if (!(fgets(DNA, MAX_DNA, pFile))) {
        printf("Error reading data from the file!");
    }
    //end of file access validation


    printf("Enter STR: ");
    scanf("%s", STR);

    //the file is closed
    fclose(pFile);

    printf("%s is repeated %d times", STR, count_repeats(DNA, STR));

    return 0;
}



int count_repeats(char *sequence, char *STR) {

    //this will track the number of repeats
    int count = 0;

    char *remainder = sequence;

    //searches for "STR" in remainder until it is empty
    while ((remainder = strstr(remainder, STR)) != NULL) {
        //tracking by incrementing
        ++count;
        /*"remainder" points to a substring after "STR"
           is found, not including it itself*/
        remainder += strlen(STR);
    }

    return count;
}

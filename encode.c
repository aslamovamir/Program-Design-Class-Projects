#include <stdio.h>

/*
    Name: Amir Aslamov
    Description of Program: This program is designed to encrypt an array of integers
                            input by the user according to a key array of 10 integers
                            from 0 to 9 based on their indeces in the key array.
                            The key array is input by the user.
*/

/*the max size of the array to be encrypted is 10(digits from 0 to 9)
  , so a macro definition will be used to initialize the size of
  all the arrays*/
#define MAX_SIZE 10
int main(){

    void encode(int input[], int encrypt[], int key[], int size);

    int size;
    int input[MAX_SIZE];
    int encrypt[MAX_SIZE];
    int key[MAX_SIZE];

    printf("Enter the size of the input array: ");
    scanf("%d", &size);
    printf("Enter the digits: ");
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &input[i]);
    }
    printf("Now enter the key array: ");
    int k;
    for (k = 0; k < MAX_SIZE; k++)  {
        scanf("%d", &key[k]);
    }

    encode(input, encrypt, key, size);

    return 0;
}
/*the function encode will use two for loops: one will
  run through each digit of the input array, while another
  will run through each digit of the key array*/
void encode(int input[], int encrypt[], int key[], int size) {
    int t, j;
    for (t = 0; t < size; t++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (input[t] == key[j]) {     //if identical digits are found, the encrypted digit will
                encrypt[t] = j;           //simply be equal to j, which in this case is the index of key
            }
        }
    }
    int l;
    for (l = 0; l < size; l++)  {
        printf("%d ", encrypt[l]);
    }
}

#include <stdio.h>
/*
    Name: Amir Aslamov
    Description of Program: This program is designed to simulate a cart at a produce stand, with the input of
                            a type of item in the cart, the amount of that item or the number of that item, 
                            and with the output of the amount due. This program also displays the amount of 
                            change to be paid back in cash, after the input of cash received.
*/

int main()
{
    int item_choice, num_items;
    float item_charge = 0, amount_of_item, total_charge, cash_received, change;
    int invalid = 1; /*this flag will be used to account for the loop - when the user enters a number out
                       of the range [1, 6], this flag will cause the termination of the loop*/

    printf("Please select from the following list:");
    printf("\n1. Lemons - $0.21 each\n2. Lettuce - $2.39 each\n3. Potatoes - $0.79/lb\n4. Beans - $0.99/lb"
           "\n5. Avocado - $1.50 each\n6. Tomatoes - $1.99/lb\n");

    /*a switch block will be placed inside the loop to facilitate the calculation of amount of charge per item
      and the addition of this amount to the total charge for all items selected*/  

    while (invalid == 1)  {
        printf("\nEnter selection: ");
        scanf("%d", &item_choice);
        
        //an if statement to check for 0 input by the user, which indicates termination of selection
        if (item_choice == 0)   {
            printf("\nSelection terminated\n");
            break;
        }

        //another loop to validate the choice selection; the flag will be placed in the loop below
        while (item_choice < 1 || item_choice > 6)    {
            printf("Ivalid Selection!\nPlease enter a number in the range (1 - 6) inclusive or enter 0 to terminate selection");
            printf("\nEnter a selection: ");
            scanf("%d", &item_choice);
            if (item_choice == 0)   {
                printf("Selection terminated.");
                invalid = 0;
                break;
            }
        }

        /*the if statement below ensures the outer loop is also terminated if the flag is 0 after a number 
          outside the range [1, 6] is selected*/
        if (invalid == 0)   {
            break;
        }
        else    {
            switch (item_choice)
            {
            case 1:
                printf("Enter number of items: ");
                scanf("%d", &num_items);
                item_charge = 0.21 * num_items;
                total_charge += item_charge;
                break;
            case 2:
                printf("Enter number of items: ");
                scanf("%d", &num_items);
                item_charge = 2.39 * num_items;
                total_charge += item_charge;
                break;
            case 3:
                printf("Enter weight (lb): ");
                scanf("%f", &amount_of_item);
                item_charge = 0.79 * amount_of_item;
                total_charge += item_charge;
                break;
            case 4:
                printf("Enter weight (lb): ");
                scanf("%f", &amount_of_item);
                item_charge = 0.99 * amount_of_item;
                total_charge += item_charge;
                break;
            case 5:
                printf("Enter number of items: ");
                scanf("%d", &num_items);
                item_charge = 1.50 * num_items;
                total_charge += item_charge;
                break;
            case 6:
                printf("Enter number of items: ");
                scanf("%f", &amount_of_item);
                item_charge = 1.99 * amount_of_item;
                total_charge += item_charge;
                break;

            /*no need for a default case because an exceptional selection is taken care of 
              in the inner while loop above*/
            }
        }
    }

    //display of the total amount due, cash recived and the calculation of change
    printf("\nAmount due ($): %.2f", total_charge);
    printf("\nEnter cash received ($): ");
    scanf("%f", &cash_received);
    change = cash_received - total_charge;
    printf("\nYour change is $%.2f", change);

    return 0;
}

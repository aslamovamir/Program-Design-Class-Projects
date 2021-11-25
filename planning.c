#include <stdio.h>
/*
    Name: Amir Aslamov
    Description of program: This program is designed to display the total amount of charge of a stay in one of three locations for an
    organization, based on the location chosen, the number of people who will stay, and the number of hours of stay. Certain restrictions
    are validated, such as room capacity, maximum rental charge per day, and the maximum number of hours of stay per day.
*/

int main()
{
    int location, num_attendees, hours;
    int room_charge, food_charge;

    printf("This program will display the total charge of a stay in a location selected.\n");
    printf("Please select from the following menu: \n1. Holiday House\n2. Fun Center\n3. Party Plaza\n");
    printf("Select: ");
    scanf("%d", &location);

    /*input validation is implemented: the choice must be an integer in the range 1-3 correspondent to the choice of location
    If the user inputs an invalid number, the program will terminate; otherwise, further information collection will proceed*/

    if (location >= 1 && location <= 3)   {
        printf("Now enter hours: ");
        scanf("%d", &hours);

        //another input validation is implemented: the maximum hours is 10, while the minimum is 1

        if (hours > 0 && hours <= 10)   {
            printf("Now enter the number of people: ");
            scanf("%d", &num_attendees);

            //another input validation: room capacity determined by the location selection as well;for this matter, if else structure will help
            //to determine the location selected and the capacity for that selection

            if (location == 1 && num_attendees > 200)   {
                printf("Failure. Room capacity exceed.");
            }
            else if (location == 2 && num_attendees > 100)  {
                printf("Failure. Room capacity exceeded.");
            }
            else if (location == 3 && num_attendees > 150)  {
                printf("Failure. Room capacity exceeded.");
            }
            else    {

                //another if else structure placed will lead through the room selection point to lead to the total charge of the stay
                //the assumption is that at this point all the input is valid to produce the total charge
                //Not to repeat the if else structure for the calculation of food charge, this food charge calculation will be performed in the structure below

                if (location == 1)  {
                    room_charge = 400 + ((hours - 1) * 200);

                    //another if structure to look for the maximum rental charge possible according to the location selection

                    if (room_charge > 1800)  {
                        room_charge = 1800;
                    }
                    food_charge = num_attendees * 10;
                }
                else if (location == 2)  {
                    room_charge = 300 + ((hours - 1) * 150);
                    if (room_charge > 1300)  {
                        room_charge = 1300;
                    }
                    food_charge = num_attendees * 20;
                }
                else if (location == 3)  {
                    room_charge = 250 + ((hours - 1) * 120);
                    if (room_charge > 800)  {
                        room_charge = 800;
                    }
                    food_charge = num_attendees * 15;
                }

                //finally we can display the final result as the total charge

                printf("Charge: $%d", (room_charge + food_charge));
            }
        }
        else    {
            printf("Invalid input. Input must be a positive number less than or equal to 10.\n");
        }
    }
    else    {
        printf("Invalid input. The input should be in the range of 1 to 3.\n");
    }

    return 0;
}

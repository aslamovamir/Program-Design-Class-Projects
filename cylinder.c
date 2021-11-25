#include <stdio.h>

/*
    Name: Amir Aslamov
    Description of Program: This program is designed to calculate the volume and 
                            the surface area of a cylinder, radius and height of which is
                            input by a user.
*/

#define PI 3.141592 //the approximate value of π

void area_volume(double radius, double height, double *pointer_area, double *pointer_volume);

int main() {

  double radius, height, area, volume;
    
  printf("Enter the radius of the cylinder: ");
  scanf("%lf", &radius);
  printf("Enter the height of the cylinder: ");
  scanf("%lf", &height);

  /*in the function call below, only the pointers (addresses) of the variables volume and area 
    are passed. The function calcuates and stores the values of interest in the variables*/
    
  area_volume(radius, height, &area, &volume);

  printf("The volume of the cylinder is %.3lf, while the surface area is %.3lf", volume, area);

  return 0;
}

/*the function "are_volume"  below is of type void and does not return anything. Instead, it  calculates
  the values of surface area and volume defined in the main function and stores them in the 
  the pointers passed as arguments, respectively.*/

void area_volume(double radius, double height, double *pointer_area, double *pointer_volume){

  //the forumula for the surface area of a cylinder: 2πrh + 2πr^2
  *pointer_area = 2 * PI * radius * height + 2 * PI * radius * radius;

  //the forumula for the volume of a cylinder: π(r^2)h 
  *pointer_volume = PI * radius * radius * height;   
}

/* Code to test Tanget Load Cell Fault Detection
   M2 server - Rubin
   May 2022
   Patricio Cortes
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159

int main()
{
    double fa2 = 0.0, fa3 = 0.0, fa5 = 0.0, fa6 = 0.0; // tangential forces
    double fw = 15140.0; // gravity force on mirror weight
    double eA = 0.0; // elevation angle in degrees
    double zd = 0.0; // zenith distance in degrees
    double tanWeight;
    double tanWeightError = 1000.0;
    
    // ask user enter values	
    printf("Enter fa2 : ");
    scanf("%lf",&fa2);
    printf("Enter fa3 : ");
    scanf("%lf",&fa3);
    printf("Enter fa5 : ");
    scanf("%lf",&fa5);
    printf("Enter fa6 : ");
    scanf("%lf",&fa6);
    printf("Enter Elevation Angle : ");
    scanf("%lf",&eA);

    // calculations
    zd = 90.0 - eA;
    tanWeight = (fa2 + fa3 - fa5 - fa6)*cos(30.0*(PI/180)) - 15140*sin(zd*(PI/180));
    printf("Tangent Weight = %.2lf N\n", tanWeight);	
    double absTanWeight = abs(tanWeight);
    //printf("Abs Tangent Weight = %.2lf N\n", absTanWeight);	
    
    if(absTanWeight >= tanWeightError)
      printf("¡Tangential Load Error!\n");
    else
      printf("No Tangential Load Error\n-");
    
    return 0;
}

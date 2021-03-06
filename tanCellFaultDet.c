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
    double fa1 = 0.0, fa2 = 0.0, fa3 = 0.0, fa4 = 0.0 , fa5 = 0.0, fa6 = 0.0; // tangential forces (N)
    double fw = 15140.0; // gravity force on mirror weight (N)
    double eA = 0.0; // elevation angle (°)
    double zd = 0.0; // zenith distance (°)
    double tanWeight; // tangential total wight (N)
    double loadBearing2, loadBearing3, loadBearing5, loadBearing6; // load bearing calculations (N) 
    double tanWeightError = 1000.0; // tangential witgh error (N)
    double netMoments; // net moment of forces (N)
    
    // ask user enter values	
    printf("Enter fa1 : ");
    scanf("%lf",&fa1);
    printf("Enter fa2 : ");
    scanf("%lf",&fa2);
    printf("Enter fa3 : ");
    scanf("%lf",&fa3);
    printf("Enter fa4 : ");
    scanf("%lf",&fa4);
    printf("Enter fa5 : ");
    scanf("%lf",&fa5);
    printf("Enter fa6 : ");
    scanf("%lf",&fa6);
    printf("Enter Elevation Angle : ");
    scanf("%lf",&eA);

    // get the zenith distance
    zd = 90.0 - eA;

    // tangential total weight calculation
    tanWeight = (-fa2 - fa3 + fa5 + fa6)*cos(30.0*(PI/180)) - fw*sin(zd*(PI/180));
      printf("Tangent Weight = %.2lf N\n", tanWeight);	
    double absTanWeight = abs(tanWeight); // absolute value of tanWeight
 
    // load bearing calculations
    loadBearing2 = fa2*cos(30.0*(PI/180)) + (fw*sin(zd*(PI/180)))/4;
      printf("Load Bearing 2 = %.3lf N\n", loadBearing2); 
    loadBearing3 = fa3*cos(30.0*(PI/180)) + (fw*sin(zd*(PI/180))/4); 
      printf("Load Bearing 3 = %.3lf N\n", loadBearing3);
    loadBearing5 = fa5*cos(30.0*(PI/180)) - (fw*sin(zd*(PI/180))/4); 
      printf("Load Bearing 5 = %.3lf N\n", loadBearing5);
    loadBearing6 = fa6*cos(30.0*(PI/180)) - (fw*sin(zd*(PI/180))/4); 
      printf("Load Bearing 6 = %.3lf N\n", loadBearing6);

    // net moment calculations
    netMoments = fa1 + fa2 + fa3 + fa4 + fa5 + fa6; 
      printf("Net Moments of Forces = %.3lf N\n", netMoments);

   return 0;
}

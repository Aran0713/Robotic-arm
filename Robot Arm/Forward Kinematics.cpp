#include "library.h"
#include <stdio.h>
#include <math.h>


void Forward(double angle1, double angle2, double angle3, double angle4, double angle5){

  angle5 = (M_PI/180) * (angle5 - 180);
  angle4 =  (M_PI/180) * (angle4 - 180);
  angle3 =  (M_PI/180) * (angle3 - 150);
  double a1 = 12.7, a2 = 3.3, a3 = 6.4, a4 = 0.6, a5 = 10.8, a6 = 3.5;
  double H01[4][4] = {
    {0, sin(angle5), cos(angle5), a2*cos(angle5)},
    {0, -cos(angle5), sin(angle5), a2*sin(angle5)},
    {1,0,0,a1},
    {0,0,0,1}};
  double H12[4][4] = {
    {cos(angle4), sin(angle4), 0, a3*cos(angle4)},
    {sin(angle4), -cos(angle4), 0, a3*sin(angle4)},
    {0,0,-1,-a4},
    {0,0,0,1}};
  double H23[4][4] = {
    {cos(angle3), -sin(angle3), 0, a5*cos(angle3) - a6*sin(angle3)},
    {sin(angle3), cos(angle3), 0, a5*sin(angle3) + a6*cos(angle3)},
    {0,0,-1,0},
    {0,0,0,1}};
  double first[4][4];
  double H[4][4];

  for (int i=0; i<4; i++){
    for (int j=0; j < 4; j++){
      first[i][j] = 0;
      H[i][j] = 0;
    }
  }

  for (int i=0; i<4; i++){
    for (int j=0; j < 4; j++){
      for (int k=0; k<4; k++){
        first[i][j] += H01[i][k] * H12[k][j];
      }
    }
  }

  for (int i=0; i<4; i++){
    for (int j=0; j < 4; j++){
      for (int k=0; k<4; k++){
        H[i][j] += first[i][k] * H23[k][j];
      }
    }
  }

  for (int i=0; i<4; i++){
    for (int j=0; j < 4; j++){
      Serial.print(H[i][j]);
      Serial.print(" ");
      if (j == 3){
        Serial.print("\n");
      }
    }
  }
  
  
}

  #include <stdio.h>
  #include "s21_math.h"
  
  
  int main(){
  //double x = 23479852987346.000001;
  //double y = 3.14159265358979323846;
   double a = -0.999999;
  long double orig = asin(a);
  long double s21 = s21_asin(a);
 printf("%.10Lf \n%.10Lf\n", orig, s21);
  }


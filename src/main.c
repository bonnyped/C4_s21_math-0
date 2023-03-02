  #include <stdio.h>
  #include "s21_math.h"
  
  
  int main(){
  double a = 123123123.123;
  long double orig = cos(a);
  long double s21 = s21_cos(a);
 printf("%Lf %Lf", orig, s21);
  }


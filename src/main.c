#include <stdio.h>

#include "s21_math.h"

int main() {
  double a = 1374532334;
  long double s21 = s21_exp(a);
  long double orig = exp(a);
  printf("%.10Lf \n%.10Lf\n", orig, s21);
}

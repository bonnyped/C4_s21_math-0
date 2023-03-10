#ifndef S21_MATH_H
#define S21_MATH_H

#define s21_EXP 2.71828182845904523536028747
#define s21_M_05PI 3.14159265358979323846 * 0.5
#define s21_M_PI 3.14159265358979323846
#define s21_M_2PI 3.14159265358979323846 * 2
#define s21_NAN 0.0 / 0.0
#define s21_EPSILON 1e-10
#define s21_POSITIVE_INFINITY 1.0 / 0.0
#define s21_NEGATIVE_INFINITY -1.0 / 0.0
#define s21_ZERO_NUMBER 0.0

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
int is_negative_zero(double x);
int is_integer_number(double x);
int is_even_number(double x);
int checking_number(double x);

#endif  // S21_MATH_H

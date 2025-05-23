#include "s21_math.h"

int s21_abs(int x) {
  int result = x;
  if (x < 0) {
    result = -result;
  }
  return result;
}

long double s21_acos(double x) { return s21_M_05PI - s21_asin(x); }

long double s21_asin(double x) {
  long double result = 0;
  if (x == s21_NAN || x > 1 || x < -1 || x != x) {
    result = s21_NAN;
  } else if (x == 1.0) {
    result = s21_M_05PI;
  } else if (x == -1.0) {
    result = -s21_M_05PI;
  } else if (x == 0) {
    result = 0;
  } else {
    long double left = -s21_M_05PI;
    long double right = s21_M_05PI;
    while ((right - left) / 2 > 10e-14) {
      long double center = (right + left) / 2;
      if (s21_sin(center) - x < 0) {
        left = center;
      } else {
        right = center;
      }
    }
    result = (right + left) / 2;
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0.0;
  x != x ? result = x : result;
  if (result == result) {
    if (x == s21_POSITIVE_INFINITY || x == s21_NEGATIVE_INFINITY) {
      x > 0 ? result = s21_M_PI / 2 : (result = -s21_M_PI / 2);
    } else {
      result = s21_asin(x / s21_sqrt(1.0 + s21_pow(x, 2.0)));
      if (result != result) {
        result = s21_asin(1);
      }
    }
  }
  return result;
}

long double s21_ceil(double x) {
  long double result = (long double)x;
  double x_ceil = (long double)x;
  if (checking_number(x)) {
    if (s21_fabs(x) <= 1.84467441e+018 && s21_fabs(x) >= -1.84467441e+018) {
      x < 0 ? x_ceil *= -1. : x_ceil;
      result = (long long unsigned)x_ceil;
      x < 0 ? result *= -1 : result;
    } else {
      result = x_ceil;
    }
    result < x ? result += 1 : result;
  }
  return result;
}

long double s21_cos(double x) {
  long double result = 0;
  long double prev = -1;
  long double add = 1;
  int n = 1;
  if (x == s21_NAN || x == s21_POSITIVE_INFINITY ||
      x == s21_NEGATIVE_INFINITY || x != x) {
    result = s21_NAN;
  } else {
    x = s21_fabs(x);
    x = s21_fmod(x, (2 * s21_M_PI));
    while (result != prev) {
      prev = result;
      result = result + add;
      add = -add * x * x / (2 * n) / (2 * n - 1);
      n++;
    }
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 0;
  long double prev = -1;
  long double add = 1;
  int n = 1;
  if (x != x) {
    result = s21_NAN;
  } else {
    if (x < 0) {
      result = 1 / s21_exp(-x);
      prev = result;
    }
    while (result != prev && add > s21_EPSILON) {
      prev = result;
      result = result + add;
      add = add * x / n;
      n++;
    }
  }
  return result;
}

long double s21_fabs(double x) {
  long double result = x;
  if (result < 0) result *= -1;
  if (result == s21_ZERO_NUMBER) result = s21_ZERO_NUMBER;
  if (result != result) result *= -1;

  return result;
}

long double s21_floor(double x) {
  long double result = (long double)x;
  long double x_floor = (long double)x;
  if (checking_number(x)) {
    if (s21_fabs(x) <= 1.84467441e+018 && s21_fabs(x) >= -1.84467441e+018) {
      x < 0 ? x_floor *= -1. : x_floor;
      result = (long long unsigned)x_floor;
      x < 0 ? result *= -1 : result;
      x<0 && result> x ? result -= 1 : result;
    } else {
      result = x_floor;
    }
  }
  return result;
}

long double s21_fmod(double x, double y) {
  long double result = x;
  double x_fmod = s21_fabs(x);
  double y_fmod = s21_fabs(y);
  if (x_fmod >= y_fmod && checking_number(x) && checking_number(y)) {
    result = x_fmod;
    double approximation = 0;
    int e = (s21_floor(s21_log(x_fmod) * 1.4426950408889634) + 1) -
            (s21_floor(s21_log(y_fmod) * 1.4426950408889634) + 1);
    double v = 2.0;
    while (e > 1) {
      v *= 2.0;
      e -= 1;
    }
    approximation = v * y_fmod;
    while (approximation >= y_fmod) {
      result >= approximation ? result -= approximation : result;
      approximation /= 2;
    }
    x < 0 ? result *= -1 : result;
  } else if (checking_number(x) && checking_number(y)) {
    result = x;
  } else {
    result = (x == 0.0 && y != 0.0) ? 0.0 : (s21_NAN);
    result = (x != s21_POSITIVE_INFINITY && x != s21_NEGATIVE_INFINITY) &&
                     (y == s21_NEGATIVE_INFINITY || y == s21_POSITIVE_INFINITY)
                 ? x
                 : result;
    result = (x == s21_NAN) || (y == s21_NAN) ? (s21_NAN) : result;
  }
  return result;
}

long double s21_log(double x) {
  long double result = x;
  int n = 0;
  if (x > 0 && x != 1 && checking_number(x)) {
    result = 0;
    long double xx = x;
    while (++n, (xx /= s21_EXP) > s21_EXP)
      ;
    while (s21_fabs(xx - s21_exp(result)) / (xx + s21_exp(result)) > 1e-10) {
      result += (xx - s21_exp(result)) / (xx + s21_exp(result));
    }
    result += n;
  } else if (x < 0) {
    result = s21_NAN;
  } else if (x == -x) {
    result = s21_NEGATIVE_INFINITY;
  } else if (x == 1) {
    result = 0;
  }
  return result;
}

long double s21_pow(double base, double exponent) {
  long double result = s21_exp(exponent * s21_log(base));
  int flag = 0;
  if (base < 0 && is_integer_number(exponent)) {
    result = s21_exp(exponent * s21_log(s21_fabs(base)));
    if (!is_even_number(exponent)) result *= (-1);
  }
  if (exponent == s21_ZERO_NUMBER) result = 1.0;
  if (base == s21_ZERO_NUMBER && is_integer_number(exponent) &&
      !is_even_number(exponent)) {
    is_negative_zero(base) ? result = result * -1 : (result);
  } else if (base == 1) {
    result = 1.0;
    flag = 1;
  } else if (base == s21_NEGATIVE_INFINITY) {
    if (exponent < 0 && is_integer_number(exponent) &&
        !is_even_number(exponent)) {
      result = -s21_ZERO_NUMBER;
    }
    if ((exponent < 0 && !is_integer_number(exponent)) ||
        (exponent < 0 && is_even_number(exponent))) {
      result = s21_ZERO_NUMBER;
    }
    if (exponent > 0 && is_integer_number(exponent) &&
        !is_even_number(exponent)) {
      result = s21_NEGATIVE_INFINITY;
    }
    if ((exponent > 0 && !is_integer_number(exponent)) ||
        (exponent > 0 && is_even_number(exponent))) {
      result = s21_POSITIVE_INFINITY;
    }
  } else if (base == s21_POSITIVE_INFINITY) {
    if (exponent < 0) result = s21_ZERO_NUMBER;
    if (exponent > 0) result = s21_POSITIVE_INFINITY;
  } else if (exponent == s21_NEGATIVE_INFINITY ||
             exponent == s21_POSITIVE_INFINITY) {
    if (base == -1) {
      result = 1.0;
      flag = 1;
    }
    if (exponent == s21_POSITIVE_INFINITY) {
      if (base < 1 && base > -1 && flag == 0) result = s21_ZERO_NUMBER;
      if (base < -1 && flag == 0) result = s21_POSITIVE_INFINITY;
      if (base > 1) result = s21_POSITIVE_INFINITY;
    }
    if (exponent == s21_NEGATIVE_INFINITY) {
      if (base < 1 && base > -1 && flag == 0) result = s21_POSITIVE_INFINITY;
      if (base < -1 && flag == 0) result = s21_ZERO_NUMBER;
      if (base > 1) result = s21_ZERO_NUMBER;
    }
  }

  return result;
}

long double s21_sin(double x) {
  long double result = 0;
  if (checking_number(x)) {
    long double x_sin = x > s21_M_2PI || x < -s21_M_2PI
                            ? s21_fmod(x, -s21_M_2PI)
                            : (long double)x;
    long double add = x_sin;
    int n = 1;
    while (s21_fabs(add) > 10e-10 && add != s21_POSITIVE_INFINITY &&
           add != s21_NEGATIVE_INFINITY) {
      result += add;
      add *= -x_sin * x_sin / (2 * n * (2 * n + 1));
      n++;
    }
  } else if (x == -x) {
    result = x;
  } else {
    result = x * s21_NAN;
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result = x;
  if (x > 0 && checking_number(x)) {
    long double res = 0;
    result = 1;
    while (s21_fabs(res) != s21_fabs(result)) {
      res = result;
      result = (x / result + result) / 2;
    }
  } else if (x < 0) {
    result = s21_NAN;
  }
  return result;
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

int is_negative_zero(double x) {
  return (x == s21_ZERO_NUMBER && 1.0 / x == s21_NEGATIVE_INFINITY);
}

int is_integer_number(double x) { return (x - s21_floor(x) < s21_EPSILON); }

int is_even_number(double x) {
  x = s21_fabs(x);
  return s21_fmod(x, 2.0) < s21_EPSILON;
}

int checking_number(double x) {
  int stop = 0;
  if (!(x != x || (x == s21_NEGATIVE_INFINITY || x == s21_POSITIVE_INFINITY) ||
        x == -x)) {
    stop = 1;
  }
  return stop;
}
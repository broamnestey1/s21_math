#include "s21_math.h"
#include <math.h>

int main() {
    // printf("%d\n", s21_abs(5));
    // printf("%Lf\n", s21_pow(10, -1));
    // printf("%Lf\n", s21_factorial(2));
    // printf("%Lf\n", s21_cos(2));
    // printf("%f\n", cos(2));
    printf("%Lf\n", s21_sin(-9));
    printf("%f\n", sin(-9));
    // printf("%Lf\n", s21_tan(2));
    // printf("%f\n", tan(2));
    // printf("%Lf\n", s21_sqrt(49));
    // printf("%f\n", sqrt(49));
    // printf("%Lf\n", s21_fabs(-5.789998));
    // printf("%f\n", fabs(-5.789998));
    // printf("%Lf\n", s21_ceil(-3.2));
    // printf("%f\n", ceil(-3.2));
    // printf("%Lf\n", s21_floor(3.2));
    // printf("%f\n", floor(3.2));
    return 0;
}


int s21_abs(int x) { //надеюсь готово 1
    if (x < 0) {
        x *= -1; 
    }
    return x;
}

long double s21_acos(double x) {

}

long double s21_asin(double x) {

}

long double s21_atan(double x) {

}

long double s21_ceil(double x) { //надеюсь готово 7
    long double result = (int)x;
    if (x > 0 && x != result) {
        result++;
    }
    return result;
}

long double s21_cos(double x) { //надеюсь готово 2
    long double result = 0;
    for (int i = 0; i < 500; i++) {
        result += (s21_pow(-1, i) * s21_pow(x, 2 * i)) / (s21_factorial(2 * i));  
    }
    return result;
}

long double s21_exp(double x) {

}

long double s21_fabs(double x) { //надеюсь готово 3
    if (x < 0) {
        x *= -1; 
    }
    return x;
}

long double s21_floor(double x) { //надеюсь готово 8
    long double result = (int)x;
    if (x < 0 && x != result) {
        result--;
    }
    return result;
}

long double s21_fmod(double x, double y) {

}

long double s21_log(double x) {

}

long double s21_pow(double base, double exp) { //не совсем готово
    double result = base;
    if (exp == 0) {
        result = 1;
    } else if (exp < 0) { //возведение в отрицательную степень недоступно пока
        double temp = 0;
        exp *= -1;
        for (int i = 1; i < exp; i++) {
            temp *= base;
            printf("%f\n", temp);
        }
        result = 1/temp;
    } else if (exp == 1) {
        result = base;
    } else {
        for (int i = 1; i < exp; i++) {
            result *= base;
        }
    }
    return result;
}

long double s21_sin(double x) { //надеюсь готово 4??????
    long double result = 0;
    for (; x < -2 * S21_PI || 2 * S21_PI < x;) {
        if (x > 2 * S21_PI) {
            x -= 2 * S21_PI;
        } else {
            x += 2 * S21_PI;
        }
    }
    for (int i = 0; i < 500; i++) {
        result += (s21_pow(-1, i) * s21_pow(x, 2 * i + 1)) / (s21_factorial(2 * i + 1));
    }
    return result;
}

long double s21_sqrt(double x) { //надеюсь готово 5, не реализован в методе возведения в степень? NADO LI, Realizovan tut!
    double guess = x;
    double epsilon = 1e-15;

    while(1) {
        double newGuess = 0.5 * (guess + x / guess);
        printf("%f\n", newGuess);
        if (fabs(newGuess - guess) < epsilon) {
            return newGuess;
        }
        guess = newGuess;
    }


    return guess;
}

long double s21_tan(double x) { //надеюсь готово 6
    long double result = 0;
    result = s21_sin(x) / s21_cos(x);
    return result;
}

long double s21_factorial(long long int x) { //просто готово
    if (x < 0) {
        return 0;
    }
    if (x == 0) {
        return 1;
    } else {
        return x * s21_factorial(x - 1);
    }
}
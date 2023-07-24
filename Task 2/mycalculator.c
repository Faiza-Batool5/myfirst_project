#include <stdio.h>
#include "mycalculator.h"
int addition(int num1, int num2)
 {
    return num1 + num2;
 }
 int subtraction(int num1, int num2)
 {
    return num1 - num2;
 }
 int multiply(int num1, int num2)
 {
    return num1 * num2;
 }
 float division(int num1, int num2) {
    if (num2 != 0) {
        return (float)num1 / num2;
    } else {
        return 0.0; 
    }
}
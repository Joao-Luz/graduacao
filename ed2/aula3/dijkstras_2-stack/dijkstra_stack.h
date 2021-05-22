#pragma once

#include <string.h>
#include <stdio.h>
#include "stack.h"

double DS_execute(char* op);

static inline double evaluate(double a, double b, char o){
    if(o == '+') return a + b;
    if(o == '-') return a - b;
    if(o == '*') return a * b;
    if(o == '/') return a / b;
};

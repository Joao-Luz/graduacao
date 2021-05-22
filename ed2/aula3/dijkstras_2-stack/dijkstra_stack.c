#include "dijkstra_stack.h"

double DS_execute(char* op){
    stack* operators =  ST_init(sizeof(char));
    stack* operands = ST_init(sizeof(double));

    int i = 0;
    char c;
    do{
        c = op[i];
        i++;
        if(c == '(' || c == ' ') continue;
        else if(c == ')'){
            double b = *((double*)ST_pop(operands));
            double a = *((double*)ST_pop(operands));
            char o = *((char*)ST_pop(operators));
            double res = evaluate(a, b, o);
            ST_push(operands, &res);
        }
        else if(c == '+' || c == '-' || c == '/' || c == '*') ST_push(operators, &c);
        else{
            double val = (c - '1' + 1);
            ST_push(operands, &val);
        }
    }while(op[i]);

    double result = *((double*)ST_pop(operands));
    ST_delete(operands);
    ST_delete(operators);
    return result;
}
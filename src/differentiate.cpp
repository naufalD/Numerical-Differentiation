#include "include/differentiate.h"
//#include "float.h"

#include <cmath>
double h = pow(2,-40);

double differentiateFD(double x, std::function<double(double)> theFunction){
    return (theFunction(x+h)-theFunction(x))/h;
}

double differentiateCD(double x, std::function<double(double)> theFunction){
    return (theFunction(x+h/2)-theFunction(x-h/2))/h;
}

double differentiateExtrap(double x, std::function<double(double)> theFunction){
    return (8*(theFunction(x+h/4)-theFunction(x-h/4)) - (theFunction(x+h/2)-theFunction(x-h/2)))/3/h;
}

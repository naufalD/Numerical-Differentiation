#ifndef DIFFERENTIATE_H
#define DIFFERENTIATE_H

#include <functional>

double differentiateFD(double x, std::function<double(double)> theFunction);
double differentiateCD(double x, std::function<double(double)> theFunction);
double differentiateExtrap(double x, std::function<double(double)> theFunction);

#endif // DIFFERENTIATE_H

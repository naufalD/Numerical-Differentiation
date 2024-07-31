## Introduction
This program is an implementation of numerical differentiation methods using the forward difference, central difference and Extrapolation methods. It is part of chapter 7 in the computational physics textbook by Landau (2015)[^1] on numerical differentiation. 

[^1]: Landau, R. H. (2015). Computational physics problem solving with python. John Wiley & Sons, Incorporated. 

## Forward Difference Method
$$\frac{dy}{dt} = \frac{y(t+h)-y(t)}{h}$$

## Central Difference Method
$$\frac{dy}{dt} = \frac{y(t+h/2)-y(t-h/2)}{h}$$
## Extrapolated Difference Method
$$\frac{dy}{dt} = \frac{8(y(t+h/4)-y(t-h/4))-(y(t+h/2)-y(t-h/2))}{3h}$$

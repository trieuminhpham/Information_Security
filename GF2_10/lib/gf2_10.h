#ifndef GF2_10_H
#define GF2_10_H

#include <iostream>
#include <algorithm>

int degree(unsigned int a);
unsigned int poly_mul(unsigned int a, unsigned int b);
unsigned int poly_mod(unsigned int a, unsigned int mod);

unsigned int gf_inverse(unsigned int a, unsigned int mod);

void print_poly(unsigned int a);

#endif